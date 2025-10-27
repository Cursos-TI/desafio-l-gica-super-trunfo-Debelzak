#include <stdio.h>
#include <stdbool.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

struct Carta {
    char id_estado[2];
    char codigo[4];
    char nome[21];
    unsigned long populacao;
    float area;
    float pib;
    float pib_per_capita;
    int pontos_turisticos;
    float densidade_populacional;
    float super_poder;
};

struct Carta nova_carta() {
    struct Carta carta;
    printf("- Digite o identificador de estado: (Ex: A)\n");
    scanf(" %1s", carta.id_estado);
    printf("- Digite o código da carta: (Ex: A01)\n");
    scanf(" %3s", carta.codigo);
    printf("- Digite o nome da carta: (Ex: Rio de Janeiro)\n");
    scanf(" %20[^\n]", carta.nome);
    printf("- Digite o número da população: (Ex: 1600000)\n");
    scanf("%lu", &carta.populacao);
    printf("- Digite a área em km²: (Ex: 1200.50)\n");
    scanf("%f", &carta.area);
    printf("- Digite o PIB: (Ex: 949300000000)\n");
    scanf("%f", &carta.pib);
    printf("- Digite o número de pontos turísticos: (Ex: 100)\n");
    scanf("%d", &carta.pontos_turisticos);
    carta.pib_per_capita = carta.pib / (float)carta.populacao;
    carta.densidade_populacional = (float)carta.populacao / carta.area;
    carta.super_poder = carta.populacao + carta.area + carta.pib + carta.pib_per_capita + ((float)1 / carta.densidade_populacional) + carta.pontos_turisticos;

    return carta;
}

void exibir_carta(struct Carta carta) {
    printf("===== [%s] %s =====\n", carta.codigo, carta.nome);
    printf("- População: %ld habitantes\n", carta.populacao);
    printf("- Área: %.2fkm²\n", carta.area);
    printf("- Densidade Populacional: %.2f habitantes/km²\n", carta.densidade_populacional);
    printf("- PIB: R$%.2f bilhões\n", carta.pib/1000000000);
    printf("- PIB (per capita): R$%.2f mil\n", carta.pib_per_capita/1000);
    printf("- Pontos turísticos: %d+\n", carta.pontos_turisticos);
    printf("- Super Poder: %.2f\n", carta.super_poder);
}

int comparar_atributo(struct Carta carta1, struct Carta carta2) {
    // Retorna 1 se carta 1 vencer, 2 se carta 2 vencer, 0 se empate. -1 para opção inválida.
    printf("Selecione o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. Densidade Populacional\n");
    printf("4. PIB\n");
    printf("5. PIB (per capita)\n");
    printf("6. Pontos turísticos\n");
    printf("7. Super Poder\n");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha) {
        case 1:
            return carta1.populacao > carta2.populacao ? 1 : 
                   carta1.populacao < carta2.populacao ? 2 : 0;
        case 2:
            return carta1.area > carta2.area ? 1 : 
                   carta1.area < carta2.area ? 2 : 0;
        case 3:
            return carta1.densidade_populacional > carta2.densidade_populacional ? 1 : 
                   carta1.densidade_populacional < carta2.densidade_populacional ? 2 : 0;
        case 4:
            return carta1.pib > carta2.pib ? 1 : 
                   carta1.pib < carta2.pib ? 2 : 0;
        case 5:
            return carta1.pib_per_capita > carta2.pib_per_capita ? 1 : 
                   carta1.pib_per_capita < carta2.pib_per_capita ? 2 : 0;
        case 6:
            return carta1.pontos_turisticos > carta2.pontos_turisticos ? 1 : 
                   carta1.pontos_turisticos < carta2.pontos_turisticos ? 2 : 0;
        case 7:
            return carta1.super_poder > carta2.super_poder ? 1 : 
                   carta1.super_poder < carta2.super_poder ? 2 : 0;
        default:
            printf("Opção inválida.\n");
            return -1;
    }
}

int comparar_atributos(struct Carta carta1, struct Carta carta2, bool atributos_usados[]) {
    printf("Selecione o atributo para comparar:\n");
    for(int i = 1; i <= 7; i++) {
        if (!atributos_usados[i]) {
            switch(i) {
                case 1: printf("%d. População\n", i); break;
                case 2: printf("%d. Área\n", i); break;
                case 3: printf("%d. Densidade Populacional\n", i); break;
                case 4: printf("%d. PIB\n", i); break;
                case 5: printf("%d. PIB (per capita)\n", i); break;
                case 6: printf("%d. Pontos turísticos\n", i); break;
                case 7: printf("%d. Super Poder\n", i); break;
            }
        }
    }
    
    int escolha;
    scanf("%d", &escolha);
    
    if (escolha < 1 || escolha > 7 || atributos_usados[escolha]) {
        printf("Opção inválida ou atributo já usado.\n");
        return -1;
    }
    
    atributos_usados[escolha] = true;
    
    switch (escolha) {
        case 1:
            return carta1.populacao > carta2.populacao ? 1 : 
                   carta1.populacao < carta2.populacao ? 2 : 0;
        case 2:
            return carta1.area > carta2.area ? 1 : 
                   carta1.area < carta2.area ? 2 : 0;
        case 3:
            return carta1.densidade_populacional > carta2.densidade_populacional ? 1 : 
                   carta1.densidade_populacional < carta2.densidade_populacional ? 2 : 0;
        case 4:
            return carta1.pib > carta2.pib ? 1 : 
                   carta1.pib < carta2.pib ? 2 : 0;
        case 5:
            return carta1.pib_per_capita > carta2.pib_per_capita ? 1 : 
                   carta1.pib_per_capita < carta2.pib_per_capita ? 2 : 0;
        case 6:
            return carta1.pontos_turisticos > carta2.pontos_turisticos ? 1 : 
                   carta1.pontos_turisticos < carta2.pontos_turisticos ? 2 : 0;
        case 7:
            return carta1.super_poder > carta2.super_poder ? 1 : 
                   carta1.super_poder < carta2.super_poder ? 2 : 0;
        default:
            return -1;
    }
}

int main() {
    // Primeiro faz o cadastro de duas cartas
    printf("===== Registrando primeira carta =====\n");
    struct Carta carta1 = nova_carta();
    int carta1_vitorias = 0;

    printf("===== Registrando segunda carta =====\n");
    struct Carta carta2 = nova_carta();
    int carta2_vitorias = 0;

    // Exibe as cartas cadastradas
    printf("\n===== Primeira carta =====\n");
    exibir_carta(carta1);

    printf("\n===== Segunda carta =====\n");
    exibir_carta(carta2);

    // Compara dois atributos escolhido pelo jogador
    bool atributos_usados[8] = {false}; // Array para controlar atributos já usados

    int primeira_comparacao = comparar_atributos(carta1, carta2, atributos_usados);
    while(primeira_comparacao == -1) {
        primeira_comparacao = comparar_atributos(carta1, carta2, atributos_usados);
    }
    carta1_vitorias += (primeira_comparacao == 1) ? 1 : 0;
    if (primeira_comparacao == 1) printf("Carta 1 venceu a primeira comparação!\n");
    carta2_vitorias += (primeira_comparacao == 2) ? 1 : 0;
    if (primeira_comparacao == 2) printf("Carta 2 venceu a primeira comparação!\n");

    int segunda_comparacao = comparar_atributos(carta1, carta2, atributos_usados);
    while(segunda_comparacao == -1) {
        segunda_comparacao = comparar_atributos(carta1, carta2, atributos_usados);
    }
    carta1_vitorias += (segunda_comparacao == 1) ? 1 : 0;
    if (segunda_comparacao == 1) printf("Carta 1 venceu a segunda comparação!\n");
    carta2_vitorias += (segunda_comparacao == 2) ? 1 : 0;
    if (segunda_comparacao == 2) printf("Carta 2 venceu a segunda comparação!\n");

    // Exibe o resultado final
    printf("Resultado Final:\n");
    if (carta1_vitorias > carta2_vitorias) {
        printf("Carta 1 venceu!\n");
    } else if (carta2_vitorias > carta1_vitorias) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("O resultado foi empate!\n");
    }

    return 0;
}