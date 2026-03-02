#include <stdio.h>
#include <stdlib.h>

// Definição de constantes para tamanhos máximos
#define MAX_NAME 30
#define MAX_COLOR 10
#define MAX_TERRITORIOS 5

// Estrutura para representar um território
struct Territorio{
    char nome[MAX_NAME];
    char corDoExercito[MAX_COLOR];
    int qtdDeTropas;
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main(void) {
    // Array para armazenar os territórios cadastrados
    struct Territorio territorios[MAX_TERRITORIOS];
    // Variável para contar o número total de territórios cadastrados
    int totalTerritorios = 0;


    // Exibição de mensagem de boas-vindas
    printf("##################################################\n");
    printf("Bem-vindo ao jogo de tabuleiro War!\n");
    printf("##################################################\n");

    // Loop para cadastrar os territórios
    do{
        printf("Cadastro de Territórios\n");
        for (int i = 0; i < MAX_TERRITORIOS; i++) {
            // Solicitação de dados para cada território
            printf("Digite o nome do território %d: ", i + 1);
            fgets(territorios[i].nome, MAX_NAME, stdin);
            printf("Digite a cor do exército para o território %d: ", i + 1);
            fgets(territorios[i].corDoExercito, MAX_COLOR, stdin);
            printf("Digite a quantidade de tropas para o território %d: ", i + 1);
            scanf("%d", &territorios[i].qtdDeTropas);
            limparBuffer();

            // Incremento do contador de territórios cadastrados
            totalTerritorios++;

            // Exibição dos dados do território cadastrado
            printf("\nTerritório %d cadastrado com sucesso!\n", i + 1);

            printf("\n--------------------------------------------------\n");
            printf("Dados do território %d:\n", i + 1);
            printf("Território: %s", territorios[i].nome);
            printf("Cor do Exército: %s", territorios[i].corDoExercito);
            printf("Quantidade de Tropas: %d\n", territorios[i].qtdDeTropas);
            printf("\n--------------------------------------------------\n");

            // Verificação se o número máximo de territórios foi atingido
            if (totalTerritorios >= MAX_TERRITORIOS) {
                printf("Número máximo de territórios cadastrados!\n");
                break;
            }
        }


    } while (totalTerritorios < MAX_TERRITORIOS); // Condição para continuar cadastrando territórios

    return 0; // Retorno indicando que o programa terminou com sucesso
}