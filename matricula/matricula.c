#include "matricula.h"

FilaMatricula *criarFilaMatricula() {
  FilaMatricula *fila = (FilaMatricula *) malloc(sizeof(FilaMatricula));
  fila->tamanho = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

void inserirEstudanteMatricula(FilaMatricula *fila, Estudante estudante) {
  DisciplinaNode *novo = (DisciplinaNode *) malloc(sizeof(DisciplinaNode));
  novo->estudante = estudante;
  novo->prox = NULL;
  novo->ant = fila->fim;
  if (fila->fim != NULL) {
    fila->fim->prox = novo;
  }
  fila->fim = novo;
  if (fila->inicio == NULL) {
    fila->inicio = novo;
  }
  fila->tamanho++;
}

void removerEstudanteMatricula(FilaMatricula *fila, ListaEstudantes *lista) {
  if (fila->tamanho == 0) {
    printf("Fila vazia!\n");
    return;
  }
  DisciplinaNode *removido = fila->inicio;
  fila->inicio = removido->prox;
  if (fila->inicio != NULL) {
    fila->inicio->ant = NULL;
  }
  if (removido == fila->fim) {
    fila->fim = NULL;
  }
  inserirEstudanteLista(lista, removido->estudante);
  free(removido);
  fila->tamanho--;
}

void exibirFilaMatricula(FilaMatricula *fila) {
  if (fila->tamanho == 0) {
    printf("\n");
    printf("Fila de matrícula vazia!\n");
    return;
  }
  int i = 0;
  DisciplinaNode *atual = fila->inicio;
  while (atual != NULL) {
    printf("\n");
    printf("------ Estudante %d ------\n", ++i);;
    printf("Matrícula: %d\n", atual->estudante.matricula);
    printf("Nome: %s\n", atual->estudante.nome);
    printf("Disciplina: %s\n", atual->estudante.disciplina);
    printf("Notas: %.2f, %.2f, %.2f\n", atual->estudante.notas[0], atual->estudante.notas[1], atual->estudante.notas[2]);
    printf("--------------------------\n");
    atual = atual->prox;
  }
}