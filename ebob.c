#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void EBOB1(int sayi1, int sayi2){
    int ebob;
    for(int i = 2; i < sayi1 && i < sayi2; i++)
    {
        if(sayi1 % i == 0 && sayi2 % i == 0){ // iki sayıyıda tam bölmesi lazım.
            printf("Ortak bolenler = %d\n",i);
            ebob = i;
        }
    }
    printf("\nSayilarin ebobu = %d",ebob);
}

void EBOB2(int sayi1, int sayi2){
    int r;
    
    if(sayi1<sayi2){
        while(sayi2!=0){
            r=sayi1%sayi2;
            sayi1=sayi2;
            sayi2=r;
        }

    printf("sayilarin obebi = %d",sayi1);
    }
else if(sayi1>sayi2){
    while(sayi1!=0){
        r=sayi2%sayi1;
        sayi2=sayi1;
        sayi1=r;
    }
    printf("sayilarin obebi = %d",sayi2);}
    else printf("sayilari eşit girdiniz!");
}

void carpan(){
    int msec = 0, trigger = 10; /* 10ms */
    int iterations;
    clock_t before = clock();

    do {
        EBOB1(1392,934);
        EBOB1(1056,724);
        EBOB1(5745,351);
        EBOB1(1512,560);
        EBOB1(6789,1330);

    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    iterations++;
    }while ( msec < trigger );
    printf("\nTime taken %d seconds %d milliseconds (%d iterations)\n",msec/1000, msec%1000, iterations);
}

void euler(){
    int msec = 0, trigger = 10; /* 10ms */
    int iterations;
    clock_t before = clock();

    do {
        EBOB2(1392,934);
        EBOB2(1056,724);
        EBOB2(5745,351);
        EBOB2(1512,560);
        EBOB2(6789,1330);

    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    iterations++;
    }while ( msec < trigger );
    printf("\nTime taken %d seconds %d milliseconds (%d iterations)\n",msec/1000, msec%1000, iterations);
}


int main(){
    carpan();
    euler();
    return 0;
}
