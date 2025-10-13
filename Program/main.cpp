#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo = fopen("dados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Nome,Idade,Cidade\n");
    fprintf(arquivo, "João,30,São Paulo\n");
    fprintf(arquivo, "Maria,25,Rio de Janeiro\n");

    fclose(arquivo);
    return 0;
}