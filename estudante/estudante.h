#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Estudante {
  int matricula;
  char nome[50];
  char disciplina[20];
  float notas[3];
} Estudante;

typedef struct ListaEstudantes {
  int tamanho;
  struct EstudanteNode *inicio;
  struct EstudanteNode *fim;
} ListaEstudantes;

typedef struct EstudanteNode {
  Estudante estudante;
  struct EstudanteNode *prox;
  struct EstudanteNode *ant;
} EstudanteNode;

Estudante cadastrarEstudante(char nome[], char disciplina[], float notas[]);
ListaEstudantes *criarListaEstudantes();
void inserirEstudanteLista(ListaEstudantes *lista, Estudante estudante);
void removerEstudanteLista(ListaEstudantes *lista, int matricula);
void exibirListaEstudantes(ListaEstudantes *lista);
Estudante *buscarEstudanteLista(ListaEstudantes *lista, int matricula);
void atualizarNotasEstudante(Estudante *estudante, float notas[]);
void calcularMediaEstudantes(ListaEstudantes *lista);
void liberarListaEstudantes(ListaEstudantes *lista);

#endif