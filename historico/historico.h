#include "../estudante/estudante.h"

typedef struct historico {
  int tamanho;
  struct HistoricoNode *fim;
} Historico;

typedef struct HistoricoNode {
  Estudante estudante;
  struct HistoricoNode *ant;
} HistoricoNode;

Historico *criarHistorico();
void adicionarEstudanteHistorico(Historico *historico, Estudante *estudante);
void exibirHistorico(Historico *historico, char disciplina[]);