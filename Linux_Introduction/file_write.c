#include <stdio.h>

int main(void){
    int last_grade, submitted_grade;
    FILE * ifile = fopen("myGrades.txt", "r");
   
    scanf("%d", &submitted_grade);
    if(ifile == NULL){
        ifile = fopen("myGrades.txt", "w");
        goto z;
    }

    while(fscanf(ifile, "%d", &last_grade) != EOF);
    if(last_grade != submitted_grade){
        ifile = fopen("myGrades.txt", "a");
        z:fprintf(ifile, " %d ", submitted_grade);
        fclose(ifile);
    }

    ifile = fopen("myGrades.txt", "r");
    while(fscanf(ifile, "%d", &last_grade) != EOF){
        printf("%d ", last_grade);
    }

    fclose(ifile);
    return 0;
}