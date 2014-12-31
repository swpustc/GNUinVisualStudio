#include <stdint.h>
#include <crtdefs.h>

#include <cassert>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>

#define _STRING_PRINTF_NO_VARIADIC_TEMPLATES_ 0
#include <stringprintf.h>
#include "version.h"

// string_printf
using namespace stdex;

// oblects
using std::cin;
using std::cout;
using std::cerr;
using std::clog;
using std::endl;

// container
using std::unique_ptr;
using std::shared_ptr;
using std::ios;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::deque;
using std::map;
using std::set;
using std::pair;
using std::tuple;

// algorithm
using std::move;
using std::forward;
using std::for_each;
using std::transform;
using std::remove;
using std::remove_if;
using std::reverse;
using std::find;
using std::find_if;
using std::sort;
using std::stable_sort;
using std::unique;
using std::min;
using std::max;
using std::any_of;
using std::equal;
using std::make_pair;
using std::get;
using std::make_tuple;
using std::getline;
using std::strerror;

// functional
using std::bind;
using namespace std::placeholders;


static const string empty_string = "";
static uint32_t format_item_length = 0;
static const string format_item32_format = "%%-%us  %%#010llx%%5s%%#8x";
static const string format_item64_format = "%%-%us  %%#014llx%%1s%%#8x";
static const string format_item_single32 = "%s  %#010llx%2s%#x";
static const string format_item_single64 = "%s  %#014llx%2s%#x";
static string format_item32 = "%-32s  %#010llx%5s%#8x";
static string format_item64 = "%-32s  %#014llx%1s%#8x";
static const string print_record_pre_32 = "%s(%s): %#010llx(%#x)";
static const string print_record_pre_64 = "%s(%s): %#014llx(%#x)";
static const string print_record_dump32 = "%s(%s): %#010llx(%#x)";
static const string print_record_dump64 = "%s(%s): %#014llx(%#x)";
static const string comment_increased_reset = "Increased base For BaseAddress";
#define COMMENT_INCREASED_BY_ALIGNMENT "Increased base By Alignment("
static const string comment_increased_by_alignment = COMMENT_INCREASED_BY_ALIGNMENT;
static const string comment_increased_by_alignment_format = COMMENT_INCREASED_BY_ALIGNMENT "%#x)";
#define EDIT_RECORD_SAMPLE        "BASEADDRESS MODIFY RECORDS"
#define EDIT_RECORD_HEAD          EDIT_RECORD_SAMPLE " -- DO NOT EDIT RECORDS LINES -- MAX RECORDS TABLE LINES("
#define EDIT_RECORD_TITLE         "- TITLE"
#define EDIT_RECORD_TITLE_OLD1    "RECORDS TITLE"
#define EDIT_RECORD_INFO          "LAST MODIFY"
#define EDIT_RECORD_INFO_OLD1     "LAST RECORD MODIFY"
#define EDIT_RECORD_INFO_OLD2     "LAST MODIFY RECORD"
#define EDIT_RECORD_END           EDIT_RECORD_SAMPLE " -- DO NOT EDIT RECORDS LINES -- RECORDS TABLE LINES("
static const string edit_record_sample = EDIT_RECORD_SAMPLE;
static const string edit_record_head = EDIT_RECORD_HEAD;
static const string edit_record_head_format = "; " EDIT_RECORD_HEAD "%u) -- VERSION " FILE_VERSION;
static const string edit_record_title = EDIT_RECORD_TITLE;
static const string edit_record_title_old1 = EDIT_RECORD_TITLE_OLD1;
static const string edit_record_title_format_less14_full = "; " EDIT_RECORD_TITLE " ------ PROJECT NAME -- BASEADDRESS -- OLDSIZE --- NEWSIZE - SPACE - MODIFY DATE TIME --";
static const string edit_record_title_format_greater_equal14 = "; " EDIT_RECORD_TITLE " ------ PROJECT NAME --%s BASEADDRESS -- OLDSIZE --- NEWSIZE - SPACE - MODIFY DATE TIME --";
static const string edit_record_title_format_greater_equal25 = "; " EDIT_RECORD_TITLE " ------ PROJECT NAME - PLATFORM --%s BASEADDRESS -- OLDSIZE --- NEWSIZE - SPACE - MODIFY DATE TIME --";
static const string edit_record_title_format_greater_equal32 = "; " EDIT_RECORD_TITLE " ------ PROJECT NAME - TARGET PLATFORM --%s BASEADDRESS -- OLDSIZE --- NEWSIZE - SPACE - MODIFY DATE TIME --";
static string edit_record_title_format = "; " EDIT_RECORD_TITLE " ------ PROJECT NAME - TARGET PLATFORM -- BASEADDRESS -- OLDSIZE --- NEWSIZE - SPACE - MODIFY DATE TIME --";
static const string edit_record_info = EDIT_RECORD_INFO;
static const string edit_record_info_old1 = EDIT_RECORD_INFO_OLD1;
static const string edit_record_info_old2 = EDIT_RECORD_INFO_OLD2;
static uint32_t edit_record_info_format_length = 14;
static const string edit_record_info_format32_format = ";   " EDIT_RECORD_INFO ": %%-%us  %%#010llx%%5s%%#08x %%2s %%#08x +%%-#6x  %%04u/%%02u/%%02u %%02u:%%02u:%%02u";
static const string edit_record_info_format64_format = ";   " EDIT_RECORD_INFO ": %%-%us  %%#014llx%%1s%%#08x %%2s %%#08x +%%-#6x  %%04u/%%02u/%%02u %%02u:%%02u:%%02u";
static string edit_record_info_format32 = ";   " EDIT_RECORD_INFO ": %-32s  %#010llx%5s%#08x %2s %#08x +%-#6x  %04u/%02u/%02u %02u:%02u:%02u";
static string edit_record_info_format64 = ";   " EDIT_RECORD_INFO ": %-32s  %#014llx%1s%#08x %2s %#08x +%-#6x  %04u/%02u/%02u %02u:%02u:%02u";
static const string edit_record_info_rewrite_format = ";   " EDIT_RECORD_INFO ": %%-%us  %%s";
static string edit_record_info_rewrite = ";   " EDIT_RECORD_INFO ": %-32s  %s";
static const string edit_record_end = EDIT_RECORD_END;
static const string edit_record_end_format = "; " EDIT_RECORD_END "%u) END";
static const uint32_t edit_record_info_buffer_line_max = 1024;
static uint32_t edit_record_info_buffer_line = 0;
static const string single_info_head1 = "; BaseAddress addressTable.txt file for VisualStudio generated by " INTERAL_NAME "(Ver." FILE_VERSION_NUMSTR ")";
static const string single_info_head2 = ";     DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN";
static const string error_format1 = INTERAL_NAME ": unrecognized option '%s'\nTry '" INTERAL_NAME " --help' for more information.\n";
static const string error_format2 = INTERAL_NAME ": too few arguments\nTry '" INTERAL_NAME " --help' for more information.\n";
static const string error_format3 = INTERAL_NAME ": option '%s' requires an argument\n";
static const string error_format4 = INTERAL_NAME ": invalid argument '%s' for '%s'\nTry '" INTERAL_NAME " --help' for more information.\n";
static const string error_format5 = INTERAL_NAME ": option '%s' requires an file argument\n";
static const string error_format6 = INTERAL_NAME ": %s: file ABI(%#6X) unknow\n";
static const string warning_format1 = INTERAL_NAME ": refused to work for the high version: Ver.%llu (CurVer.%llu)\n";
static const string warning_format2 = INTERAL_NAME ": %s: %s\n";
static const string warning_format3 = INTERAL_NAME ": %s: the given ABI(%s) is not same as file ABI(%s).\n";
static const uint64_t base_dll64 = 0x076062000000;
static const uint32_t base_dll32 = 0x62000000;
static const uint64_t base_exe64 = 0x004C00420000;
static const uint32_t base_exe32 = 0x00420000;
static const uint64_t base_default = 0x10000000;
static const uint32_t size_default = 0x00000000;
static const uint32_t image_alignment_size = 0x00010000; // 64KB
static const uint32_t  page_alignment_size = 0x00001000; // 8KB
static const uint64_t current_version = FILE_VERSION_NUMBER; // current version


template<typename T> static inline typename is_string<T>::type format_directory(T&& _directory);
template<typename T> static inline uint32_t getImageSize(T&& file);
static inline int format_parameters(int argc, char *const argv[], struct parameters_list& argl);
static inline void read_value_from_file(istream& fin, deque<string>& record, deque<struct _value>& value, uint32_t& record_info_buffer_line);
static BOOL WINAPI CtrlHandle(DWORD CtrlType);


struct _value
{
    string   value_key;
    uint64_t value_base;
    uint32_t value_size;
    string   value_comment;
    enum increased_type_t {
        INCREASED_NONE,
        INCREASED_RESET,
        INCREASED_BY_ALIGNMENT
    } increased_base;
    uint32_t increased_alignment;
    inline _value() : value_base(NULL), value_size(NULL)
    {
        increased_base = INCREASED_NONE;
        increased_alignment = NULL;
    }
    template<typename T> inline _value(T&& key, uint64_t base, uint32_t size = NULL)
        : value_key(forward<T>(key)), value_base(base), value_size(size)
    {
        increased_base = INCREASED_NONE;
        increased_alignment = NULL;
    }
    /* Members Methot */
    inline string gen_comment() const
    {
        string comment = value_comment;
        size_t pos_comment_start = comment.find_first_not_of(" \t\r\n;");
        size_t pos_comment_end__ = comment.find_first_of("\r\n", pos_comment_start);
        if (string::npos != pos_comment_start)
            comment = comment.substr(pos_comment_start, pos_comment_end__ - pos_comment_start);
        else
            comment.clear();
        /* erase all increased comment (auto comment) */
        size_t pos_increased_start = string::npos, pos_increased_end__ = string::npos;
        if (string::npos != (pos_increased_start = comment.find(comment_increased_reset)))
        {
            pos_increased_start = pos_increased_start == NULL ? NULL :
                comment.find_last_not_of(" \t\r\n;", pos_increased_start - 1) + 1;
            pos_increased_end__ = pos_increased_start + comment_increased_reset.length();
            comment.erase(pos_increased_start, pos_increased_end__ - pos_increased_start);
        }
        if (string::npos != (pos_increased_start = comment.find(comment_increased_by_alignment)))
        {
            pos_increased_start = pos_increased_start == NULL ? NULL :
                comment.find_last_not_of(" \t\r\n;", pos_increased_start - 1) + 1;
            pos_increased_end__ = comment.find_first_of(')', pos_increased_start + comment_increased_by_alignment.length());
            if (string::npos != pos_increased_end__)
                pos_increased_end__++;
            comment.erase(pos_increased_start, pos_increased_end__ - pos_increased_start);
        }
        if (increased_base == INCREASED_RESET)
        {
            if (comment.empty())
                comment = comment_increased_reset;
            else
                comment = move(comment) + "  ;" + comment_increased_reset;
        }
        else if (increased_base == INCREASED_BY_ALIGNMENT)
        {
            string comment_value(string_printf(comment_increased_by_alignment_format, increased_alignment));
            if (comment.empty())
                comment = move(comment_value);
            else
                comment = move(comment) + "  ;" + move(comment_value);
        }
        /* add comment head: ';' */
        if (!comment.empty())
            comment = ";" + move(comment);
        return move(comment);
    }
    inline string gen_output() const
    {
        bool value_x64_number = false;
        if (value_base > INT32_MAX)
            value_x64_number = true;

        string comment = gen_comment();
        if (value_key.empty())
            return move(comment);
        else
        {
            string value_format = string_printf(value_x64_number ? format_item64 : format_item32,
                value_key, value_base, empty_string, value_size);
            if (comment.empty())
                return move(value_format);
            else
                return move(value_format) + "  " + move(comment);
        }
    }
    inline bool operator==(const _value& r)
    {
        if (value_key != r.value_key)
            return false;
        else if (value_base != r.value_base)
            return false;
        else if (value_size != r.value_size)
            return false;
        else if (increased_base != r.increased_base)
            return false;
        else if (increased_base == INCREASED_BY_ALIGNMENT &&
            increased_alignment != r.increased_alignment)
            return false;
        else if (gen_comment() != r.gen_comment())
            return false;
        else
            return true;
    }
};

struct increased_base_addr
{
    uint64_t base_for_base;
    uint32_t base_for_size;
    inline increased_base_addr()
        : base_for_base(base_default), base_for_size(size_default)
    {}
    inline void operator() (_value& in)
    {
        if (!in.value_key.empty())
        {
            switch (in.increased_base)
            {
            case _value::INCREASED_BY_ALIGNMENT:
                base_for_base = (base_for_base + base_for_size + in.increased_alignment - 1) / in.increased_alignment * in.increased_alignment;
                base_for_size = in.value_size;
                in.value_base = base_for_base;
                break;
            case _value::INCREASED_RESET:
                base_for_base = (in.value_base + image_alignment_size - 1) / image_alignment_size * image_alignment_size;
                base_for_size = in.value_size;
                break;
            case _value::INCREASED_NONE:
            default:
                base_for_base = (base_for_base + base_for_size + image_alignment_size - 1) / image_alignment_size * image_alignment_size;
                base_for_size = in.value_size;
                in.value_base = base_for_base;
                break;
            }
        }
    }
};

struct auto_lock_mutex
{
    HANDLE m_hobject;
    template<typename T> inline auto_lock_mutex(T&& object_name, bool bLockState, DWORD dwMilliSeconds = INFINITE)
    {
        static_assert(is_string<T>::value, "object_name is NOT a string");
        typename is_string<T>::type _object_name = forward<T>(object_name);
        m_hobject = CreateMutex(nullptr, FALSE, "Global\\{F2DDD9E9-5ADF-4E27-AC75-A71872DF1D32}" + move(_object_name));
        if (bLockState)
            lock(dwMilliSeconds);
    }
    ~auto_lock_mutex()
    {
        unlock();
        CloseHandle(m_hobject);
    }
    inline void lock(DWORD dwMilliSeconds = INFINITE)
    {
        WaitForSingleObject(m_hobject, dwMilliSeconds);
    }
    inline void unlock()
    {
        ReleaseMutex(m_hobject);
    }
};

struct auto_lock_multi_mutex
{
    HANDLE m_hmulti_lock;
    map<string, tuple<shared_ptr<auto_lock_mutex>, bool, DWORD> > m_lock;
    auto_lock_multi_mutex(DWORD dwMilliSeconds = INFINITE)
    {
        m_hmulti_lock = CreateMutex(nullptr, FALSE, "Global\\{88C262B3-E50E-4030-9CE8-FAAD2B642548}");
        WaitForSingleObject(m_hmulti_lock, dwMilliSeconds);
    }
    ~auto_lock_multi_mutex()
    {
        if (m_hmulti_lock != INVALID_HANDLE_VALUE)
            CloseHandle(m_hmulti_lock);
    }
    template<typename T> inline void add_single_object(T&& object_name, bool bLockState = true, DWORD dwMilliSeconds = INFINITE)
    {
        static_assert(is_string<T>::value, "object_name is NOT a string");
        assert(m_hmulti_lock != INVALID_HANDLE_VALUE);
        auto ins = m_lock.insert(make_pair(forward<T>(object_name), make_tuple(shared_ptr<auto_lock_mutex>(), bLockState, dwMilliSeconds)));
        if (ins.second) /* object_name has already forword, so it could be empty */
            get<0>(ins.first->second).reset(new auto_lock_mutex(ins.first->first, false));
    }
    inline void add_complete()
    {
        assert(m_hmulti_lock != INVALID_HANDLE_VALUE);
        for_each(m_lock.begin(), m_lock.end(), [&](const decltype(*m_lock.end())& in)
        {
            if (get<1>(in.second))
                get<0>(in.second)->lock(get<2>(in.second));
        });
        ReleaseMutex(m_hmulti_lock);
        CloseHandle(m_hmulti_lock);
        m_hmulti_lock = INVALID_HANDLE_VALUE;
    }
};

struct parameters_list
{
    bool     pre;
    bool     dump;
    uint64_t workapcae_version;
    typedef enum record_line_t { RECORD_LINE_NOTSET, RECORD_LINE_SET, RECORD_LINE_ADD, RECORD_LINE_SUB } record_line;
    pair<uint32_t, record_line> recordline;
    deque<pair<size_t, string> > input;
    deque<pair<size_t, string> > output;
    deque<pair<size_t, string> > addrDir;
    typedef enum file_info_t { FILE_INFO_NOTSET, FILE_INFO_DLL, FILE_INFO_EXE } file_info;
    typedef enum platform_info_t { PLATFORM_INFO_NOTSET, PLATFORM_INFO_32, PLATFORM_INFO_64 } platform_info;
    /* pair<serial_number,tuple<file_name, key_name, file_type, platform, is_skip>> */
    deque<pair<size_t, tuple<string, string, file_info, platform_info, bool> > > file;
    struct debugoutput_t {
        bool     null_is_set;
        ostream* pcout;
        FILE*    pstdout;
        ostream* pcerr;
        FILE*    pstderr;
        ostream* pclog;
        csys_t*  pcsys;
        inline debugoutput_t()
            : null_is_set(false), pcout(nullptr), pstdout(nullptr),
                pcerr(nullptr), pstderr(nullptr),
                pclog(nullptr), pcsys(nullptr)
        {}
        inline void reset()
        {
            null_is_set = false;
            pcout = nullptr;
            pstdout = nullptr;
            pcerr = nullptr;
            pstderr = nullptr;
            pclog = nullptr;
            pcsys = nullptr;
        }
        inline void initialization()
        {
            reset();
            pstderr = stderr;
            pcsys = &csys;
        }
        inline bool null()
        {
            return pcout == nullptr && pstdout == nullptr &&
                pcerr == nullptr && pstderr == nullptr &&
                pclog == nullptr && pcsys == nullptr;
        }
#define DEBUG_PUTS_ARG(_Val) _Val.debugoutput.pcout, _Val.debugoutput.pstdout,  \
            _Val.debugoutput.pcerr, _Val.debugoutput.pstderr,                   \
            _Val.debugoutput.pclog, _Val.debugoutput.pcsys
#define DEBUG_PRINTF_ARG(_Val) _Val.debugoutput.pcsys, _Val.debugoutput.pclog,  \
            _Val.debugoutput.pstderr, _Val.debugoutput.pcerr,                   \
            _Val.debugoutput.pstdout, _Val.debugoutput.pcout
    } debugoutput;
    inline parameters_list()
        : pre(false), dump(false), workapcae_version(NULL), recordline(0, RECORD_LINE_NOTSET)
    {}
    inline void reset()
    {
        pre = false;
        dump = false;
        workapcae_version = NULL;
        recordline.first = 0;
        recordline.second = RECORD_LINE_NOTSET;
        input.clear();
        output.clear();
        addrDir.clear();
        file.clear();
        debugoutput.reset();
    }
};


template<typename T> static inline tuple<uint32_t, parameters_list::platform_info, WORD> getImageInfomation(T&& file);

static deque<string>    global_record;
static deque<_value>    global_value;
static parameters_list  global_argl;

int main(int argc, char* argv[])
{
    int error_code = format_parameters(argc, argv, global_argl);
    if (error_code >= 0)
        return error_code;

    /* setup ctrl+C handle */
    SetConsoleCtrlHandler(CtrlHandle, TRUE);

    if (global_argl.pre || global_argl.dump)
    {
        /* preprocessing file name, and lock all input and output files or directorys */
        auto_lock_multi_mutex auto_lock;
        auto _lock_object = [&](decltype(*global_argl.input.end())& in)
        {
            auto_lock.add_single_object(format_directory(in.second));
        };
        for_each(global_argl.input.begin(), global_argl.input.end(), _lock_object);
        for_each(global_argl.output.begin(), global_argl.output.end(), _lock_object);
        for_each(global_argl.addrDir.begin(), global_argl.addrDir.end(), _lock_object);
        auto_lock.add_complete();
        /* read from input */
        if (any_of(global_argl.input.begin(), global_argl.input.end(), [](const decltype(*global_argl.input.end())& in)->bool
        {
            shared_ptr<istream> pin;
            if (in.second.empty())
                pin.reset(&cin, [](...){});
            else
                pin.reset(new ifstream(in.second));
            if (pin->fail())
                return stream_printf(stderr, warning_format2, in.second, strerror(errno)), true;
            read_value_from_file(*pin, global_record, global_value, edit_record_info_buffer_line);
            return false;
        }))
            return 1;
        /* set the record line */
        switch (global_argl.recordline.second)
        {
        case parameters_list::RECORD_LINE_NOTSET:
            break;
        case parameters_list::RECORD_LINE_SET:
            edit_record_info_buffer_line = global_argl.recordline.first;
            break;
        case parameters_list::RECORD_LINE_ADD:
            edit_record_info_buffer_line += global_argl.recordline.first;
            break;
        case parameters_list::RECORD_LINE_SUB:
            edit_record_info_buffer_line -= global_argl.recordline.first;
            break;
        default:
            assert(global_argl.recordline.second != parameters_list::RECORD_LINE_NOTSET);
            return 2;
        }
        if (edit_record_info_buffer_line > edit_record_info_buffer_line_max)
            edit_record_info_buffer_line = edit_record_info_buffer_line_max;
        /* format data */
        for_each(global_value.begin(), global_value.end(), increased_base_addr());
        /* setup single output format */
        format_item32 = format_item_single32;
        format_item64 = format_item_single64;
        /* handle addrDir directory first, only read back empty value_size */
        if (any_of(global_argl.addrDir.begin(), global_argl.addrDir.end(), [&](const decltype(*global_argl.addrDir.end())& addr)->bool
        {
            if (!mkdir(addr.second) && errno != EEXIST && errno != NULL)
                return stream_printf(stderr, warning_format2, addr.second, strerror(errno)), true;
            for_each(global_value.begin(), global_value.end(), [&](decltype(*global_value.end())& in)
            {
                if (in.value_key.empty() || NULL != in.value_size)
                    return;
                _value origin;
                ifstream faddr_in(addr.second + in.value_key + ".txt");
                if (!faddr_in.fail())
                {
                    deque<string> record;
                    deque<_value> value;
                    uint32_t record_info_buffer_line = NULL;
                    read_value_from_file(faddr_in, record, value, record_info_buffer_line);
                    find_if(value.begin(), value.end(), [&](decltype(*value.end())& value_single)->bool
                    {
                        if (in.value_key == value_single.value_key)
                        {
                            origin.value_base = value_single.value_base;
                            origin.value_size = value_single.value_size;
                            origin.value_key = move(value_single.value_key); /* move() becareful! */
                            return true;
                        }
                        return false;
                    });
                }
                if (NULL != origin.value_size)
                {
                    in.value_size = origin.value_size;
                    for_each(global_value.begin(), global_value.end(), increased_base_addr());
                }
            });
            return false;
        }))
            return 3;
        /* handle input PE files */
        if (any_of(global_argl.file.begin(), global_argl.file.end(), [&](const decltype(*global_argl.file.end())& file_in)->bool
        {
            /* find send key iterator */
            auto iter = find_if(global_value.begin(), global_value.end(), [&](const decltype(*global_value.end())& in)->bool
            {
                return equal_to_nocase()(in.value_key, get<1>(file_in.second));
            });
            if (global_argl.pre || global_argl.dump)
            {
                bool add_record = false;
                if (iter == global_value.end())
                {
                    add_record = true;
                    _value value_struct(get<1>(file_in.second), 0, size_default);
                    if (global_value.empty() || get<2>(file_in.second) != parameters_list::FILE_INFO_DLL)
                        value_struct.increased_base = _value::INCREASED_RESET;
                    iter = global_value.insert(global_value.end(), move(value_struct)); /* move() becareful! */
                }
                iter->value_key == get<1>(file_in.second);
                if (NULL == iter->value_base)
                {
                    iter->value_base = parameters_list::FILE_INFO_DLL == get<2>(file_in.second) ?
                        (parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? base_dll64 : base_dll32) :
                        (parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? base_exe64 : base_exe32);
                }
                /* check base address setting */
                for_each(global_value.begin(), global_value.end(), increased_base_addr());
                if ((parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) && iter->value_base < INT32_MAX) ||
                    (parameters_list::PLATFORM_INFO_64 != get<3>(file_in.second) && iter->value_base > INT32_MAX))
                {
                    iter->value_base = parameters_list::FILE_INFO_DLL == get<2>(file_in.second) ?
                        (parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? base_dll64 : base_dll32) :
                        (parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? base_exe64 : base_exe32);
                    iter->increased_base = _value::INCREASED_RESET;
                }
                if (global_argl.pre && add_record)
                {
                    debug_printf<true>(DEBUG_PRINTF_ARG(global_argl),
                        parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? print_record_pre_64 : print_record_pre_32,
                        get<1>(file_in.second), "New", iter->value_base, iter->value_size);
                }
                else if (global_argl.pre)
                {
                    debug_printf<true>(DEBUG_PRINTF_ARG(global_argl),
                        parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? print_record_pre_64 : print_record_pre_32,
                        get<1>(file_in.second), "Get", iter->value_base, iter->value_size);
                }
            }
            if (global_argl.dump)
            {
                auto image_information = getImageInfomation(get<0>(file_in.second));
                uint32_t &image_size = get<0>(image_information), full_size, old_size, old_full_size;
                image_size = (image_size + page_alignment_size - 1) / page_alignment_size * page_alignment_size;
                full_size = (image_size + image_alignment_size - 1) / image_alignment_size * image_alignment_size;
                if (parameters_list::PLATFORM_INFO_NOTSET == get<1>(image_information))
                    return stream_printf(stderr, error_format6, get<0>(file_in.second), get<2>(image_information)), true;
                if (parameters_list::PLATFORM_INFO_NOTSET != get<3>(file_in.second))
                {
                    if (get<3>(file_in.second) != get<1>(image_information))
                    {
                        debug_printf(csys, cerr, warning_format3, get<0>(file_in.second),
                            parameters_list::PLATFORM_INFO_32 == get<3>(file_in.second) ? "x86" : "x64",
                            parameters_list::PLATFORM_INFO_32 == get<1>(image_information) ? "x86" : "x64");
                    }
                }
                if (iter->value_size != image_size && image_size != 0)
                {
                    old_size = iter->value_size;
                    old_full_size = (old_size + image_alignment_size - 1) / image_alignment_size * image_alignment_size;
                    iter->value_size = image_size;
                    /* add record modify key to global_record here */
                    string conjunction;
                    if (old_size == NULL)
                        conjunction = "<>";
                    else if (old_full_size < full_size)
                        conjunction = "++";
                    else if (old_full_size > full_size)
                        conjunction = "--";
                    else if (old_size < image_size)
                        conjunction = "->";
                    else /* if (old_size > image_size) */
                    {
                        assert(old_size > image_size);
                        conjunction = "<-";
                    }
                    SYSTEMTIME st;
                    GetLocalTime(&st);
                    global_record.push_front(string_printf(
                        parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? edit_record_info_format64 : edit_record_info_format32,
                        get<1>(file_in.second), iter->value_base, empty_string, old_size, conjunction,
                        image_size, full_size - image_size,
                        st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond));
                    debug_printf<true>(DEBUG_PRINTF_ARG(global_argl),
                        parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? print_record_dump64 : print_record_dump32,
                        get<1>(file_in.second), "New", iter->value_base, image_size);
                }
                else if (image_size == 0)
                {
                    debug_printf<true>(DEBUG_PRINTF_ARG(global_argl),
                        parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? print_record_dump64 : print_record_dump32,
                        get<1>(file_in.second), "Old", iter->value_base, iter->value_size);
                }
                else
                {
                    debug_printf<true>(DEBUG_PRINTF_ARG(global_argl),
                        parameters_list::PLATFORM_INFO_64 == get<3>(file_in.second) ? print_record_dump64 : print_record_dump32,
                        get<1>(file_in.second), "Get", iter->value_base, iter->value_size);
                }
            }
            for_each(global_value.begin(), global_value.end(), increased_base_addr());
            /* set the key length */
            uint32_t length = (uint32_t)get<1>(file_in.second).length();
            format_item_length = max(length, format_item_length);
            return false;
        }))
            return 4;
        /* handle addrDir directory second, synchronization */
        if (any_of(global_argl.addrDir.begin(), global_argl.addrDir.end(), [&](const decltype(*global_argl.addrDir.end())& addr)->bool
        {
            return any_of(global_value.begin(), global_value.end(), [&](decltype(*global_value.end())& in)->bool
            {
                if (in.value_key.empty())
                    return false;
                _value origin;
                string single_file_name = addr.second + in.value_key + ".txt";
                ifstream faddr_in(single_file_name);
                if (!faddr_in.fail())
                {
                    deque<string> record;
                    deque<_value> value;
                    uint32_t record_info_buffer_line = NULL;
                    read_value_from_file(faddr_in, record, value, record_info_buffer_line);
                    any_of(value.begin(), value.end(), [&](decltype(*value.end())& value_single)->bool
                    {
                        if (in.value_key == value_single.value_key)
                        {
                            origin.value_base = value_single.value_base;
                            origin.value_size = value_single.value_size;
                            origin.value_key = move(value_single.value_key);
                            return true;
                        }
                        return false;
                    });
                }
                assert(!(NULL == in.value_size && NULL != origin.value_size));
                _value single_value(in.value_key,
                    (in.value_base + image_alignment_size - 1) / image_alignment_size * image_alignment_size,
                    (in.value_size + image_alignment_size - 1) / image_alignment_size * image_alignment_size);
                if (origin.value_base != single_value.value_base ||
                    origin.value_size != single_value.value_size ||
                    origin.value_key != single_value.value_key)
                {
                    ofstream faddr_out(single_file_name);
                    if (faddr_out.fail())
                        return stream_printf(stderr, warning_format2, single_file_name, strerror(errno)), true;
                    faddr_out << single_info_head1 << endl;
                    faddr_out << single_info_head2 << endl;
                    faddr_out << single_value.gen_output() << endl;
                }
                return false;
            });
        }))
            return 5;
        /* remove duplicate key and bad key in record */
        set<string, less_nocase> record_key;
        global_record.erase(remove_if(global_record.begin(), global_record.end(), [&](const string& in)->bool
        {
            size_t record_title_pos = in.find(edit_record_info);
            if (string::npos != record_title_pos)
                record_title_pos += edit_record_info.length();
            size_t key_start = in.find_first_not_of(" \t;:", record_title_pos);
            size_t key_end__ = in.find_first_of(" \t;\r\n", key_start);
            if (string::npos != key_end__)
                return !record_key.insert(in.substr(key_start, key_end__ - key_start)).second;
            else
                return true;
        }), global_record.end());
        record_key.empty();
        /* generate record output format */
        uint32_t record_num = (uint32_t)min((size_t)edit_record_info_buffer_line, global_record.size());
        for_each(global_record.begin(), global_record.begin() + record_num, [&](const string& in)
        {
            size_t record_title_pos = in.find(edit_record_info);
            if (string::npos != record_title_pos)
                record_title_pos += edit_record_info.length();
            size_t key_start = in.find_first_not_of(" \t;:", record_title_pos);
            size_t key_end__ = in.find_first_of(" \t;\r\n", key_start);
            assert(string::npos != key_end__);
            edit_record_info_format_length = max((uint32_t)(key_end__ - key_start), edit_record_info_format_length);
        });
        edit_record_info_format_length = min(MAX_PATH, edit_record_info_format_length);
        if (edit_record_info_format_length >= 32)
            edit_record_title_format = string_printf(edit_record_title_format_greater_equal32, string(edit_record_info_format_length - 32, '-'));
        else if (edit_record_info_format_length >= 25)
            edit_record_title_format = string_printf(edit_record_title_format_greater_equal25, string(edit_record_info_format_length - 25, '-'));
        else if (edit_record_info_format_length >= 14)
            edit_record_title_format = string_printf(edit_record_title_format_greater_equal14, string(edit_record_info_format_length - 14, '-'));
        else
            edit_record_title_format = edit_record_title_format_less14_full, edit_record_info_format_length = 14;
        edit_record_info_format32 = string_printf(edit_record_info_format32_format, edit_record_info_format_length);
        edit_record_info_format64 = string_printf(edit_record_info_format64_format, edit_record_info_format_length);
        edit_record_info_rewrite = string_printf(edit_record_info_rewrite_format, edit_record_info_format_length);
        /* generate value output format */
        for_each(global_value.begin(), global_value.end(), [&](const decltype(*global_value.end())& in)
        {
            uint32_t length = (uint32_t)in.value_key.length();
            format_item_length = max(length, format_item_length);
        });
        format_item32 = string_printf(format_item32_format, format_item_length);
        format_item64 = string_printf(format_item64_format, format_item_length);
        /* output */
        if (any_of(global_argl.output.begin(), global_argl.output.end(), [&](const decltype(*global_argl.output.end())& in)->bool
        {
            shared_ptr<ostream> pout;
            if (in.second.empty())
                pout.reset(&cout, [](...){});
            else
            {
                unique_ptr<istream> pin(new ifstream(in.second));
                if (!pin->fail())
                {
                    deque<string> record;
                    deque<_value> value;
                    uint32_t record_info_buffer_line = NULL;
                    read_value_from_file(*pin, record, value, record_info_buffer_line);
                    if (edit_record_info_buffer_line == record_info_buffer_line &&
                        global_value.size() == value.size() &&
                        equal(global_value.begin(), global_value.end(), value.begin()))
                        return false; /* The documents of this file is the same as output(without records) */
                    pin.reset();
                }
                pout.reset(new ofstream(in.second));
            }
            if (!pout || pout->fail())
                return stream_printf(stderr, warning_format2, in.second, strerror(errno)), true;
            /* output records */
            stream_printf<true>(*pout, edit_record_head_format, edit_record_info_buffer_line);
            /* output title and records */
            if (record_num > 0)
            {
                stream_printf<true>(*pout, edit_record_title_format);
                for_each(global_record.begin(), global_record.begin() + record_num, [&](const string& in)
                {
                    if (!in.empty())
                    {
                        size_t record_title_pos = in.find(edit_record_info);
                        if (string::npos != record_title_pos)
                            record_title_pos += edit_record_info.length();
                        size_t key_start = in.find_first_not_of(" \t;:", record_title_pos);
                        size_t key_end__ = in.find_first_of(" \t;\r\n", key_start);
                        assert(string::npos != key_end__);
                        string record_key = in.substr(key_start, key_end__ - key_start);
                        size_t other_start = in.find_first_not_of(" \t\r\n", key_end__);
                        size_t other_end__ = in.find_first_of("\r\n", other_start);
                        string record_other;
                        if (string::npos != other_start)
                            record_other = in.substr(other_start, other_end__ - other_start);
                        stream_printf<true>(*pout, edit_record_info_rewrite, record_key, record_other);
                    }
                });
                stream_printf<true>(*pout, edit_record_end_format, record_num);
            }
            /* output values */
            for_each(global_value.begin(), global_value.end(), [&](decltype(*global_value.end())& in)
            {
                *pout << in.gen_output() << endl;
            });
            return false;
        }))
            return 6;
        return 0;
    }
    return 7;
}


/* transform directory to another string */
template<typename T> static inline typename is_string<T>::type format_directory(T&& _directory)
{
    static_assert(is_string<T>::value || is_container<T>::value, "_directory is NOT a string or container");
    typename is_string<T>::type directory = forward<T>(_directory);
    uint8_t hash_start = 0xe9;
    static const string no_change = "1234567890abcdefghijklmnopqrstuvwxyz`~!@#$%^&()-_+=[{]}\\:;,. ";
    static const char erase_char = '|';
    static const string empty_value = "Input_Is_Empty";
    for_each(directory.begin(), directory.end(), [&](uint8_t in)->uint8_t
    {
        return (hash_start = hash_start << 3) ^= in;
    });
    string in_str(1, '\0');
    transform(directory.begin(), directory.end(), directory.begin(), [&](char in)->char
    {
        in_str.at(0) = in;
        if (in_str.find_first_of(no_change) != string::npos)
            return in;
        else if (in >= 'A' && in <= 'Z')
            return in - 'A' + 'a';
        else if (in == '/')
            return '\\';
        else
            return erase_char;
    });
    directory.erase(remove(directory.begin(), directory.end(), erase_char), directory.end());
    if (directory.empty())
        return typename is_string<T>::type(empty_value.begin(), empty_value.end());
    while (directory.size() < 10)
        directory.insert(directory.end(), directory.begin(), directory.end());
    transform(directory.begin(), directory.end(), directory.begin(), [&](uint8_t in)->uint8_t
    {
        return ((hash_start = hash_start << 5) ^= in) % ('z' - 'a') + 'a';
    });
    reverse(directory.begin(), directory.end());
    return move(directory);
}


static inline uint32_t _getImageSize32(PIMAGE_NT_HEADERS32 pNTHeader, uint32_t size)
{
    if (!pNTHeader)
        return NULL;
    if (pNTHeader->FileHeader.SizeOfOptionalHeader != sizeof(pNTHeader->OptionalHeader))
        return NULL;
    PIMAGE_SECTION_HEADER pSectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)pNTHeader + sizeof(*pNTHeader));
    for (int i = NULL; i < pNTHeader->FileHeader.NumberOfSections; i++)
    {
        if ((pSectionHeader[i].PointerToRawData + pSectionHeader[i].SizeOfRawData) > size)
            return NULL;
    }
    return pNTHeader->OptionalHeader.SizeOfImage;
}

static inline uint32_t _getImageSize64(PIMAGE_NT_HEADERS64 pNTHeader, uint32_t size)
{
    if (!pNTHeader)
        return NULL;
    if (pNTHeader->FileHeader.SizeOfOptionalHeader != sizeof(pNTHeader->OptionalHeader))
        return NULL;
    PIMAGE_SECTION_HEADER pSectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)pNTHeader + sizeof(*pNTHeader));
    for (int i = NULL; i < pNTHeader->FileHeader.NumberOfSections; i++)
    {
        if ((pSectionHeader[i].PointerToRawData + pSectionHeader[i].SizeOfRawData) > size)
            return NULL;
    }
    return pNTHeader->OptionalHeader.SizeOfImage;
}

/* return file ImageSize and Platform in IMAGE_NT_HEADERS struct */
/* the return value is tuple<image_size,platform enum,raw Machine value> */
template<typename T> static inline tuple<uint32_t, parameters_list::platform_info, WORD> getImageInfomation(T&& file)
{
    static_assert(is_string<T>::value, "file is NOT a string");
    HANDLE hFile = CreateFile(file, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING);
    if (hFile == nullptr || hFile == INVALID_HANDLE_VALUE)
        return make_tuple((uint32_t)NULL, parameters_list::PLATFORM_INFO_NOTSET, (WORD)INVALID_HANDLE_VALUE);
    union {
        uint32_t u32;
        uint64_t u64;
        size_t   u;
        LARGE_INTEGER length;
    } size, pos;
    GetFileSizeEx(hFile, &size.length);
    pos.u64 = NULL;
    SetFilePointerEx(hFile, pos.length, nullptr, FILE_BEGIN);
    vector<BYTE> data;
    data.resize(size.u, 0);
    DWORD size_read;
    ReadFile(hFile, data.data(), size.u32, &size_read, nullptr);
    CloseHandle(hFile);
    PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)data.data(); // DOS header
    if (size_read < (pDosHeader->e_lfanew + sizeof(IMAGE_NT_HEADERS)))
        return make_tuple((uint32_t)NULL, parameters_list::PLATFORM_INFO_NOTSET, (WORD)IMAGE_DOS_SIGNATURE);
    PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)(data.data() + pDosHeader->e_lfanew); // NT header
    if (pNTHeader->Signature != IMAGE_NT_SIGNATURE)
        return make_tuple((uint32_t)NULL, parameters_list::PLATFORM_INFO_NOTSET, (WORD)IMAGE_NT_SIGNATURE);
    if (pNTHeader->FileHeader.Machine == IMAGE_FILE_MACHINE_I386)
        return make_tuple(_getImageSize32((PIMAGE_NT_HEADERS32)pNTHeader, size_read), parameters_list::PLATFORM_INFO_32, pNTHeader->FileHeader.Machine);
    else if (pNTHeader->FileHeader.Machine == IMAGE_FILE_MACHINE_IA64 ||
        pNTHeader->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64)
        return make_tuple(_getImageSize64((PIMAGE_NT_HEADERS64)pNTHeader, size_read), parameters_list::PLATFORM_INFO_64, pNTHeader->FileHeader.Machine);
    else
        return make_tuple((uint32_t)NULL, parameters_list::PLATFORM_INFO_NOTSET, pNTHeader->FileHeader.Machine);
}

/* return file ImageSize in IMAGE_NT_HEADERS struct */
template<typename T> static inline uint32_t getImageSize(T&& file)
{
    static_assert(is_string<T>::value, "file is NOT a string");
    return get<0>(getImageInfomation(forward<T>(file)));
}


/* GetFullPathName of string */
template<bool _RemovedIfEmpty = false> struct preprocessing_filename
{
    template<typename _Ty> inline bool operator()(_Ty& in)
    {
        static_assert(!std::is_const<_Ty>::value, "_Ty is a const type");
        if (string_size(in) > 0)
        {
            auto pathb = GetFullPathName(in);
            in = move(pathb.first);
            return !pathb.second;
        }
        else
            return _RemovedIfEmpty;
    }
};

/* GetFullPathName of get<_Index>(tuple<...,string,...>) */
template<size_t _Index, bool _RemovedIfEmpty = false> struct preprocessing_filename_1
{
    template<typename _Ty> inline bool operator()(_Ty& in)
    {
        static_assert(!std::is_const<_Ty>::value, "_Ty is a const type");
        if (string_size(get<_Index>(in)) > 0)
        {
            auto pathb = GetFullPathName(get<_Index>(in));
            get<_Index>(in) = move(pathb.first);
            return !pathb.second;
        }
        else
            return _RemovedIfEmpty;
    }
};

/* GetFullPathName of get<_Index2>(get<_Index1>(tuple<...,tuple<...,string,...>,...>)) */
template<size_t _Index1, size_t _Index2, bool _RemovedIfEmpty = false> struct preprocessing_filename_2
{
    template<typename _Ty> inline bool operator()(_Ty& in)
    {
        static_assert(!std::is_const<_Ty>::value, "_Ty is a const type");
        if (string_size(get<_Index2>(get<_Index1>(in))) > 0)
        {
            auto pathb = GetFullPathName(get<_Index2>(get<_Index1>(in)));
            get<_Index2>(get<_Index1>(in)) = move(pathb.first);
            return !pathb.second;
        }
        else
            return _RemovedIfEmpty;
    }
};


/* return value less than 0: none error and continue; other value: exit with error code */
static inline int format_parameters(int argc, char *const argv[], parameters_list& argl)
{
    argl.reset();

    deque<pair<string, string> > arg;
    for (int i = 1; i < argc; i++)
    {
        string arg_vaule;
        if (argv[i])
            arg_vaule = argv[i];
        arg.push_back(make_pair(move(arg_vaule), string(arg_vaule)));
    }
    if (arg.empty())
        arg.push_back(make_pair("--help", empty_string));
    /* serial number for map<input|output|addrDir> */
    size_t serial_number = 0;
    for (size_t i = 0; i < arg.size(); i++)
    {
        size_t pos;
        if (arg.at(i).first.length() >= 2 && arg.at(i).first.at(0) == '-' && arg.at(i).first.at(1) == '-')
        {
            if (arg.at(i).first.length() == 2)
            {
                if (++i < arg.size() && !arg.at(i).first.empty())
                    argl.input.push_back(make_pair(serial_number++, move(arg.at(i).first))); /* move() becareful! */
                else
                    return stream_printf(stderr, error_format2), 1;
            }
            else if (arg.at(i).first == "--pre") /* -p */
                argl.pre = true;
            else if (arg.at(i).first == "--dump") /* -d */
                argl.dump = true;
            else if (arg.at(i).first == "--output") /* -o */
            {
                if (++i < arg.size() && !arg.at(i).first.empty())
                    argl.output.push_back(make_pair(serial_number++, move(arg.at(i).first))); /* move() becareful! */
                else
                    return stream_printf(stderr, error_format3, arg.at(i - 1).second), 1;
            }
            else if (arg.at(i).first == "--key") /* -k, ignored */
                ++i;
            else if (arg.at(i).first == "--record-line") /* -l */
            {
                if (++i < arg.size() && !arg.at(i).first.empty())
                {
                    if (string::npos == (pos = arg.at(i).first.find_first_of("|,")))
                    {
                        char* next = nullptr;
                        argl.recordline.first = strtoul(arg.at(i).first, next);
                        if (next && *next)
                            return stream_printf(stderr, error_format4, arg.at(i).first, arg.at(i - 1).second), 1;
                        argl.recordline.second = parameters_list::RECORD_LINE_SET;
                    }
                    else
                    {
                        char* next = nullptr;
                        string number_option = arg.at(i).first.substr(0, pos);
                        argl.recordline.first = strtoul(number_option, next);
                        if (next && *next)
                            return stream_printf(stderr, error_format4, number_option, arg.at(i - 1).second), 1;
                        string format_option = string_tolower(arg.at(i).first.substr(pos + 1));
                        if (format_option == "set")
                            argl.recordline.second = parameters_list::RECORD_LINE_SET;
                        else if (format_option == "add")
                            argl.recordline.second = parameters_list::RECORD_LINE_ADD;
                        else if (format_option == "sub")
                            argl.recordline.second = parameters_list::RECORD_LINE_SUB;
                        else
                            return stream_printf(stderr, error_format4, format_option, arg.at(i - 1).second), 1;
                    }
                }
                else
                    return stream_printf(stderr, error_format3, arg.at(i - 1).second), 1;
            }
            else if (arg.at(i).first == "--debugoutput")
            {
                if (++i < arg.size())
                {
                    if (arg.at(i).first.empty() || arg.at(i).first == "null")
                        argl.debugoutput.null_is_set = true;
                    else
                    {
                        arg.at(i).first.push_back(',');
                        while (string::npos != (pos = arg.at(i).first.find_first_of("|,")))
                        {
                            string out_option = arg.at(i).first.substr(0, pos);
                            arg.at(i).first = arg.at(i).first.substr(pos + 1);
                            if (out_option == "cout")
                                argl.debugoutput.pcout = &cout;
                            else if (out_option == "stdout")
                                argl.debugoutput.pstdout = stdout;
                            else if (out_option == "cerr")
                                argl.debugoutput.pcerr = &cerr;
                            else if (out_option == "stderr")
                                argl.debugoutput.pstderr = stderr;
                            else if (out_option == "clog")
                                argl.debugoutput.pclog = &clog;
                            else if (out_option == "sys" || out_option == "system")
                                argl.debugoutput.pcsys = &csys;
                            else
                                return stream_printf(stderr, error_format4, out_option, arg.at(i - 1).second), 1;
                        }
                    }
                }
                else
                    return stream_printf(stderr, error_format3, arg.at(i - 1).second), 1;
            }
            else if (arg.at(i).first == "--file") /* -f */
            {
                if (++i < arg.size() && !arg.at(i).first.empty())
                {
                    if (string::npos == (pos = arg.at(i).first.find_first_of("|,")))
                    {
                        argl.file.push_back(make_pair(serial_number++,
                            make_tuple(move(arg.at(i).first), empty_string,
                            parameters_list::FILE_INFO_NOTSET,
                            parameters_list::PLATFORM_INFO_NOTSET, false))); /* move() becareful! */
                    }
                    else
                    {
                        string file_option = arg.at(i).first.substr(0, pos);
                        if (*file_option.rbegin() == '\\' || *file_option.rbegin() == '/')
                            return stream_printf(stderr, error_format5, arg.at(i - 1).second), 1;
                        string ABI_option = string_tolower(arg.at(i).first.substr(pos + 1));
                        parameters_list::platform_info platform = parameters_list::PLATFORM_INFO_NOTSET;
                        if (ABI_option == "win64" || ABI_option == "x64" || ABI_option == "64")
                            platform = parameters_list::PLATFORM_INFO_64;
                        else if (ABI_option == "win32" || ABI_option == "x86" || ABI_option == "86" || ABI_option == "32")
                            platform = parameters_list::PLATFORM_INFO_32;
                        else
                            return stream_printf(stderr, error_format4, ABI_option, arg.at(i - 1).second), 1;
                        argl.file.push_back(make_pair(serial_number++,
                            make_tuple(move(file_option), empty_string,
                            parameters_list::FILE_INFO_NOTSET,
                            move(platform), false)));
                    }
                }
                else
                    return stream_printf(stderr, error_format3, arg.at(i - 1).second), 1;
            }
            else if (arg.at(i).first == "--ABI") /* -M, ignored */
                ++i;
            else if (arg.at(i).first == "--addrDir") /* -D */
            {
                if (++i < arg.size() && !arg.at(i).first.empty())
                {
                    if (*arg.at(i).first.rbegin() != '\\' && *arg.at(i).first.rbegin() != '/')
                        arg.at(i).first.push_back('\\');
                    argl.addrDir.push_back(make_pair(serial_number++, move(arg.at(i).first))); /* move() becareful! */
                }
                else
                    return stream_printf(stderr, error_format3, arg.at(i - 1).second), 1;
            }
            else if (arg.at(i).first == "--minver")
            {
                if (++i < arg.size() && !arg.at(i).first.empty())
                {
                    char* next = nullptr;
                    argl.workapcae_version = strtoull(arg.at(i).first, next);
                    if ((next && *next) || NULL == argl.workapcae_version)
                        return stream_printf(stderr, error_format4, arg.at(i).first, arg.at(i - 1).second), 1;
                    else if (argl.workapcae_version > current_version)
                        return stream_printf(stderr, warning_format1, argl.workapcae_version, current_version), 255;
                }
                else
                    return stream_printf(stderr, error_format3, arg.at(i - 1).second), 1;
            }
            else if (arg.at(i).first == "--version") /* -v */
            {
                std_printf(
                    INTERAL_NAME " v" FILE_VERSION FILE_VERSION_EXTRA "\n"
                    LEGAL_COPYRIGHT "\n"
                    LICENSE_INFORMATION "\n\n"
                    "Written by Wanpeng Song(swpustc).\n"
                    );
                return 0;
            }
            else if (arg.at(i).first == "--help") /* -h */
            {
                std_printf(
                    "Usage: " INTERAL_NAME " [OPTION]... [FILE]...\n"
                    "Dump the formated BaseAddress and ImageSize of PE files to standard output.\n\n"
                    "  -D, --addrDir[=]PATH   Output the separate BaseAddress information file to PATH directory(s).\n"
                    "                             Used option '-D' since 1.1.3\n"
                    "  -d, --dump             Check and dump ImageSize to BaseAddress table file.\n"
                    "  -f, --file[=]PEFILE[,ABI]\n"
                    "                         Specifies the input PE file(File can be not exist only if the option\n"
                    "                         '--pre' is set).  Set the ABI like Win32, x64, etc.\n"
                    "      --minver[=]VER     Specifies the lowest working version.\n"
                    "  -k, --key[=]KEY        (Ignored)  Read from the input PE file name(s).\n"
                    "                             Unused since version 1.1.1\n"
                    "  -l, --record-line[=]LINE[,<format>]\n"
                    "                         Set the maximum number of lines for record, where <format> can be\n"
                    "                         one of set, add and sub, the default <format> is set.\n"
                    "                             Used this option since version 1.1.7\n"
                    "      --debugoutput[=]<out>[,<out>...]\n"
                    "                         Set debug output.  where <out> can be cout|stdout, cerr|stderr, clog\n"
                    "                         and sys|system, or <out> can be null, for example '--debugoutput=null'\n"
                    "                         if <out> is system, the information will output with OutputDebugString\n"
                    "                         function.  the default debug output is cerr and system.\n"
                    "                             Used this option since version 1.1.8\n"
                    "  -M, --ABI[=]ABI        (Ignored)  ABI should set in option '--file'\n"
                    "                             Unused since version 1.1.2\n"
                    "  -o, --output[=]FILE    Write result on FILE instead of standard output.\n"
                    "  -p, --pre              Check BaseAddress table file for KEY, the input file can be not exist.\n"
                    "                             This option '--pre' is always set since version 1.1.2\n"
                    "  -v, --version          Print version and exit.\n"
                    "                             Used option '-v' since version 1.1.3\n"
                    "  -h, --help             Print usage and this help message and exit.\n\n"
                    "With no input FILE, do not read from any input.  When FILE is -, read standard input.\n"
                    "To open a file whose name starts with a '-', for example '-foo',\n"
                    "use one of these commands :\n"
                    "  " INTERAL_NAME " -- -foo.txt\n"
                    "  " INTERAL_NAME "  ./-foo.txt\n"
                    "  " INTERAL_NAME "  .\\-foo.txt\n\n"
                    "Project " INTERAL_NAME " home page: " HOME_PAGE_URL "\n"
                    "Report bugs to <" EMAIL_ADDRESS ">.\n"
                    );
                return 0;
            }
            else if (string::npos != (pos = arg.at(i).first.find_first_of('=')))
            {
                string parameter_1st = arg.at(i).first.substr(0, pos);
                string parameter_2nd = arg.at(i).first.substr(pos + 1);
                arg.insert(arg.begin() + i + 1, make_pair(move(parameter_2nd), move(arg.at(i).first))); /* move() becareful! */
                arg.insert(arg.begin() + i + 1, make_pair(move(parameter_1st), string(parameter_1st)));
            }
            else
                return stream_printf(stderr, error_format1, arg.at(i).second), 1;
        }
        else if (arg.at(i).first.length() >= 1 && arg.at(i).first.at(0) == '-')
        {
            if (arg.at(i).first.length() == 1)
                argl.input.push_back(make_pair(serial_number++, empty_string));
            else
            {
                deque<pair<string, string> > format_parameter;
                for (size_t pos = 1; pos < arg.at(i).first.length(); pos++)
                {
                    if (arg.at(i).first.at(pos) == '-')
                        return stream_printf(stderr, error_format1, "--"), 1;
                    else if (arg.at(i).first.at(pos) == 'd')
                        format_parameter.push_back(make_pair("--dump", "-d"));
                    else if (arg.at(i).first.at(pos) == 'D')
                    {
                        format_parameter.push_back(make_pair("--addrDir", "-D"));
                        if (pos + 1 < arg.at(i).first.length())
                            format_parameter.push_back(make_pair(arg.at(i).first.substr(pos + 1), move(arg.at(i).first))); /* move() becareful! */
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'f')
                    {
                        format_parameter.push_back(make_pair("--file", "-f"));
                        if (pos + 1 < arg.at(i).first.length())
                            format_parameter.push_back(make_pair(arg.at(i).first.substr(pos + 1), move(arg.at(i).first))); /* move() becareful! */
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'h')
                    {
                        format_parameter.clear();
                        format_parameter.push_back(make_pair("--help", "-h"));
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'k')
                    {
                        format_parameter.push_back(make_pair("--key", "-k"));
                        if (pos + 1 < arg.at(i).first.length())
                            format_parameter.push_back(make_pair(arg.at(i).first.substr(pos + 1), move(arg.at(i).first))); /* move() becareful! */
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'l')
                    {
                        format_parameter.push_back(make_pair("--record-line", "-l"));
                        if (pos + 1 < arg.at(i).first.length())
                            format_parameter.push_back(make_pair(arg.at(i).first.substr(pos + 1), move(arg.at(i).first))); /* move() becareful! */
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'M')
                    {
                        format_parameter.push_back(make_pair("--ABI", "-M"));
                        if (pos + 1 < arg.at(i).first.length())
                            format_parameter.push_back(make_pair(arg.at(i).first.substr(pos + 1), move(arg.at(i).first))); /* move() becareful! */
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'o')
                    {
                        format_parameter.push_back(make_pair("--output", "-o"));
                        if (pos + 1 < arg.at(i).first.length())
                            format_parameter.push_back(make_pair(arg.at(i).first.substr(pos + 1), move(arg.at(i).first))); /* move() becareful! */
                        break;
                    }
                    else if (arg.at(i).first.at(pos) == 'p')
                        format_parameter.push_back(make_pair("--pre", "-p"));
                    else if (arg.at(i).first.at(pos) == 'v')
                    {
                        format_parameter.clear();
                        format_parameter.push_back(make_pair("--version", "-v"));
                        break;
                    }
                    else
                    {
                        string parameter_single;
                        parameter_single.push_back('-');
                        parameter_single.push_back(arg.at(i).first.at(pos));
                        return stream_printf(stderr, error_format1, parameter_single), 1;
                    }
                }
                for_each(format_parameter.rbegin(), format_parameter.rend(), [&](decltype(*format_parameter.rend())& in)
                {
                    arg.insert(arg.begin() + i + 1, move(in)); /* move() becareful! */
                });
            }
        }
        else if (!arg.at(i).first.empty())
        {
            argl.input.push_back(make_pair(serial_number++, move(arg.at(i).first))); /* move() becareful! */
        }
    }

    if (!argl.pre && !argl.dump)
        argl.pre = true;
    else if (argl.pre && argl.dump)
        argl.pre = false;

    if (any_of(argl.file.begin(), argl.file.end(), [](decltype(*argl.file.end())& in)->bool
    {
        size_t pos_key_start = get<0>(in.second).find_last_of("\\/");
        get<1>(in.second) = get<0>(in.second).substr(pos_key_start + 1);
        string _ext;
        size_t pos_key_end = get<1>(in.second).find_last_of('.');
        if (string::npos != pos_key_end)
        {
            _ext = get<1>(in.second).substr(pos_key_end);
            get<1>(in.second) = get<1>(in.second).substr(0, pos_key_end);
        }
        else
            _ext = get<1>(in.second);
        _ext = string_tolower(move(_ext));
        if (get<1>(in.second).empty() || string::npos != get<1>(in.second).find_first_of(";:*?\"<>|, \t"))
            return stream_printf(stderr, error_format4, get<1>(in.second), "file name"), true;
        if (_ext == ".lib")
            get<4>(in.second) = true; /* skip library type, this iterator will be removed later */
        else if (_ext == ".dll")
            get<2>(in.second) = parameters_list::FILE_INFO_DLL;
        else if (_ext == ".exe")
            get<2>(in.second) = parameters_list::FILE_INFO_EXE;
        else
            return stream_printf(stderr, error_format4, _ext, "file type"), true;
        return false;
    }))
        return 1;
    argl.file.erase(remove_if(argl.file.begin(), argl.file.end(), bind(tuple_equal_to_ll<1, 4>(), _1, true)), argl.file.end());

    /* handle debug output object */
    if (argl.debugoutput.null_is_set)
        argl.debugoutput.reset();
    else if (argl.debugoutput.null())
        argl.debugoutput.initialization();

    /* remove duplicate input filename */
    global_argl.input.erase(remove_if(global_argl.input.begin(), global_argl.input.end(), preprocessing_filename_1<1>()), global_argl.input.end());
    reverse(global_argl.input.begin(), global_argl.input.end());
    stable_sort(global_argl.input.begin(), global_argl.input.end(), tuple_less<1>(less_nocase()));
    global_argl.input.erase(unique(global_argl.input.begin(), global_argl.input.end(), tuple_equal_to<1>(equal_to_nocase())), global_argl.input.end());
    sort(global_argl.input.begin(), global_argl.input.end(), tuple_less<0>());

    /* remove duplicate and empty output filename */
    global_argl.output.erase(remove_if(global_argl.output.begin(), global_argl.output.end(), preprocessing_filename_1<1, true>()), global_argl.output.end());
    reverse(global_argl.output.begin(), global_argl.output.end());
    stable_sort(global_argl.output.begin(), global_argl.output.end(), tuple_less<1>(less_nocase()));
    global_argl.output.erase(unique(global_argl.output.begin(), global_argl.output.end(), tuple_equal_to<1>(equal_to_nocase())), global_argl.output.end());
    sort(global_argl.output.begin(), global_argl.output.end(), tuple_less<0>());
    /* empty string for standard output */
    if (global_argl.output.empty())
        global_argl.output.push_back(make_pair(0, empty_string));

    /* remove duplicate and empty addrDir filename */
    global_argl.addrDir.erase(remove_if(global_argl.addrDir.begin(), global_argl.addrDir.end(), preprocessing_filename_1<1, true>()), global_argl.addrDir.end());
    reverse(global_argl.addrDir.begin(), global_argl.addrDir.end());
    stable_sort(global_argl.addrDir.begin(), global_argl.addrDir.end(), tuple_less<1>(less_nocase()));
    global_argl.addrDir.erase(unique(global_argl.addrDir.begin(), global_argl.addrDir.end(), tuple_equal_to<1>(equal_to_nocase())), global_argl.addrDir.end());
    sort(global_argl.addrDir.begin(), global_argl.addrDir.end(), tuple_less<0>());

    /* remove duplicate and empty PE filename */
    global_argl.file.erase(remove_if(global_argl.file.begin(), global_argl.file.end(), preprocessing_filename_2<1, 0, true>()), global_argl.file.end());
    reverse(global_argl.file.begin(), global_argl.file.end());
    stable_sort(global_argl.file.begin(), global_argl.file.end(), tuple_less<1, 0>(less_nocase()));
    global_argl.file.erase(unique(global_argl.file.begin(), global_argl.file.end(), tuple_equal_to<1, 0>(equal_to_nocase())), global_argl.file.end());
    sort(global_argl.file.begin(), global_argl.file.end(), tuple_less<0>());

    return -1;
}


/* read records and values from istream */
static inline void read_value_from_file(istream& fin, deque<string>& record, deque<_value>& value, uint32_t& record_info_buffer_line)
{
    bool record_regional = false;
    string str;
    while (getline(fin, str))
    {
        string comment;
        size_t pos_record = string::npos;
        if (string::npos == (pos_record = str.find_first_not_of(" \t\r\n")))
            ; /* output empty line */
        else if (';' != str.at(pos_record))
            ; /* continue to work */
        /* add record line to deque<record> here */
        else if (string::npos != (pos_record = str.find(edit_record_head)))
        {
            record_info_buffer_line += strtoul(str.substr(pos_record + edit_record_head.length()));
            if (record_info_buffer_line > edit_record_info_buffer_line_max)
                record_info_buffer_line = edit_record_info_buffer_line_max;
            continue;
        }
        else if (string::npos != (pos_record = str.find(edit_record_title_old1)))
        {
            if (!record_regional)
            {
                record_regional = true;
                continue;
            }
        }
        else if (string::npos != (pos_record = str.find(edit_record_title)))
        {
            if (!record_regional)
            {
                record_regional = true;
                continue;
            }
        }
        else if (string::npos != (pos_record = str.find(edit_record_info_old2)))
        {
            if (record_regional)
            {
                str.replace(pos_record, edit_record_info_old2.length(), edit_record_info);
                record.push_back(move(str)); /* move() becareful! */
                continue;
            }
        }
        else if (string::npos != (pos_record = str.find(edit_record_info_old1)))
        {
            if (record_regional)
            {
                str.replace(pos_record, edit_record_info_old1.length(), edit_record_info);
                record.push_back(move(str)); /* move() becareful! */
                continue;
            }
        }
        else if (string::npos != (pos_record = str.find(edit_record_info)))
        {
            if (record_regional)
            {
                record.push_back(move(str)); /* move() becareful! */
                continue;
            }
        }
        else if (string::npos != (pos_record = str.find(edit_record_end)))
        {
            if (record_regional)
            {
                record_regional = false;
                continue;
            }
        }
        else if (string::npos != (pos_record = str.find(edit_record_sample)))
        {
            if (record_regional)
                continue;
        }

        str.push_back('\n');
        size_t pos_comment_start = str.find_first_of(';');
        size_t pos_comment_end__ = str.find_first_of("\r\n", pos_comment_start);
        if (pos_comment_start != string::npos)
        {
            comment = str.substr(pos_comment_start, pos_comment_end__ - pos_comment_start);
            str = str.substr(0, pos_comment_start);
        }
        size_t pos_key_start = str.find_first_not_of(" \t\r\n");
        size_t pos_key_end__ = str.find_first_of(" \t\r\n", pos_key_start);
        size_t pos_base_start = str.find_first_not_of(" \t\r\n", pos_key_end__);
        size_t pos_base_end__ = str.find_first_of(" \t\r\n", pos_base_start);
        size_t pos_size_start = str.find_first_not_of(" \t\r\n", pos_base_end__);
        size_t pos_size_end__ = str.find_first_of(" \t\r\n", pos_size_start);

        _value value_struct;
        string _value_base, _value_size;
        uint32_t _size;

        pos_key_start == string::npos ? value_struct.value_key = empty_string :
            value_struct.value_key = str.substr(pos_key_start, pos_key_end__ - pos_key_start);
        pos_base_start == string::npos ? _value_base = empty_string :
            _value_base = str.substr(pos_base_start, pos_base_end__ - pos_base_start);
        value_struct.value_base = strtoull(_value_base);
        if (!value_struct.value_base)
            value_struct.value_base = strtoull(_value_base, nullptr, 16);
        pos_size_start == string::npos ? _value_size = empty_string :
            _value_size = str.substr(pos_size_start, pos_size_end__ - pos_size_start);
        value_struct.value_size = strtoul(_value_size);
        if (!value_struct.value_size)
            value_struct.value_size = strtoul(_value_size, nullptr, 16);
        value_struct.value_comment = move(comment); /* move() becareful! */

        /* make sure the first char in value_key is not ';' */
        if (!value_struct.value_key.empty() && *value_struct.value_key.begin() == ';')
        {
            value_struct.value_key.clear();
            value_struct.value_base = NULL;
            value_struct.value_size = NULL;
            value_struct.value_comment = move(str); /* move() becareful! */
        }

        if (!value_struct.value_size)
            value_struct.value_size = size_default;
        _size = (value_struct.value_size + page_alignment_size - 1) / page_alignment_size * page_alignment_size;
        value_struct.value_size = _size;

        /* set INCREASED_RESET for first record */
        if (value.empty() && !value_struct.value_key.empty())
        {
            if (value_struct.value_comment.find(comment_increased_reset) == string::npos)
                value_struct.increased_base = _value::INCREASED_RESET;
        }
        if (!value_struct.value_key.empty())
        {
            /* read increased comment information */
            if (string::npos != (pos_record = value_struct.value_comment.find(comment_increased_reset)))
                value_struct.increased_base = _value::INCREASED_RESET;
            if (string::npos != (pos_record = value_struct.value_comment.find(comment_increased_by_alignment)))
            {
                value_struct.increased_base = _value::INCREASED_BY_ALIGNMENT;
                string alignment_str = value_struct.value_comment.substr(pos_record + comment_increased_by_alignment.length());
                uint32_t increased_alignment = strtoul(alignment_str);
                if (!increased_alignment)
                    increased_alignment = strtoul(alignment_str, nullptr, 16);
                value_struct.increased_alignment = (increased_alignment + image_alignment_size - 1) / image_alignment_size * image_alignment_size;
                if (value_struct.increased_alignment <= image_alignment_size)
                    value_struct.increased_base = _value::INCREASED_NONE;
            }
            /* remove duplicate records */
            auto it = find_if(value.begin(), value.end(), [&](const decltype(*value.end())& in)->bool
            {
                return equal_to_nocase()(in.value_key, value_struct.value_key);
            });
            if (it != value.end())
                continue;
        }
        value.push_back(move(value_struct)); /* move() becareful! */
    }
    /* remove empty line at last */
    while (!value.empty())
    {
        auto empty_line_reverse_iter = value.rbegin();
        if (empty_line_reverse_iter->value_key.empty() && empty_line_reverse_iter->gen_comment().empty())
            value.erase(empty_line_reverse_iter.base() - 1);
        else
            break;
    }
}


/* handle ctrl+C */
static BOOL WINAPI CtrlHandle(DWORD CtrlType)
{
    static BOOL ignoreEvent = FALSE;
    if (CtrlType == CTRL_C_EVENT || CtrlType == CTRL_BREAK_EVENT)
    {   /* will ignore the last line */
        cin.seekg(0, ios::end);
        return ignoreEvent == FALSE ? ignoreEvent = TRUE : FALSE;
    }
    else
        return FALSE;
}
