#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//--Muhammed Said BAKIRCI <--> 16010011029
//------------------
//Merge Sort algoritmasý Ile Kullanýcýdan Alýnan Sayý Adedi Kadar 
//Diziye Rastgele Sayý atan Ve Bu Sayýlarý Büyükten Küçüðe Sýralayan Program  
//-------------------
 
void mergeSort(int *,int,int);
void merge(int *,int,int,int,int);
 
int main(){
	static int dizi[100],i,n;
	srand(time(NULL));
	printf("Dizinin Boyutu :"); scanf("%d",&n); // Kullanýcýdan dizi boyutunu aldýk. 
	for(i=0;i<n;i++){ // Rastgele bir dizi oluþturduk.
		dizi[i]=rand()% 100;
	}
	printf("Girdiginiz Dizi: ");
	for(i=0;i<n;i++){ // Rastgele oluþan diziyi ekrana bastýrdýk.
		printf("%d ",dizi[i]);
	}
	mergeSort(dizi,0,n-1); // Merge Sort algoritmasý ile diziyi sýraladýk.
	printf("\nSirali Dizi: ");
	for(i=0;i<n;i++){ // Dizinin sýralý halini ekrana bastýrdýk.
		printf("%d ",dizi[i]);
	}
	return 0;
}
 
void mergeSort(int dizi[],int bas,int son){	
	int orta;
	if(bas<son){
		// son bastan buyukse orta degeri hesaplanýr.
		orta=(bas+son)/2;
		mergeSort(dizi,bas,orta); // Ortadan bölünen dizinin önce ilk yarýsý sonra ikinci yarýsý mergeSort fonksiyonuna tekrar gönderilir.
		mergeSort(dizi,orta+1,son);
		merge(dizi,bas,orta+1,orta,son); // Parçalanan elemanlar en son merge fonksiyonunda sýralananarak birleþtirilir.
	}
}
 
void merge(int dizi[],int bas1,int bas2,int son1,int son2){
	int i,j,k,yeniDizi[100];
	j=bas2; i=bas1; k=0;
	while(i<=son1 && j<=son2){
		// Sýralý olarak gelen 2 farklý dizinin elemanlarýný karþýlaþtýrýyoruz.
		// Büyükten küçüðe sýralama yaptýðýmýz için büyük olaný yeni diziye atýyoruz.
		if(dizi[i]>dizi[j]){ 
			yeniDizi[k]=dizi[i]; 
			i++; k++;
		}
		else{
			yeniDizi[k]=dizi[j];
			j++; k++;
		}
	}
	// Dizilerden herhangi birindeki elemanlarýn hepsi yeni diziye alýnmýþsa, kalan dizideki elemanlar
	// karþýlaþtýrma yapýlmadan direk olarak yeni diziye alýnýr.
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
	// Yeni oluþturulan dizi baþtaki dizimize eþitlenir.
	for(i=bas1,j=0;i<=son2;i++,j++){
		dizi[i]=yeniDizi[j];
	}
}
