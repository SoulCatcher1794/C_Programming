#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct digit {
    int num;
    struct digit *next;
};


// Function prototypes
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);
int countRedun(struct digit * start);
struct digit * sortList(struct digit * start);
struct digit * insertIntoSorted(struct digit * sortedStart, struct digit * newDigit);
struct digit * appendStart(struct digit * start, struct digit * newDigit);

// main function routine
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}

// Functiones required defined here
int countRedun(struct digit * start){
    int count=0;
    int number=0, prev=0;
    struct digit * sortedList = sortList(start);
    struct digit * ptr = sortedList;

    while(ptr != NULL){
        number = ptr->num;
        if(number != prev){
            prev = ptr->num;
        }else{
            count++;
        }
        ptr = ptr->next;
    }
    freeNumber(sortedList);
    return count;
    
}

struct digit * sortList(struct digit * start){
    struct digit * ptr = start;
    struct digit * sortedStart = NULL;
    struct digit * newDigit;

    if(ptr != NULL){
        sortedStart = createDigit(ptr->num);
        ptr = ptr->next;
    }

    while(ptr != NULL){
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return sortedStart;
}

struct digit * insertIntoSorted(struct digit * sortedStart, struct digit * newDigit){
    struct digit *ptr = sortedStart;
    struct digit *prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDigit->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL) {
        sortedStart = appendStart(sortedStart, newDigit);
    } else {
        prev->next = newDigit;
        newDigit->next = ptr;
    }
    return(sortedStart);
}

struct digit * appendStart(struct digit * start, struct digit * newDigit){
    newDigit->next = start;
    return newDigit;
}