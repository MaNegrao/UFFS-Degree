#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define QTDVERTICES 8

typedef struct{
      short a, b, custo;
}aresta;

bool compara(aresta a, aresta b){
      return a.custo < b.custo;
}

void popula(vector <aresta> *arestas){
      //vertice, vertice, custo
      arestas->push_back({0, 1, 3});
      arestas->push_back({0, 2, 4});
      arestas->push_back({0, 3, 3});
      arestas->push_back({2, 4, 8});
      arestas->push_back({2, 5, 8});
      arestas->push_back({3, 5, 8});
      arestas->push_back({4, 6, 7});
      arestas->push_back({4, 7, 7});
      arestas->push_back({5, 6, 4});
      arestas->push_back({5, 7, 7});
      arestas->push_back({6, 7, 2});
}

// função union find: cada elemento tem um pai, e se não tiver ele é pai dele mesmo
//Verificar se dois elementos estão na mesma familia é so ver se tem o mesmo pai
int encontra(vector <int> *pai, int x){
      if((*pai)[x] == x) //se o elemento é pai dele mesmo
            return x;
      return (*pai)[x] = encontra(pai, (*pai)[x]); //recursão que acha o pai da familia, a raiz da arvore
}

//função que adiciona a aresta na árvore existente e atualiza a soma total
void une(vector <int> *pai, int peso[], short a, short b){
      a = encontra(pai, a);
      b = encontra(pai, b);

      if (peso[a] < peso[b]) 
            (*pai)[a] = b;
      else if(peso[b] < peso[a]) 
            (*pai)[b] = a;
      else{
            (*pai)[a] = b;
            peso[b]++;
      }
}

int main(){
      vector <aresta> arestas; // matriz de arestas
      vector <aresta> spanning;// arestas finais da arvore minima

      popula(&arestas); // preenche a matriz de arestas

      vector <int> pai; // vetor de pais das arvores

      int peso[arestas.size()]; //vetor de pesos (quantidade de filhos da arvore)

      for(int i = 0; i < QTDVERTICES; i++) // Define os pais iniciais como eles mesmos
            pai.push_back(i);

      sort(arestas.begin(), arestas.end(), compara); // ordena a matriz das arestas pelo peso;

      for(auto &aresta : arestas){ // percorre a aresta na matriz das arestas
            if (encontra(&pai, aresta.a) != encontra(&pai, aresta.b)){ //verifica se os vertices não estão no mesmo componente
                  une(&pai, peso, aresta.a, aresta.b); //se não estiverem, a aresta é adicionada na árvore
                  spanning.push_back(aresta); //adiciona na matriz de spanning a aresta
            }
      }

      //forma a lista de adjacencias para printar 
      vector <pair <int, int>> adjacencias[QTDVERTICES];

      for(auto &a: arestas) // pega a aresta 'a' e salva seu custo do inteiro 'a' da struct
            adjacencias[a.a].push_back({a.b, a.custo});
      for(auto &a: arestas) // pega a aresta 'a' e salva seu custo do inteiro 'b' da struct
            adjacencias[a.b].push_back({a.a, a.custo});

      printf("Lista de Adjacência:\n"); //{vertice origem} -> [vertice destino (custo)]
      for(size_t i = 0; i < QTDVERTICES; i++){
            printf("{%lu} ", i);
            for (size_t j = 0; j < adjacencias[i].size(); j++)
                  printf("-> [%d (%d)] ", adjacencias[i][j].first, adjacencias[i][j].second);
            printf("\n");
      }

      int custoTotal = 0;
      printf("\nArestas que pertencem à Arvore Geradora Mínima:\n");
      for (auto &par : spanning){
            printf("{%d, %d} (%d)\n", par.a, par.b, par.custo);
            custoTotal += par.custo;
      }
      printf("\nCusto Total da Arvore Geradora Mínima: %d\n\n", custoTotal);

      return 0;
}