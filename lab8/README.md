# Lab 8

This lab is worth 1.25% of your final grade

## Due Date: 

* End of lab class in week 11

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


## To have the best possible outcome for lab 8:

* Prior to lab, complete all the reading listed for week 11 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
    * [Files](https://seneca-scpa.github.io/Introduction-To-Programming/L-TextFiles/intro)


**CODESPACES have been disabled.  Please use your local development environment**

## Quiz Part-1

* Part-1 of quiz is based on the reading material for week 10 (Files)
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.  No need to copy the question.



## File organization

In the repository you will find 6 files, 3 of which are for the lab source code:

* lab8.h - struct definition and function prototypes.
* lab8.c - function definitions
* lab8main.c - main()

At this point, it is important for you to know how to organize your files.  You have done this numerous times in previous labs.  To complete this lab, you will need to put the appropriate information into the correct file(s).


## Lab Demo:

Your professor will demonstrate:

* how to create the format string to match the data in the Kiosk Configuration file.


## Programmimg problem

In this lab, you will be writing an application that will be used for tracking activity at one or more Currency Exchange Kiosk.  Unlike the previous lab, the data for this lab will come from files and part of the result will go to files.

### File Formats

Your program will work with **three different file formats** you will need to load information into variables used by your program:

> [!IMPORTANT]
> All three (3) files are highly structured data, therefore, you must apply [Pattern 3: Read Structured Data](https://seneca-scpa.github.io/Introduction-To-Programming/L-TextFiles/reference#pattern-3-read-structured-data) as described in the course notes.
>
> **You are not permitted to read the file line-by-line or character-by-character**


#### File 1: Kiosk Configuration (kiosks.csv)

This file consists of a header row and information about a kiosk. The header row describes the information stored in the file.  Sample file below (note the real data file may be larger than this)

```
id,commission_rate
12345,1.0
54321,1.5
67890,2.0
11111,2.5
22222,3.0
```

#### File 2: Currency Data (currencies.txt)

This file consists of a header row and the currencies stored at each kiosk. Each row of data consists of items separated by the pipe (`|`) character.  The header row describes the data stored. Sample file below (note the real data file may be larger than this)

```
kiosk_id|iso|full_name|exchange_rate
12345|USD|United States Dollar|0.73
12345|MXN|Mexican Peso|12.93
12345|GBP|British Pound|0.58
54321|EUR|Euro|0.64
54321|JPY|Japanese Yen|110.50
67890|AUD|Australian Dollar|1.35
67890|CHF|Swiss Franc|0.92
11111|INR|Indian Rupee|83.12
11111|BRL|Brazilian Real|5.25
22222|ZAR|South African Rand|18.50
22222|SGD|Singapore Dollar|0.98
```

#### File 3: Transaction Data (endofday.txt)

This file consists of a header row and a series of transactions at the various kiosks. Each row of data consists of items separated by semi-colons (`;`) character.  The header row describes the data stored.  For direction, a value of `1` means that the transaction was to CAD.  A value of `0` means it is from CAD.  Sample file below (note the real data file may be larger than this)

```
kiosk_id;currency_iso;direction;amount
12345;USD;1;100.00
12345;MXN;0;500.00
54321;EUR;1;75.50
12345;USD;0;250.00
54321;EUR;0;150.00
67890;AUD;1;200.00
11111;INR;0;1000.00
22222;ZAR;1;500.00
12345;GBP;0;300.00
54321;JPY;1;50000.00
```


### Structures

Please define all structs in `lab8.h` according to the information provided using the exact names and order for the data members and the struct name itself.  These are exactly the same structs as those defined for lab 7.  You may copy over the struct definitions from lab7.h as a starting point for this lab.

#### Currency Struct

In lab8.h, define a struct using the exact data member names, description above called `Currency`

The **Currency** struct has the following data members:

* `iso` - a null terminated string with a max of 3 characters.  These 3 characters store the ISO name fore the currency.  For example Canadian dollars is CAD
* `rate` - a double representing the amount of currency we can get with 1 Canadian Dollar
* `fullName` - the full name of the currency, a null terminated string of at most 100 characters


#### Statistics Struct

The **Statistics** Struct keeps track of the number of times a currency was exchanged and the amount of money exchanged to and from Canadian Dollars.

* `numTransactions` - an integer value representing the number of transactions involving a particular currency
* `toCAD` - a double representing the total amount of money transferred to Canadian dollars from this currency
* `fromCAD` - a double representing the total amount of money transferred from Canadian dollars to this currency

#### ExchangeKiosk Struct

The **ExchangeKiosk** struct keeps track of information about an ExchangeKiosk.  Each ExchangeKiosk struct has the following information:

* `storeID` - an integer that represents the id of the store
* `currencies` - An array of Currency structs (Capacity of 20)
* `stats` - A parallel array to currencies that keeps track of the number and amount of the transactions for the corresponding currency(Capacity of 20)
* `numCurrency` - the number of currencies the store processes (integer)
* `commission` - the percentage that the store charges each customer for doing the exchange.  For example 1% is stored as 0.01
* `profit` - the amount of profit earned at the Kiosk

### Program Overview

1. **Setup**:
	* Your program will read and process information from data files.  
	* Load information from 2 files to set up your kiosks.
	* Your program must store information about a maximum of 10 kiosks.
  	* Load kiosk data from `kiosks.csv`
	* Load currencies available at each kiosk from `currencies.txt`
	* If either files fails to open, print the error message below and end the program
		 `could not open <filename>`
2. **Print Banner**: 
	* Print the banner:
	```
	IPC Currency Exchange Batch Application
	=======================================
	```
3. **Main Menu**:
	* Print the following information and read user input
	```
	1. Display Kiosk Information
	2. Load and Process Transactions from File
	3. Exit
	Please enter your choice:
	```
 	* When the choice is 1, the program displays the information about all the kiosks in the same manner as [lab 7](../lab7/lab7.md)
    * When the choice is 2, the program will ask the user to enter the name of a transaction file.  The program will then load the transactions from that file. 
4. **Exit with File Output**:
   - When user chooses to exit, print an end of day report to the file `endofday.txt`.  See below for details
   - Exit the program


### Functions from lab 7

Start by copying over all the functions 7.  These can be used to help you implement the code for this lab. See lab 7 lab specs for details on these functions.  Note that you may need to modify some of these in order to use them for this lab.

```c
double fromCAD(const struct Currency* currency, double money);
double toCAD(const struct Currency* currency, double money);
void displayKioskInfo(const struct ExchangeKiosk* kiosk);
int addCurrency(struct ExchangeKiosk* kiosk, const struct Currency* newCurrency);
int handleTransaction(struct ExchangeKiosk* kiosk, int currencyIdx, int isToCAD, double amount);
void printStats(const struct ExchangeKiosk* kiosk);
```
### New Lab 8 Functions:

Write the following functions:

#### Function 1:

```c
int isSameString(const char s1[], const char s2[]);
```
This function returns 1 if s1 is exactly the same as s2, 0 otherwise. NOTE: using functions from string.h is not allowed here.  You need to implement this by comparing corresponding letters.


#### Function 2:

```c
int findKioskIndex(int keyID, const struct ExchangeKiosk kiosks[], int numKiosks);
```
This function is passed an storeID (`keyID`), an array of ExchangeKiosks (`kiosks`) and the number of Kiosks in the array (`numKiosks`).  The function returns the index of the kiosk with a storeID that matches the `keyID`.  If none of the kiosks have a matching storeID, function returns -1

#### Function 3:

```c
int findCurrencyIndex(const char keyIso[], const struct Currency currencies[], int numCurrency);
```
This function is passed an ISO currency string, (`keyIso`), an array of Currency structs (`currencies`) and the number of Currency in the array (`numCurrency`).  The function returns the index of the Currency with an iso that matches the `keyIso`.  If none of the currencies have a matching iso, function returns -1

(Hint: use isSameString() to compare the iso strings)

#### Function 4:

```c
int loadKiosks(const char filename[], struct ExchangeKiosk kiosks[], int capacity);
```
This function is passed the name of a file as described by Kiosk Configuration above, an array of ExchangeKiosk structs and the capacity of the array.  The function will open the file and use that information to load the data into the `kiosks` array. If the data file could not be opened, the function returns -1, otherwise function returns the number of kiosks stored.

The kiosks array is initialized as follows:
* store each row in kiosk array in the same order as that in the file.  Thus first kiosk in file is stored into kiosks[0], second kiosk is in kiosks[1] etc.
* kiosk id's must be a positive integer.  If the kiosk id is not valid, the row of data is ignored and not stored
* `storeID` and `commission` are read from file
* `numCurrency` and `profit` is initialized to 0
* `currencies` and `stats` array is initially empty
* NOTE: kiosks should never store more than `capacity`.  If the file contains more data than capacity, the excess rows must be ignored
* be sure to close the file before exiting the function



#### Function 5:

```c
int loadCurrencies(const char* filename, struct ExchangeKiosk kiosks[], int numKiosks);
```

This function is passed the name of a file as described by Currency Data file above, an array of ExchangeKiosk structs and the number of kiosks in the array.  The function will open the file and use that information to add the currencies to the kiosks. If the data file could not be opened, the function returns -1, otherwise function returns the number currencies stored.

During this process ensure to check for and handle the following:
*  If the kiosk_id value for a row of data does not have a matching kiosk in the kiosk array, the row of data is ignored and not added.
*  The kiosk's number of currencies should never store more than it is capable of.  Any attempt to store more currencies for a kiosk than it is able to hold must be ignored
*  Do not store a duplicate of the currency, if a currency with same iso already exists for that kiosk, do not add a second copy of the currency
*  Be sure to close the file before exiting the function

* Hint: Use findKioskIndex(), findCurrencyIndex() and addCurrency() to help you...work out how to make the appropriate function call and this function is a lot easier than it looks.

#### Function 6:

```c
int loadTransactions(const char* filename, struct ExchangeKiosk kiosks[],int numKiosks);
```

This function is passed the name of a file as described by Transaction Data file above, an array of ExchangeKiosk structs and the number of kiosks in the array.  The function will open the file and use that information to apply the transactions to the kiosks, updating the stats and profit information for the kiosk. If the data file could not be opened, the function returns -1, otherwise function returns the number transactions handled.

During this process ensure to check for and handle the following:
* ensure that a matching kiosk exists
* ensure that a matching currency exist for the given kiosk
* Be sure to close the file before exiting the function

* Hint: Use findKioskIndex(), findCurrencyIndex() and HandleTransactions() to help you write this function. 


#### Function 7:

```c
void printReport(const char* filename,const struct ExchangeKiosk kiosks[],int numKiosks);
```
This function is passed the name of a file, an array of ExchangeKiosk structs and the number of kiosks in the array.  The function will open the file and output a report about each kiosk in the kiosks array to that file AND output the same report to the screen.

For each kiosk output the following:
```
Kiosk # <kiosk number>
Commission Earned: <profit>

Summary:
<stats for the kiosk>
--------------------------------------------------
```
The stats for kiosk are the stats information for each currency.  Each row of output looks like this:

```
<iso> - <number of transactions>: <CAD to currency>; <CAD from currency>
```

HINT:
1. Duplicate the printStats() function from lab 7 and add a FILE* as one of the arguments then make the call to print the stats for each kiosk to a file
2. Be sure to manually review the output file with the screen output to make sure the data is properly stored!



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




### Adding Extra functions:

Outside of the functions below, you may wish to consider the addition of extra functions that you find may be commonly used.

### Function 1:
```c
int readNumericDataFile(const char* name, struct DateTime records[], int maxCapacity);
```

This function is passed the **name** of a file where the data consists of 5 numbers separated by commas on a single line (format details below).  The function will read each line of the file and store the information into the **records** array.  Each line is stored is stored into its own element, starting with the first line being stored into the first element, second line into the second element etc.  The maximum Capacity is passed into the function through **maxCapacity**.  No further records should be stored once **maxCapacity** records have been added to the array, even if there is more data in the file. If the file cannot be opened, the function does nothing and returns 0.  Otherwise, function returns the number of records stored into **records** array

File must be properly closed before the end of the function.


Below is the format of each line in the file.  The day, month, year, hour and min are all numeric and represents a single DateTime.

```
day,month,year,hour,min
```

Thus, file could look like this:

```
1,1,2024,2,12
31,12,2024,23,59
```



### Function 2:

Write the following function:
```c
int readStringDataFile(const char* name, struct DateTime records[], int maxCapacity);
```
This function is passed the **name** of a file where the data for multiple date times are stored (format details below).  The function will read each line of the file and store the information into the **records** array.  Each line is stored is stored into its own element, starting with the first line being stored into the first element, second line into the second element etc.  The maximum Capacity is passed into the function through **maxCapacity**.  No further records should be stored once **maxCapacity** records have been added to the array, even if there is more data in the file. If the file cannot be opened, the function does nothing and returns 0. Otherwise, function returns the number of records stored into **records** array

File must be properly closed before the end of the function.


Below is the format of each line in the file which stores the dates and time as string. Each line stores a single DateTime

```
date;time
```
The date is of the form:

```
dd/mm/yyy
```
For example:
```
01/01/2024
```

The time is formatted as:

```
hour:minute am/pm
```

For example:
```
2:12 am
```

Thus, file could look like this:

```
01/01/2024;2:12 am
31/12/2024;11:59 pm
```

### Function 3:


Write the following function:
```c
void printToFile(const char* filename, struct DateTime data[], int size);
```

This function is passed the name of a data file.  It will print every element of data into the file.  Each element should be printed on one line in the format:


```
date time
```
For example:

```
November 8, 2024 8:14 am
```

The format for date is:
```
monthname day, year
```

#### Examples

```
day = 1, month = 4, year = 2024 - date component will be printed as: April 1, 2024
```

(tip: remember you did part of this in an earlier lab ...)


The full format for the date and time component are described below

The format for time is:

hour:minutes am/pm

#### Examples

```
hour = 23, minute = 33 - time component will print "11:33 pm"
hour = 0, minute = 55 - time component will print "12:55 am"
hour = 6, minute = 15 - time component will print "6:15 am"
hour = 14, minute = 0 - time component will print "2:00 am"
```

Suppose that you had an array of two DateTime structs, the output would be formatted as follows:

```
November 8, 2024 8:14 am
January 1, 2024 11:25 pm
```

