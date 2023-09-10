#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arquivo;
    FILE *arquivoNovo;
    
    char linha[100];
    char nome[30];
    char telefone[25];
    char funcao[20];
    float nota1, nota2, media;

    arquivo = fopen("DadosEntrada.csv", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(1);
    }

    arquivoNovo = fopen("SituacaoFinal.csv", "w+");

    if (arquivoNovo == NULL) {
        printf("Erro ao criar o arquivo Novo.\n");
        printf(1);
    }

    // Fgets para percorrer o numero de linhas
    // sscanf para fazer a verificação dos nomes no arquivo.csv e %[^,] delimitador para tirar as virgulas
    // para fazer uma analise limpa dos dados e atribuir corretamente as variaveis

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", nome, telefone, funcao, &nota1, &nota2) == 5) {
            
            media = (nota1 + nota2)/2;
        } else {
            printf("Erro ao analisar a linha: %s", linha);
        }
        if (media >= 7){   
            fprintf(arquivoNovo, "%s,\t%.2f, APROVADO\n", nome, media);
        } else if (media < 7){
            fprintf(arquivoNovo, "%s,\t%.2f, REPROVADO\n", nome, media);
        } else
           printf(1);
    }
    
    fclose(arquivoNovo);
    fclose(arquivo);

return 0;
}