# Lab 9

This workshop is worth 1.25% of your final grade

## Due Date: 

* End of lab class in where lab is assigned

## Objectives:

* practice writing/reading functions/programs that involves complex aggregate types

## Lab Repository

### Already did Lab-0?
If you have already have completed Lab-0 and have your **own code repository**, go directly to your repository:

- https://github.com/seneca-ipc-s26
- Navigate to the respective lab folder and code your solution using the provided starter source files.

### Didn't do Lab-0...
You must join the IPC classroom to get your coding respository. Follow these instructions to get your repository for all your assessments:
1. To get started, [click on this link for your work repository](https://classroom.github.com/a/UNEXMgcI)
2. These steps may not be required if you had done this in a previous lab.
	- Enter your **SENECA USERNAME** (the username part of your seneca email)
	<img width=600 src="../enterteam.jpg"/><br>
	- Hit **`Create Team`** button
	- On the next page hit accept assignment.


## To have the best possible outcome for lab 9:

* Prior to lab, complete all the reading listed for week 11 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
	* []

**CODESPACES have been disabled.  Please use your local development environment**


## File organization

In the repository you will find 6 files, 3 of which are for the lab source code:

* lab9.h - struct definition and function prototypes.
* lab9.c - function definitions
* lab9main.c - main()

At this point, it is important for you to know how to organize your files.  You have done this numerous times in previous labs.  To complete this lab, you will need to put the appropriate information into the correct file(s).


## Lab Demo:

After giving you roughly 60 minutes to do the debugging problems, your prof will go over the list of bugs for each of the debugging problems.

## Debugging:

### Problem 1:

countSame() is a function that is passed two null terminated strings.  It will count the number of characters in the two strings where the corresponding characters are the same. alphabetic characters are compared case insensitively.  For example if the two strings where "apple" and "Alpine", this function would return 2 because these letters in the same position are the same **a**p**p**le **A**l**p**ine.  However, there are bugs in this function.

Identify the bugs and classify them as:
* (S)yntactic
* (L)ogical
  
```c
#include <string.h>
#include <ctype.h>

int countSame(char s1,char s2)
{
	int rc;
	int i;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (i = 1;i < len1 < len2;i++){
		tolower(s1[i]);
		tolower(s2[i]);
		if(s1[i]==s2[i]){
			rc++;
		}
	}
	return rc;
}
```
### Problem 2:

The following is program will call a function called generateRandomString() to generate a random string of printable character arrays. The generateRandomString function is passed a character array and the maximum number of characters it can store.  It will then call the countAlpha() function which returns a count of the number of alphabetic characters in the generated string and print the result.

However, there are bugs in this program. Identify the bugs and classify them as:
* (S)yntactic
* (L)ogical
* (P)erformance - your program works, but is ridiculously slow.  Explain how you would alter code to avoid this problem:

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CAPACITY 1000000

void generateRandomString(char str[], int max)
{
	int i;
	for (i = 0;i <= max;i++){
		str[i] = rand() % 128;
		while(!isprint(str[i])){
			str[i]= rand()%128;
			i++;
		}
	}
}
int countAlpha(const char str[])
{
	int total;
	for(i = 0;i < strlen(str);i++){
		if(isalpha(str[i])){
			count++;
		}
	}
	return 0;
}

int main(void)
{
	char str[MAX];
	int numAlpha;
	generateRandomString(str,MAX);
	numAlpha = countAlpha(str);
	return 0;
}

```
## Programming:

In this lab, we will be putting together just a new main program using the code in labs 7 and 8.  The lab will create the kiosks with various currencies based on data stored in files. (you already wrote the code to do this in lab 8).  It will then allow users to use a kiosk interactively and store the transactions to a data file.

For this lab, you will use the functions defined in the previous labs.  However, in some cases you will be asked to make some small updates to the functions.  

In this lab, make use of the following constructs where appropriate:
* switch statement
* conditional operator
* functions from string.h, ctype.h

### Altering previous lab functions:

* Alter any function that used isSameString() to use strcmp() instead

### Read the specs and identify possible functions for code reuse:

* Other than functions from lab 9, there are other elements that are used in different parts of the program.  Look the specs, and define some functions to help you with your task.  Test these functions to ensure they work.


### Program Overview

1. **Setup**:
	* Your program will read and process information from data files.  
	* Load information from 2 files to set up your kiosks. (defined in the same manner as lab 8)
	* Your program must store information about a maximum of 10 kiosks.
  	* Load kiosk data from `kiosks.csv`
	* Load currencies available at each kiosk from `currencies.txt`
	* If either files fails to open, print the error message below and end the program
		 `could not open <filename>`
2. **Get Background Information**:
	* Ask the user for the current month, day and year (in that order).  The month should be entered by their name, day and year are numeric.
	* Using this information create a file with the name `month-day-year.txt` where month, day and year are replaced with the data entered. 
	```
	Please enter the month: March
	Please enter the day: 28
	Please enter the year: 2026
	```
	The above would cause a file called March-28-2026.txt to be created for writing.  Write this header into the file:
	```
	kiosk_id;currency_iso;direction;amount
	```
3. **Print header**
	```
	IPC Currency Exchange Application
	=================================
	``` 
4. **Print main menu and ask for choice**
	print the main menu as below and ask user to enter information.
	Here is a good place to apply a **_switch_** statement
	```
	1. Display Kiosk Information
	2. Use Kiosk
	3. Add Currency
	4. Exit
	Please enter your choice:
	```		
5. **Display Kiosk Information**
	Use the same method as lab 8 to display all the kiosk information
6. **Use Kiosk**
	* This should go onto another menu that will display the kiosk's info one per row along with asking user for a choice numbering.  For example:
	```
	1. #12345 - USD MXN GBR
	2. #11111 - INR BRL
	Choose Kiosk (1 - 2):
	```
	* Once the user chooses the kiosk, the program will then ask for the currency, direction and amount.  Please note how the data is not entered using menus belows:
	* Ask for ISO, ask user to reenter if the iso is not available at that kiosk
	```
	Please enter the ISO of the currency you wish to exchange:
	```
	* Ask if they wish to convert from CAD or to CAD. Ask for reenter if it is not Y or N 
	```
	Are you converting from CAD to <ISO>?  (Y/N):
 	```
    * Ask for amount they wish to convert:
    ```
    How much would you like to exchange: 
    ```
   	* Update Kiosk Stats
   	* Write the transaction into the transaction file created in step 2
7. **Add Currency**
	* This should go onto another menu that will display the kiosk's info one per row along with asking user for a choice numbering.  For example:
	```
	1. #12345 - USD MXN GBR
	2. #11111 - INR BRL
	Choose Kiosk (1 - 2):
	```
	* Once the user chooses the kiosk, the program will then ask for the currency iso and exchange rate
	```
	Please enter the ISO of the currency you wish to add:
	```
	* Ask for the exchange rate:
	```
	Please enter the exchange rate: 
	```
	* Update the Kiosk with this new currency (ensuring that the currency doesn't already exist and that there is room to add this new currency)
	* Append this new currency to the `currencies.txt` file
8. On Exit, prepare a report in the same manner as described in lab 8


## Submission Instructions:

* Submit to your professor your paper worksheet containing your answers to the quiz questions
    * It **must be submitted to get any marks** for the lab
* Update your repository with your solution to the programming problem:
    * Here is a [guide on how to push code from Visual Studio Code and Visual Studio](../gitinstructions/gitpush.md)
 * Submit the url of your github repository (the one with the actions tab) to blackboard before end of your class!
    * On Blackboard for this course, go to the **Labs Content Area** and click on the **Lab5** assessment link. Paste the URL to your GitHub repository and submit


### Submission testing:

When you submit your code, your program will be put through a series of tests.  Please remember to check your `Actions` tab in your lab repo after you update it with your code.  Remember to expand to ensure the full program is also working as expected.  See lab 2 for more details about submission testing.


## Rubric:

To be eligible for full marks, you will need the following, (see above submission instructions for details):
 
* Score a minimum 50% on the combined questions from the quiz (parts 1 and 2 combined)
* Complete the walkthrough showing clear tables to track the data and clear output.
* Code must be committed and pushed (updated) back into your GitHub repository
	* Even if if it is not working or is incomplete (timestamped no later then by end of lab class)
	* Must have a green checkmark indicating a preliminary passed test (found in the **Actions** tab of your repository)
 * URL to github repo for lab 1 (not url to codespace) must be posted to blackboard.  See submission sections for details.

### Rubric Description

**In class participation is mandatory to receive any marks for the lab.  If you are not in class, you will get 0 marks even if you submit the code for the lab.**

| Grade | Description|
| ----- | -----------|
| **Unsatisfactory** | 1. Did not attempt debugging `OR` <br> 3. Did not update your lab repository with any code before end of lab period |
| **Incomplete** | 1.  Did not complete the debugging problems ```OR``` <br> 2.  Repository was updated by the end of class but did **not pass action tab tester for all parts of the main lab ** having a red X for one or more components of the main lab in the actions tab|
| **Satisfactory** |1. Completed debugging questions  ```AND```<br> 2. Repository was updated by end of the lab```AND```<br> 3. Coded solution **passed action tab tester** with a green check mark in the actions tab for all parts of main lab|


### Rubric

|  | Level: 0 | Level: 1 | Level: 2 |
| -------- | ------- | ------- | ------- |
| **Grade** | `0.0` | `0.5` | `1.0` |
| **Description** | Unsatisfactory | Incomplete | Satisfactory |



## Extra Practice 



### Debugging part a:

In this problem there is a struct called StringCollection.  This struct stores 2 C-strings of at most MAX characters where MAX is a constant defined using a #define statement.  

combine() is a function that is passed a character array and the address of an instance of StringCollection.  The function will place into the character array a combination of the 2 string from the StringCollection struct so that the combined string contains the shorter string first and the longer string second.  If the strings are the same length, put the string that is alphabetically earlier first. Thus, if the struct had the strings "Hello there", "Hi hi", the combined string would be "Hi hi Hello there".  If the string had "orange", "banana" the combined string would be "banana orange".  You may assume that the character array is big enough to hold the resulting string.  The function returns the length of the final string.  

The code below defines the struct and implements the combine function.  However, there are bugs.  Identify the bugs and classify them as:
* (S)yntactic
* (L)ogical


```c
//assume all includes and defines have been done

struct StringCollection
{
	char s1[MAX];
	char s2[MAX];
};

int combine(char str[], struct StringCollection* collection)
{
	int len1 = strlen(collection.s1);
	int len2 = strlen(collection.s2);
	if(len1 == len2){
		if(strcmp(collection.s1, collection.s2) > 0){
			str = collection.s1;
			strcat(str,collection.s2);	
		}
		else{
			str = collection.s2;
			strcat(str,collection.s1);	
		}
	}
	else if(len1 < len2)){
		str = collection.s1;
		strcat(str,collection.s2);
	}
	else if(len2 > len1){
		str = collection.s2
		strcat(str,collection.s1);
	}
	return strlen(str);
}
```
### Debugging - part b:


This program defines 3 instances of StringCollection.  The first 2 are initialized with some strings.  The function will use the combine() function on these two StringCollections and store the results into the third initially empty collection.

```c
#include <string.h>
#include <stdio.h>
#define MAX 10
//assume the fixed up version of the struct and combined() are coded here
int main(void)
{
	struct StringCollections collection1 = {"daisy", "lilac"};
	struct StringCollections collection2 = {"turtle", "dove"};
	struct StringCollections collection3;

	char temp[MAX];
	combine(temp, collection1);
	strcpy(collections3.s1, temp);

	combine(collection3.s2, collection2);
	
}
```


### Programming

Some of the functions below work with the DateTime Struct:

```c
#define STRINGMAX 10
struct DateTime
{
	int day;
	char month[STRINGMAX+1];
	int year;
	int hour;
	int minute;
};
```

* day is the day of the month (1 to 31)
* month of the year in its full form.
* year is the year
* hour is the hour component of time on the 24 hour clock
* minute is the minute component of the time


In the lab9practice folder you will find these 3 files:

* lab9practice.h - this file is where you will put the function prototypes.
* lab9practice.c - this is where your functions go
* lab9practicemain.c - this is where you write a main() function to test your program.  

You will also find two data files called:

* lab9format1.txt - an input file for one of the functions
* lab9format2.txt - an input file for one of the functions


In this lab as the data is provided, you would simply verify that what you stored is correct by outputing the data to the screen.




### Adding Extra functions:

Outside of the functions below, you may wish to consider the addition of extra functions that you find may be commonly used.

### Function 1:
```c
int readDataFile1(const char* name, struct DateTime records[], int maxCapacity);
```

This function is passed the **name** of a file where the data consists of 5 numbers separated by commas on a single line (format details below).  The function will read each line of the file and store the information into the **records** array.  Each line is stored to its own element, starting with the first line being stored into the first element, second line into the second element etc.  The maximum Capacity is passed into the function through **maxCapacity**.  No further records should be stored once **maxCapacity** records have been added to the array, even if there is more data in the file. If the file cannot be opened, the function does nothing and returns 0. Otherwise return the number of records read into the array.

Files must be properly closed before the end of the function.


Below is the format of each line in the file.  The day, month, year, hour and min are all numeric and represents a single DateTime.

```
day,month,year,hour,min
```


### Function 2:

Write the following function:
```c
int readDataFile2(const char* name, struct DateTime records[], int maxCapacity);
```
This function is passed the **name** of a file where the data for multiple date times are stored (format details below).  The function will read each line of the file and store the information into the **records** array.  Each line is stored to its own element, starting with the first line being stored into the first element, second line into the second element etc.  The maximum Capacity is passed into the function through **maxCapacity**.  No further records should be stored once **maxCapacity** records have been added to the array, even if there is more data in the file. If the file cannot be opened, the function does nothing and returns 0.  Otherwise return the number of records read into the array.

Files must be properly closed before the end of the function.


Below is the format of each line in the file which stores the dates and time as string. Each line stores a single DateTime

```
time;date
```

The time is formatted as:

```
hour:minute am/pm
```

For example:
```
2:12 am
```

The date is of the form:

```
dd-Mon-yyyy
```
Mon is the three character abbreviation of the month

For example:
```
01-Jan-2024
```


Thus, file could look like this:

```
2:12 am;01-Jan-2024
11:59 pm;31-Dec-2024
```

### Function 3

```c
int numMonths(const char monthName[], const struct DateTime dates[], int size);
```
This function is passed the name of a month, an array of DateTime structs and the size of that array.

Function will return the number of structs in the dates array with a matching month.


## Walkthrough

What is the exact output of the following program.  Show your work with tables and diagrams

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

void go(int n, char s[]);
void climb(char s[]);
void fall(char s[]);

int main(void)
{
    char s1[MAX+1] = "grjm";
    char s2[MAX+1] = "RM";
    char s3[MAX+1] = " fQyP!";
    char final[MAX+1] = "";
    int i;

    climb(s1);
    printf("1: %s\n", s1);

    fall(s2);
    printf("2: %s\n", s2);

    climb(s3);
    printf("3: %s\n", s3);

    strcpy(final, s1);
    printf("4: %s\n", final);

    strcat(final, " ");
    strcat(final, strcat(s2, "! "));
    printf("5: %s\n", final);
    
    strcat(final, s1);
    printf("6: %s\n", final);

    go(3,final);
    printf("7: %s\n", final);

    go(-2, s3);
    printf("8: %s\n", s3);

    strcat(final, s3);
    printf("7: %s\n", final);

    return 0;
}

void go(int n, char s[])
{
    int len = strlen(s);
    int i;

    for (i = 0;i<len;i++){
        if(isalpha(s[i])){
            s[i]+=n;
        }
    }
}

void climb(char s[])
{
    int len = strlen(s);
    int i;

    for(i = 0;i<len;i++){
        s[i]=toupper(s[i]);
    }
}

void fall(char s[])
{
    int len = strlen(s);
    int i;

    for(i = 0;i<len;i++){
        s[i]=tolower(s[i]);
    }
}
```

