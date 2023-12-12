#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct Empresa
{
    char nome[250];
    char cargo[250];
    float salario;
};
void limpatela()
{
    system("CLS");
    fflush (stdin);
}

float calcularMediaSalarial(struct Empresa *funcionarios, int qtdFuncionarios, char *cargo)
{
    int i;
    float somaSalarios = 0;
    int cont = 0;

    for (i = 0; i < qtdFuncionarios; i++)
    {
        if (strcmp(funcionarios[i].cargo, cargo) == 0)
        {
            somaSalarios += funcionarios[i].salario;
            cont++;
        }
    }

    if (cont > 0)
    {
        return somaSalarios / cont;
    }
    else
    {
        return 0.0;
    }
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    int qtdFuncionarios;
    int i;
    printf("Quantidade de funcionários contratados : ");
    scanf("%d", &qtdFuncionarios);

    struct Empresa *funcionarios = (struct Empresa *)malloc(qtdFuncionarios * sizeof(struct Empresa));

    for (i = 0; i < qtdFuncionarios; i++)
    {
        printf("Informe o nome do funcionário %d: ", i + 1);
        scanf("%s", funcionarios[i].nome);

        printf("Informe o cargo de %s: ", funcionarios[i].nome);
        scanf("%s", funcionarios[i].cargo);

        printf("Informe o salário de %s: ", funcionarios[i].nome);
        scanf("%f", &funcionarios[i].salario);
    }

    const char *cargoPreferencial = "Programador";
    float mediaSalarial = calcularMediaSalarial(funcionarios, qtdFuncionarios, cargoPreferencial);

limpatela();

    printf("\nA média salarial entre todos os funcionários é: %.2f\n", mediaSalarial);
}
