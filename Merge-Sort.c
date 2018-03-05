#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//--Muhammed Said BAKIRCI 
//------------------
//Merge Sort algoritması Ile Kullanıcıdan Alınan Sayı Adedi Kadar 
//Diziye Rastgele Sayı atan Ve Bu Sayıları Büyükten Küçüğe Sıralayan Program  
//-------------------
 
void mergeSort(int *,int,int);
void merge(int *,int,int,int,int);
 
int main(){
	static int dizi[100],i,n;
	srand(time(NULL));
	printf("Dizinin Boyutu :"); scanf("%d",&n); // Kullanıcıdan dizi boyutunu aldık. 
	for(i=0;i<n;i++){ // Rastgele bir dizi oluşturduk.
		dizi[i]=rand()% 100;
	}
	printf("Girdiginiz Dizi: ");
	for(i=0;i<n;i++){ // Rastgele oluşan diziyi ekrana bastırdık.
		printf("%d ",dizi[i]);
	}
	mergeSort(dizi,0,n-1); // Merge Sort algoritması ile diziyi sıraladık.
	printf("\nSirali Dizi: ");
	for(i=0;i<n;i++){ // Dizinin sıralı halini ekrana bastırdık.
		printf("%d ",dizi[i]);
	}
	return 0;
}
 
void mergeSort(int dizi[],int bas,int son){	
	int orta;
	if(bas<son){
		// son bastan buyukse orta degeri hesaplanır.
		orta=(bas+son)/2;
		mergeSort(dizi,bas,orta); // Ortadan bölünen dizinin önce ilk yarısı sonra ikinci yarısı mergeSort fonksiyonuna tekrar gönderilir.
		mergeSort(dizi,orta+1,son);
		merge(dizi,bas,orta+1,orta,son); // Parçalanan elemanlar en son merge fonksiyonunda sıralananarak birleştirilir.
	}
}
 
void merge(int dizi[],int bas1,int bas2,int son1,int son2){
	int i,j,k,yeniDizi[100];
	j=bas2; i=bas1; k=0;
	while(i<=son1 && j<=son2){
		// Sıralı olarak gelen 2 farklı dizinin elemanlarını karşılaştırıyoruz.
		// Büyükten küçüğe sıralama yaptığımız için büyük olanı yeni diziye atıyoruz.
		if(dizi[i]>dizi[j]){ 
			yeniDizi[k]=dizi[i]; 
			i++; k++;
		}
		else{
			yeniDizi[k]=dizi[j];
			j++; k++;
		}
	}
	// Dizilerden herhangi birindeki elemanların hepsi yeni diziye alınmışsa, kalan dizideki elemanlar
	// karşılaştırma yapılmadan direk olarak yeni diziye alınır.
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
	// Yeni oluşturulan dizi baştaki dizimize eşitlenir.
	for(i=bas1,j=0;i<=son2;i++,j++){
		dizi[i]=yeniDizi[j];
	}
}
