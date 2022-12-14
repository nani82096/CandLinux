#include	<stdio.h>
static char daytab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
							 {0,31,29,31,30,31,30,31,31,30,31,30,31}};


int day_of_year (int year, int month, int day){
	
	int i, leap;
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	
	for ( i = 1 ; i < month; i++)
		
		day += daytab[leap][i];

	return day;
	
}
void month_day(int year, int yearday, int *pmonth, int *pday){

	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for ( i = 1; yearday > daytab[leap][i]; i++)
		
		yearday -= daytab[leap][i];
	
	*pmonth = i;
	
	*pday = yearday;
}

int main(void){

	int year = 2016;
	int month = 10;
	int day = 22;
	int yearday = day_of_year (year, 10, 22);

	printf ("The Date %d:%d:%d is %d th day of year\n", day, month, year, yearday);
	
	month = 0, day = 0;

	month_day(year, yearday, &month, &day);

	printf ("month = %d day = %d from yearday %d\n", month, day, yearday);
	
	return 0;
	
}
