mingw-unicode-main
==================

Note: This should no longer be used as MinGW now has a built-in solution. Add -municode to the command line (and possibly extern "C" to the wmain function).

Simple wrappers to add wmain and wWinMain support in MinGW

These wrappers allow for use of wmain / wWinMain in MinGW seamlessly with Unicode (WCHAR), regular (CHAR), or the ability to choose (TCHAR).

The instructions for using them are in the files. Also take a look at other programs that use them.
