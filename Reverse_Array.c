#include <stdio.h>

void reverseArray(int *);

int main(void){
    int i, array[6];
    for(i=0; i<6; i++){
        scanf("%d", &array[i]);
    }
    reverseArray(array);
    for(i=0; i<6; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

void reverseArray(int *arr){
    int temp[6];
    int i;
    for(i=0; i<6; i++){
        temp[i] = arr[5-i];
    }
    for(i=0; i<6; i++){
        arr[i] = temp[i];
    }
}