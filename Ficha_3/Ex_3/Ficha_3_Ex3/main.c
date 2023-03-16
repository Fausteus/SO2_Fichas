#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include "SO2_F3_DLL.h"

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
		
			do {
				//A
				_tscanf_s(_T("%lf"), &factor);
				_tprintf(_T("\na: %lf\n"), factor);

				// B
				_tscanf_s(_T("%lf"), &val);
				_tprintf(_T("\nb: %lf\n"), val);

				_tprintf(_T("\nResultado: %lf * %lf = %lf\n"), factor, val, applyFactor(val));

			} while (factor != -1);
		
		FreeLibrary(hLib);
	}
	return 0;
}