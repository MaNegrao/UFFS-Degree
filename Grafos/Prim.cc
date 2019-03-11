#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair <int, int> par; // o primeiro representa distancia e o segundo o vertice     

#define MAX 10100
#define INFINITO 99999
#define QTDVERTICES 8

void prim(vector <par> vizinhos[]){
      par arestas[MAX]; //arestas
      int distancias[MAX], visitado[MAX];

      for(int i = 0; i < QTDVERTICES; i++) //zeramos os vetores
            distancias[i] = INFINITO;

	distancias[0] = 0; //definição padrão

      //fila de prioridade com o menor peso no topo
      priority_queue <par, vector<par>, greater<par>> fila;
	fila.push(par(distancias[0], 0));

      while(true){
            int davez = -1;
            //seleciona o próximo vértice
            while(!fila.empty()){ //enquanto a fila estiver com algo
			int atual = fila.top().second; // pega o atual 
			fila.pop(); //tira da fila
			if(!visitado[atual]){ //verifica se o vértice não foi visitado
				davez = atual;
				break;
			}
		}
            if(davez == -1) 
                  break; //todos visitados, fim do algoritmo

            visitado[davez] = true; //marca como visitado

            //atualiza as distancias
            for(int i = 0; i < (int) vizinhos[davez].size();i++){
			int dist  = vizinhos[davez][i].first; //nova distancia
			int atual = vizinhos[davez][i].second;
			if( distancias[atual] > dist && !visitado[atual]){
				distancias[atual] = dist; //atualiza a distancia
                        arestas[atual] = par(atual, davez); // salva par da vez
				fila.push(par(distancias[atual], atual)); //insere na fila
			}
		}
      }

      printf("\nArestas que pertencem à Arvore Geradora Mínima:\n");
      int custoTotal = 0;
      for (int i = 0; i < 8; i++) {
            custoTotal += distancias[i];
            if (arestas[i].first != 0 || 0 != arestas[i].second) {
                  printf("{%d, %d} (%d)\n", arestas[i].second, arestas[i].first, distancias[i]);
            }
      }
      printf("\nCusto Total da Arvore Geradora Mínima: %d\n\n", custoTotal);
}

void popula(vector <par> adj[]){
      //vertice origem, custo, "vertice destino"
      adj[0].push_back({2, 1});
      adj[0].push_back({6, 3});
      adj[0].push_back({5, 4});

      adj[1].push_back({2, 0});
      adj[1].push_back({7, 2});
      adj[1].push_back({7, 3});

      adj[2].push_back({7, 1});
      adj[2].push_back({6, 4});
      adj[2].push_back({2, 5});

      adj[3].push_back({6, 0});
      adj[3].push_back({7, 1});

      adj[4].push_back({5, 0});
      adj[4].push_back({6, 2});
      adj[4].push_back({4, 6});
      adj[4].push_back({5, 7});

      adj[5].push_back({2, 2});
      adj[5].push_back({4, 6});
      adj[5].push_back({6, 7});

      adj[6].push_back({4, 4});
      adj[6].push_back({4, 5});
      adj[6].push_back({1, 7});

      adj[7].push_back({5, 4});
      adj[7].push_back({6, 5});
      adj[7].push_back({1, 6});
}

int main(){
      vector <par> vizinhos[QTDVERTICES];

      popula(vizinhos);

      printf("Lista de Adjacência:\n");
      for(int i = 0; i < QTDVERTICES; i++){
            printf("{%d} ", i);
            for (size_t j = 0; j < vizinhos[i].size(); j++) {
                  printf("-> [%d (%d)] ", vizinhos[i][j].second, vizinhos[i][j].first);
            }
            printf("\n");
      }

      prim(vizinhos);
	return 0;
}