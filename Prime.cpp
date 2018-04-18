#include <stdio.h>
#include <stdlib.h>

int main() {

    int number = -1;    //Variable to hold user input
    int flag = 0;       //Flag to determine prime or not
    int i;              //for loop counter variable
    int ret;

    //get a number greater than 1 since 0 and 1 not prime
    while(number <= 1)
    {
        printf("Enter a number greater than 1: ");
        ret = scanf("%d", &number);
	if (ret != 1) {
    	    printf("Invalid entry\n");
      	    exit(EXIT_FAILURE);
	    }
    }

    //if number is divisible by anything other than itself,
    //number is not prime, so flag is 1 and break
    for (i = 2; i <= (number/2); i++){
        if((number%i) == 0){
            flag = 1;
            break;
        }
    }

    //print results to the user
    if (flag==0)
        printf("%d is a prime number. \n",number);
    else
        printf("%d is not a prime number. \n",number);

    return 0;
}
