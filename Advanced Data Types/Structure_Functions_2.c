#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
void readDate(struct date *today){
    scanf("%d %d %d", &today->year, &today->month, &today->day);
}

void printDate(struct date day){
    printf("%02d/%02d/%d\n", day.month, day.day, day.year);
}

struct date advanceDay(struct date today){
    struct date tomorrow;
    int monthDays=0;
    int day, month, year;

    day = today.day;
    month = today.month;
    year = today.year;

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        monthDays = 31;
    }else if (month == 2){
        monthDays = 28;
    }else{
        monthDays = 30;
    }

    if(day + 1 > monthDays){
        day = 1;
        month++;
    }

    if(month > 12){
        month = 1;
        year++;
    }

    tomorrow.day = day;
    tomorrow.month = month;
    tomorrow.year = year;

    return tomorrow;
}