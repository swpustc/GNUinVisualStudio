#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#include <Windows.h> // HANDLE, CreateMutex, CloseHandle ...
#include <cassert> // assert
#if _MSC_VER >= 1700
#include <mutex> // std::mutex
#endif

struct spin_lock
{
    bool block;
    spin_lock(){ block = false; }
    void lock(){ while (block); block = true; }
    void unlock(){ assert(block); block = false; }
};

#if _MSC_VER >= 1700
struct mutex_lock
{
    std::mutex mlock;
    void lock(){ mlock.lock(); }
    void unlock(){ mlock.unlock(); }
};
#else
struct mutex_lock
{
    HANDLE hmutex;
    mutex_lock(){ hmutex = CreateMutex(NULL, FALSE, NULL); }
    ~mutex_lock(){ CloseHandle(hmutex); }
    void lock(){ WaitForSingleObject(hmutex, INFINITE); }
    void unlock(){ ReleaseMutex(hmutex); }
};
#endif

template<class _Mutex> class lock_guard
{
private:
    _Mutex& _MyMutex;
public:
    lock_guard(_Mutex& _Mtx) : _MyMutex(_Mtx){ _MyMutex.lock(); }
    ~lock_guard(){ _MyMutex.unlock(); }
};
