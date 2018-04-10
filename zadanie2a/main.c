#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char wczytaj(char *tab, char numer[8]);//wczytuje liczbe i zwraca jej znak
void wypisz(char *tab, int dlugosc);
void przeskaluj(char *tab, char minus);//konwertuje znak ascii (np. '0') na numer (np. 0)

int main() {
	printf("");//czyszczenie ekranu pod linuksem
	int a,b;//odpowiednio numery ostatniego znaku tab1 i tab2
	int n,m;//dlugosc tablicy dynamicznej
	char* wynik;//tablica dynamiczna
	char tab1[102]; //100 cyfr + znak + element null jako koniec stringa
	char tab2[102]; //100 cyfr + znak + element null jako koniec stringa
	char minus1,minus2; //zmienne sprawdzajace znak (1 dla "-", 0 dla "+")

	printf("Program podaje iloczyn dwoch liczb calkowitych, maksymalnie stucyfrowych.\n");
	minus1=wczytaj(tab1,"pierwsza");
	minus2=wczytaj(tab2,"druga");
	a=strlen(tab1)-1;//numer ostatniego znaku tab1
	b=strlen(tab2)-1;//numer ostatniego znaku tab2
	przeskaluj(tab1,minus1);
	przeskaluj(tab2,minus2);
	n=a+b+2-minus1-minus2;//(a+1) i (b+1) to ilosc elementow w tab1 i tab2, pomijamy rowniez znak '-'
	wynik=(char*)calloc(n,sizeof(char));//utworzenie i wyzerowanie tablicy wynikowej
	//petla mnozenia:
	int i,j;
	for (i=b;i>=minus2;i--) {
		m=n-1;//numer ostatniego znaku w tablicy wynikowej
		for (j=a;j>=minus1;j--) {
			wynik[m-b+i]+=((tab1[j])*(tab2[i]));
			while (wynik[m-b+i]>9) {//przeniesienie liczby dziesietnej
				wynik[m-b+i]-=10;
				wynik[m-b+i-1]+=1;
			}//koniec petli przenoszacej dziesiatki
			m--;
		}//koniec petli wewnetrznej
	}//koniec petli mnozenia

	if (((minus1==1)||(minus2==1)) && !((minus1==1) && (minus2==1))) {
		printf("-");//wypisanie znaku wyniku
	}
	wypisz(wynik,n-1);
	free(wynik);

	return 0;
}//koniec main

char wczytaj(char *tab, char numer[8]) {
    int i;
	char minus=0;//oznacza znak (0 dla "+", 1 dla "-")
	char check=0;//0 - poprawne dane, 1 - blad
	printf("\nPodaj %s liczbe (max 100 cyfr):\n",numer);
	scanf("%s",tab);
	if (tab[0]=='-') {minus=1;}//sprawdzenie znaku
	for (i=minus;i!=strlen(tab);i++) {
		if ((tab[i]>57) || (tab[i]<48)) {check=1;}
	}//petla sprawdza, czy wpisane dane to cyfry
	if ((tab[0]=='0') || ((minus==1) && (tab[1]=='0'))) {check=1;}//liczba nie moze zaczynac sie zerem
	if ((strlen(tab)-minus)>100) {check=1;}//liczba nie moze miec wiecej niz 100 cyfr
	if (check==1) {
		printf("\n\nNIEPOPRAWNE DANE!\n\n");
		minus=wczytaj(tab,numer);//dla niepoprawnych danych podprogram powtarza sie
	}
	return minus;//zwraca znak
}//koniec wczytaj

void przeskaluj(char *tab, char minus) {
	int i=0;
	if (minus==1) {i=1;}
	while (tab[i]!=0) {
		tab[i]-=48;
		i++;
	}
}//koniec przeskaluj

void wypisz(char *tab, int dlugosc) {
    int i;
	for (i=(dlugosc);i>0;i--) {
		tab[i]+=48;
	}//wypisanie bez pierwszego znaku
	if (tab[0]==0) {
		printf("%s", tab+1);//obciecie zera na poczatku
	}else {
		tab[0]+=48;
		printf("%s",tab);
	}
}//koniec wypisz
