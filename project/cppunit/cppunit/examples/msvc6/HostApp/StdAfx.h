// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A9C94DE9_1663_11D2_A499_00805FC1C042__INCLUDED_)
#define AFX_STDAFX_H__A9C94DE9_1663_11D2_A499_00805FC1C042__INCLUDED_

#pragma once

#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT  _WIN32_WINNT_WINXP  // Support Windows XP and later
#define _WIN32_IE     _WIN32_IE_IE70      // Support IE 7.0 and later
#include <SDKDDKVer.h>

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>         // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#pragma warning( disable : 4786 )

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9C94DE9_1663_11D2_A499_00805FC1C042__INCLUDED_)
