#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct escola
{
    char nome[777];
    char dataDeNascimento[777];
    float notaN1;
    float notaN2;
    float media;
};

int calcularMediaAluno(struct escola aluno)
{
    return (aluno.notaN1 + aluno.notaN2) / 2;
}

void AprovadoOuReprovado(struct escola aluno)
{
    if (aluno.media >= 7)
    {
        printf("\n%s: Foi aprovado!", aluno.nome);
    }
    if (aluno.media < 7)
    {
        printf("\n%s:Foi reprovado!", aluno.nome);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i;
    struct escola aluno[5];

    for (i = 0; i < 5; i++)
    {
        printf("Digite o nome do %dº aluno:", i + 1);
        gets(aluno[i].nome);

        fflush(stdin);

        printf("Digite a data de nascimento do aluno:");
        gets(aluno[i].dataDeNascimento);

        fflush(stdin);

        printf("Digite a 1º nota do aluno:");
        scanf("%f", &aluno[i].notaN1);

        printf("Digite a 2º nota do aluno:");
        scanf("%f", &aluno[i].notaN2);

        aluno[i].media = calcularMedia(aluno[i]);

        fflush(stdin);
    }

    fflush(stdin);
    system("CLS || CLEAR");

    for (i = 0; i < 5; i++)
    {
        printf("\n\nNome do %dº aluno:%s", i + 1, aluno[i].nome);

        printf("\nData de nascimento do aluno:%s", aluno[i].dataDeNascimento);

        printf("\nM[edia do aluno:%.2f\n", aluno[i].media);

        situacaoAluno(aluno[i]);
    }
    return 0;
}
