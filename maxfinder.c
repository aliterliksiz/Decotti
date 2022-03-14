#include <stdio.h>
int main(){
    int dizi[10]={1,2,3,4,5,6,7,8,9,20};
    int max=dizi[1];
    int i;
    for(i=0; i<10; i++){
        if(max<dizi[i]){
            max=dizi[i];
        }
    }
    printf("%d", max);
}