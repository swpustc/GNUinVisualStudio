#include <vector> // std::vector
#include <map> // std::map
#include <set> // std::set
#include <algorithm> // std::find, std::find_if
#include "auto_lock.h" // spin_lock, mutex_lock, lock_guard
#include "hook_inline.h" // CWINAPI_INLINE_HOOK
#include "hook_iat.h" // CWINAPI_IAT_HOOK
#include "hook_memory_manager.h" // FARPROC, BOOL

using std::map;
using std::set;
using std::pair;
using std::vector;
using std::make_pair;
using std::find;
using std::find_if;

template<typename OBJECT_TYPE>
struct std::less < pair<FARPROC, OBJECT_TYPE*> >
{
    typedef pair<FARPROC, OBJECT_TYPE*> PAIR_TYPE;
    bool operator ()(const PAIR_TYPE& l, const PAIR_TYPE& r)
    {
        return l.first < r.first;
    }
};
map<pair<FARPROC, CWINAPI_INLINE_HOOK*>, vector<FARPROC> > g_inline;
set<pair<FARPROC, CWINAPI_IAT_HOOK*> > g_iat;

spin_lock mtx_inline;
spin_lock mtx_iat;


BOOL InlineHookOn(FARPROC relPoint, FARPROC hookPoint, CWINAPI_INLINE_HOOK* pObject/*=NULL*/)
{
    if (!pObject)
        return FALSE;
    lock_guard<decltype(mtx_inline)> lck(mtx_inline);
    auto ins = g_inline.insert(make_pair(make_pair(relPoint, pObject), vector<FARPROC>()));
    if (ins.second)
    {
        ins.first->second.push_back(hookPoint);
        return TRUE;
    }
    else
    {
        auto iter = find(ins.first->second.begin(), ins.first->second.end(), hookPoint);
        if (iter == ins.first->second.end())
        {
            ins.first->second.push_back(hookPoint);
            return TRUE;
        }
        else
            return FALSE;
    }
}

BOOL InlineHookOff(FARPROC relPoint, FARPROC hookPoint)
{
    lock_guard<decltype(mtx_inline)> lck(mtx_inline);
    auto iter1 = find_if(g_inline.begin(), g_inline.end(), [&](const decltype(*g_inline.end())& in)->bool{return in.first.first == relPoint; });
    if (iter1 == g_inline.end())
        return FALSE;
    else
    {
        auto iter2 = find(iter1->second.begin(), iter1->second.end(), hookPoint);
        if (iter2 == iter1->second.end())
            return FALSE;
        else
        {
            iter1->second.erase(iter2, iter1->second.end());
            return TRUE;
        }
    }
}


BOOL IatHookOn(FARPROC relPoint, CWINAPI_IAT_HOOK* pObject/*=NULL*/)
{
    if (!pObject)
        return FALSE;
    lock_guard<decltype(mtx_iat)> lck(mtx_iat);
    auto ins = g_iat.insert(make_pair(relPoint, pObject));
    return TRUE;
}

BOOL IatHookOff(FARPROC relPoint)
{
    lock_guard<decltype(mtx_iat)> lck(mtx_iat);
    auto iter = find_if(g_iat.begin(), g_iat.end(), [&](const decltype(*g_iat.end())& in)->bool{return in.first == relPoint; });
    if (iter == g_iat.end())
        return FALSE;
    else
    {
        g_iat.erase(iter);
        return TRUE;
    }
}
