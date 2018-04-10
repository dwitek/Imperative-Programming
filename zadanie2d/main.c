#include <stdio.h>
#include <stdlib.h>

int potegowanie (int a,int b)
{
    int c=1;
    int i;
    for (i=0;i<b;i++)
    {
        c=c*a;
    }
    return c;
}
int zamien_16 (int liczba)
{

}

int zamien_8 (int liczba)
{

}

int zamien_2 (int liczba)
{

}

bool sprawdz (int liczba,int b)
{
    int kopia=liczba;
    int rozmiar=0;
    while (kopia!=0)
    {
        rozmiar++;
        kopia=kopia/10;
    }
    kopia=liczba;
    int i;
    int tab[rozmiar];
    for (i=rozmiar-1;i>=0;i--)
    {
        tab[i]=kopia%10;
        kopia=kopia/10;
    }
    int suma=0;
    for (i=0;i<rozmiar;i++)
    {
        suma+=potegowanie(t[i],b);
    }
    if (suma==liczba) return true;
    else return false;
}

int main()
{
    int liczba;
    printf("Wpisz liczbe ktora chcesz sprawdzic: \n");
    scanf()

    return 0;
}
