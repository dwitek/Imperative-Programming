#include <stdio.h>
#include <stdlib.h>

int max (int a,int b)
{
    if (a>b) return a;
    else return b;
}

void wypisz_2d (int N, int t[N][N])
{
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n,r,i,j,k,l;
    printf("Podaj rozmiar tablicy i r:\n");
    scanf("%d %d", &n,&r);
    int tab[n][n];
    for (i=0;i<n;i++)
    {
        printf("Podaj %d wiersz tablicy:\n", i+1);
        for (j=0;j<n;j++)
        {
            scanf("%d", &k);
            tab[i][j]=k;
        }
    }
    printf("Tabelka F:\n");
    wypisz_2d(n,tab);
    int wyjsciowa[n][n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            wyjsciowa[i][j]=0;
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                for (l=0;l<n;l++)
                {
                    if (max(abs(i-k),abs(j-l))<=r) wyjsciowa[i][j]+=tab[k][l];
                }
            }
        }
    }
    printf("Tabelka wyjsciowa:\n");
    wypisz_2d(n,wyjsciowa);

    return 0;
}
