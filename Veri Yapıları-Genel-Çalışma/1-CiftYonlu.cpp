#include <stdio.h>
#include <stdlib.h>

typedef struct deger{
	int data;
	struct deger *next;
	struct deger *prev;
}Bliste;

Bliste * insert ( Bliste *root, int data ){
	if ( root == NULL ){
		root = (Bliste*) malloc (sizeof(Bliste));
		root->data = data;
		root->next = root;
		root->prev = root;
		return root;
	}
	if ( root->data > data ){
		Bliste *temp = ( Bliste* ) malloc ( sizeof( Bliste ));
		temp->data = data;
		temp->next = root;
		temp->prev = root->prev;
		root->prev = temp;
		temp->prev->next = temp;
		return temp;
	}
	Bliste *iter = root;
	while ( iter->next->data < data && iter->next!=root){
		if ( iter->next == root ){
			iter->next = ( Bliste* ) malloc ( sizeof(Bliste));
			iter->next->data = data;
			iter->next->prev = iter;
			iter->next->next = iter;
			iter->prev = iter->next;
			return root;
		}
		iter = iter->next;
	}
	Bliste *temp = (Bliste*) malloc ( sizeof(Bliste));
	temp->data = data;
	temp->prev = iter;
	temp->next = iter->next;
	temp->next->prev = temp;
	iter->next = temp;
	return root;
}

void print( Bliste *root , Bliste *iter ){
	if ( root != NULL ){
		while ( iter->next != root ){
			printf("%d<->",iter->data);
			iter = iter->next;
		}
		printf("%d\n",iter->data);
	}
}

Bliste * del ( Bliste *root , int data ){
	if ( root == NULL ) return NULL;
	if ( root->data == data && root->next == root ){
		free(root);
		return NULL;
	}
	if ( root->data == data ){
		Bliste * temp = root->next;
		temp->prev = root->prev;
		root->prev->next = temp;
		free(root);
		return temp;
	}
	Bliste *iter = root;
	while ( iter->data != data ){
		if ( iter->next == root ) return root;
		iter = iter->next;
	}
	iter->next->prev = iter->prev;
	iter->prev->next = iter->next;
	free(iter);
	return root;
}

int main (){
	Bliste *root = NULL;
	root = insert ( root , 10 );
	root = insert ( root , 20 );
	root = insert ( root , 30 );
	root = insert ( root , 25 );
	root = insert ( root , 15 );
	root = insert ( root , 5 );
	root = insert ( root , 40 );
	
	print ( root , root );
	
	root = del ( root , 25 );
	print ( root , root );
}
