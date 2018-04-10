#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k=0,l=1;
    float a,x,y;

    printf("Podaj liczbe pomiarow n i liczbe a:\n");
    scanf("%d%f", &n,&a);
    float **tab;
    tab=(float**)malloc(n+1*sizeof(float *));
    for(i=0;i<n+1;i++)
    {
        tab[i]=(float*)malloc(n+2*sizeof(float));
    }
    for (i=0;i<n+1;i++)
    {
        for (j=0;j<n+2;j++)
        {
            tab[i][j]=0;
        }
    }

    for (i=0;i<n+1;i++)
    {
        printf("Podaj %d wiersz tablicy, najpierw x potem y: \n", i);
        scanf("%f",&x);
        tab[i][0]=x;
        scanf("%f",&y);
        tab[i][1]=y;
    }

    for (i=1;i<n+1;i++)
    {
        for (j=2;j<i+2;j++)
        {
            tab[i][j]=(1/(tab[l][0]-tab[k][0]))*((tab[i][j-1]*(tab[l][0]-a))-(tab[i+1][j]*(tab[k][0]-a)));
            k++;
        }
        l++;
        k=0;
    }

    printf("Wspolczynniki: \n");

    for (i=1;i<n+1;i++)
    {
        printf("%f ", tab[i][i+1]);
    }

    return 0;
}
