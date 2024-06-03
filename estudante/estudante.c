#include "estudante.h"

Estudante cadastrarEstudante(char nome[], char disciplina[], float notas[]) {
  Estudante estudante;
  srand(time(NULL));
  estudante.matricula = (rand() % 1000) + 1000;
  strcpy(estudante.nome, nome);
  strcpy(estudante.disciplina, disciplina);
  for (int i = 0; i < 3; i++) {
    estudante.notas[i] = notas[i];
  }
  return estudante;
}

ListaEstudantes *criarListaEstudantes() {
  ListaEstudantes *lista = (ListaEstudantes *) malloc(sizeof(ListaEstudantes));
  lista->tamanho = 0;
  lista->inicio = NULL;
  lista->fim = NULL;
  return lista;
}

void inserirEstudanteLista(ListaEstudantes *lista, Estudante estudante) {
  EstudanteNode *novo = (EstudanteNode *) malloc(sizeof(EstudanteNode));
  novo->estudante = estudante;
  novo->prox = NULL;
  novo->ant = lista->fim;
  if (lista->fim != NULL) {
    lista->fim->prox = novo;
  }
  lista->fim = novo;
  if (lista->inicio == NULL) {
    lista->inicio = novo;
  }
  lista->tamanho++;
}

void removerEstudanteLista(ListaEstudantes *lista, int matricula) {
  EstudanteNode *atual = lista->inicio;
  while (atual != NULL) {
    if (atual->estudante.matricula == matricula) {
      if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
      } else {
        lista->inicio = atual->prox;
      }
      if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
      } else {
        lista->fim = atual->ant;
      }
      free(atual);
      lista->tamanho--;
      return;
    }
    atual = atual->prox;
  }
  printf("Estudante não encontrado!\n");
}

void exibirListaEstudantes(ListaEstudantes *lista) {
  if (lista->tamanho == 0) {
    printf("\n");
    printf("Lista de estudantes vazia!\n");
    return;
  }

  int i = 0;
  EstudanteNode *atual = lista->inicio;
  while (atual != NULL) {
    printf("\n");
    printf("------ Estudante %d ------\n", ++i);
    printf("Matrícula: %d\n", atual->estudante.matricula);
    printf("Nome: %s\n", atual->estudante.nome);
    printf("Disciplina: %s\n", atual->estudante.disciplina);
    printf("Notas: %.2f, %.2f, %.2f\n", atual->estudante.notas[0], atual->estudante.notas[1], atual->estudante.notas[2]);
    printf("-------------------------\n");
    atual = atual->prox;
  }
}

Estudante *buscarEstudanteLista(ListaEstudantes *lista, int matricula) {
  EstudanteNode *atual = lista->inicio;
  while (atual != NULL) {
    if (atual->estudante.matricula == matricula) {
      return &atual->estudante;
    }
    atual = atual->prox;
  }
  printf("Estudante não encontrado!\n");
  return NULL;
}

void atualizarNotasEstudante(Estudante *estudante, float notas[]) {
  for (int i = 0; i < 3; i++) {
    estudante->notas[i] = notas[i];
  }
}

void calcularMediaEstudantes(ListaEstudantes *lista) {
  EstudanteNode *atual = lista->inicio;
  while (atual != NULL) {
    float media = 0;
    for (int i = 0; i < 3; i++) {
      media += atual->estudante.notas[i];
    }
    media /= 3;
    printf("Média do estudante %d: %.2f\n", atual->estudante.matricula, media);
    atual = atual->prox;
  }
}

void liberarListaEstudantes(ListaEstudantes *lista) {
  EstudanteNode *atual = lista->inicio;
  while (atual != NULL) {
    EstudanteNode *prox = atual->prox;
    free(atual);
    atual = prox;
  }
  free(lista);
}