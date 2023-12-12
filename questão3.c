#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct mercado
{
    char nome[777];
    float preco;
    int quantidadeNoEstoque;
};

float calcularValorTotal(struct mercado mercadoria)
{
    return mercadoria.preco * mercadoria.quantidadeNoEstoque;
}

void realizarCompra(struct mercado *mercadoria, int quantidade)
{
    if (quantidade <= mercadoria->quantidadeNoEstoque)
    {
        mercadoria->quantidadeNoEstoque -= quantidade;
        printf("\nCompra efetuada!\n");
    }
    else
    {
        printf("\nQuantidade inv�lida. Compra n�o efetuada.\n\n");
    }
}

void consultarEstoque(struct mercado mercadoria)
{
    printf("\nNome do produto: %s", mercadoria.nome);
    printf("\nPre�o: R$ %.2f", mercadoria.preco);
    printf("\nQuantidade em estoque: %d", mercadoria.quantidadeNoEstoque);
    printf("\nValor total no estoque: R$ %.2f\n", calcularValorTotal(mercadoria));
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct mercado mercadoria;
    int opcao;
    int quantidade;

    printf("Informe o produto: ");
    gets(mercadoria.nome);

    printf("Informe o pre�o do produto: ");
    scanf("%f", &mercadoria.preco);

    printf("Informe: ");
    scanf("%d", &mercadoria.quantidadeNoEstoque);

    system("CLS");

    do
    {

        printf("         OP��ES     DISPON�VEIS  \n");
        printf("1| COMPRAR|\n");
        printf("2| ESTOQUE    |\n");
        printf("3| ENCERRAR PROGRAMA     |\n");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        system("CLS");
        
        switch (opcao)
        {
        case 1:
            printf("\nInforme a quantidade de compra : ");
            scanf("%d", &quantidade);
            realizarCompra(&mercadoria, quantidade);
            break;
        case 2:
            consultarEstoque(mercadoria);
            break;
        case 3:
            printf("\nPrograma sendo encerrado.\n");
            break;
        default:
            printf("\nQuantidade  insuficiente do estoque.\n");
            break;
        }

    } while (opcao != 3);

    return 0;
}