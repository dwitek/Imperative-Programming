#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_jedna (int t[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\n", t[i]);
    }
    printf("\n");
}
void wypisz_dwie (int t1[], int t2[], int n1, int n2)
{
    int i;
    printf("Pierwsza tablica: \n");
    for (i=0;i<n1;i++)
    {
        printf("%d\n", t1[i]);
    }
    printf("\n");
    printf("Druga tablica: \n");
    for (i=0;i<n2;i++)
    {
        printf("%d\n", t2[i]);
    }
    printf("\n");
}

void zamiana (int t[], int a, int b)
{
    int tmp=t[a];
    t[a]=t[b];
    t[b]=tmp;
}

void odwroc (int t[],int n)
{
    int i;
    for (i=0;i<n/2;i++)
    {
        zamiana(t,i,n-1-i);
    }
}

void wymien_tablice (int t1[], int t2[], int n1, int n2)
{
    int i,tmp;
    if (n1<n2)
    {
        for (i=0;i<n1;i++)
        {
            tmp=t1[i];
            t1[i]=t2[i];
            t2[i]=tmp;
        }
    }
    else
    {
        for (i=0;i<n2;i++)
        {
            tmp=t1[i];
            t1[i]=t2[i];
            t2[i]=tmp;
        }
    }
}

void sortuj(int t[], int n)
{
    int i,j,tmp;
    for(i=1;i<n;i++)
    {
        tmp=t[i];
        for(j=i-1;j>=0 && t[j]>tmp;j--) t[j+1]=t[j];
        t[j+1]=tmp;
    }
}

int one_two (int t1[], int s1, int t2[], int s2,int t3[])
{
    int t4[s1+s2];
    int i,j;
    for (i=0;i<s1;i++)
    {
        t4[i]=t1[i];
    }
    for (i=s1;i<s1+s2;i++)
    {
        t4[i]=t2[i-s1];
    }

    sortuj(t4,s1+s2);

    t3[0]=t4[0];
    for (i=1,j=1;i<s1+s2;i++)
    {
        if (t4[i]!=t4[i-1])
        {
            t3[j]=t4[i];
            j++;
        }
    }
    return j;
}

int main()
{
    srand(time(NULL));
    int s1, s2, i;
    int* t1;
    int* t2;

    printf("Podaj rozmiar pierwszej tablicy: ");
    scanf("%d", &s1);
    t1=(int*)malloc(s1 * sizeof(*t1));

    printf("Podaj rozmiar drugiej tablicy: ");
    scanf("%d", &s2);
    t2=(int*)malloc(s2 * sizeof(*t2));
    printf("\n");

    for (i=0;i<s1;i++)
    {
        t1[i]=rand()%10+1;
    }
    for (i=0;i<s2;i++)
    {
        t2[i]=rand()%10+1;
    }
    wypisz_dwie(t1,t2,s1,s2);

    zamiana(t1,0,s1-1);
    printf("Pierwsza tablica po zamianie ostatniego elementu z pierwszym: \n");
    wypisz_jedna(t1,s1);

    odwroc(t1,s1);
    printf("Pierwsza tablica po odwroceniu: \n");
    wypisz_jedna(t1,s1);

    wymien_tablice(t1,t2,s1,s2);
    printf("Tablice po zamianie: \n");
    wypisz_dwie(t1,t2,s1,s2);

    sortuj(t1,s1);
    sortuj(t2,s2);
    printf("Tablice po sortowaniu: \n");
    wypisz_dwie(t1,t2,s1,s2);

    int t3[s1+s2];

    int wynik=one_two(t1,s1,t2,s2,t3);
    printf("Rozmiar ostatniej tablicy:  %d\n", wynik);
    printf("Ostatnia tablica: \n");
    wypisz_jedna(t3,wynik);

    return 0;
}
