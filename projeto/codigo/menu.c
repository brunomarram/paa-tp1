#include "menu.h"

int* definirTamanhoVetor(int tam){
    int *vetor = NULL;
    vetor = (int*) malloc(tam * sizeof(int));
    return vetor;
}

void resetaVetor(int *vetor, int tam){
    //gerar números aleatórios entre 0 e 100
    for(int i=0;i<tam;i++)
        vetor[i] = geraRandom(tam);
}

void imprimeVetorMain(int *vetor, int tam){
    for(int i=0;i<tam;i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void menuPrincipal(){

    int opc, tam, num;
    int *vetor = NULL;

    while(1) {
        system("clear");
        printf("Bem vindo ao verificador de Soma!\n\n");
        printf("Escolha uma das opções abaixo:\n\n");
        printf("1 - Criar vetor para testes!\n");
        printf("2 - Ordenar por bubbleSort!\n");
        printf("3 - Ordenar por heapSort!\n");
        printf("4 - Fazer pesquisa por método 1!\n");
        printf("5 - Fazer pesquisa por método 2!\n");
        printf("0 - Sair\n\n");
        printf("> ");
        scanf("%d", &opc);
        getchar();

        switch(opc) {
            case 1:
                system("clear");
                printf("Digite o tamanho do vetor: ");
                scanf("%d", &tam);
                getchar();
                vetor = definirTamanhoVetor(tam);
                resetaVetor(vetor, tam);
                printf("Um vetor com valores aleatórios será gerado\n");
                imprimeVetorMain(vetor, tam);
                printf("\nPressione enter para continuar...\n");
                getchar();
                break;
            case 2:
                //imprimeVetorMain(vetor, tam);
                bubbleSort(vetor, tam);
                printf("Ordenação concluída!\n");
                imprimeVetorMain(vetor, tam);
                printf("\nPressione enter para continuar...\n");
                getchar();
                break;
            case 3:
                heapSort(vetor, tam);
                printf("Ordenação concluída!\n");
                imprimeVetorMain(vetor, tam);
                printf("\nPressione enter para continuar...\n");
                getchar();
                break;
            case 4:
                printf("Digite o número que deseja verificar: ");
                scanf("%d", &num);
                getchar();
                metodo1(vetor, num, tam);
                printf("Ordenação concluída!\n");
                printf("\nPressione enter para continuar...\n");
                getchar();
                break;
            case 5:
                printf("Digite o número que deseja verificar: ");
                scanf("%d", &num);
                getchar();
                metodo2(vetor, num, tam);
                printf("\nPressione enter para continuar...\n");
                getchar();
                break;
            case 0:
                system("clear");
                printf("Até mais :)\n\n");
                break;
            default:
                do {
                    printf("\nOpção inválida!\n");
                    printf("\nPressione enter para digitar novamente...");
                    getchar();
                    system("clear");
                    printf("Bem vindo ao verificador de Soma!\n\n");
                    printf("Escolha uma das opções abaixo:\n\n");
                    printf("1 - Criar vetor para testes!\n");
                    printf("2 - Ordenar por bubbleSort!\n");
                    printf("3 - Ordenar por heapSort!\n");
                    printf("4 - Fazer pesquisa por método 1!\n");
                    printf("5 - Fazer pesquisa por método 2!\n");
                    printf("0 - Sair\n\n");
                    printf("> ");
                    scanf("%d", &opc);
                    getchar();
                } while (opc < 0 || opc > 5);
                switch(opc) {
                    case 1:
                        system("clear");
                        printf("Digite o tamanho do vetor: ");
                        scanf("%d", &tam);
                        getchar();
                        vetor = definirTamanhoVetor(tam);
                        resetaVetor(vetor, tam);
                        printf("Um vetor com valores aleatórios será gerado\n");
                        imprimeVetorMain(vetor, tam);
                        printf("\nPressione enter para continuar...\n");
                        getchar();
                        break;
                    case 2:
                        //imprimeVetorMain(vetor, tam);
                        bubbleSort(vetor, tam);
                        printf("Ordenação concluída!\n");
                        imprimeVetorMain(vetor, tam);
                        printf("\nPressione enter para continuar...\n");
                        getchar();
                        break;
                    case 3:
                        heapSort(vetor, tam);
                        printf("Ordenação concluída!\n");
                        imprimeVetorMain(vetor, tam);
                        printf("\nPressione enter para continuar...\n");
                        getchar();
                        break;
                    case 4:
                        printf("Digite o número que deseja verificar: ");
                        scanf("%d", &num);
                        getchar();
                        metodo1(vetor, num, tam);
                        printf("Ordenação concluída!\n");
                        printf("\nPressione enter para continuar...\n");
                        getchar();
                        break;
                    case 5:
                        printf("Digite o número que deseja verificar: ");
                        scanf("%d", &num);
                        getchar();
                        metodo2(vetor, num, tam);
                        printf("\nPressione enter para continuar...\n");
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
        if(opc==0)
            break;
    }

}

int main() {

    inicializaSrand();
    menuPrincipal();

    return 0;
}
