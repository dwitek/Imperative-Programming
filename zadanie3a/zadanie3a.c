#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N=10;

void wypisz_2d (int t[N][N])
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

void losowe (int t[N][N])
{
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            t[i][j]=rand()%33+12;
        }
    }
}

int przekatna (int t[N][N])
{
    int suma=0,i;
    for (i=0;i<N;i++)
    {
        suma+=t[i][i];
    }
    return suma;
}

int podprzekatna (int t[N][N])
{
    int suma=0,i,j;
    for (i=0;i<N;i++)
    {
        for (j=i+1;j<N;j++)
        {
            suma+=t[j][i];
        }
    }
    return suma;
}

int wszystkie (int t[N][N])
{
    int suma=0,i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            suma+=t[i][j];
        }
    }
    return suma;
}
void pomnoz (int t1[N][N], int t2[N][N], int t3[N][N])
{
    int i,j,k;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            for (k=0;k<N;k++)
            {
                t3[i][j]+=t1[i][k]*t2[k][j];
            }
        }
    }
}

int main()
{
    srand (time(NULL));
    int t1[N][N];
    int t2[N][N];
    losowe(t1);
    printf("Pierwsza tablica: \n");
    wypisz_2d(t1);

    int przekat = przekatna(t1);
    printf("Suma elementow na przekatnej wynosi: %d\n", przekat);

    int podprzekat = podprzekatna (t1);
    printf("Suma elementow pod przekatna wynosi: %d\n", podprzekat);

    int wszyst = wszystkie (t1);
    printf("Suma elementow w tablicy wynosi: %d\n", wszyst);

    printf("\n");
    losowe(t2);
    printf("Druga tablica: \n");
    wypisz_2d(t2);

    int t3[N][N];
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            t3[i][j]=0;
        }
    }
    pomnoz (t1,t2,t3);
    printf("Tablica po przemnozeniu: \n");
    wypisz_2d(t3);

    return 0;
}
