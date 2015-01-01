/*  Before using this project, You must import gnu_vcxx.props to your project first,
  and set $(GNUDir) to the directories.
    See gnu_vcxx.props.

    You must add $(GNUExecutablePath) to $(ExecutablePath), add $(GNUIncludePath) to
  $(IncludePath), add $(GNULibraryPath) to $(LibraryPath), add $(GNUSourcePath) to
  $(SourcePath), and add $(GNUincludeDir);$(GNUincludeDir).local\;$(GNUinclude_etcDir) to
  $(AdditionalIncludeDirectories).

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
      <AdditionalIncludeDirectories>$(GNUincludeDir);$(GNUincludeDir).local\;
        $(GNUinclude_etcDir);%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>
    </ClCompile>
  </ItemDefinitionGroup>

    If you want to use LOCAL projects as DLLs, define USING_LOCAL_DLL, or you can defined
  USING_ALL_DLL to use GNU and LOCAL projects as DLLs.
    If you want to use all LOCAL projects in ONE DLL, please set $(GNUBuildOneDLL) to true
  in gnu_vcxx.props file, and rebuild all LOCAL projects.
*/

#ifndef _RMLD_LINK_LIB_H_
#define _RMLD_LINK_LIB_H_

#ifdef __GNU_PROJECT_NAME__
#  undef __GNU_PROJECT_NAME__
#endif
#define __GNU_PROJECT_NAME__        librmld


#if defined(USING_LOCAL_DLL) || defined(USING_ALL_DLL) || defined(USING_rmld_DLL)
#  include "_linkdynamic"
#else
#  include "_linkstatic"
#endif


#undef __GNU_PROJECT_NAME__

#endif /* _RMLD_LINK_LIB_H_ */
