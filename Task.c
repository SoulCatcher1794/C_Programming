#include <stdio.h>

int main(void){
    char word[51];
    scanf("%s", word);
    int i=0, j, k;
    int wordCount=0, repeatCounter=0, skip=0;
    
    //Define word length
    while(word[i] != '\0'){
        wordCount++;
        i++;
    }
    
    //Sort word array in alpabetical order
    char swap;
    for(i=0; i<wordCount-1; i++){
        for(j=0; j<wordCount-1; j++){
            if(word[j]>word[j+1]){
                swap = word[j];
                word[j] = word[j+1];
                word[j+1] = swap;
            }
        }
    }
    
    //Count of repetitive letters
    for(k=0; k<wordCount-1; k++){
        if((word[k] == word[k+1]) && !skip){
            
            skip=1;
        }else{
            skip=0;
        }
    }
    
    printf("%d", repeatCounter);
    return 0;
}