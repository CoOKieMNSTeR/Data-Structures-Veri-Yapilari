#include <stdlib.h>
#include <stdio.h>

/* 
	Eleman Eklemenin sonundan oldugu,
	cikartmanin bastan yapildigi dizilerdir.
	OR : atm sirasi vs...
	
	Maliyetli Versyonu :
*/
#define Kboyut 5

typedef struct Kuyruk{
	int son;
	int eleman[Kboyut];
} Kuyruklar;

int Enqueu( Kuyruklar *yeni , int ekle ){ // EKLE
	if( yeni->son >= Kboyut-1 ) {
		printf("\n\tKuyruk Doldu...\n\t");
		return -1;
	}
	yeni->eleman[++yeni->son] = ekle;
	return 1;
}

int Dequeu( Kuyruklar *yeni ){ // CIKAR
	if ( yeni->son <= -1 ){
		printf("\n\tKuyruk Bos...");
		return -1;
	}
	char cikan = yeni->eleman[0];
	for (int i=1 ; i<Kboyut ; i++ ){
		yeni->eleman[i-1] = yeni->eleman[i];
	}
	yeni->son--;
	return cikan;
}

void Listele( Kuyruklar *gelen ){
	printf("\n");
	for ( int i=0 ; i<=gelen->son ; i++ ){
		printf("\n\t %d - %d ",i+1,gelen->eleman[i]);
	}
}

Kuyruklar *Kuyruk_Olustur(){
	Kuyruklar *olusturulan = (Kuyruklar*) malloc(sizeof(Kuyruklar));
	olusturulan->son = -1;
	return olusturulan;
}

int main(){
	
	Kuyruklar *Yeni = Kuyruk_Olustur();
	Dequeu(Yeni);
	Enqueu(Yeni,10);
	Enqueu(Yeni,20);
	Listele(Yeni);
	Enqueu(Yeni,30);
	Enqueu(Yeni,40);
	printf("\n\tDequeu : %d",Dequeu(Yeni));
	Listele(Yeni);
	Enqueu(Yeni,50);
	Enqueu(Yeni,60);
	Enqueu(Yeni,70);
	Listele(Yeni);
}
