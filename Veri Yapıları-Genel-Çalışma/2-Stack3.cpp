#include <stdio.h>
#include <stdlib.h>

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

void printStack(){
	Slist *temp = iter;
	printf("\n\t");
	while ( temp ){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void cevir(int sayi){
	int digit;
	while ( sayi > 0 ){
		digit = sayi % 2;
		push(digit);
		sayi /= 2;
	}
	printStack();
}

int main(){
	int numara;
	printf("\n\tSayi : ");
	scanf("%d",&numara);
	cevir(numara);
	return 0;
}
