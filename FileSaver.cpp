#define _CRT_SECURE_NO_WARNINGS

#include "FileSaver.h"
#include "stdio.h"
#include "cstdio"
#include "Windows.h"

bool FileSaver::IsFileExists(const std::string& fname)
{
	WIN32_FIND_DATAA fData;
	HANDLE h;
	h = FindFirstFileA("./*", &fData);

	if (h == INVALID_HANDLE_VALUE) {
		throw std::exception("Error in method:{IsFileExists}");
	}
	do
	{
		if (strcmp(fData.cFileName , fname.c_str()) == 0) {
			return true;
		}
	} while (FindNextFileA(h, &fData));

	FindClose(h);

	return false;
}

