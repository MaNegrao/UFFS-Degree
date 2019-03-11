#include <stdio.h>

int main ()
{    
    int i,j,m,n=1;
    printf("Digite um numero:\n");
    scanf("%d",&m);
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= i; j++, n++) 
            printf( (n%2 == 0) ? "P" : "Q");
        printf("\n");
    }
    return 0;
}