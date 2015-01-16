## GNUinVisualStudio
This is GNU projects for Microsoft (R) Visual Studio (R) 2010, 2012 and 2013.

Make by Song Wanpeng ([swpustc](https://swpustc.wicp.net/ "swpustc Homepage")),<swpustc@mail.ustc.edu.cn>.

University of Science and Technology of China,
No.96, JinZhai Road, Baohe District, Hefei, Anhui, 230026, P.R.China.
2014/08/04


### Git Repository
The Default Git Repository is **USTC** Repository.

- [USTC](https://git.ustclug.org/swp/gnuinvisualstudio "USTC Default")
- [GitHub](https://github.com/swpustc/GNUinVisualStudio "GitHub")
- [Local](https://git-swp.wicp.net/swp/gnuinvisualstudio "Local Preview")


### GNU Source
#### Now this project include the following packages
1. zlib **`1.2.8`**
  [Homepage](http://www.zlib.net/)
1. libsigc++ **`2.4.0`**
  [Sourcecode](https://git.gnome.org/browse/libsigc++2/)
  [Download](https://mirrors.ustc.edu.cn/gnome/sources/libsigc++/)
1. libpng **`1.6.16`**
  [Homepage](http://www.libpng.org/pub/png/libpng.html)
  [Sourcecode](http://sourceforge.net/p/libpng/code/ci/master/tree/)
1. libiconv **`1.14`**
  [Homepage](https://www.gnu.org/software/libiconv/)
  [Download](https://mirrors.ustc.edu.cn/gnu/libiconv/)
1. libxml2 **`2.9.2`**
  [Homepage](http://xmlsoft.org/)
  [Sourcecode](https://git.gnome.org/browse/libxml2/)
  [FTP](ftp://xmlsoft.org/libxml2/)(ftp://xmlsoft.org/libxml2/)
1. libxslt **`1.1.28`**
  [Homepage](http://xmlsoft.org/XSLT.html)
  [Sourcecode](https://git.gnome.org/browse/libxslt/)
  [FTP](ftp://xmlsoft.org/libxslt/)(ftp://xmlsoft.org/libxslt/)
1. libcppunit **`(master606)`**
  [Download](http://sourceforge.net/p/cppunit/code/)
1. libxmlrpc-c **`1.39.00(master2640)`**
  [Homepage](http://xmlrpc.scripting.com/default.html)
  [Sourcecode](http://sourceforge.net/p/xmlrpc-c/code/)
1. libgmp **`6.0.0a`**
  [Homepage](https://gmplib.org/)
  [Download](https://mirrors.ustc.edu.cn/gnu/gmp/)
1. libcrypto++ **`5.6.2`**
  [Homepage](http://www.cryptopp.com/)
  [Download](http://www.cryptopp.com/#download)
1. Blitz++ **`0.10`**
  [Download](http://sourceforge.net/projects/blitz/)
1. Xerces-C++ **`3.1.1`**
  [Homepage](http://xerces.apache.org/xerces-c/)
  [Download](http://xerces.apache.org/xerces-c/download.cgi)
1. s11n **`1.3.1`**
  [Homepage](http://s11n.net/)
  [Download](http://s11n.net/download/#s11n)


#### These is local projects below
1. dumpImageSize **`1.1.9`**
  [Sourcecode](project/.dumpImageSize)
1. libhook **`0.0.1(NOT released)`**
  [Sourcecode](project/.hook)
1. librmld **`1.0.2`**
  [Sourcecode](project/.rmld)


### Install and Build
1. Run `install.bat` to write **GNUDir** in system environment
  variables.</br>
  ```
  cmd '/c ' install.bat [cur|all]
  ```

  When you add **GNUDir** to your environmental variables, you maybe
  need to *REBOOT* your computer otherwise this value maybe unavailabled
  in VisualStudio and Command Line.

1. Run `build.bat` script.</br>
  ```
  cmd '/c ' build.bat [vc10|vc10.0|2010|vs2010] [vc11|vc11.0|2012|vs2012] [vc12|vc12.0|2013|vs2013] [all|c[r|m]t[r|d][d|l][32|64]] [sign|signture]
  ```

  Sample: ```cmd '/c ' build.bat vc12 crtd(debug)l(static library)32(platform)```

1. Import attribute table file [[vs2010](gnu_vc10.props)|[vs2012](gnu_vc11.props)|
  [vs2013](gnu_vc12.props)] to your project (.vcxproj file) like this:</br>
  ```
  <Import Project="$(GNUDir)gnu_vc10.props" />
  ```

  File `gnu_vc10.prop` is the global setting file.

1. Import env file [[vs2010](etc/vc10/global/env.props)|[vs2012](etc/vc11/global/env.props)|
  [vs2013](etc/vc12/global/env.props)] to your project .vcxproj
  file.  You should do like this:</br>
  ```
  <Import Project="$(GNUetcglobalDir)env.props" />
  ```

  File `env.props` is the environment setting for GNU projects.  When you
  import this props, you can use `#include <zlib.h>` in your code to
  include GNU project.</br>
  This statement must be after:</br>
  ```
  <PropertyGroup Label="UserMacros" />
  ```


### Build options

1. **GNUBuildOneDLL**: *true* or *false*</br>
  Generation all GNU and local in one dll.  If you want to use all
  GNU or LOCAL projects in ONE DLL, please set $(**GNUBuildOneDLL**) to
  true in `gnu_vcxx.props` file, and rebuild all GNU and LOCAL projects.

1. **GNUGenerateBrowseInformation**: *true* or *false*</br>
  When you build this project, it will output .bsc files in `bsc`
  directory or the path you set in `gnu_vcxx.props`.

1. **GNUGenerateDebugInformation**: *true* or *false*</br>
  When you build this project, it will output .pdb and .idb files
  in **pdb** directory or the path you set in gnu_vcxx.props.

1. **GNUGeneratePublicSymbolDebugInformation**: *true* or *false*</br>
  When you build this project, it will generation another public
  symbol debug information files in `pdb_pub` directory or the path
  you set in `gnu_vcxx.props`.
.
1. **GNUGenerateMapFile**: *true* or *false*</br>
  When you build this project, it will output .map files in `map`
  directory or the path you set in `gnu_vcxx.props`.

1. **GNUHardLinkInsteadofCopyExe**: *true* or *false*</br>
  **GNUHardLinkInsteadofCopyDll**: *true* or *false*</br>
  **GNUHardLinkInsteadofCopyLib**: *true* or *false*</br>
  When you build this project, it will make a hardlink of these
  generation files to `bin`, `dll` and `lib` directory or the
  path you set in `gnu_vcxx.props`.

1. **addressTable.txt**: *BaseAddress* setting file</br>
  When you build this project, this file [[vs2010](etc/vc10/addressTable.txt)|
  [vs2012](etc/vc11/addressTable.txt)|[vs2013](etc/vc12/addressTable.txt)]
  will automatic generation.  Then you can edit it and rebuild the
  projects to overriding the default location for exe or dll file.</br>
  For more information, see
  [MSDN](http://msdn.microsoft.com/en-us/library/f7f5138s.aspx).

**Note:** If you change the default path setting in gnu_vcxx.props,
be careful to modify these values in batch files.


### Link options
1. Macro **`USING_GNU_DLL`**</br>
  Macro **`USING_ALL_DLL`**</br>
  If you want to use GNU projects as DLLs, defined `USING_GNU_DLL`,
  or you can defined `USING_ALL_DLL` to use GNU and LOCAL projects as
  DLLs.</br>
  For more information, see linker header file [sample](include/linkzlib.h).

### BaseAddress Setting

When you build this project, it will generation a BaseAddress text
file for dll or exe files which is `etc/vcxx/addressTable.txt`
[[template](etc/addressTable.in)|[vs2010](etc/vc10/addressTable.txt)|
[vs2012](etc/vc11/addressTable.txt)|[vs2013](etc/vc12/addressTable.txt)].  When
you build this projects again, this project will fix the BaseAddress
with the right settings.

1. `;Increased base For BaseAddress`</br>
  This comment means one program which you want to keep it's BaseAddress
  unchanged.

1. `;Increased base By Alignment(size)`</br>
  This comment means BaseAddress will automatic increase by send alignment size.

  Otherwise, the linker will automatic increase ImageSize according
  to last record.


### Clean and Dist clean

Run `cleat.bat` to clean the workspace, or you really want to clean all generation
files, you should run `clean.bat dist-clean`, it will removes the intermediate files
at the same time, such as addressTable file [[vs2010](etc/vc10/addressTable.txt)|
[vs2012](etc/vc11/addressTable.txt)|[vs2013](etc/vc12/addressTable.txt)], and a
file list defined [here](project/.dist_clean) (Compile-time generated files).</br>
```
cmd '/c ' clean.bat [all|dist|dist-clean] [vc10|vc10.0|2010|vs2010] [vc11|vc11.0|2012|vs2012] [vc12|vc12.0|2013|vs2013]
```
