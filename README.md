# GNUinVisualStudio
This is GNU projects for Microsoft (R) Visual Studio (R) 2010, 2012 and 2013.

Make by Song Wanpeng ([swpustc](https://swpustc.wicp.net/ "swpustc Homepage")),<swpustc@mail.ustc.edu.cn>.

University of Science and Technology of China,
No.96, JinZhai Road, Baohe District, Hefei, Anhui, 230026, P.R.China.
2014/08/04

## Git Repository
The Default Git Repository is **USTC** Repository.
- [USTC](https://git.ustclug.org/swp/gnuinvisualstudio "USTC Default")
- [GitHub](https://github.com/swpustc/GNUinVisualStudio "GitHub")
- [Local](https://git-swp.wicp.net/swp/gnuinvisualstudio "Local Preview")

## GNU Source
### Now this project include the following packages
- zlib ver.1.2.8
  - [Homepage](http://www.zlib.net/)
- libsigc++ ver.2.4.0
  - [Sourcecode](https://git.gnome.org/browse/libsigc++2/)
[Download](https://mirrors.ustc.edu.cn/gnome/sources/libsigc++/)
- libpng ver.1.6.16
  - [Homepage](http://www.libpng.org/pub/png/libpng.html)
[Sourcecode](http://sourceforge.net/p/libpng/code/ci/master/tree/)
- libiconv ver.1.14
  - [Homepage](https://www.gnu.org/software/libiconv/)
[Download](https://mirrors.ustc.edu.cn/gnu/libiconv/)
- libcppunit ver.(master606)
  - [Download](http://sourceforge.net/p/cppunit/code/)
- libxmlrpc-c ver.1.39.00(master2640)
  - [Homepage](http://xmlrpc.scripting.com/default.html)
[Sourcecode](http://sourceforge.net/p/xmlrpc-c/code/)
- libgmp ver.6.0.0a
  - [Homepage](https://gmplib.org/)
[Download](https://mirrors.ustc.edu.cn/gnu/gmp/)
- libcrypto++ ver.5.6.2
  - [Homepage](http://www.cryptopp.com/)
[Download](http://www.cryptopp.com/#download)
- Blitz++ ver.0.10
  - [Download](http://sourceforge.net/projects/blitz/)


- dumpImageSize ver.1.1.9
  - [Sourcecode](project/.dumpImageSize)
- libhook ver.0.0.1(NOT released)
  - [Sourcecode](project/.hook)
- librmld ver.1.0.2
  - [Sourcecode](project/.rmld)


## Setup
### First
- You should run install.bat to write **GNUDir** in system environment
variables.
- When you add **GNUDir** to your environmental variables, you maybe
need to **REBOOT** your computer otherwise this value maybe unavailabled
in Visual Studio and Command Line.
- Finally, you should import the right version attribute table file
gnu_vcxx.props to your project (.vcxproj file) like this:

```
<Import Project="$(GNUDir)gnu_vcxx.props" />
```
- **$(GNUDir)gnu_vcxx.prop** is the global setting and important.

### Second
- You should import etc\vcxx\global\env.props to your project .vcxproj
file.  You should do like this:

```
<Import Project="$(GNUetcglobalDir)env.props" />
```
- **$(GNUetcglobalDir)env.props** is the environment setting for
GNU project.  When you import this props, you can use **#include**
**\<zlib.h\>** in your code to include GNU project.
- This statement must be after:

```
<PropertyGroup Label="UserMacros" />
```

## Build options
- **GNUBuildOneDLL**: true or false
  - Generation all GNU and local in one dll.  If you want to use all
GNU or LOCAL projects in ONE DLL, please set **$(GNUBuildOneDLL)** to
true in gnu_vcxx.props file, and rebuild all GNU and LOCAL projects.
- **GNUGenerateBrowseInformation**: true or false
  - When you build this project, it will output .bsc files in **bsc**
directory or the path you set in gnu_vcxx.props.
- **GNUGenerateDebugInformation**: true or false
  - When you build this project, it will output .pdb and .idb files
in **pdb** directory or the path you set in gnu_vcxx.props.
- **GNUGeneratePublicSymbolDebugInformation**: true or false
  - When you build this project, it will generation another public
symbol debug information files in **pdb_pub** directory or the path
you set in gnu_vcxx.props.
- **GNUGenerateMapFile**: true or false
  - When you build this project, it will output .map files in **map**
directory or the path you set in gnu_vcxx.props.
- **GNUHardLinkInsteadofCopyExe**:
- **GNUHardLinkInsteadofCopyDll**:
- **GNUHardLinkInsteadofCopyLib**: true or false
  - When you build this project, it will make a hardlink of these
generation files to **bin**, **dll** and **lib** directory or the
path you set in gnu_vcxx.props.
- **etc/vcxx/addressTable.txt**: BaseAddress setting file
  - When you build this project, this file will generation.  Now
you can edit it and rebuild the projects to overriding the default
location for an exe or dll file.  For more information, see
http://msdn.microsoft.com/en-us/library/f7f5138s.aspx

**Note:** If you change the default path setting in gnu_vcxx.props,
be careful to modify these values in batch files.

## Link options
- Macro USING_GNU_DLL and USING_ALL_DLL
  - If you want to use GNU projects as DLLs, defined USING_GNU_DLL,
or you can defined USING_ALL_DLL to use GNU and LOCAL projects as
DLLs.
  - For more information, see include/linkxx.h.

## BaseAddress Setting
- When you build this project, it will generation a BaseAddress text
file for dll or exe files which is etc/vcxx/addressTable.txt.  When
you build this projects again, this project will fix the BaseAddress
with the right settings.
- **;Increased base For BaseAddress**
  - You can add this comment(it will always set at the first line in
the file etc/vcxx/addressTable.txt) for one program which you want to
keep it's BaseAddress unchanged.
- **;Increased base By Alignment(*size*)**
  - Or you can add this comment for one program which you want to
automatic increase by send alignment size.
- Otherwise, the linker will automatic increase ImageSize according
to last record.
