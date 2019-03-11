#include <iostream>
#include <stdlib.h>
#include <queue>
#include <list>
#include <vector>

using namespace std;

typedef struct{
    int vist, ant;
}matBFS;

void inicia(matBFS info[]){
    for (int i = 0; i < 21; i++) {
        info[i].ant = -1;
        info[i].vist =  0;
    }
}

void popula(vector <int> grafoAd[]){
    grafoAd[ 0 ].push_back( 1 );
    grafoAd[ 0 ].push_back( 10 );
    grafoAd[ 1 ].push_back( 0 );
    grafoAd[ 1 ].push_back( 2 );
    grafoAd[ 1 ].push_back( 3 );
    grafoAd[ 2 ].push_back( 1 );
    grafoAd[ 2 ].push_back( 4 );
    grafoAd[ 3 ].push_back( 1 );
    grafoAd[ 3 ].push_back( 4 );
    grafoAd[ 3 ].push_back( 11 );
    grafoAd[ 4 ].push_back( 2 );
    grafoAd[ 4 ].push_back( 3 );
    grafoAd[ 4 ].push_back( 5 );
    grafoAd[ 4 ].push_back( 6 );
    grafoAd[ 5 ].push_back( 4 );
    grafoAd[ 5 ].push_back( 7 );
    grafoAd[ 6 ].push_back( 4 );
    grafoAd[ 6 ].push_back( 8 );
    grafoAd[ 7 ].push_back( 5 );
    grafoAd[ 7 ].push_back( 8 );
    grafoAd[ 7 ].push_back( 9 );
    grafoAd[ 8 ].push_back( 6 );
    grafoAd[ 8 ].push_back( 7 );
    grafoAd[ 8 ].push_back( 9 );
    grafoAd[ 9 ].push_back( 7 );
    grafoAd[ 9 ].push_back( 8 );
    grafoAd[ 9 ].push_back( 20 );
    grafoAd[ 10 ].push_back( 0 );
    grafoAd[ 10 ].push_back( 11 );
    grafoAd[ 10 ].push_back( 12 );
    grafoAd[ 10 ].push_back( 13 );
    grafoAd[ 11 ].push_back( 3 );
    grafoAd[ 11 ].push_back( 10 );
    grafoAd[ 11 ].push_back( 14 );
    grafoAd[ 12 ].push_back( 10 );
    grafoAd[ 12 ].push_back( 14 );
    grafoAd[ 13 ].push_back( 10 );
    grafoAd[ 13 ].push_back( 14 );
    grafoAd[ 14 ].push_back( 11 );
    grafoAd[ 14 ].push_back( 12 );
    grafoAd[ 14 ].push_back( 13 );
    grafoAd[ 14 ].push_back( 15 );
    grafoAd[ 14 ].push_back( 17 );
    grafoAd[ 15 ].push_back( 14 );
    grafoAd[ 15 ].push_back( 16 );
    grafoAd[ 16 ].push_back( 15 );
    grafoAd[ 16 ].push_back( 17 );
    grafoAd[ 16 ].push_back( 18 );
    grafoAd[ 16 ].push_back( 19 );
    grafoAd[ 17 ].push_back( 14 );
    grafoAd[ 17 ].push_back( 16 );
    grafoAd[ 18 ].push_back( 16 );
    grafoAd[ 18 ].push_back( 19 );
    grafoAd[ 18 ].push_back( 20 );
    grafoAd[ 19 ].push_back( 16 );
    grafoAd[ 19 ].push_back( 18 );
    grafoAd[ 19 ].push_back( 20 );
    grafoAd[ 20 ].push_back( 9 );
    grafoAd[ 20 ].push_back( 18 );
    grafoAd[ 20 ].push_back( 19 );
}

void BFS(matBFS info[], vector <int> grafoAd[], int inicio){
    queue <int> fila_Pr;
    fila_Pr.push(inicio);

    while (!fila_Pr.empty()){     //enquanto a fila não estiver vazia
        int i = fila_Pr.front();   //pega o primeiro da fila
        fila_Pr.pop();             //tira da fila
        for(int j = 0; j < grafoAd[i].size(); j++){  //percorre todas as adjacências dele
            if(info[grafoAd[i][j]].vist == 0){       //se a adjacência não foi visitada
                info[grafoAd[i][j]].vist = 1;         //marca como visitada
                info[grafoAd[i][j]].ant = i;         //seta qual é o vértice anterior a ela
                fila_Pr.push(grafoAd[i][j]);             //coloca ela na fila
            }
        }
    }
}

void print(matBFS info[], int i) {
    if(info[i].ant > 0){
        print(info, info[i].ant);
    }
    if(info[i].ant == 0){
        printf(" %c ", info[i].ant + 65);
    }
    if(i == 20){
        printf(" %c ", i + 70);
    }
    else{
        printf(" %c ", i + 65);
    }
}

int main(){

    vector <int> grafoAd[21];
    matBFS info[21];

    inicia(info);
    popula(grafoAd);
    BFS(info, grafoAd, 0);

    info[0].ant = -1;

    printf("\t┏━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t┃ Vértice ┃  Anterior ┃      Menor Caminho     ┃\n");
    printf("\t┣━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    for(int i = 0; i < 21; i++) {
        if(i == 20){
            printf("\t┃    %c    ┃     %c     ┃", i + 70, info[i].ant + 70);
        }
        else{
            printf("\t┃    %c    ┃     %c     ┃", i + 65, info[i].ant + 65);
        }
        print(info, i);
        printf("\n");
    }
    printf("\t┗━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    return 0;
}
