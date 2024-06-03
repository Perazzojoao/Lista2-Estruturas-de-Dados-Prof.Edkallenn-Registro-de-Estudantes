#include "historico.h"

Historico *criarHistorico() {
  Historico *historico = (Historico *) malloc(sizeof(Historico));
  historico->tamanho = 0;
  historico->fim = NULL;
  return historico;
}

void adicionarEstudanteHistorico(Historico *historico, Estudante *estudante) {
  HistoricoNode *novo = (HistoricoNode *) malloc(sizeof(HistoricoNode));
  novo->estudante = *estudante;
  novo->ant = historico->fim;
  historico->fim = novo;
  historico->tamanho++;
}

void exibirHistorico(Historico *historico,  char disciplina[]) {
  HistoricoNode *atual = historico->fim;
    printf("------ Disciplina: %s ------\n", disciplina);
  while (atual != NULL) {
    printf("\n");
    printf("Nome: %s\n", atual->estudante.nome);
    printf("Matricula: %d\n", atual->estudante.matricula);
    printf("Nota - 1: %.2f\n", atual->estudante.notas[0]);
    printf("Nota - 2: %.2f\n", atual->estudante.notas[1]);
    printf("Nota - 3: %.2f\n", atual->estudante.notas[2]);
    printf("\n");
    atual = atual->ant;
  }
  printf("-----------------------------\n");
  
}