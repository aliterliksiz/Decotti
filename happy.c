#include <stdio.h>     
int isHappyNumber(int num){    
    int rem = 0, sum = 0;    
        
    //Calculates the sum of squares of digits    
    while(num > 0){    
        rem = num%10;    
        sum = sum + (rem*rem);    
        num = num/10;    
    }    
    return sum;    
}    
        
int main()    
{    
    int num;    
    printf("100 ile 300 arasinda bir sayi giriniz: ");
    scanf("%d",&num); 

    int result = num;
        
    while(result != 1 && result != 4){    
        result = isHappyNumber(result);    
    }    
        
    //Happy number always ends with 1    
    if(result == 1)    
        printf("%d is a happy number", num);    
    //Unhappy number ends in a cycle of repeating numbers which contains 4    
    else if(result == 4)    
        printf("%d is not a happy number", num);     
     
    return 0;    
}  