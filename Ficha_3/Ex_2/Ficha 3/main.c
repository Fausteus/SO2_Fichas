#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
//#include "SO2_F3_DLL.h"

typedef double(*applyFactorFunc)(double);

int _tmain(int argc, TCHAR* argv[]) {

	double* varAdd;
	HINSTANCE hLib;
	applyFactorFunc procAdd;
	double val;
	

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif
	
	hLib = LoadLibrary(_T("SO2_F3_DLL.dll"));
	
	if (hLib != NULL) {
		varAdd = (double*)GetProcAddress(hLib, "factor");

		procAdd = (applyFactorFunc)GetProcAddress(hLib, "applyFactor");
		if (varAdd != NULL && procAdd != NULL) {
			do {
				//A
				_tscanf_s(_T("%lf"), varAdd);
				_tprintf(_T("\na: %lf\n"), *varAdd);

				// B
				_tscanf_s(_T("%lf"), &val);
				_tprintf(_T("\nb: %lf\n"), val);

				_tprintf(_T("\nResultado: %lf * %lf = %lf\n"), *varAdd, val, procAdd(val));

			} while (varAdd != -1);
		}
		FreeLibrary(hLib);
	}else{
		_tprintf(_T("\nDLL not found\n"));}
	return 0;
}