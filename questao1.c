#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 3
struct agenda
{
    char nome[250];
    char numero[250];
    char gmail[250];
};
char *buscarContato(struct agenda contato[], char *escolha)
{
    int a;
    for (a = 0; a < TAM; a++)
    {
        if (strcmp(contato[a].nome, escolha) == 0)
        {
           return printf("\nTelefone de %s: %s", contato[a].nome, contato[a].numero);
            break;
        }
    }
     return printf("Contato inexistente");
}
void main()
{
    struct agenda telefone[TAM];
    int a;
    char escolha[250];
    for (a = 0; a < TAM; a++)
    {
        printf("Informe o nome do %d contato: ", a + 1);
        gets(telefone[a].nome);

        printf("Informe o numero de %s: ", telefone[a].nome);
        gets(telefone[a].numero);

            printf("Informe o gmail de %s: ", telefone[a].nome);
        gets(telefone[a].gmail);
    }
    system("CLS");
    printf("Informe o contato escolhido:");
    gets(escolha);
    system("CLS");

    buscarContato(telefone, escolha);
}