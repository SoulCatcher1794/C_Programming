#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *day){
    scanf("%d %d %d", &(*day).year, &(*day).month, &(*day).day);
}

void printDate(struct date day){
    printf("%d/%02d/%d\n", day.month, day.day, day.year);
}