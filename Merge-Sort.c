#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//--Muhammed Said BAKIRCI <--> 16010011029
//------------------
//Merge Sort algoritmas� Ile Kullan�c�dan Al�nan Say� Adedi Kadar 
//Diziye Rastgele Say� atan Ve Bu Say�lar� B�y�kten K����e S�ralayan Program  
//-------------------
 
void mergeSort(int *,int,int);
void merge(int *,int,int,int,int);
 
int main(){
	static int dizi[100],i,n;
	srand(time(NULL));
	printf("Dizinin Boyutu :"); scanf("%d",&n); // Kullan�c�dan dizi boyutunu ald�k. 
	for(i=0;i<n;i++){ // Rastgele bir dizi olu�turduk.
		dizi[i]=rand()% 100;
	}
	printf("Girdiginiz Dizi: ");
	for(i=0;i<n;i++){ // Rastgele olu�an diziyi ekrana bast�rd�k.
		printf("%d ",dizi[i]);
	}
	mergeSort(dizi,0,n-1); // Merge Sort algoritmas� ile diziyi s�ralad�k.
	printf("\nSirali Dizi: ");
	for(i=0;i<n;i++){ // Dizinin s�ral� halini ekrana bast�rd�k.
		printf("%d ",dizi[i]);
	}
	return 0;
}
 
void mergeSort(int dizi[],int bas,int son){	
	int orta;
	if(bas<son){
		// son bastan buyukse orta degeri hesaplan�r.
		orta=(bas+son)/2;
		mergeSort(dizi,bas,orta); // Ortadan b�l�nen dizinin �nce ilk yar�s� sonra ikinci yar�s� mergeSort fonksiyonuna tekrar g�nderilir.
		mergeSort(dizi,orta+1,son);
		merge(dizi,bas,orta+1,orta,son); // Par�alanan elemanlar en son merge fonksiyonunda s�ralananarak birle�tirilir.
	}
}
 
void merge(int dizi[],int bas1,int bas2,int son1,int son2){
	int i,j,k,yeniDizi[100];
	j=bas2; i=bas1; k=0;
	while(i<=son1 && j<=son2){
		// S�ral� olarak gelen 2 farkl� dizinin elemanlar�n� kar��la�t�r�yoruz.
		// B�y�kten k����e s�ralama yapt���m�z i�in b�y�k olan� yeni diziye at�yoruz.
		if(dizi[i]>dizi[j]){ 
			yeniDizi[k]=dizi[i]; 
			i++; k++;
		}
		else{
			yeniDizi[k]=dizi[j];
			j++; k++;
		}
	}
	// Dizilerden herhangi birindeki elemanlar�n hepsi yeni diziye al�nm��sa, kalan dizideki elemanlar
	// kar��la�t�rma yap�lmadan direk olarak yeni diziye al�n�r.
	if(i<=son1){
		while(i<=son1){
			yeniDizi[k]=dizi[i];
			i++; k++;
		}
	}
	if(j<=son2){
		while(j<=son2){
			yeniDizi[k]=dizi[j];
			j++; k++;
		}
	}
	// Yeni olu�turulan dizi ba�taki dizimize e�itlenir.
	for(i=bas1,j=0;i<=son2;i++,j++){
		dizi[i]=yeniDizi[j];
	}
}
