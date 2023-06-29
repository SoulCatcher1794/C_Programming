#include <stdio.h>

int main(void){
    char type;
    int variables, size;
    int sizeMB=0, sizeKB=0, sizeB=0;

    scanf("%c %d", &type, &variables);

    if(type == 'i') {
        size = variables*sizeof(int);
    }else if (type == 's'){
        size = variables*sizeof(short);
    }else if (type == 'c'){
        size = variables*sizeof(char);
    }else if (type == 'd'){
        size = variables*sizeof(double);
    }else{
        printf("Invalid input");
    }

    if(size >= 1000000){
        sizeMB = size/1000000;
        sizeKB = (size%1000000)/1000;
        sizeB = (size%1000000)%1000;
        printf("%d MB and %d KB and %d B", sizeMB, sizeKB, sizeB);
    }else if(size >= 1000){
        sizeKB = (size/1000);
        sizeB = size%1000;
        printf("%d KB and %d B", sizeKB, sizeB);
    }else{
        sizeB = size;
        printf("%d B", sizeB);
    }
    return 0;
}