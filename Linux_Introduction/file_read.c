#include <stdio.h>

int main(void){
    int class=2, value = 0;
    float my_class, grade;
    FILE *ifile = fopen("gradeComparison.txt", "r");

    fscanf(ifile, "%f", &my_class);

    while(fscanf(ifile, "%f", &grade) != EOF){
        if(grade > my_class){
            value = 1;
            break;
        }
        class++;
    }

    fclose(ifile);
    if(value == 0){
        printf("Yes");
    }else{
        printf("No %d", class);
    }

    return 0;
}