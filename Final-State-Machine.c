/*#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

Sonlu durum makinasý(graph yapýsý ile yapýlýr)
<(paliti biti nedir????)>

Q = {q1,q2,....,qn}

FSM(Q,q0,NEXT,OUT)
1 ler tek ise 1 çift ise 0 yazan sonlu durum makinasý ile yapýnýz...

Durum   Input   Next 
q0       0       q0
q0        1       q1
q1         0       q1
q1           1      q0


q0 state de çift q1 state inde tek dir.
q0 dan baþlat 

*/
/*
struct Durum{
	char *state;
	char *durum;
	struct Durum *onceki;
	struct Durum *sonraki;
}*q0,q1,son;


int main(){
	Durum_Kur();
	son = q0;
	printf("0-1");
	Input();
	free(q0);
	free(q1);
}

void Durum_Kur(){
	q0 = (Durum*) malloc (Sizeof(Durum));
	q1 = (Durum*) malloc (Sizeof(Durum));
	q0->durum="q0";
	q1->durum="q1";
	q0->onceki=q0;
	q0->sonraki=q1;
	q1->sonraki=q0;
	q1->onceki=q1;	
}
void Input() {
	do {
		tus = getch();
		if(tus == '1' || tus == '0')
			Giris(tus);
	}
	while(tus=='1' || tus=='0')
		if(strcmp(son->durum,"q0")==0)
			printf("Cift Paliti(PARITY)");
		else
			printf("Tek Paliti");
}
void Giris(char a) {
	if(a=='0')
		son = son->onceki;
	if(a == '1')
		son = son->sonraki;	
	
}
*/

/*Sonlu Durum Tanýyýcýsý FSR(Q,q0,Next,F)
Çift 0 Çift 1
Çift 0 Tek 1
Tek 0 Çift 1
Tek 0 Tek 1
0011
00100
00011
01


Final State Çift halka içine alýnýr...
*/
#include<conio.h>  
#include<string.h>  
#include<stdio.h>  
#include <stdlib.h>  
typedef struct yapi{   struct yapi *adres0; 
 
struct yapi *adres1;   }YAPI;  
void  main()  {
   int i,sayi,j;
    i=0;
	int number=10;
	char string[100]="";
	YAPI *q0,*q1,*q2,*q3,*sonuc;
	printf("bir sayi giriniz=");
	scanf("%s",&string);
	
  	q0->adres1=q1;   q0->adres0=q3;   
  	q1->adres0=q2;   q1->adres1=q0;   
  	q2->adres1=q3;   q2->adres0=q1;  
  	q3->adres1=q2;   q3->adres0=q0;   
  	sonuc=q0;
	    
  	for(j=0;j<strlen(string);j++)   {
	    if(string[j]=='1') 
			sonuc=sonuc->adres1;     
		else      
   			sonuc=sonuc->adres0;   }   
   	if(sonuc==q0)   {
     	printf("\ncift sayida 1 ve 0 var");   }   
   	else   
  		printf("\ncift sayida 1 ve 0 yok");   
		
	getch();   
}



























