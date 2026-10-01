/***************************************************************** 

    File: lab3.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile the program on matrix, type:
        gcc -Wall lab3.c lab3main.c -o lab3
    To run program:
        ./lab3
        
***************************************************************/
// Visual Studio users: Uncomment next line
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



// --------------------------------------------
// Function PROTOTYPES
// --------------------------------------------

// NOTE: You must COMMENT Each function prototype!!!

int isLower(char letter);

char toUpper(char letter);

int readAge(void);

int readDayOfWeek(void);

int readHasCoupon(void);

double ticketPrice(int age, int hasCoupon, int dayOfWeek);



// --------------------------------------------
// Function DEFINITIONS (define each function below)
// --------------------------------------------

