/* 
	Stack ile Parantez Kontrolu
	
	KURAL 1: 
	Parantez sayisi sonudna her zaman 0 olmali 
	( = +1;
	) = -1;
	
	KURAL 2:
	Hicbir Parantez Acilmadan Kapanmamali
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode {
	int data;
	struct lnode *next;
} Slist;

Slist *iter = NULL;

void push(int data);
int pop();

void push( int data ){
	if ( iter == NULL ){
		iter = (Slist*) malloc ( sizeof( Slist ) );
		iter->next = NULL;
		iter->data = data;	
	}
	else {
		Slist *information = (Slist*) malloc (sizeof(Slist));
		if ( information == NULL ){
			printf("\n\tOverflowed !!\n\t");
			system("pause");
			return;
		}
		information->data = data;
		information->next = iter;
		iter = information;
	}
}

int pop ( ){
	if ( iter == NULL ) return -1;
	int result = iter->data;
	Slist *gofree = iter;
	iter = iter->next;
	free(gofree);
	return result;
}

int Kontrol( char *islem ){
	for ( int i=0 ; i<strlen(islem) ; i++ ){
		if ( islem[i] == '(' ) push(islem[i]);
		else if ( islem[i] == ')' ) if ( pop() == -1 ) return -1;
	}
	if ( iter == NULL ) return 1;
	else return 0;
}

int main () {
	int i;
	char islem[100];
	printf("islemi giriniz : ");
	scanf("%s",islem);
	i = Kontrol(islem);
	switch ( i ){
		case -1:{
			printf("\n\tAcma Eksik");
			break;
		}
		case 0:{
			printf("\n\tKapatma Eksik");
			break;
		}
		case 1:{
			printf("\n\tParantez Hatasi Yok");
			break;
		}
	}
	return 0;
}













