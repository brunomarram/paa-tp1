#include "menu.h"

int *definirTamanhoVetor(int tam)
{
    int *vetor = NULL;
    vetor = (int *)malloc(tam * sizeof(int));
    return vetor;
}

void resetaVetor(int *vetor, int tam)
{
    //gerar números aleatórios entre 0 e 100
    for (int i = 0; i < tam; i++)
        vetor[i] = geraRandom(tam);
}

void imprimeVetorMain(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void menuPrincipal()
{

    int opc, tam, num, sortOpt;
    int *vetor = NULL;

    system("clear");
    free(vetor);
    vetor = definirTamanhoVetor(TAM_INICIAL);
    resetaVetor(vetor, TAM_INICIAL);

    while (1)
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
            printf("Digite o número que deseja verificar: ");
            scanf("%d", &num);
            getchar();
            pesquisaSequencial(vetor, num, tam);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 3:
            do
            {
                system("clear");
                printf("Escolha um metodo de ordenacao:\n\n");
                printf("1 - BubbleSort\n");
                printf("2 - HeapSort\n\n");
                printf("> ");
                scanf("%d", &sortOpt);
                getchar();
            } while (sortOpt != 1 && sortOpt != 2);

            if (sortOpt == 1)
                bubbleSort(vetor, tam);
            else
                heapSort(vetor, tam);

            printf("Digite o número que deseja verificar: ");
            scanf("%d", &num);
            getchar();
            buscaBinaria(vetor, num, tam);
            printf("\nPressione enter para continuar...");
            getchar();
            break;
        case 0:
            system("clear");
            printf("Até mais :)\n\n");
            break;
        default:
            do
            {
                printf("\nOpção inválida!\n");
                printf("\nPressione enter para digitar novamente...");
                getchar();
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
            } while (opc < 0 || opc > 5);
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
                imprimeVetorMain(vetor, tam);
                printf("\nPressione enter para continuar...");
                getchar();
                break;
            case 2:
                printf("Digite o número que deseja verificar: ");
                scanf("%d", &num);
                getchar();
                pesquisaSequencial(vetor, num, tam);
                printf("Ordenação concluída!\n");
                printf("\nPressione enter para continuar...");
                getchar();
                break;
            case 3:
                printf("Digite o número que deseja verificar: ");
                scanf("%d", &num);
                getchar();
                buscaBinaria(vetor, num, tam);
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

// case 2:
//     //imprimeVetorMain(vetor, tam);
//     bubbleSort(vetor, tam);
//     printf("Ordenação concluída!\n");
//     imprimeVetorMain(vetor, tam);
//     printf("\nPressione enter para continuar...");
//     getchar();
//     break;
// case 3:
//     heapSort(vetor, tam);
//     printf("Ordenação concluída!\n");
//     imprimeVetorMain(vetor, tam);
//     printf("\nPressione enter para continuar...");
//     getchar();
//     break;