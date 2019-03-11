#include <stdio.h>

int main ()
{    
    int i,j,m,nm=1;
    printf("Digite um numero:\n");
    scanf("%d",&m);
    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= i; j++, nm++) 
            printf("%d ",nm);
        printf("\n");
    }
    return 0;
}