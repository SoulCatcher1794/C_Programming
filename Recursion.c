#include <stdio.h>

int sumOfDigits(int num){
    if(num>=10){
        num = (num%10) + sumOfDigits(num/10);
        return num;
    }else{
        return num;
    }
}

int main(void){
    int number, result;
    scanf("%d", &number);
    result = sumOfDigits(number);
    printf("%d", result);
    return 0;
}