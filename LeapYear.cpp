#include <stdio.h>
#include <stdlib.h>

int main() {
    //Variable to hold the year
    int year = 0;
    int ret;

    //Error-checking for 4-digit year entry
    while(year > 9999 || year < 1000)
    {
        printf("Enter a year (must be four digits): ");
        ret = scanf("%d", &year);
        if(ret != 1){
	    printf("Invalid entry\n");
	    exit(EXIT_FAILURE);
	}
    }

    //if year is evenly divisible by 100 and 4, not a leap year
    if((year%100) == 0 && (year%4) == 0)
    {
        printf("%d is not a leap year. \n", year);
    }
    //if year is evenly divisible by 400 or 4, leap year
    else if((year%4) == 0 || (year%400) == 0)
    {
        printf("%d is a leap year! \n", year);
    }
    //all other cases, not a leap year
    else
        printf("%d is not a leap year. \n", year);

    return 0;
}
