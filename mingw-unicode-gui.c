// This is for the MinGW compiler which does not support wWinMain.
// It is a wrapper for _tWinMain when _UNICODE is defined (wWinMain).
//
// !! Do not compile this file, but instead include it right before your _tWinMain function like:
// #include "mingw-unicode-gui.c"
// int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
//
// This wrapper adds ~400 bytes to the program and negligible overhead

#undef _tWinMain
#ifdef _UNICODE
#define _tWinMain wWinMain
#else
#define _tWinMain WinMain
#endif

#if defined(__GNUC__) && defined(_UNICODE)

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
#define NOUSER
#define NONLS
#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX
#include <windows.h>
#include <stdlib.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR _lpCmdLine, int nCmdShow) {
	WCHAR *lpCmdLine = GetCommandLineW();
	if (__argc == 1) { // avoids GetCommandLineW bug that does not always quote the program name if no arguments
		do { ++lpCmdLine; } while (*lpCmdLine);
	} else {
		BOOL quoted = lpCmdLine[0] == L'"';
		++lpCmdLine; // skips the " or the first letter (all paths are at least 1 letter)
		while (*lpCmdLine) {
			if (quoted && lpCmdLine[0] == L'"') { quoted = FALSE; } // found end quote
			else if (!quoted && lpCmdLine[0] == L' ') {
				// found an unquoted space, now skip all spaces
				do { ++lpCmdLine; } while (lpCmdLine[0] == L' ');
				break;
			}
			++lpCmdLine;
		}
	}
	return wWinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

#endif
