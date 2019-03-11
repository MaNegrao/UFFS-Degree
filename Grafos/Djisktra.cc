#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct{
    int visit, custo, ant;
}matDjk;


void inicializa(matDjk info[]) {
    for (int i = 0; i < 7; i++) {
        info[i].visit = 00;
        info[i].custo = 10000;
        info[i].ant = -1;
    }
}

int menor(matDjk info[], int *para) {
    int menorIndice, i, menorCusto = 1000;

    for(i = 0; i < 7; i++){ 
        if(info[i].visit == 0){ 
            break;
        }
    }    

    if(i == 7){
        *para = 1;
        return 0;
    }

    for(i = 0; i < 7; i++){
        if((info[i].custo < menorCusto) && (info[i].visit == 0)){
            menorCusto = info[i].custo;
            menorIndice = i;
        }
    }

    return menorIndice;
}

void dijkstra(int grafo[7][7], matDjk info[], int vertice){
    // marcar vértice como visitado
    info[vertice].visit = 1;

    //percorrer para registrar custo e vértice anterior
    for(int i = 0; i < 7; i++){
        if((grafo[vertice][i] > 0) && (info[i].visit == 0) && (info[vertice].custo + grafo[vertice][i] < info[i].custo)){
            info[i].custo = grafo[vertice][i] + info[vertice].custo;
            info[i].ant = vertice;
        }
    }

    // repetir o processo para o menor filho não visitado
    int para = 0, prox = menor(info, &para);
    if(!para) dijkstra(grafo, info, prox);
}

void print(matDjk info[], int indice){
    if(info[indice].ant > 0){
        print(info, info[indice].ant);
    }
    if(info[indice].ant == 0){
        printf(" %c ", info[indice].ant + 65);
    }
    printf(" %c ", indice + 65);
}

int main(){
    int grafoAd[7][7] = {   0, 7, 0,  5,  0,  0,  0,
                        7, 0, 8,  9,  7,  0,  0,
                        0, 8, 0,  0,  5,  0,  0,
                        5, 9, 0,  0, 15,  8,  0,
                        0, 7, 5, 15,  0,  8,  9,
                        0, 0, 0,  8,  8,  0, 11,  
                        0, 0, 0,  0,  9, 11,  0 };
    
    matDjk info[7];
    inicializa(info);

    info[0].custo = 0;
    dijkstra(grafoAd, info, 0);

    printf("\t┏━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┓\n");
    printf("\t┃ Vértice ┃ Anterior  ┃   Custo   ┃  Menor Caminho  ┃\n");
    printf("\t┣━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    for(int i = 0; i < 7; i++){
        printf("\t┃    %c    ┃     %c     ┃ %5d     ┃", i + 65, info[i].ant + 65, info[i].custo);
        print(info, i);
        printf("\n");
    }
    printf("\t┗━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┛\n");
    return 0;
}