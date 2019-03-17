#include <stdio.h>
#include <stdlib.h>

int area(int x1, int y1, int x2, int y2, int x3, int y3){
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y){   
   int A = area (x1, y1, x2, y2, x3, y3);
   int A1 = area (x, y, x2, y2, x3, y3);  
   int A2 = area (x1, y1, x, y, x3, y3);   
   int A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

int main(void){
   int x[3], y[3];
   printf("Digite os valores do primeiro vertice: \n");
   scanf("%d %d", &y[0], &x[0]);
   printf("Digite os valores do segundo vertice: \n");
   scanf("%d %d", &y[1], &x[1]);
   printf("Digite os valores do terceiro vertice: \n");
   scanf("%d %d", &y[2], &x[2]);
   system("clear");
   for(int i = 0; i < 50; i++){
      for(int j = 0; j < 50; j++){
         printf(isInside(y[0], x[0], y[1], x[1], y[2], x[2], i, j) ? "*" : " ");
      }
      printf("\n");
   }
   return 0;
}