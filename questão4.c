#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ContaDoBanco
{
    int numeroConta;
    char nomeTitular[250];
    float saldo;
    char tipoConta[200];
};

void depositar(struct ContaDoBanco *conta, float valor)
{
    conta->saldo += valor;
    printf("Depósito efeituado! Novo saldo: %.2f\n", conta->saldo);
}

void sacar(struct ContaDoBanco *conta, float valor)
{
    if (valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("\nSaque efetuado! \nNovo saldo: %.2f\n", conta->saldo);
    }
    else
    {
        printf("\nSaldo insuficiente. Operação não realizada.\n");
    }
}

void imprimirSaldo(struct ContaDoBanco *conta)
{
    printf("Saldo atual da conta: %.2f\n", conta->saldo);
}

void main()
{
    setlocale(LC_ALL, "portuguese");
    float valor;
    int opcao;
    struct ContaDoBanco conta;

    printf("Digite o número da conta: ");
    scanf("%d", &conta.numeroConta);

    fflush(stdin);

    printf("Informe o nome do titular da conta: ");
    gets(conta.nomeTitular);

    fflush(stdin);

    printf("Conta Poupança ou Conta Corrente: ");
    gets(conta.tipoConta);

    printf("Informe o seu saldo: ");
    scanf("%f", &conta.saldo);

    system("CLS");

    do
    {
        printf("\n  Operações Bancárias \n");
        printf("1| DEPOSITAR           |\n");
        printf("2| SACAR           |\n");
        printf("3| IMPRIMIR SALDO      |\n");
        printf("4| ENCERRAR SISTEMA           |\n");
        printf("\nEscolha a operacao desejada: ");
        scanf("%d", &opcao);

        system("CLS");

        switch (opcao)
        {
        case 1:
            printf("Digite o valor de depósito : ");
            scanf("%f", &valor);
            depositar(&conta, valor);
            break;

        case 2:
            printf("Informe a quantia para efetuar o saque: ");
            scanf("%f", &valor);
            sacar(&conta, valor);
            break;

        case 3:
            imprimirSaldo(&conta);
            break;

        case 4:
            printf("Sistema encerrado.\n");
            break;

        default:
            printf("Opção inexistente.\n");
            break;
        }

    } while (opcao != 4);
}