#include "menu.h"
#include "arquivo.h"
#define OPERACOES_MEDIA 1

int *definirTamanhoVetor(int tam)
{
    int *vetor = NULL;
    vetor = (int *)malloc(tam * sizeof(int));
    return vetor;
}

void resetaVetor(int *vetor, int tam)
{
    char endereco[16];
    strcpy(endereco, "log.txt");
    for (int i = 0; i < tam; i++)
        vetor[i] = geraRandom(tam);

    registraArquivo(endereco, vetor, tam);
}

void imprimeVetorMain(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void menuPrincipal()
{
    char endereco[16];
    int opc, tam = 0, num, sortOpc, i;
    double tempoMedio=0;
    int *vetor = NULL;

    strcpy(endereco, "log.txt");
    inicializaArquivo(endereco);

    system("clear");
    // free(vetor);
    // vetor = definirTamanhoVetor(TAM_INICIAL);
    // resetaVetor(vetor, TAM_INICIAL);
    // imprimeVetorMain(vetor, TAM_INICIAL);
    // getchar();

    while (1)
    {
        do
        {
            system("clear");
            printf("Bem vindo ao verificador de Soma!\n\n");
            printf("Escolha uma das opções abaixo:\n\n");
            printf("1 - Criar novo vetor!\n");
            printf("2 - Fazer pesquisa por pesquisa sequencial!\n");
            printf("3 - Fazer pesquisa por busca binária!\n");
            printf("0 - Sair\n\n");
            printf("> ");
            scanf("%d", &opc);
            getchar();
            if (opc < 0 || opc > 3)
            {
                printf("Opção inválida\n");
                printf("Pressione enter para continuar...");
                getchar();
            }
        } while (opc < 0 || opc > 3);
        switch (opc)
        {
        case 1:
            system("clear");
            printf("Digite o tamanho do vetor: ");
            scanf("%d", &tam);
            getchar();
            free(vetor);
            vetor = definirTamanhoVetor(tam);
            resetaVetor(vetor, tam);
            printf("Um vetor com valores aleatórios será gerado\n");
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 2:
            printf("\nDigite o número que deseja verificar: ");
            scanf("%d", &num);
            getchar();
            tempoMedio = 0;
            for(i=0;i<OPERACOES_MEDIA;i++)
                pesquisaSequencial(vetor, num, tam, &tempoMedio);
            // printf("%lf\n", tempoMedio/OPERACOES_MEDIA);
            printf("Tempo de pesquisa sequencial: %lf\n", tempoMedio/OPERACOES_MEDIA);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 3:
            system("clear");
            printf("\nDigite o número que deseja verificar: ");
            scanf("%d", &num);
            getchar();
            do
            {
                printf("\nDigite um metodo de ordenacao\n\n");
                printf("1 - Bubble Sort!\n");
                printf("2 - Heap Sort!\n\n> ");
                scanf("%d", &sortOpc);
                getchar();
            } while (sortOpc != 1 && sortOpc != 2);
            if (sortOpc == 1)
                bubbleSort(vetor, tam);
            else if (sortOpc == 2)
                heapSort(vetor, tam);
            tempoMedio = 0;
            for(i=0;i<OPERACOES_MEDIA;i++)
                verificaSomaBinaria(vetor, num, tam, &tempoMedio);
            // printf("%lf\n", tempoMedio/OPERACOES_MEDIA);
            printf("Tempo de busca binaria: %lf\n", tempoMedio/OPERACOES_MEDIA);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 0:
            system("clear");
            printf("Até mais :)\n\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }

        if (opc == 0)
            break;
    }
}

int main()
{

    inicializaSrand();
    menuPrincipal();

    return 0;
}
