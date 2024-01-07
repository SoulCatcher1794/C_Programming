/*
    Some useful precompiled binaries are located in /usr/lib folder
    as well as C header files are located in /usr/include.
*/
#include <stdio.h>
#include <math.h>

int main(){
    int num;
    scanf("%d", &num);
    printf("%.8lf\n", sqrt(num));
    printf("%.10lf\n",exp(1));
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c /usr/lib/libm.a -o program\n");
    return 0;
}