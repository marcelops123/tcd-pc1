#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "Funcoes.c"

void main()
{

    UINT CPAGE_UTF8 = 65001;        // Definindo código padrão da linguagem UTF8
    SetConsoleOutputCP(CPAGE_UTF8); // Settando saída do console para padrão UTF8 para acentuação correta

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Define a saída do console para a cor padrão
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;            // Define a saída do console para a cor padrão
    WORD saved_attributes;                             // Define a saída do console para a cor padrão

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Salvar estado atual do console
    saved_attributes = consoleInfo.wAttributes;         // Salvar estado atual do console
    int option;                                         // Variável que determinará qual função do programa o usuário quer executar

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // Settando a partir daqui a cor Verde para o console
    printf("+--------------------------------------+");
    printf("\n\n           |---MENU---|              \n");
    printf("\n   Por favor, digite a opção desejada :\n\n");
    printf("      1- |CADASTRAR EVENTO|             |\n\n");
    printf("      2- |PESQUISAR EVENTO|             |\n\n");
    printf("      3- |REGISTRAR INGRESSOS VENDIDOS| |\n\n");
    printf("      4- |EXIBIR RESULTADO POR EVENTO|  |\n\n");
    printf("      5- |EXIBIR RESULTADO GERAL|       |\n\n");
    printf("      6-        |SAIR|                  |\n\n");
    printf("+---------------------------------------+\n");
    SetConsoleTextAttribute(hConsole, saved_attributes); // Voltando console para a cor padrão

    fflush(stdin); // Limpando o cache da memória local
    scanf("%d", &option);
    switch (option)
    {
    case 1:

        CadastrarEvento();
        return 0;

    case 2:
        PesquisarEvento();
        return 0;

    case 3:
        RegistrarVendidos();
        return 0;

    case 4:
        InformarLucroPrejuizo();
        return 0;

    case 5:
        SaldoPromoter();
        return 0;

    case 6:
        EncerrarPrograma();
        return 0;
    }

    if (option > 6)
    {
        OpcaoInvalida();
        return 0;
    }
}
