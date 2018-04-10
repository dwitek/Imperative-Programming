#include <stdio.h>
#include <stdlib.h>

struct book
{
    char tytul[20];
    int num_kat;
    int kod_dz;
};

int compare (const void*a, const void*b)
{
    struct book *c=a;
    struct book *d=b;
    if (c->kod_dz < d->kod_dz) return -1;
    else if (c->kod_dz == d->kod_dz) return 0;
    else return 1;
}

int get_lw (struct book* tab, int n)
{
    int lw=0,i;
    for (i=0;i<n;i++)
    {
        if (tab[i].kod_dz > lw) lw=tab[i].kod_dz;
    }
    return lw+1;
}

void wypisz_dzial (int lw, int lenw, struct book** tab)
{
    int i;
    printf("Wypisuje dzial %d :\n", lw+1);
    for (i=0;i<lenw;i++)
    {
        printf("%s ", tab[lw]->tytul);
        printf("%d \n", tab[lw]->num_kat);
        tab[lw]++;
    }
}

void wpisz_array_2 (struct book** tab, struct book katalog[], int n)
{
    int i,c=1;
    struct book prev = katalog[0];
    tab[0]=katalog;
    for (i=0;i<n;i++)
    {
        if (katalog[0].kod_dz!=prev.kod_dz)
        {
            tab[c++]=katalog;
        }
        prev=katalog[0];
        katalog++;
    }
}

void wczytaj ()
{
    int n,i,a;
    printf("Ile ksiazek chcesz wczytac? :");
    scanf("%d", &n);
    struct book * katalog = malloc(sizeof(struct book)*n);
    for (i=0;i<n;i++)
    {
        printf("Podaj po kolei tytul, numer katalogowy i kod dzialu danej ksiaznki:\n");
        struct book tmp;
        scanf("%s", &tmp.tytul);
        scanf("%d", &tmp.num_kat);
        scanf("%d", &tmp.kod_dz);
        katalog[i]=tmp;
    }
    qsort(katalog,n,sizeof(struct book),compare);
    int lw= get_lw(katalog,n);
    struct book ** array_2 = (struct book*)malloc(sizeof(struct book*)*lw);
    int * lenw = malloc(sizeof(int)*lw);
    for (i=0;i<lw;i++)
    {
        lenw[i]=0;
    }
    wpisz_array_2(array_2, katalog, n);
    for (i=0;i<n;i++)
    {
        lenw[katalog[i].kod_dz]++;
    }
    printf("Ktory dzial chcesz wypisac? : \n");
    scanf("%d", &a);
    wypisz_dzial(a-1,lenw[a],array_2);
}

int main()
{
    wczytaj();

    return 0;
}
