# Lab 6

This lab is worth 1.25% of your final grade

## Due Date: 

* End of lab class in week 9

## Objectives:

* practice writing/reading functions/programs that involves structs
* practice writing/reading functions/programs that involves pointers

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


## To have the best possible outcome for lab 6:

* Prior to lab, complete all the reading listed for week 8 and 9 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
    * [Structs](https://seneca-scpa.github.io/Introduction-To-Programming/I-Structs/intro)
    * [Pointers](https://seneca-scpa.github.io/Introduction-To-Programming/J-PointersAndParameters/intro)



**CODESPACES have been disabled.  Please use your local development environment**

## Quiz Part-1

* Part-1 of quiz is based on the reading material for week 8 and 9 (stucts and pointers)
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.  No need to copy the question.



## File organization

In the repository you will find 6 files, 3 of which are for the main lab:

* lab6.h - struct definition and function prototypes.
* lab6.c - function definitions
* lab6main.c - main()

At this point, it is important for you to know how to organize your files.  You have done this numerous times in previous labs.  To complete this lab, you will need to put the appropriate information into the correct file.

## Lab Demo 1:

Your professor will discuss with you what to put into each file for your lab and how to write the ```makeChange()``` function


## Programming Problem Overview

In this lab you will write currency Exchange program.  You will define a struct that represents a currency's exchange rate.  You will then write a program that can convert amounts to and from Canadian dollars to that currency.

In next week's lab, we will augment this problem to build a more robust program involving multiple exchange rates.


The program for this week's lab will:

* will ask the user whether they wish to convert some amount of money to Canadian Dollars or From Canadian Dollars.
* Ask them to enter an amount
* calculate the converted value
* Output the converted value's result
* If the exchange is converting to Canadian dollars, it will calculate the number of types of each bill and coins required to make up the amount.


### Defining the Currency struct

In order to solve this problem we want to represent a currency.  A currency is more than just the exchange rate.  It is also has a description and an iso name.  We want to represent this all of this information in our struct.  Please use these exact names in this exact order

This is the information we want in every currency struct:

* `iso` - a string with a max of 3 characters.  These 3 characters store the ISO name fore the currency.  For example Canadian dollars is CAD
* `rate` - a double, the amount of currency we can get with 1 Canadian Dollar
* `fullName` - the full name of the currency, a string of 100 characters

In lab6.h, define a struct using the exact data member names, description above called `Currency`

### Function 1:
```c
void makeChange(int cents, int* quarters, int* dimes, int* nickels);
```
In Canada, we have only 3 denominations of coins worth less than $1. They 
are:
* quarters (25 cent coin)
* dimes (10 cent coin)
* nickels (5 cent coin)

When giving change we round to the nearest nickel.  If the ending cents is 1,2,6 or 7 we round down, if it is 3,4,8 or 9, we round up.

Thus, if the amount of change is 87 cents, we would round down to 85 cents in coins (3 quarters and 1 dime).  However, if the amount of change was 88 cents, we would round up to 90 cents in coins (3 quarters, 1 dime and one nickel).

This function is passed **total cents** which is the amount of money we are making change for.  You may assume this number is between 0 and 97 inclusive (98 and 99 round up to $1.  Therefore we are not going to pass those values in) Your function will calculate the number of each coins needed to reach this amount (rounding up and down as needed).

Examples:

```c
int quarters, dimes, nickels;
makeChange(86, &quarters, &dimes, &nickels);
//after the function call, quarters = 3, dimes = 1, nickels = 0

makeChange(89, &quarters, &dimes, &nickels);
//after the function call, quarters = 3, dimes = 1, nickels = 1
```
### Function 2:
```c
void getBills(int money, int* hundreds, int* fifties, int* twenties, int* tens,
											int* fives, int* toonies, int* loonies);
```
This function is given an amount of money and passes back the number of bills/coins needed to make up that amount of money.

Note: 
* a toonie are two dollar coins (because it rhymes with loonie but is worth (t)wo dollars)
* a loonies are one dollar coins (because there is bird (a loon) on it)

Examples:

```c
int hundreds, fifties, twenties, tens, fives, toonies, loonies;
getBills(15, &hundreds, &fifties, &twenties, &tens, &fives, &toonies, &loonies);
//after the function call, hundreds= 0, fifties=0, twenties=0, tens=1, fives=1, toonies = 0, loonies = 0

getBills(103, &hundreds, &fifties, &twenties, &tens, &fives, &toonies, &loonies);
//after the function call, hundreds= 1, fifties=0, twenties=0, tens=0, fives=0, toonies = 1, loonies = 1);
```

### Function 3:

Write the following function:
```c
double fromCAD(const struct Currency* currency, double money);
```
This function is passed a Currency and the amount of money (in Candian Dollars) and returns the amount of money using the exchange rate specified in currency


### Function 4:

Write the following function:
```c
double toCAD(const struct Currency* currency, double money);
```
This function is passed a Currency the amount of money (in a foreign currency) and returns the amount of money in Canadian Dollars.

### Function 5:

Write the following function:
```c
void getDollarsAndCents(double money, int* dollarPart, int* centPart);
```
This function is passed an amount of money represented as a double.  The function passes back the number of dollars and cents through dollarPart and centPart

Example:

```c
int dollars, cents;
getDollarsAndCents(123.00, &dollars, &cents);
//after the function call, dollars = 123, cents = 0);

getDollarsAndCents(0.54, &dollars, &cents);
//after the function call, dollars = 0, cents = 54);

getDollarsAndCents(123.54, &dollars, &cents);
//after the function call, dollars = 123, cents = 54);

```

### The program:

Your program will:

* Print this banner at start of program:
```
IPC Currency Exchange Machine
=============================
```
* Set up an instance of Currency for any non-Canadian currency you want.
* Use google to find the description, iso name and rate.
* Ask user if they wish to exchange from `<iso>` to CAD or vice versa.
	* Example, if you chose United States dollars then the iso name is USD and your menu would be:
	```
	1) exchange from USD to CAD
	2) exchange from CAD to USD
	Your choice (1 or 2):
	```
	* Make sure you are not hardcoding your iso name into your output, use the instance of the Currency struct you created for this output.
	* The input must be validated using methods previously discussed.  If user enters invalid information, be sure to ask them to re-enter.
    	* the process of doing this has been done many times in the past.  You can look back to your previous labs on how to do this.  Ensure that user enters either a 1 or a 2
* Ask user to enter the amount of money
	```
	Enter amount: 
	```
* Perform the exchange as necessary
* Print one of the following depending on menu choice
	* If converting to CAD, make sure to list the number of each type of bills and coins for amount of money, one per line:
	```
	Converting <description> to Canadian Dollars
	<user input> <currency iso> is <amount of money> CAD
	* <a> hundreds
	* <b> fifties
	*  ...
	```
	* or if converting from CAD only print the amount of money with the iso currency and currency description
	```
	Converting Canadian Dollars to <description>
	<user input> CAD is <amount of money> <currency iso>
	```
#### Sample run 1:
```
IPC Currency Exchange Machine
=============================
1) exchange from USD to CAD
2) exchange from CAD to USD
Your choice (1 or 2): 3
That was not a valid option
Your choice (1 or 2): 2
Enter Amount: 10.00
Converting Canadian Dollars to United States Dollars
10.00 CAD is 7.40 USD
```

#### Sample run 2:
```
IPC Currency Exchange Machine
=============================
1) exchange from USD to CAD
2) exchange from CAD to USD
Your choice (1 or 2): 1
Enter Amount: 10.00
Converting United States Dollars to Canadian Dollars
10.00 USD is 13.60 CAD
* 0 hundreds
* 0 fifites
* 0 twenties
* 1 tens
* 0 fives
* 1 toonie
* 1 loonie
* 2 quarters
* 1 dime
* 0 nickels
```


---

## Walkthrough

### Lab Demo 2:

Your professor will demonstrate how to setup walkthroughs involving structs.

Programs that involve structs are track in a similar way as those that involve arrays.  In your table, each instance of a struct has a column for each of the data members of the struct.


<img width="575" src="./_images/lab6walk.png"/>


## Quiz Part-2

Part 2 of the quiz is based on the lab.

* Your professor will project the question(s) for quiz part-2 on the screen
* Record your answers on the same worksheet used from quiz part-1
* You only need to note the question number and your answer - there is no need to copy the question


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
| **Unsatisfactory** | 1. Scored 0 on the quiz  `OR` <br> 2. Did not attempt walkthrough `OR` <br> 3. Did not update your lab 1 repository with any code before end of lab period |
| **Incomplete** | 1.  Scored more than 0% but less than 50% on the quiz```OR``` <br> 2. Did not complete walkthrough ```OR```<br> 3. Repository was updated by the end of class but did **not pass action tab tester for all parts of the main lab ** having a red X for one or more components of the main lab in the actions tab|
| **Satisfactory** |1. Scored 50% or better on the quiz ```AND```<br> 2. Completed walkthrough ```AND```<br> 3. Repository was updated by end of the lab```AND```<br> 3. Coded solution **passed action tab tester** with a green check mark in the actions tab for all parts of main lab|


### Rubric

|  | Level: 0 | Level: 1 | Level: 2 |
| -------- | ------- | ------- | ------- |
| **Grade** | `0.0` | `0.5` | `1.0` |
| **Description** | Unsatisfactory | Incomplete | Satisfactory |



## Extra Practice:



### DateTime Struct

Some of the functions below work with the DateTime Struct:

```c
struct DateTime
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
};
```
* day is the day of the month (1 to 31)
* month is the month of the year (1 to 12)
* year is the year
* hour is the hour component of time on the 24 hour clock
* minute is the minute component of the time

## Extra Practice 1:


Write the following function:
```c
void setTime(const char timeString[], struct DateTime* dt);
```

This function is passed **timeString** which is a string in the form 
hh:mm. You may assume the string is always this format.  The function 
will extract the hour and minutes from **timeString** and store this 
information as integers into the DateTime struct pointed at by **dt**


## Extra Practice 2


```c
void countCharacters(const char str[], int* numAlpha, int* numDigits);
```

This function is passed a null terminated character string.  It will pass 
back the number of alphabetic characters (either upper or lower case) 
through numAlpha, and the number of numeric characters through numDigits. 
 Function does not return anything.


## Extra Practice 3:


```c
void minMaxAverage(int array[],int size, int* minIdx, int* maxIdx, 
double* average);
```

This function finds and passes back:
* index of the smallest value in the array through minIdx.  In the case 
of a tie, pass back the index of the first of the smallest index
* index of the largest value in the array through maxIdx.  In the case of 
a tie, pass back the index of the last of the largest index
* average of the values in the array



### Extra Practice 4:

Write the following function:

```c
void setDate(const char dateString[], struct DateTime* dt);
```

This function is passed **dateString** which is in the form dd/mm/yyyy.  You may assume the string is always this format.  The function will extract the day, month and year from **dateString** and store the information as integers into the DateTime struct pointed at by **dt**.


