#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	int rzad; //rzad macierzy
	float** A;//macierz wspolczynnikow
	float* B;//macierz wyrazow wolnych
	float* X;//macierz wynikowa
	float wsp; //wpolczynnik przemnozenia
    int i,j,k;
    do {
		printf("Podaj rzad rownania w postaci cyfry:\n");
		scanf("%d",&rzad);
		if ((rzad>4) || (rzad==0)) {
			printf("\n\nNIEPRAWIDLOWE DANE!\n\n");
		}
	}while((rzad>4)||(rzad==0));
	B=(float*)calloc(rzad,sizeof(float));
	X=(float*)calloc(rzad,sizeof(float));
	A=(float**)calloc(rzad,sizeof(float*));
	for (i=0;i<rzad;i++) {
		A[i]=(float*)calloc(rzad,sizeof(float));
	}
	for (i=0;i<rzad;i++) {
		printf("\nPodaj %d. wiersz macierzy wspolczynnikow A:\n",i+1);
		for (j=0;j<rzad;j++) {
			printf("\nPodaj %d. wspolczynnik: ",j+1);
			scanf("%f",&A[i][j]);
		}
	}
	printf("\n\nPodaj kolumne wyrazow wolnych:");
	for (i=0;i<rzad;i++) {
		printf("\n%d. element:",i+1);
		scanf("%f",&B[i]);
	}
	// eliminacja Gaussa
	for (k=0; k<rzad-1;k++) {//nr eliminowanej zmiennej
		for (i=k+1; i<rzad; i++) {// nr wiersza do eliminacji zmiennej
			wsp = A[i][k]/A[k][k]; // wspolczynnik przemnozenia wiersza k
			for (j=k;j<rzad;j++) {
				A[i][j]-=wsp*A[k][j];// odjecie wiersza k (razy wsp) od wiersza i
			}
				B[i]-=wsp*B[k];// to samo dla kolumny wyrazow wolnych
		}
	}
// rozwiazanie ukladu z macierza trojkatna gorna
	for (i=rzad-1;i>=0;i--) {
		X[i]=B[i];
		for (j=i+1;j<rzad;j++) X[i]-=A[i][j]*X[j];
		X[i]/=A[i][i];
	}

	for(i=0;i<rzad;i++) {
		if (isnan(X[i])) {
			printf("\n\nUKLAD NIEOZNACZONY.\n\n");
			return 0;
		}
		if (isinf(X[i])) {
			printf("\n\nUKLAD SPRZECZNY.\n\n");
			return 0;
		}
	}

	for (i=0;i<rzad;i++) {
		printf("\n");
		printf("X%d=%f",i+1,X[i]);
	}
system("pause");
	for (i=0;i<rzad;i++) {
		free(A[i]);
	}
	free(A);
	free(B);
	return 0;
}
