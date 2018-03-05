#include <stdio.h>
#include <stdlib.h>

/*
		Last in First Out typed variable ( LIFO )
	
	push : push(s,i) = add i variable to s stack;
	pop : i = pop(s) = delete last variable from s and define to i;
	empty : empty(s) = stack is empty or not? - true = empty;
	
	Underflow : tring to pop an empty stack or cant find last variable;
	Overflow : cant add variable any more;
*/
#define N 100

int Yigin[N] = {0} , indis = 0;
int Push(int veri);
int Pop();

int Push( int veri ){
	if ( indis >= N ){
		printf("\n\tYigin Dolu!");
		return -1;
	}
	Yigin[indis++] = veri;
	return 0;
}

int Pop (  ){
	if ( indis <= 0 ){
		printf("\n\tYigin Bos!");
		return -1;
	}
	return Yigin[--indis];
}

int main (){
	Push(5);
	Push(8);
	Push(11);
	for ( ; indis != 0 ; )
		printf("\n\t%d",Pop());
}
