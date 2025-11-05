#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10 // capacidade máxima da mochila

// -----------------------------------------------------------
// Estrutura: Item
// Representa um item na mochila com nome, tipo e quantidade
// -----------------------------------------------------------
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// -----------------------------------------------------------
// Função: inserirItem()
// Adiciona um novo item na mochila (se houver espaço disponível)
// -----------------------------------------------------------
void inserirItem(struct Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\n⚠️  Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    struct Item novo;
    printf("\n🔹 CADASTRO DE NOVO ITEM 🔹\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Tipo do item (ex: arma, munição, cura): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*total] = novo;
    (*total)++;

    printf("\n✅ Item '%s' cadastrado com sucesso!\n", novo.nome);
}

// -----------------------------------------------------------
// Função: removerItem()
// Remove um item da mochila com base no nome informado
// -----------------------------------------------------------
void removerItem(struct Item mochila[], int *total) {
    if (*total == 0) {
        printf("\n⚠️  Nenhum item para remover.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n🗑️  Digite o nome do item a remover: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = -1;
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        // Desloca os itens após o removido
        for (int j = encontrado; j < *total - 1; j++) {
            mochila[j] = mochila[j + 1];
        }
        (*total)--;
        printf("\n✅ Item '%s' removido com sucesso!\n", nomeBusca);
    } else {
        printf("\n❌ Item '%s' não encontrado na mochila.\n", nomeBusca);
    }
}

// -----------------------------------------------------------
// Função: listarItens()
// Exibe todos os itens cadastrados na mochila
// -----------------------------------------------------------
void listarItens(struct Item mochila[], int total) {
    printf("\n🎒 ITENS NA MOCHILA (%d/%d):\n", total, MAX_ITENS);
    if (total == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d. %s - Tipo: %s - Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// -----------------------------------------------------------
// Função: buscarItem()
// Busca um item na mochila pelo nome (busca sequencial)
// -----------------------------------------------------------
void buscarItem(struct Item mochila[], int total) {
    if (total == 0) {
        printf("\n⚠️  A mochila está vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\n🔍 Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n✅ Item encontrado:\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\n❌ Item '%s' não encontrado.\n", nomeBusca);
}

// -----------------------------------------------------------
// Função principal (main)
// Controla o fluxo do sistema e exibe o menu interativo
// -----------------------------------------------------------
int main() {
    struct Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n=========================================\n");
        printf("🎮 SISTEMA DE MOCHILA DO JOGADOR\n");
        printf("=========================================\n");
        printf("1 - Cadastrar novo item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item pelo nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 4:
                buscarItem(mochila, total);
                break;

            case 0:
                printf("\n👋 Encerrando o sistema...\n");
                break;

            default:
                printf("\n❌ opcao inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
