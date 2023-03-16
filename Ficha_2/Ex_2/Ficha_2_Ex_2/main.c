#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#define TAM 200

int _tmain(int argc, TCHAR* argv[]) {
    HKEY chave;
    TCHAR chave_nome[TAM] = _T("SOFTWARE\\AULA\\Rodrigo"), par_nome[TAM] = _T("Ficha_2_Ex2"), par_valor[TAM] = _T("Registry");

    /* ... Mais variáveis ... */

    TCHAR nome[TAM];
    DWORD resultado, menu;

#ifdef UNICODE 
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
    _setmode(_fileno(stderr), _O_WTEXT);
#endif

    /* ... as várias alíneas ...*/

    _tprintf(_T("Insira o nome da chave que quer criar: "));
   // _tscanf_s(_T("%s"), nome, TAM - 1);

   // _tcscat_s(chave_nome, TAM, nome);

    if (RegCreateKeyEx(HKEY_CURRENT_USER, chave_nome, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &chave, &resultado) == ERROR_SUCCESS) {
        if (resultado == REG_CREATED_NEW_KEY)
            _tprintf(_T("\nChave criada com sucesso!"));
        else
            _tprintf(_T("\nChave aberta com sucesso!"));
    }
    else
        _tprintf(_T("\nErro ao criar ou abrir a chave!"));

    _tprintf(_T("\n\n0 - Criar ou Mudar Valor da chave \n1 - Consultar o valor da chave\n2 - Eliminar o valor da chave \n"));
    _tscanf_s(_T("%d"), &menu); 


    if(menu == 0)
    {
        _tprintf(_T("\nO valor será: "));
        _tscanf_s(_T("%s"), par_valor, TAM-1);

        RegSetValueEx(chave, par_nome, 0, REG_SZ, par_valor, _tcslen(par_valor) * sizeof(TCHAR));
    }
    else if (menu == 1)
    {
        _tprintf(_T("\nCriar//Mudar valores da chave\n O valor será: "));

    }
    else if (menu == 2)
    {
        RegDeleteKeyValue(chave, NULL, NULL);   
    }
    else {
        _tprintf(_T("\nOpção inválida."));
    }
    RegCloseKey(chave);

    return 0;
}