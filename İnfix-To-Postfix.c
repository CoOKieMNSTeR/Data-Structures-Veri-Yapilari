#include<stdio.h>
#include<conio.h>              //Muhammed Said BAKIRCI
#include<stdlib.h>					//16010011029
#define  STACKSIZE  50

struct  stack
{
    int  top ;
    char  items[STACKSIZE] ;
} ;

void  postfix(char  gir[ ], char  cik[ ]) ;
int  isoperand(char  c) ;
int  prcd(char  secim, char  car) ;
int  empty(struct  stack  *ps) ;
char  pop(struct  stack  *ps) ;
void  push(struct  stack  *ps, char  x) ;
char  stacktop(struct  stack  s) ;

void  main()
{
    char  gir[50], cik[50] ;
    system("cls");
    printf("Infix halini giriniz:\n") ;
    gets(gir) ;
    postfix(gir,cik) ;
    printf(" Postfix Hali :\n%s",cik) ;
    getch() ;
}

/* Bu i�leve sonu�ta gelen son deyim cik'de depolanacakt�r */
/* yani - giri� ifadesi,cik - ��kt� ifadesi */
void  postfix(char  gir[ ], char  cik[ ])
{
    int  i, j ;
    char  ts, car ;
    struct  stack  s ;
    s.top=-1 ;
    j=0;
    
    for(i=0 ; (car=gir[i])!='\0' ; i++)
        if(isoperand(car)){
		
            cik[j++]=car ;
        	
        }
        else
            {
                while( !empty(&s) && prcd(stacktop(s),car) )
                    {
                        ts=pop(&s) ;
                        cik[j++]=ts ;
                        ;
                    }
                if(empty(&s)||car!=')'){
				
                    push(&s,car) ;
                    
                }
                else {
                    ts=pop(&s) ;
                    
                }
                
            }
    while(!empty(&s))
        {
            ts=pop(&s) ;
            cik[j++]=ts ;
        }
    cik[j]='\0' ;
}

/* Belirtilen karakter bir i�lenen ise bu i�lev true de�erini d�nd�r�r */
int  isoperand(char  c)
{
    if(c>='A'&&c<='Z'||c>='a'&&c<='z'||c>='0'&&c<='9')
        return  1 ;
    else
        return  0 ;
}

/*
prcd (secim, car) true d�nd�ren bir i�levdir
1) car'nin car'den y�ksek �nceli�i varsa
2) �ncelikler ayn� ise, at�lganl�k d���n�l�r
   Dolay�s�yla prcd (*, +) = 1, prcd (+, +) = prcd (+, -) = ... = 1
prcd (+, *) = 0 prcd ($, $) = 0
*/

int  prcd(char  secim, char  car)
{
    switch(secim)
        {
        case '+':
        case '-':
            if(car=='+'||car=='-'||car==')')  return  1 ;
            if(car=='*'||car=='/'||car=='$'||car=='(')  return  0 ;
        case '*':
        case '/':
            if(car=='+'||car=='-'||car=='*'||car=='/'||car==')')  return  1 ;
            if(car=='$'||car=='(')  return  0 ;
        case '$':
            if(car=='+'||car=='-'||car=='*'||car=='/'||car==')')  return  1 ;
            if(car=='$'||car=='(')  return  0 ;
        case '(':
            return  0 ;
        default:
            printf("\nHatal� �al��ma.") ;
            getch() ;
            exit(1) ;
        }
}

int  empty(struct  stack  *ps)
{
    if(ps->top==-1)
        return  1 ;
    else
        return  0 ;
}

char  pop(struct  stack  *ps)
{
    return  (ps->items[(ps->top)--]) ;
}

char  stacktop(struct  stack  s)
{
    return  (s.items[s.top]) ;
}

void  push(struct  stack  *ps, char  x)
{
    if(ps->top==STACKSIZE-1)
        {
            printf("Stack Overflow.push edemeyiz \n") ;
            getch() ;
            exit(1) ;
        }
    ps->items[++(ps->top)]=x ;
}
