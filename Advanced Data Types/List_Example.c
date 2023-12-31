#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void freeStudents(struct student *start);

// Write other function prototypes here (if any)

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;

    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);

    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

// Write your createStudent function here (and any other functions you see fit)
struct student *createStudent(char studentName[], int studentAge){
    struct student *student = (struct student *)malloc(sizeof(struct student));
    int i = 0;

    while(studentName[i] != '\0'){
        student->name[i] = studentName[i];
        i++;
    }

    student->age = studentAge;
    student->next = NULL;
    return student;
}

struct student * append(struct student * end, struct student * newStudptr){
    end->next = newStudptr;
    end = newStudptr;
    return end;
}

void printStudents(struct student *start){
    struct student * ptr = start;
    while(ptr != NULL){
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr->next;
    }
}

void freeStudents(struct student *start){
    struct student * ptr = start;
    struct student * temp;
    while(ptr != NULL){
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}