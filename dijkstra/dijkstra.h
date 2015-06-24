#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <stdio.h>
#include <stdlib.h>


int tamanho = 0;

void iniciaMatrizAdj(int matriz[tamanho][tamanho]);
void incluiAresta(int matriz[tamanho][tamanho], int a, int b, int peso);
void removeAresta(int matriz[tamanho][tamanho], int a, int b);
int grau(int matriz[tamanho][tamanho], int a);
void imprimeMatriz(int matriz[tamanho][tamanho]);
void imprimeAdj(int matriz[tamanho][tamanho]);
void dijkstra(int matriz[tamanho][tamanho], int origem);

#endif // __DIJKSTRA_H__
