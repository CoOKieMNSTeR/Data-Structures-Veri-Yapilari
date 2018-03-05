#include <stdio.h>
#include <stdlib.h>

/* 
	Dairesel Bagli Listeden Olusturulan
	
	ODEV : Bunun Pointerli Halini Yap
*/

#define Kboyut 5

typedef struct Llist {
	int son;
	int bas;
	int sayi;
	int eleman[Kboyut];
}Kuyruk;


int enqueu( Kuyruk *yeni , int ekle ){
	if ( yeni->sayi >= Kboyut ){
		printf("\n\tKuyruk Dolu...");
		return -1;
	}
	yeni->eleman[yeni->son] = ekle;
	yeni->son = ( yeni->son + 1 ) % Kboyut;
	yeni->sayi++;
	return 1;
}

int dequeu( Kuyruk *yeni ){
	if ( yeni->sayi == 0 ){
		printf("\n\tKuyruk Bos...");
		return -1;
	}
	int cikan = yeni->eleman[yeni->bas];
	yeni->bas = (yeni->bas+1) % Kboyut;
	yeni->sayi--;
	return cikan;
}

Kuyruk *Olustur(){
	Kuyruk *yeni = (Kuyruk*) malloc (sizeof(Kuyruk));
	yeni->son = 0;
	yeni->bas = 0;
	yeni->sayi = 0;
	return yeni;
}

void Listele( Kuyruk *yeni ){
	for ( int i=0 ; i<yeni->sayi ; i++ ){
		printf("\n\t%d - %d",i+1,yeni->eleman[i]);
	}
}

int main(){  // KODU DUZELT BÝ ZAHMET :)
	enqueu(1);
	enqueu(2);
	enqueu(3);
	enqueu(4);
	enqueu(5);
	enqueu(6);
	enqueu(7);
	Listele();
	dequeu();
	Listele();
}
