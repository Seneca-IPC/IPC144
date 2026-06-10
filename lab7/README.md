# Lab 7

This lab is worth 1.25% of your final grade

## Due Date: 

* End of lab class in week 9

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


## To have the best possible outcome for lab 7:

* Prior to lab, complete all the reading listed for week 10 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
    * [Complex Aggregate Types](https://seneca-scpa.github.io/Introduction-To-Programming/K-ComplexAggregateTypes/intro)



**CODESPACES have been disabled.  Please use your local development environment**

## Quiz Part-1

* Part-1 of quiz is based on the reading material for week 10 (Complex Aggregate Types)
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.  No need to copy the question.



## File organization

In the repository you will find 6 files, 3 of which are for the main lab:

* lab7.h - struct definition and function prototypes.
* lab7.c - function definitions
* lab7main.c - main()

At this point, it is important for you to know how to organize your files.  You have done this numerous times in previous labs.  To complete this lab, you will need to put the appropriate information into the correct file.


## Lab Demo:

Your professor will demonstrate:

* how to define the Currency Struct as well as part of ExchangeKiosk Struct with you (how to add the data members for `storeID` and `currencies`.  You will be responsible for the rest)
* how you would create an instance of ExchangeKiosk in your main initialized with the data for kiosk 1 in the description below.
* how to call the toCAD() function using the MXN currency from the variable that represents kiosk 1.


## Programmimg problem

In this lab, you will be writing an application that will be used for tracking activity at one or more Currency Exchange Kiosk.  This application will involve the creation and use of some complex aggregate types as well as some functions that operate on these structs.

### Structs

Please define all structs in `lab7.h` according to the information provided using the exact names and ordering for the data members and struct Name.  

#### Currency Struct

(Note that this struct was previously defined in lab 6, you can copy it from that lab if you wish)

In lab7.h, define a struct using the exact data member names, description above called `Currency`

The **Currency** struct has the following data members:

* `iso` - a null terminated string with a max of 3 characters.  These 3 characters store the ISO name fore the currency.  For example Canadian dollars is CAD
* `rate` - a double representing the amount of currency we can get with 1 Canadian Dollar
* `fullName` - the full name of the currency, a null terminated string of at most 100 characters


#### Statistics Struct

The **Statistics** Struct keeps track of the number of times a currency was exchanged and the amount of money exchanged to and from Canadian Dollars.

* `numTransactions` - an integer value representing the number of transactions involving a particular currency
* `toCAD` - a double representing the total amount of money transfered to Canadian dollars from this currency
* `fromCAD` - a double representing the total amount of money transfered from Canadian dollars to this currency

#### ExchangeKiosk Struct

The **ExchangeKiosk** struct keeps track of information about an ExchangeKiosk.  Each ExchangeKiosk struct has the following information:

* `storeID` - an integer that represents the id of the store
* `currencies` - An array of Currency structs (Capacity of 20)
* `stats` - An array of Statistics structs that is a parallel array to currencies that keeps track of the number and amount of the transactions for the corresponding currency(Capacity of 20)
* `numCurrency` - the number of currencies the store processes (integer)
* `commission` - the percentage that the store charges each customer for doing the exchange.  For example 1% is stored as 0.01
* `profit` - the amount of profit earned at the Kiosk

### Program Overview

You will implement the functions listed below and use them to create your program.  In all cases where data entry is required, basic input validation must be implemented (range checking).  You are welcome and encouraged to add additional functions to help you handle the input/output and menus required by the main program.  It will be a good exercise in how to break down your problem. 

The program will do the following:

1. Create two ExchangeKiosks initialized with the following information:
	* Kiosk 1:
		* id - 12345
		* USD (United States Dollar) - exchange rate of 0.73
		* MXN (Mexican Peso) - exchange rate of 12.93
		* commission of 1%
	* Kiosk 2:
		* id - 54321
		* EUR - (Euro) - exchange rate 0.64
		* commision of 1.5%
	* For each currency available at a kiosk, we add a corresponding Statistic with 0 values to the kiosk
	* Initialize profit to 0 for both kiosks
3. Create a menu driven program as follows:
	* Print a starting banner at start of program:
	```
	IPC Currency Exchange Application
	=================================
	```
	* Print the following main menu and ask user for choice:
	```
	1. Use Kiosk 1
	2. Use Kiosk 2
	3. Add Currency to Kiosk 1
	4. Add Currency to Kiosk 2
	5. Display Kiosk Information
	6. Exit
    Please enter your choice: 
	```
4. If the user chooses to Display Kiosk Information print out the basic information about the two Kiosks
```
Kiosk #12345 - 1% commission
Available Currencies:
1. <currency 1>
2. <currency 2>
3. ...

Kiosk #54321 - 1.5% commission
Available Currencies:
1. <currency 1>
2. <currency 2>
3. ...
```
    * go back to the main menu for further processing

5. If the user chooses to Add Currency to one of the Kiosks:
	* Ask user to enter the following
		* iso
		* full name of currency
		* rate
	* Add that Currency to the chosen kiosk, updating the all necessary data members
	* Go back to the main menu
6. If the user chooses to use a specific Kiosk, 
   * create the following sub menu:
   ```
   Which Currency Would you like to exchange?
   1. <currency 1>
   2. <currency 2>
   3. ...
   Please enter your choice:
   ```
   * After choice is entered, ask user if they would like to exchange from CAD or to CAD from the currency chosen
   ```
   1. exchange from <iso> to CAD
   2. exchange from CAD to <iso>
   Please enter your choice: 
   ```
   * After asking from/to, ask for the amount of money they wish to exchange:
   ```
   How much would you like to exchange: 
   ```
   * Update the ExchangeKiosk with the information provided
       * Update the associated Stats object based on user's choice
       * Update the commission earned.  The commission earned is based on the commission rate applied to the amount of Canadian dollars in the transaction
       * Print out the result
    ```
    Converting <description> to Canadian Dollars
	<user input> <currency iso> is <amount of money> CAD
	Commission: <commission amount> CAD
    ```
    or:
    
	```
	Converting Canadian Dollars to <description>
	<user input> CAD is <amount of money> <currency iso>
	Commission: <commission amount> CAD
	```
   * Go back to main menu
7. If the user chooses to exit the program, for each kiosk print an end of day report which includes:
    * the total amount of commission earned
    * statistical report (see printStats() function below for details)
    ```
    End of Day Report
    =================
    Kiosk # <kiosk number>
    Commission Earned: <profit>

    Transaction Summary:
    ====================
    Currency - Number of Transactions: From CAD; To CAD
    <contents of report>
    ```

### Functions

The above program may seem really complicated but we will break down the problem into small functions.  Your program can then use these functions by making the appropriate function calls.  This decomposition process is key to working on large programs.  You may wish to add additional functions to your program to make it easier to write the main.  There may also be code that you wrote in lab 6 that could be very useful here.  You may make use of that code in your solution.



#### Function 1:

Write the following function:

```c
double fromCAD(const struct Currency* currency, double money);
```
This function is passed a Currency and the amount of money (in Candian Dollars) and returns the amount of money using the exchange rate specified in currency

(this was done in lab 6, feel free to copy this over from your previous lab)

#### Function 2:

Write the following function:
```c
double toCAD(const struct Currency* currency, double money);
```

This function is passed a Currency the amount of money (in a foreign currency) and returns the amount of money in Canadian Dollars.

(this was done in lab 6, feel free to copy this over from your previous lab)

#### Function 3:

Write the following function:
```c
void displayKioskInfo(const struct ExchangeKiosk* kiosk);
```
This function displays basic information about the kiosk:
```
Kiosk #<id> - <commissionRate>% commission
Available Currencies:
1. <currency 1>
2. <currency 2>
3. ...
```

#### Function 4:

Write the following function:
```c
int addCurrency(struct ExchangeKiosk* kiosk, const struct Currency* newCurrency);
```
This function is passed the address of an ExchangeKiosk and the address of a Currency struct.  This function will add a copy of the newCurrency to the kiosk using the information passed to the function if there is space in the array to do so.  Should the kiosk already hold the maximum number of currency the kiosk can hold, the newCurrency is not added. Ensure that the related Statistics object is set up with 0 values for every data member.  Functions returns the number of Currency structs held by the kiosk

#### Function 5:

Write the following function:

```c
int handleTransaction(struct ExchangeKiosk* kiosk, int currencyIdx, int isToCAD, double amount);
```
This function is provided with the
* address of an ExchangeKiosk
* the index of the currency we will use for the transaction
* whether the transaction is if it is from CAD to currency (isToCAD == 0) or from currency to CAD (isToCAD == 1
* and the amount of money to exchange

The function will update kiosk by doing the following if currencyIdx is valid:
* update the associated Statistic for the transaction
* update the profit
* return 1

If the currencyIdx is invalid:
* leave kiosk unaltered
* return 0


#### Function 6:

Write the following function:
```c
void printStats(const struct ExchangeKiosk* kiosk);
```

This function is passed a pointer to an ExchangeKiosk object.  The function will:
* print out one per line the currency iso, the number of transactions, the amount of money exchnage from/to CAD to/from the currency.  HINT: remember the currencies and stats arrays are parallel

```
<iso> - <number of transactions>: <CAD to currency>; <CAD from currency>
```

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

### Walkthrough:

What is the output of the following program?

![walkthrough lab 7 image](lab7walk.png)

### Function 1:

Given the following struct definition:

```c
struct Date
{
	int day;
	int month;
	int year;
};
```


Write the following function:
```c
int findDate(int day, int month, int year, struct Date dates[],int size);
```

This function is passed a day, month and year representing a date that we are looking for.  It is also passed an array of Date structs and the size of that array. It will look for a match within the Date array (all 3 numbers have to match in order for the function to be considered a match).  The function returns index of the element with a matching date or -1 if none is found.  You may assume the dates are unique


### Function 2:

Given the following struct definition:

```c
struct Date
{
	int day;
	int month;
	int year;
};
```

Write the following function:
```c
int numInYear(int year, struct Date dates[], int size);
```
This function returns the number of dates that match the year


### Function 3:

Given the following struct definition


```c
struct Date
{
	int day;
	int month;
	int year;
};
```
Write the following function:
```c
int cmpDates(int dayIndex1, int dayIndex2, struct Date dates[]);
```
This function is passed an array and two numbers representing indexes to dates array. You may assume that dayIndex1 and dayIndex2 are both valid elements.

This function returns:

```
0 if dates[dayIndex1] is the same date as dates[dayIndex2]
1 if dates[dayIndex1] is earlier than dates[dayIndex2]
-1 if dates[dayIndex1] is later than dates[dayIndex2]
```


### Function 4:

Given the following struct definition:

```c
struct Date
{
	int day;
	int month;
	int year;
};
```

Write the following function:
```c
int printDates(struct Date dates[], int size)
```
This function is passed an array of Date structs and the size of the array.  It will print the dates stored in the array in the following format.  This will be printed one date per line:

monthname day, year

For example, if the Date array had 3 dates:
```c
struct Date dates[3]={{1,1,2024}, {2,9,2023}, {24, 11, 2024}};
```
the function would print:
```
January 1, 2024
September 2, 2023
November 24, 2024
```









