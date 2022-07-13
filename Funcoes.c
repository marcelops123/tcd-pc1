#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "Struct.c"

#define ANSI_COLOR_RED "\x1b[31m"          // cores em ANSI utilizadas
#define ANSI_COLOR_PADRAO "\e[0;37m"       // cor saída padrão
#define ANSI_COLOR_AZUL_CLARO "\033[1;94m" // cor azul claro
#define ANSI_COLOR_BRANCO "\033[1;97m"     // cor branco
#define ANSI_COLOR_CYAN "\033[1;96m"       // cor cyano
#define ANSI_COLOR_WHITE_RED "\033[1;91m"  // cor vermelho claro
#define ANSI_COLOR_MAGENTA "\033[1;35m"    // cor magenta
#define ANSI_COLOR_AMARELO "\033[1;33m"    // cor amarelo
#define ANSI_COLOR_VERDE "\033[1;32m"      // cor verde

struct Register register_event[100];
int i;                // variável contadora
int pergunta_openbar; // variável pra saber se o evento registrado terá ou não openbar

void CadastrarEvento()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Salvar estado atual do console e fazer com que funcione o gerenciamento de cores
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;             // Salvar estado atual do console e fazer com que funcione o gerenciamento de cores
    WORD saved_attributes;                              // Salvar estado atual do console e fazer com que funcione o gerenciamento de cores
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Salvar estado atual do console e fazer com que funcione o gerenciamento de cores
    saved_attributes = consoleInfo.wAttributes;         // Salvar estado atual do console e fazer com que funcione o gerenciamento de cores

    UINT CPAGE_UTF8 = 65001;        // Definindo a variável com o código do UTF8
    SetConsoleOutputCP(CPAGE_UTF8); // Settando a saída para o padrão UTF8

    system("cls");

    printf(ANSI_COLOR_BRANCO "\n+-------------------------------+"); // A partir daqui a cor da fonte do console ficará azul até que esse parâmetro seja fechado.
    printf("\n|------CADASTRO DE EVENTOS------|");
    printf("\n+-------------------------------+ \n");
    printf("Redirecionando...");
    Sleep(1000);

    for (i = 0;; i++)
    {
        system("cls");
        printf("Insira o ID do evento que deseja cadastrar. \n ");
        fflush(stdin); // Limpando o buffer da memória
        scanf("%d", &register_event[i].id);

        if (register_event[i].id == 0) // Quando o Id for igual a 0 ele encerra o laço e finaliza o cadastro de eventos.
        {

            printf("Eventos cadastrados com sucesso!\n\n");
            printf("Redirecionando....\n" ANSI_COLOR_PADRAO); // A partir daqui o console volta a sua cor padrão.
            Sleep(1000);                                      // Delay de 1000 milisegundos = (1 segundo)
            system("cls");

            return main(); // Retorna ao menu principal
        }
        while (register_event[1].id > 0 && register_event[1].id == register_event[0].id || register_event[2].id > 0 && register_event[2].id == register_event[0].id || register_event[2].id > 0 && register_event[2].id == register_event[1].id || register_event[3].id > 0 && register_event[3].id == register_event[0].id || register_event[3].id > 0 && register_event[3].id == register_event[1].id || register_event[3].id > 0 && register_event[3].id == register_event[2].id || register_event[4].id > 0 && register_event[4].id == register_event[0].id || register_event[4].id > 0 && register_event[4].id == register_event[1].id || register_event[4].id > 0 && register_event[4].id == register_event[2].id || register_event[4].id > 0 && register_event[4].id == register_event[3].id
               // Função criada para não permitir que um Id seja registrado mais de uma vez
        )
        {
            system("cls");
            printf("Esse id já foi digitado!\n");
            printf("\nPor favor digite outro Id que ainda não tenha sido cadastrado!\n");
            scanf("%d", &register_event[i].id);
            if (register_event[i].id == 0) // Quando o Id for igual a 0 ele encerra o laço e finaliza o cadastro de eventos.
            {

                printf("Eventos cadastrados com sucesso!");
                Sleep(1000); // Delay de 1000 milisegundos = (1 segundo)
                system("cls");
                printf("Redirecionando....");
                system("cls");

                return main();
            }
        }
        system("cls");
        printf("\nDigite o nome do evento.\n ");
        fflush(stdin);
        scanf("%[^\n]", &register_event[i].name);

        printf("\nDigite o nome do lugar que acontecerá o evento. \n ");
        fflush(stdin);
        scanf("%[^\n]", &register_event[i].place);

        printf("Insira a data do evento(XX/XX/XXXX).\n\n ");
        fflush(stdin);
        scanf("%s[^\n]", &register_event[i].date);

        printf("Insira a quantidade de ingressos disponíveis. \n\n ");
        fflush(stdin);
        scanf("%d", &register_event[i].tickets_quantity);

        printf("Insira os custos do evento. \n\n ");
        fflush(stdin);
        scanf("%f", &register_event[i].organization_costs);

        register_event[i].valor_ent_popular = register_event[i].organization_costs / register_event[i].tickets_quantity;         // Cáluclo que obtém o valor da entrada popular
        register_event[i].valor_ent_normal = register_event[i].valor_ent_popular + (0.1 * register_event[i].valor_ent_popular);  // Cáluclo que obtém o valor da entrada normal
        register_event[i].valor_ent_especial = register_event[i].valor_ent_normal + (0.15 * register_event[i].valor_ent_normal); // Cáluclo que obtém o valor da entrada especial

        printf("O evento será open bar?(Digite 1 se sim ou 0 se não). \n\n");
        fflush(stdin);
        scanf("%d", &pergunta_openbar);
        if (pergunta_openbar == 1) // Se a resposta do usuário for igual a 1 ele executará os passos seguintes fazendo o cadastro das bebidas que estarão no evento
        {

            system("cls");
            printf("Qual o nome da primeira bebida?\n ");
            fflush(stdin);
            scanf("%[^\n]", &register_event[i].nomebebida1);

            
            printf("Qual o teor alcóolico da primeira bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].teorbebida1);

            
            printf("Qual o valor da primeira bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].valorbebida1);

            system("cls");
            printf("Qual o nome da segunda bebida?\n");
            fflush(stdin);
            scanf("%[^\n]", &register_event[i].nomebebida2);

            
            printf("Qual o teor alcóolico da segunda bebida?\n ");
            fflush(stdin);
            scanf("%.2f", &register_event[i].teorbebida2);

            printf("Qual o valor da segunda bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].valorbebida2);

            system("cls");
            printf("Qual o nome da terceira bebida?\n ");
            fflush(stdin);
            scanf("%[^\n]", &register_event[i].nomebebida3);
            printf("Qual o teor alcóolico da terceira bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].teorbebida3);
            printf("Qual o valor da terceira bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].valorbebida3);

            system("cls");
            printf("Qual o nome da quarta bebida?\n ");
            fflush(stdin);
            scanf("%[^\n]", &register_event[i].nomebebida4);
            printf("Qual o teor alcóolico da quarta bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].teorbebida4);
            printf("Qual o valor da quarta bebida?\n ");
            fflush(stdin);
            scanf("%f", &register_event[i].valorbebida4);

            register_event[i].somatodasbebidas = (register_event[i].valorbebida1 * 1.75) + (register_event[i].valorbebida2 * 1.75) + (register_event[i].valorbebida3 * 1.75) + (register_event[i].valorbebida4 * 1.75); // Cálculo que obtém o valor da soma de todas as bebidas
            register_event[i].valor_ent_popular = register_event[i].organization_costs / register_event[i].tickets_quantity + register_event[i].somatodasbebidas;                                                       // Cálculo que obtém o valor da entrada popular
            register_event[i].valor_ent_normal = register_event[i].valor_ent_popular + (0.1 * register_event[i].valor_ent_popular);                                                                                     // Cálculo que obtém o valor da entrada normal
            register_event[i].valor_ent_especial = register_event[i].valor_ent_normal + (0.15 * register_event[i].valor_ent_normal);                                                                                    // Cálculo que obtém o valor da entrada especial
        }
        printf(ANSI_COLOR_VERDE "O evento %s foi cadastrado com sucesso! \n" ANSI_COLOR_PADRAO, register_event[i].name);
        printf("\nRedirecionando...\n");
        Sleep(1000);
    }
}

void PesquisarEvento()
{

    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int Idpesquisa; // Id do evento que o usuário quer pesquisar
    int digito;     // Saber se o usuário deseja retornar para o menu principal
    system("cls");  // Limpando o console

    printf(ANSI_COLOR_WHITE_RED "\n+-------------------------------+"); // Settando a cor do console a partir daqui para a variável que define a cor
    printf("\n|------PESQUISA DE EVENTOS------|");
    printf("\n+-------------------------------+ \n");
    printf("Digite o ID do evento para buscar sobre o evento desejado :\n");
    fflush(stdin);
    scanf("%d", &Idpesquisa);
    for (i = 0; i <= 4; i++) // Variável contadora de 0 a 4 que percorrerá o Array encontrando os elementos presentes.
    {
        if (register_event[i].id == Idpesquisa) // Verifica se o ID que o usuário digitou é igual a algum ID encontrado dentro do for
        {

            fflush(stdin); // Limpando o cache de memória local
            system("cls"); // Limpando a tela
            printf("\n------------DADOS DO EVENTO------------\n\n");
            printf(ANSI_COLOR_BRANCO "\n Id do evento = %d\n\n", register_event[i].id);
            printf(" Nome do evento = %s\n\n", register_event[i].name);
            printf(" Lugar do evento = %s\n\n", register_event[i].place);
            printf(" Data do evento = %s\n\n", register_event[i].date);
            printf(" Quantidade de ingressos = %d\n\n", register_event[i].tickets_quantity);
            printf(" Custos de organizacao = %.2f\n\n", register_event[i].organization_costs);
            printf(" Valor da Entrada Normal = %.2f\n\n", register_event[i].valor_ent_normal);
            printf(" Valor da Entrada Popular = %.2f\n\n", register_event[i].valor_ent_popular);
            printf(" Valor da Entrada Especial = %.1f\n\n", register_event[i].valor_ent_especial);
            system("pause"); // Pausa o programa até o usuário pressionar alguma tecla dentro do console
            printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
            Sleep(600);
            system("cls");
            return main();
        }
    }
    printf(ANSI_COLOR_RED "\n Não foi possível encontrar algum evento com o ID informado! \n" ANSI_COLOR_PADRAO);
    printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
    Sleep(1000);   // Delay de 1 segundo
    system("cls"); // Limpando a tela do console

    return main();
}

void RegistrarVendidos() // Função usada para registrar a quantidade de ingressos vendidos por evento
{

    UINT CPAGE_UTF8 = 65001;        // Código padrão da linguagem UTF8
    SetConsoleOutputCP(CPAGE_UTF8); // Define o console como UTF8 para acentuação correta
    int Idpesquisa;
    int lucro;
    system("cls");
    printf(ANSI_COLOR_AZUL_CLARO "\n+------------------------------------+");
    printf("\n|----REGISTRAR INGRESSOS VENDIDOS----|");
    printf("\n+------------------------------------+\n");
    for (i = 0;; i++)
    {
        printf("Digite o ID do evento para fazer o cálculo sobre o evento desejado : \n");
        fflush(stdin);
        scanf("%d", &Idpesquisa);
        for (i = 0; i <= 4; i++)
        {
            if (register_event[i].id == Idpesquisa) // Faz a verificação se dentro do for foi encontrado algum ID igual ao que o usuário digitou
            {
                system("cls"); // Limpando a tela
                printf("Digite o número de ingressos vendidos para entrada normal : \n\n");
                fflush(stdin);
                scanf("%f", &register_event[i].numero_vendidos_normal);

                printf("Digite o número de ingressos vendidos para entrada popular : \n\n");
                fflush(stdin);
                scanf("%f", &register_event[i].numero_vendidos_popular);

                printf("Digite o número de ingressos vendidos para entrada especial : \n\n");
                fflush(stdin);
                scanf("%f", &register_event[i].numero_vendidos_especial);

                register_event[i].calculo_valor_entrada_vendidos = register_event[i].numero_vendidos_normal * register_event[i].valor_ent_normal + register_event[i].numero_vendidos_popular * register_event[i].valor_ent_popular + register_event[i].valor_ent_especial * register_event[i].numero_vendidos_especial;
                if (register_event[i].numero_vendidos_normal + register_event[i].numero_vendidos_popular + register_event[i].numero_vendidos_especial > register_event[i].tickets_quantity)
                {
                    printf(ANSI_COLOR_RED "\nO número de ingressos vendidos é maior do que o número de ingressos disponíveis!\n" ANSI_COLOR_PADRAO);
                    printf(ANSI_COLOR_AMARELO "\nSeu limite de ingressos para venda é de %d\n", register_event[i].tickets_quantity, ANSI_COLOR_PADRAO);
                    printf(ANSI_COLOR_AMARELO"\nRetornando para o menu principal...\n"ANSI_COLOR_PADRAO);
                    Sleep(3000);
                    system("cls");
                    return main();
                }
                register_event[i].saldo = register_event[i].calculo_valor_entrada_vendidos - register_event[i].organization_costs;

                printf("\n Valor total de ingressos vendidos = R$ %.2f\n", register_event[i].calculo_valor_entrada_vendidos);
                printf("\n Custos de organização = %.2f\n", register_event[i].organization_costs);
                fflush(stdin);
                if (register_event[i].calculo_valor_entrada_vendidos > register_event[i].organization_costs)
                {
                    printf(ANSI_COLOR_VERDE "\n O EVENTO %s TEVE LUCRO! \n\n" ANSI_COLOR_PADRAO, register_event[i].name);
                    system("pause");
                    printf("\nRedirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
                    Sleep(1000);
                    system("cls");
                    return main();
                }
                else
                    printf(ANSI_COLOR_RED "\n O EVENTO %s TEVE PREJUÍZO! \n\n" ANSI_COLOR_PADRAO, register_event[i].name);
                system("pause");
                printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
                Sleep(1000);
                system("cls");
                return main();
            }
        }

        printf(ANSI_COLOR_RED "\n Não foi possível identificar o evento com o ID informado!\n" ANSI_COLOR_PADRAO);
        printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
        Sleep(1000);
        system("cls");
        return main();
    }
}

void InformarLucroPrejuizo()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    int Idpesquisa;
    system("cls");
    printf(ANSI_COLOR_MAGENTA "\n+--------------------------------------+");
    printf("\n|-----------LUCRO OU PREJUÍZO----------|");
    printf("\n+--------------------------------------+\n");
    for (i = 0;; i++)
    {
        printf("Digite o ID do evento para saber se ele teve lucro ou prejuízo : \n");
        fflush(stdin);
        scanf("%d", &Idpesquisa);
        for (i = 0; i <= 5; i++)
        {
            if (register_event[i].id == Idpesquisa)
            {

                if (register_event[i].calculo_valor_entrada_vendidos > register_event[i].organization_costs)
                {
                    printf(ANSI_COLOR_VERDE "\n ESSE EVENTO TEVE LUCRO! \n\n" ANSI_COLOR_PADRAO);
                }
                if (register_event[i].calculo_valor_entrada_vendidos == 0) // Se a somatória de todos os ingressos vendidos ainda não tiver sido realizada ele retornará uma mensagem de "erro" para o usuário
                {
                    printf(ANSI_COLOR_AMARELO "\n ESSE EVENTO AINDA NÃO TEVE SEUS INGRESSOS CADASTRADOS! \n\n" ANSI_COLOR_PADRAO);
                    system("pause");
                    printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
                    Sleep(1000);
                    system("cls");
                    return main();
                }
                if (register_event[i].calculo_valor_entrada_vendidos < register_event[i].organization_costs)
                    printf(ANSI_COLOR_RED "\n ESSE EVENTO TEVE PREJUÍZO! \n\n" ANSI_COLOR_PADRAO);
                system("pause");
                printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
                Sleep(1000);
                system("cls");
                return main();
            }
        }
        printf(ANSI_COLOR_RED "\n Não foi possível identificar o evento com o ID informado!\n" ANSI_COLOR_PADRAO);
        printf("\n Redirecionando para a página principal...\n" ANSI_COLOR_PADRAO);
        Sleep(1000);
        system("cls");
        return main();
    }
}
void SaldoPromoter()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    printf(ANSI_COLOR_AMARELO "\n+------------------+");
    printf("\n|-------SALDO------|");
    printf("\n+------------------+\n" ANSI_COLOR_PADRAO);
    for (i = 0;; i++)
    {

        if (register_event[i].saldo > 0) // Se o saldo for positivo ele mostra uma mensagem em verde informando que o saldo do promoter está positivo
        {

            printf(ANSI_COLOR_VERDE "\n Seu saldo atual é de R$ %.2f\n", register_event[i].saldo);
            printf("\n SEU SALDO ATUAL ESTÁ POSITIVO, CONTINUE INVESTINDO NOS EVENTOS! \n\n" ANSI_COLOR_PADRAO);
        }

        if (register_event[i].saldo < 0) // Se o saldo for negativo ele mostra uma mensagem em vermelho informando que o saldo do promoter está negativo
        {

            printf(ANSI_COLOR_RED "\n Seu saldo atual é de R$ %.2f\n", register_event[i].saldo);
            printf("\n SEU SALDO ATUAL ESTÁ NEGATIVO, CUIDADO COM OS ALTOS INVESTIMENTOS NOS EVENTOS! \n\n" ANSI_COLOR_PADRAO);
        }

        if (register_event[i].saldo == 0) // Se o saldo for igual a zero ele mostra uma mensagem na cor cyan informando que o promoter ainda não possui saldo
        {
            printf(ANSI_COLOR_CYAN "\n VOCÊ AINDA NÃO POSSUI SALDO! \n");
            printf(ANSI_COLOR_CYAN "\n Experimente fazer o cadastro de algum evento e logo após faça o registro da quantidade de ingressos vendidos!\n\n" ANSI_COLOR_PADRAO);
        }
        system("pause");
        printf(ANSI_COLOR_PADRAO "\n Redirecionando para a página principal...\n\n");
        Sleep(1000);
        system("cls");
        return main();
    }
}

void EncerrarPrograma()
{
    int i;
    int digito;
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    printf(ANSI_COLOR_RED "\n Tem certeza de que deseja encerrar o programa?\n" ANSI_COLOR_PADRAO);
    printf(ANSI_COLOR_AMARELO "\nPara encerrar o programa digite 6 novamente\n" ANSI_COLOR_PADRAO);
    scanf("%d", &digito);

    if (digito == 6)
    {

        printf(ANSI_COLOR_VERDE "\nPrograma encerrado com sucesso!\n" ANSI_COLOR_PADRAO);
        printf("+-------------------------------+\n");
        return 0;
    }

    else
        system("cls");
    return main();
}

void OpcaoInvalida()
{
    printf("+-------------------------------+\n");
    printf("Opção inválida! Digite novamente:\n");
    printf("+-------------------------------+\n");
    Sleep(300);
    system("cls");
    return main();
    return 0;
}
