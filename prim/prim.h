#ifndef __PRIM_H__
#define __PRIM_H__

#include <stdio.h>
#include <stdlib.h>

int tamanho = 0;

void iniciaMatrizAdj(int matriz[tamanho][tamanho]);
void incluiAresta(int matriz[tamanho][tamanho], int a, int b, int peso);
void removeAresta(int matriz[tamanho][tamanho], int a, int b);
int grau(int matriz[tamanho][tamanho], int a);
void imprimeMatriz(int matriz[tamanho][tamanho]);
void imprimeAdj(int matriz[tamanho][tamanho]);
void prim(int matriz[tamanho][tamanho], int raiz);

#endif // __PRIM_H__
