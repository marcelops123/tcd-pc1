#include <stdio.h>
#include <stdlib.h>

typedef struct Register
{
    int id;                               // ID ÚNICO DE CADA EVENTO
    char name[30];                        // NOME DE CADA EVENTO
    char place[30];                       // LUGAR ONDE ACONTECERÁ CADA EVENTO
    char date[20];                        // DATA DE REALIZAÇÃO DO EVENTO
    int tickets_quantity;                 // QUANTIDADE DE INGRESSOS DISPONÍVEIS
    float organization_costs;             // CUSTOS DE ORGANIZAÇÃO DO EVENTO
    float entry_value;                    // VALOR DE ENTRADA DO EVENTO
    int openbar;                          // PARA SABER SE O EVENTO TERÁ OU NÃO OPENBAR
    char nomebebida1;                     // NOME DA BEBIDA 1
    char nomebebida2;                     // NOME DA BEBIDA 2
    char nomebebida3;                     // NOME DA BEBIDA 3
    char nomebebida4;                     // NOME DA BEBIDA 4
    float teorbebida1;                    // TEOR ALCÓOLICO DA BEBIDA 1
    float teorbebida2;                    // TEOR ALCÓOLICO DA BEBIDA 2
    float teorbebida3;                    // TEOR ALCÓOLICO DA BEBIDA 3
    float teorbebida4;                    // TEOR ALCÓOLICO DA BEBIDA 4
    float valorbebida1;                   // VALOR DA BEBIDA 1
    float valorbebida2;                   // VALOR DA BEBIDA 2
    float valorbebida3;                   // VALOR DA BEBIDA 3
    float valorbebida4;                   // VALOR DA BEBIDA 4
    float valor_ent_normal;               // VALOR DA ENTRADA NORMAL
    float valor_ent_popular;              // VALOR DA ENTRADA POPULAR
    float valor_ent_especial;             // VALOR DA ENTRADA ESPECIAL
    float divisaovalor;                   // CÁLCULO QUE FAZ A DIVISÃO DE TODOS OS VALORES DO EVENTO
    float somatodasbebidas;               // CÁLCULO QUE FAZ A SOMA DO PREÇO DE TODAS AS BEBIDAS
    float numero_vendidos_normal;         // NÚMERO DE INGRESSOS VENDIDOS NORMAIS
    float numero_vendidos_popular;        // NÚMERO DE INGRESSOS VENDIDOS POPULARES
    float numero_vendidos_especial;       // NÚMERO DE INGRESSOS VENDIDOS ESPECIAIS
    int somatodasentradas;                // CÁLCULO QUE FAZ A SOMA DE TODAS AS ENTRADAS DO EVENTO
    float calculo_valor_entrada_vendidos; // CÁLCULO QUE FAZ A MULTIPLICAÇÃO ENTRE O VALOR DE ENTRADA E A QUANTIDADE DE INGRESSOS VENDIDOS DE CADA EVENTO
    float saldo;                          // SALDO DO PROMOTER
} Register;
