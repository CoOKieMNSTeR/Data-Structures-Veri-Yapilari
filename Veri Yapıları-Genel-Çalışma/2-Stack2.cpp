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
	printf("\n");
	while ( temp ){
		printf("\t%d",temp->data);
		temp = temp->next;
	}
}

int main (){
	push(10);
	printStack();
	push(20);
	push(40);
	push(70);
	push(30);
	printf("\n\tPop : %d ",pop());
	printf("\n\tPop2 : %d",pop());
	printStack();
}
