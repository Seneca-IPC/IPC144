/***************************************************************** 

    File: lab4practice.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab4practice.c lab4main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

/*
This function is passed 2 whole numbers min and max.  It will return
the sum of all the whole numbers between min and max inclusive.
You may assume that min is always <= max.
*/
int sum(int start, int stop);


/*
This function is passed a number called endPoint.  It will return a 
score based on the game fizz-buzz.  1 point for Fizz, 2 points for Buzz,
5 points for FizzBuzz.  See specs for details.
*/
int fizzBuzzScore(int endPoint);

/*
This function returns the sum of the digits from the passed number.  
You may assume that number is non-negative.
*/
int sumDigits(int number);

