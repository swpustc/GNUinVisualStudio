#ifndef s11n_CONFIG_HPP_INCLUDED
#define s11n_CONFIG_HPP_INCLUDED 1
// Template file for s11n_config.hpp - project-wide defines.  Make
// your changes in s11n_config.hpp.at, not in s11n_config.hpp, as the
// configure script will use s11n_config.hpp.at to create
// s11n_config.hpp.

////////////////////////////////////////////////////////////////////////
// Code which wants to check for s11n's inclusion should check
// for:
#define s11n_S11N_INCLUDED 1
// This does not mean that ALL components are loaded, only that
// some part of it has been. Classes may use this to conditionally
// include their s11n registrations.
// As of version 1.0.2, a more configurable approach is to check
// against s11n_S11N_LIBRARY_VERSION_HEX, which contains the
// version number encoded as a hex int. e.g., 1.0.8 == 0x010008
////////////////////////////////////////////////////////////////////////


#define S11N_VERSION_MAJOR  1
#define S11N_VERSION_MINOR  3
#define S11N_VERSION_POINT  1
#define S11N_VERSION_POINT2 0

#define s11n_S11N_PACKAGE_NAME "s11n"
#define s11n_S11N_LIBRARY_VERSION "1.3.1"
#define s11n_S11N_LIBRARY_VERSION_HEX (0x010301)
#define s11n_PACKAGE_RELEASE_CODENAME "Approved by Me"
#define s11n_PACKAGE_LICENSE "Public Domain"
#define s11n_PACKAGE_URL "http://s11n.net/"
#define s11n_PACKAGE_EMAIL_ADDRESS "s11n-devel@lists.sourceforge.net"
#define s11n_S11NLITE_DEFAULT_SERIALIZER_TYPE_NAME std::string("s11n::io::funtxt_serializer")

/* Shared paths for s11n and clients. */
#if defined(WIN32)
#  define s11n_CONFIG_SHARED_DIR std::string("s11n.net\\shared")
#  define s11n_CONFIG_LIB_DIR std::string("s11n.net\\lib")
#else
#  define s11n_CONFIG_SHARED_DIR std::string("/home/stephan/share/s11n")
#  define s11n_CONFIG_LIB_DIR std::string("/home/stephan/lib/s11n")
#endif


////////////////////////////////////////////////////////////////////////
// Optional components...
#if defined(WIN32)
 /* have libexpat XML parser? */
#  define s11n_CONFIG_HAVE_LIBEXPAT (0)
 /* have libzfstream? */
#  define s11n_CONFIG_HAVE_ZFSTREAM (0)
/* have pthreads? */
#  define s11n_CONFIG_HAVE_PTHREADS (0)
/* have GNU Pth threads? */
#  define s11n_CONFIG_HAVE_GNUPTH_THREADS (0)
/* have win32 threads? */
#  define s11n_CONFIG_HAVE_WIN32_THREADS (1)
 /* Enable s11n::plugin module? */
#  define s11n_CONFIG_ENABLE_PLUGINS (1)
 /* Enable s11n::io::pstreams addon? */
#  define s11n_CONFIG_ADDON_PSTREAMS_ENABLE (0)
#else
#  define s11n_CONFIG_HAVE_LIBEXPAT (1)
#  define s11n_CONFIG_HAVE_ZFSTREAM (0)
#  define s11n_CONFIG_HAVE_WIN32_THREADS (0)
#  define s11n_CONFIG_HAVE_GNUPTH_THREADS (0)
#  define s11n_CONFIG_HAVE_PTHREADS (0)
#  define s11n_CONFIG_ENABLE_PLUGINS (1)
#  define s11n_CONFIG_ADDON_PSTREAMS_ENABLE (1)
#endif


////////////////////////////////////////////////////////////////////////
// s11n_CONFIG_PURE_ISO is a flag which tells us to turn of
// features which are not ISO-standard C++, like support
// for any external libraries. Set it to 0 or 1
#define s11n_CONFIG_PURE_ISO 1
#if s11n_CONFIG_PURE_ISO
#  undef s11n_CONFIG_HAVE_LIBEXPAT
#  define s11n_CONFIG_HAVE_LIBEXPAT 0
#  undef s11n_CONFIG_HAVE_ZFSTREAM
#  define s11n_CONFIG_HAVE_ZFSTREAM 0
#  undef s11n_CONFIG_HAVE_WIN32_THREADS
#  define s11n_CONFIG_HAVE_WIN32_THREADS 0
#  undef s11n_CONFIG_HAVE_PTHREADS
#  define s11n_CONFIG_HAVE_PTHREADS 0
#  undef s11n_CONFIG_HAVE_GNUPTH_THREADS
#  define s11n_CONFIG_HAVE_GNUPTH_THREADS 0
#  undef s11n_CONFIG_ENABLE_PLUGINS
#  define s11n_CONFIG_ENABLE_PLUGINS 0
#  define s11n_CONFIG_SINGLE_THREADED 1
#endif // s11n_CONFIG_PURE_ISO


#if s11n_CONFIG_HAVE_PTHREADS || s11n_CONFIG_HAVE_GNUPTH_THREADS || defined(WIN32)
#  undef s11n_CONFIG_SINGLE_THREADED
#  define s11n_CONFIG_SINGLE_THREADED 0
#endif

#if !defined(s11n_CONFIG_SINGLE_THREADED)
#    define s11n_CONFIG_SINGLE_THREADED 1
#endif

#define s11n_CONFIG_HAVE_CPP0X 0

#endif // s11n_CONFIG_HPP_INCLUDED
