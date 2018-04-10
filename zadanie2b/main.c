#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz (int t[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\n", t[i]);
    }
}

int main()
{
    srand(time(NULL));

    int rozmiar1,i,j,k=0;
    int* tablica1;

    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &rozmiar1);
    tablica1=(int*)malloc(rozmiar1 * sizeof(*tablica1));

    for (i=0;i<rozmiar1;i++)
    {
        tablica1[i]=rand()%58+55;
    }
    printf("Pierwsza tablica: \n");
    wypisz(tablica1,rozmiar1);

    int rozmiar2=((rozmiar1+1)/2);
    int* tablica2;
    tablica2=(int*)malloc(rozmiar2 * sizeof(*tablica2));
    printf("\n");

    if (rozmiar1%2==1)
    {
        tablica2[rozmiar2-1]=tablica1[rozmiar1-1];
    }
    else
    {
        tablica2[rozmiar2-1]=tablica1[rozmiar1-1]+tablica1[rozmiar1-2];
    }
    for (j=0;j<rozmiar2-1;j++)
    {
        tablica2[j]=tablica1[k]+tablica1[k+1];
        k=k+2;
    }

    printf("Druga tablica: \n");
    wypisz(tablica2,rozmiar2);

    return 0;
}
