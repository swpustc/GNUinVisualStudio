/*  Before using this project, You must import gnu_vcxx.props to your project first,
  and set $(GNUDir) to the directories.
    See gnu_vcxx.props.

    You must add $(GNUExecutablePath) to $(ExecutablePath), add $(GNUIncludePath) to
  $(IncludePath), add $(GNULibraryPath) to $(LibraryPath), add $(GNUSourcePath) to
  $(SourcePath), and add $(GNUincludeDir);$(GNUinclude_etcDir) to $(AdditionalIncludeDirectories).

    You can add the following configuration to vcxproj file or import $(GNUetcglobalDir)env.props
  to your vcxproj file after <PropertyGroup Label="UserMacros" />.

  <PropertyGroup>
    <ExecutablePath>$(GNUExecutablePath);$(ExecutablePath)</ExecutablePath>
    <IncludePath>$(GNUIncludePath);$(IncludePath)</IncludePath>
    <LibraryPath>$(GNULibraryPath);$(LibraryPath)</LibraryPath>
    <SourcePath>$(GNUSourcePath);$(SourcePath)</SourcePath>
  </PropertyGroup>
  <ItemDefinitionGroup>
    <ClCompile>
      <AdditionalIncludeDirectories>$(GNUincludeDir);$(GNUinclude_etcDir);
        %(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
    </ClCompile>
  </ItemDefinitionGroup>

    If you want to use GNU projects as DLLs, defined USING_GNU_DLL, or you can defined
  USING_ALL_DLL to use GNU and LOCAL projects as DLLs.
    If you want to use all GNU projects in ONE DLL, please set $(GNUBuildOneDLL) to true
  in gnu_vcxx.props file, and rebuild all GNU projects.
*/

#ifndef _XMLRPC_SERVER_ABYSS_LINK_LIB_H_
#define _XMLRPC_SERVER_ABYSS_LINK_LIB_H_

#ifdef __GNU_PROJECT_NAME__
#  undef __GNU_PROJECT_NAME__
#endif
#define __GNU_PROJECT_NAME__        libxmlrpc_server_abyss


#if defined(USING_GNU_DLL) || defined(USING_ALL_DLL) || defined(USING_xmlrpc_server_abyss_DLL)
#  include "_linkdynamic"
#else
#  include "_linkstatic"
#  include "linkxmlrpc_util.h"
#  include "linkxmlrpc.h"
#  include "linkxmlrpc_abyss.h"
#  include "linkxmlrpc_server.h"
#endif


#undef __GNU_PROJECT_NAME__

#endif /* _XMLRPC_SERVER_ABYSS_LINK_LIB_H_ */
