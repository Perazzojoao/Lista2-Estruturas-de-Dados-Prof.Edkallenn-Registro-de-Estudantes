#include "../estudante/estudante.h"

#define DISCIPLINA1 "Matemática"
#define DISCIPLINA2 "Português"

typedef struct FilaMatricula {
  int tamanho;
  struct DisciplinaNode *inicio;
  struct DisciplinaNode *fim;
} FilaMatricula;

typedef struct DisciplinaNode {
  Estudante estudante;
  struct DisciplinaNode *prox;
  struct DisciplinaNode *ant;
} DisciplinaNode;

FilaMatricula *criarFilaMatricula();
void inserirEstudanteMatricula(FilaMatricula *fila, Estudante estudante);
void removerEstudanteMatricula(FilaMatricula *fila, ListaEstudantes *lista);
void exibirFilaMatricula(FilaMatricula *fila);