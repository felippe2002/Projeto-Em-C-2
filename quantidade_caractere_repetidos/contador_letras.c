/*
Faça um programa que receba do usuário o nome de um arquivo texto e um caractere. Mostre na tela
quantas vezes aquele caractere aparece dentro do arquivo.
*/

#include <stdio.h>
#include <string.h>


int main()
{
    FILE *arq,*arq2;
    char nome_arquivo[50]; //vai ser recebido o nome do arquivo
    char caractere,contador,letra_achar;
    int contidade = 0;

    printf("Infome o nome do arquivo: \n");
    fgets(nome_arquivo,sizeof(nome_arquivo),stdin);

    nome_arquivo[strcspn(nome_arquivo,"\n")] = '\0';
    printf(nome_arquivo);

    arq = fopen(nome_arquivo,"a");

    if(arq)
    {
        do
        {
            printf("Informe o caractere: \n");
            scanf(" %c",&caractere);
            if(caractere == '0')
            {
                printf("Finalizado o Programa!\n");
            }else
            {
                fputc(caractere,arq);
                printf("Foi inserido o caractere desejado!\n");
            }
        }while (caractere != '0');
    }else
    {
        printf("Informamos que infelizmente nao foi possivel abrir o arquivo!\n");
    }

    fclose(arq);
    arq = NULL;

    arq2 = fopen(nome_arquivo,"r");

    printf("Informe a letra desejada para ser achada: \n");
    scanf(" %c",&letra_achar);

    if(arq2)
    {
        for(contador = getc(arq2); contador != EOF;contador = getc(arq2))
        {
            if(contador == letra_achar)
            {
                contidade++;
            }
        }
        printf("A quantidade de veiz que foi achada foi de %d.",contidade);
    }else
    {
        printf("Informamos que infelizmente nao foi possivel abrir o arquivo!");
    }

    fclose(arq2);
    arq2 = NULL;

    return 0;
}
