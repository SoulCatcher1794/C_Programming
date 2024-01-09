#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int plants;
    float price;
    if(argc == 3){
        plants = atoi(argv[1]);
        price = atof(argv[2]);
        printf("%d plants for %0.2lf dollars each cost %0.2lf dollars\n",plants, price, plants*price);
        
    }else{
        printf("Invalid input\n");
    }
    return 0;
}