#include <stdio.h>
#include <stdlib.h>

/* 
	Tek Yonlu Bagli Listeden Olusturulan
	Bilgisayar icin Daha az Performans Harcayan versyonu:
*/
typedef struct Llist {
	int data;
	struct Llist *next;
}Kuyruk;

Kuyruk *first=NULL;
int size=0;

void enqueu(int data){
	if ( size == 0 ){
		first = (Kuyruk*) malloc (sizeof(Kuyruk));
		first->data = data;
		first->next = NULL;
		size++;
	}
	else {
		Kuyruk *iter = (Kuyruk*) malloc (sizeof(Kuyruk));
		iter->data = data;
		iter->next = first;
		first = iter;
		size++;
	}
}

int dequeu(){
	if (size == 0) return -1;
	if (size == 1){
		int result = first->data;
		free(first);
		first = NULL;
		size--;
		return result;
	}
	Kuyruk *iter = first;
	for ( int i=0 ; i<size-2 ; i++ ) iter = iter->next;
	Kuyruk *temp = iter->next;
	int result = iter->next->data;
	iter->next = NULL;
	free(temp);
	size--;
	return result;
}

void Listele(){
	Kuyruk *temp = first;
	printf("\n");
	while ( temp ){
		printf("\n\t %d ",temp->data);
		temp = temp->next;
	}
}

int main(){
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
