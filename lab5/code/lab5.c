/*****************************************************************

	File          : lab5.c
	Author        : [Your Name]
	Student Number: [Your Student Number]

	To compile program on matrix, in a terminal type:
		gcc -Wall lab5.c lab5main.c -o lab5
	To run program on matrix, in a terminal type:
		./lab5

***************************************************************/
// Optional: comment the next line if you are NOT using Visual Studio
// This has no side-effect on other compilers and can be left as-is:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "lab5.h"

// Helper macro used for sizing the dynamically created C String 
// input format string. This macro is only available to the 
// functions in this file and should not be moved into the header!
#define FMTCAP 20

// -------------------------------------------------------------
// FREEBIE Helper Function
// -------------------------------------------------------------
void readMessage(char message[], int max)
{
	char formatString[FMTCAP + 1] = { 0 };
	
	// This function creates a dynamic format string in the form:
	//  %<max>[^\n] 
	// ... where <max> is replaced with the value of parameter value max
	// Therefore, this functions supports any string capacity we wish!
	// 
	// Example, if max=30, this format string would be: "%30[^\n]"
	// 
	// which will enforce reading and storing of no more than max characters 
	// or until new line is read
	sprintf(formatString, " %%%d[^\n]", max);

	//do the actual read
	scanf(formatString, message);

	// Clear the input buffer: 
	// Ask your professor for an explanation why this is necessary!
	while (getchar() != '\n') {
		; // EMPTY CODE BLOCK ON PURPOSE!
	}
}


// -------------------------------------------------------------
// Function Definitions: Place your function solutions below
// -------------------------------------------------------------
