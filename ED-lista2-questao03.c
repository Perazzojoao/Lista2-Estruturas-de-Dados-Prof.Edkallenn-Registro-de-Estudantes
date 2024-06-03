/*
** Função: Sistema de Registro de Estudantes
** Autor: João Victor Barbosa Perazzo
** Data: 01/06/2024
** Observações:
*/

#include <locale.h>
#include "historico/historico.h"
#include "matricula/matricula.h"
#include "estudante/estudante.h"

void menu();
void menuEstudantes();
void menuMatriculas();
void matricularEstudante(FilaMatricula *filaMatricula);
void exibirMediasEstudantes(ListaEstudantes *listaEstudantes);

int main() {
  setlocale(LC_ALL, "Portugese");

  Historico *historico = criarHistorico();
  FilaMatricula *filaMatricula = criarFilaMatricula();
  ListaEstudantes *listaEstudantes = criarListaEstudantes();

  int opcao;
  do {
    menu();
    printf("Opção: ");
    scanf("%d", &opcao);
    fflush(stdin);
    switch (opcao) {
      case 1:
        do {
          int matricula;
          menuEstudantes();
          printf("Opção: ");
          scanf("%d", &opcao);
          fflush(stdin);
          switch (opcao) {
            case 1:
              exibirListaEstudantes(listaEstudantes);
              break;
            case 2:
              printf("Informe a matrícula do estudante:\n");
              printf("Matrícula: ");
              scanf("%d", &matricula);
              fflush(stdin);
              removerEstudanteLista(listaEstudantes, matricula);
              break;
            case 3:
              printf("Informe a matrícula do estudante:\n");
              printf("Matrícula: ");
              scanf("%d", &matricula);
              fflush(stdin);
              Estudante *estudante1 = buscarEstudanteLista(listaEstudantes, matricula);
              if (estudante1 == NULL) {
                free(estudante1);
                break;
              }
              printf("\n");
              printf("Nome: %s\n", estudante1->nome);
              printf("Disciplina: %s\n", estudante1->disciplina);
              printf("Nota 1: %.2f\n", estudante1->notas[0]);
              printf("Nota 2: %.2f\n", estudante1->notas[1]);
              printf("Nota 3: %.2f\n", estudante1->notas[2]);
              printf("\n");

              break;
            case 4:
              printf("Informe a matrícula do estudante:\n");
              printf("Matrícula: ");
              scanf("%d", &matricula);
              fflush(stdin);
              Estudante *estudante = buscarEstudanteLista(listaEstudantes, matricula);
              if (estudante == NULL) {
                free(estudante);
                break;
              }

              float notas[3];
              printf("Informe as novas notas:\n");
              for (int i = 0; i < 3; i++) {
                printf("Nota %d: ", i + 1);
                scanf("%f", &notas[i]);
                fflush(stdin);
              }
              adicionarEstudanteHistorico(historico, estudante);
              atualizarNotasEstudante(estudante, notas);
              break;
            case 5:
              exibirMediasEstudantes(listaEstudantes);
              break;
            case 6:
              break;
            default:
              printf("Opção inválida!\n");
              break;
          }
          if (opcao == 6) {
            break;
          }
        } while (1);
        break;
      case 2:
        do {
          menuMatriculas();
          printf("Opção: ");
          scanf("%d", &opcao);
          fflush(stdin);
          switch (opcao) {
            case 1:
              exibirFilaMatricula(filaMatricula);
              break;
            case 2:
              matricularEstudante(filaMatricula);
              break;
            case 3:
              removerEstudanteMatricula(filaMatricula, listaEstudantes);
              break;
            case 4:
              break;
            default:
              printf("Opção inválida!\n");
              break;
          }
          if (opcao == 4) {
            break;
          }
        } while (1);
        break;
      case 3: ;
        char disciplina[20];
        printf("Informe a disciplina: ");
        scanf("%s", disciplina);
        exibirHistorico(historico, disciplina);
        break;
      case 4:
        return 0;
      case 5:
        return 0;
      default:
        printf("Opção inválida!\n");
        break;
    }
  } while (1);

  return 0;
}

void menu() {
  printf("\n");
  printf("1 - Estudantes\n");
  printf("2 - Matrículas\n");
  printf("3 - Histórico\n");
  printf("4 - Mais opções\n");
  printf("5 - Sair\n");
  printf("\n");
}

void menuEstudantes() {
  printf("\n");
  printf("1 - Exibir estudantes\n");
  printf("2 - Remover estudante\n");
  printf("3 - Buscar estudante\n");
  printf("4 - Atualizar notas\n");
  printf("5 - Relatório de médias\n");
  printf("6 - Voltar\n");
  printf("\n");
}

void menuMatriculas() {
  printf("\n");
  printf("1 - Exibir fila de matrícula\n");
  printf("2 - Matricular estudante\n");
  printf("3 - Andar fila de matrícula\n");
  printf("4 - Voltar\n");
  printf("\n");
}

void matricularEstudante(FilaMatricula *filaMatricula) {
  char nome[50], disciplina[20];
  float notas[3];
  printf("Nome: ");
  scanf("%s", nome);
  fflush(stdin);
  printf("Disciplina: ");
  scanf("%s", disciplina);
  fflush(stdin);
  printf("Nota 1: ");
  scanf("%f", &notas[0]);
  fflush(stdin);
  printf("Nota 2: ");
  scanf("%f", &notas[1]);
  fflush(stdin);
  printf("Nota 3: ");
  scanf("%f", &notas[2]);
  fflush(stdin);
  Estudante estudante = cadastrarEstudante(nome, disciplina, notas);
  inserirEstudanteMatricula(filaMatricula, estudante);
}

void exibirMediasEstudantes(ListaEstudantes *listaEstudantes) {
  printf("\n");
  printf("------ Médias dos estudantes ------\n");
  printf("\n");
  calcularMediaEstudantes(listaEstudantes);
  printf("\n");
}