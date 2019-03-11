#include <stdio.h>

void gulosoAdj1(int mat[5][5], int path[]){
    for(int i = 0; i < 5; path[i] = 0, i++);

    int i = 0;
    for(int k = 1; k <= 5; k++){
        path[0] = 1;
        int smaller_edge = 1000000;
        int smaller_col_edge;
        for(int j = 0; j < 5; j++){
            if (mat[i][j] < smaller_edge && mat[i][j] > 0) {
                smaller_edge = mat[i][j];
                smaller_col_edge = j;
            }
        }
        i = smaller_col_edge;
        path[k] = smaller_col_edge + 1;
    }
}

void gulosoInc1(int mat[5][8], int path[]){
    for (int i = 0; i < 5; path[i] = 0, i++);

    int i = 0;
    for (int k = 1; k <= 5; k++) {
        path[0] = 1;
        int smaller_edge = 1000000;
        int smaller_col_edge;
        for (int j = 0; j < 8; j++) {
            if (mat[i][j] < smaller_edge && mat[i][j] > 0) {
                smaller_edge = mat[i][j];
                smaller_col_edge = j;
            }
        }
        for (int j = 0; j < 5; j++){
            if (mat[j][smaller_col_edge] != 0 && j != i){
                i = j;
                path[k] = j + 1;
                break;
            }
        }
    }
}

void gulosoAdj2(int mat[7][7], int path[]){
    for (int i = 0; i < 7; path[i] = 0, i++);

    int i = 0;
    for (int k = 1; k <= 7; k++) {
        path[0] = 1;
        int smaller_edge = 1000000;
        int smaller_col_edge;
        for (int j = 0; j < 7; j++) {
            if (mat[i][j] < smaller_edge && mat[i][j] > 0) {
                smaller_edge = mat[i][j];
                smaller_col_edge = j;
            }
        }
        i = smaller_col_edge;
        path[k] = smaller_col_edge + 1;
    }
}

void gulosoInc2(int mat[7][9], int path[]){
    for (int i = 0; i < 7; path[i] = 0, i++);
        
    int i = 0;
    for (int k = 1; k <= 7; k++) {
        path[0] = 1;
        int smaller_edge = 1000000;
        int smaller_col_edge;
        for (int j = 0; j < 9; j++) {
            if (mat[i][j] < smaller_edge && mat[i][j] > 0) {
                smaller_edge = mat[i][j];
                smaller_col_edge = j;
            }
        }
        for (int j = 0; j < 7; j++){
            if (mat[j][smaller_col_edge] != 0 && j != i){
                i = j;
                path[k] = j + 1;
                break;
            }
        }
    }
}

void main(void){

    int i, matAdj1[5][5], path_Adj1[5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) 
            scanf("%d", &matAdj1[i][j]);
    }
    gulosoAdj1(matAdj1, path_Adj1);
    
    printf("Caminho encontrado pela Matriz de Adjacência 1: ");
    for(i = 0; i < 5; i++) 
        printf("- %d ", path_Adj1[i]);
    printf("\n\n");

    int matInc1[5][8], path_Inc1[5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++)
            scanf("%d", &matInc1[i][j]);
    }
    gulosoInc1(matInc1, path_Inc1);
    
    printf("Caminho encontrado pela Matriz de Incidência 1: ");
    for(i = 0; i < 5; i++)
        printf("- %d ", path_Inc1[i]);
    printf("\n\n");

    int matAdj2[7][7], path_Adj2[7];
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++)
            scanf("%d", &matAdj2[i][j]);
    }
    gulosoAdj2(matAdj2, path_Adj2);

    printf("Caminho encontrado pela Matriz de Adjacência 2: ");
    for(i = 0; i < 7-3; i++)
        printf("- %d ", path_Adj2[i]);
    printf("\n\n");

    int matInc2[7][9], path_Inc2[7];
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 9; j++)
            scanf("%d", &matInc2[i][j]);
    }
    gulosoInc2(matInc2, path_Inc2);

    printf("Caminho encontrado pela Matriz de Incidência 2: ");
    for(i = 0; i < 7-3; i++) 
        printf("- %d ", path_Inc2[i]);
    printf("\n\n");
}