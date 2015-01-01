#include <stdlib.h>
#include <windows.h>

#include "RemoteMemLoadDll.h"
#include "RMLDUnknown.h"
#include "RMLDNormal.h"

REMOTEMEMLOADDLL_API IRemoteMemLoadDll* WINAPI CreateRemoteMemLoadDll(DWORD Flags)
{
    if( Flags &
        ~(RMLD_NORMAL | RMLD_WITHOUT_DLLMAIN | RMLD_IGNORE_SHARED_PROTECT | RMLD_RANDOM_BASE_ADDRESS) )
        return NULL;
    else
        return new CRMLDNormal(Flags);
}

#include <InitGuid.h>
// {63100DEF-6FB5-4A65-83A8-23BA876B2F35}
DEFINE_GUID(IID_IRemoteMemLoadDll, 
0x63100def, 0x6fb5, 0x4a65, 0x83, 0xa8, 0x23, 0xba, 0x87, 0x6b, 0x2f, 0x35);
