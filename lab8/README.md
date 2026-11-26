# Lab 8

This lab is worth 1.25% of your final grade

## Due Date: 

* End of lab class in week 11

## What you need to do (by the end of the lab class) 

* Quiz: Record your answers to the in-class quiz on the paper provided to you
* Code: Update your PRIVATE GitHub ipc144 repository:
	* With the solutions to the assigned lab work even if it is not fully functional or completed
	* Submit the code using matrix submitter
	* Submit the URL to your private ipc144 GitHub repository on Blackboard


## Objectives:

* practice writing/reading functions / **FILES** / programs that involve complex types including composition and aggregation.


## To have the best possible outcome for lab 7:

* Prior to lab, complete all the reading listed for week 11 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
    * [Files](https://seneca-scpa.github.io/Introduction-To-Programming/L-TextFiles/intro)


## Lab Preparation

To submit your work for this lab, **YOU MUST HAVE SUCCESSFULLY COMPLETED [Lab-0](../lab0/README.md)** where you configure the tooling and learn the process involved in completing a lab and how to submit your work!


## Quiz Part-1

```
   ___        _          ____            _        _ 
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_     / |
 | | | | | | | |_  /    | |_) / _` | '__| __|____| |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____| |
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|    |_|
```

* Part-1 of quiz is based on the reading material for week 10 (Complex Aggregate Types)
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.  No need to copy the question.

---

## Programming Problem Overview

Continuing with the Currency Exchange Kiosk theme from prior labs (see: [Lab7](../lab7/README.md)), this lab will be include tracking activity at one or more Currency Exchange Kiosks with reading and writing of data from and to files.


## Program Outline

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
	2. Process Transactions from File
	3. Exit
	Please enter your choice:
	```
 	* When the choice is 1, the program displays the information about all the kiosks in the same manner as [lab 7](../lab7/lab7.md)
    * When the choice is 2, the program will ask the user to enter the name of a transaction file.  The program will then load the transactions from that file. 

4. **Exit with File Output**:
   - When user chooses to exit, print an end of day report to the file `endofday.txt`.  See below for details
   - Exit the program

---

## Data Files

The program will require working with **three different file formats**. The file data will need to be loaded into variables and used by your program (or written out to a file from the stored data):

> [!CAUTION]
>
> All three (3) files are highly structured data, therefore, **you must apply [Pattern 3: Read Structured Data](https://seneca-scpa.github.io/Introduction-To-Programming/L-TextFiles/reference#pattern-3-read-structured-data)** as described in the course notes.
>
> **You are not permitted to read the file as complete line-by-line C strings or character-by-character**
>


### File 1: Kiosk Configuration (kiosks.csv)

This file consists of a header row and information about a kiosk. The header row describes the information stored in the file.  Sample file below (note the real data file may be larger than this). This file is read by the application.

```
id,commission_rate
12345,1.0
54321,1.5
67890,2.0
11111,2.5
22222,3.0
```

### File 2: Currency Data (currencies.txt)

This file consists of a header row and the currencies stored at each kiosk. Each row of data consists of items separated by the pipe (`|`) character.  The header row describes the data stored. Sample file below (note the real data file may be larger than this). This file is read by the application.

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

### File 3: Transaction Data (transactions.txt)

This file consists of a header row and a series of transactions at the various kiosks. Each row of data consists of items separated by semi-colons (`;`) character.  The header row describes the data stored.  For direction, a value of `1` means that the transaction was to CAD.  A value of `0` means it is from CAD.  Sample file below (note the real data file may be larger than this). This file is read to by the program, and the same format is used to write parts of the "endofday.txt" report.

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

---

## Structures

Define all structs in `lab8.h` according to the information provided using the exact names and order for the data members and the struct name itself. These are exactly the same structs as those defined from [Lab 7](../lab7/README.md). You may copy the struct definitions from lab7.h as a starting point for this lab.

### **Currency** Struct

The **Currency** struct was previously defined in Lab 6 and has the same requirements for this lab having the following members:

|Member | Description |
|------ | ----------- |
`iso` | a C string with a max of 3 displayable characters.  These 3 characters store the ISO name for the currency.  For example Canadian dollars is CAD
`rate` | a double, the amount of currency we can get with 1 Canadian Dollar
`fullName` | a C string with a max of 100 displayable characters for the full name of the currency


### **Statistics** Struct

The **Statistics** struct keeps track of the number of times a currency was exchanged and the amount of money exchanged **to** and **from** Canadian dollars.

|Member | Description |
|------ | ----------- |
`numTransactions` | an integer value representing the **number of transactions** involving a particular currency
`toCAD` | a double representing the **total amount** of money transferred **to** Canadian dollars from this currency
`fromCAD` | a double representing the **total amount** of money transferred **from** Canadian dollars. NOTE: this total uses the CAD value only NOT the conversion to the other currency.

### **ExchangeKiosk** Struct

The **ExchangeKiosk** struct keeps track of information about a kiosk.  Each ExchangeKiosk struct has the following information:

|Member | Description |
|------ | ----------- |
`storeID` | an integer representing the unique identifier for a store (what store owns the kiosk)
`currencies` | An array of `Currency` structs (**capacity of 20**)
`stats` | An array of `Statistics` structs that is a parallel array to **currencies** that keeps track of the number and amount of the transactions for the corresponding currency(**capacity of 20**)
`numCurrency` | an integer representing the number of currencies the kiosk can exchange (integer)
`commission` | a double representing the percentage the store charges each customer for performing an exchange.  For example 1% is stored as 0.01
`profit` | a double representing the kiosk's amount of profit earned

---

## Functions

### Carry-over functions from Lab-7

Start by copying the functions from Lab-7 as these will be needed for this lab (refer to the [Lab-7](../lab7/README.md) specifications for details on these functions). 

**Note**: that you may need to modify some of these functions to work for this lab.

Here are the prototypes:
```c
double fromCAD(const struct Currency* currency, double money);

double toCAD(const struct Currency* currency, double money);

void displayKioskInfo(const struct ExchangeKiosk* kiosk);

int addCurrency(struct ExchangeKiosk* kiosk, const struct Currency* newCurrency);

int handleTransaction(struct ExchangeKiosk* kiosk, int currencyIdx, int isToCAD, double amount);

void printStats(const struct ExchangeKiosk* kiosk);
```

---


Write the following **new/additional functions**:

### Function 1:

```c
int isSameString(const char s1[], const char s2[]);
```
This function returns 1 if s1 is exactly the same as s2, 0 otherwise.

> [!NOTE]
>
> Using functions from `string.h` is NOT permitted. You will need to implement this logic by comparing corresponding letters.
>

### Function 2:

```c
int findKioskIndex(int keyID, const struct ExchangeKiosk kiosks[], int numKiosks);
```

This function is passed a storeID (`keyID`), an array of ExchangeKiosks (`kiosks`) and the number of actual data Kiosks in the array (`numKiosks`).  The function returns the **index** of the kiosk with a storeID that matches the `keyID`.  If none of the kiosks have a matching storeID, the function returns -1.


### Function 3:

```c
int findCurrencyIndex(const char keyIso[], const struct Currency currencies[], int numCurrency);
```
This function is passed an ISO currency string (`keyIso`), an array of Currency structs (`currencies`) and the number of Currency in the array (`numCurrency`).  The function returns the index of the Currency with an iso that matches the `keyIso`.  If none of the currencies have a matching iso, the function returns -1.

(**Hint: use isSameString() to compare the iso strings**)

### Function 4:

```c
int loadKiosks(const char filename[], struct ExchangeKiosk kiosks[], int capacity);
```
This function is passed the name of a kiosk configuration data file (C string), an array of ExchangeKiosk structs and the capacity of the array. The function reads the data file and stores the data to the `kiosks` array. If the data file could not be opened, the function returns -1, otherwise the function returns the number of kiosk records successfully stored.

The kiosks array is assigned data as follows:
* store each data row from the file to the kiosk array in the same order as the file. Example, the first kiosk in the file is stored into kiosks[0], the second kiosk is assigned to kiosks[1] etc.

* Kiosk id's must be a positive integer.  If the data from the file has a kiosk id that is not valid, the row of data is ignored and not stored to the kiosks array.

* `storeID` and `commission` are assigned to the kiosk as read from the file (no extra validation required).

* `numCurrency` and `profit` must be set to 0.

* `currencies` and `stats` arrays must be set to empty.

* **IMPORTANT**: 
	- Protect the kiosks array! The array must never exceed more than its `capacity`.  If the file contains more data than capacity, the **excess rows must be ignored**.
	- The connection to the data file must be **closed** before exiting the function!

### Function 5:

```c
int loadCurrencies(const char* filename, struct ExchangeKiosk kiosks[], int numKiosks);
```

This function is passed the name of the currency data file (C string), an array of ExchangeKiosk structs and the number of kiosks in the array. The function must read the data from the data file  add store the currencies to the respective kiosks. If the data file could not be opened, the function returns -1, otherwise the function returns the number currencies stored.

Keep the following in mind when processing each data row from the file:
* If the kiosk_id value for a row of data does not have a matching kiosk in the kiosk array, the row of data is ignored and not added (move on to the next data row).

* Protect the kiosk's currencies array boundaries. The kiosk's number of currencies should never store more than it is capable of. Once the capacity of the array is reached, ignore the remaining records.

* Do not store a duplicate of the same currency. If a currency with the **same iso** already exists for that kiosk, do not add a second copy (ignore it and move on to the next row/record).

* **Hints**: 
	- Use `findKioskIndex()`, `findCurrencyIndex()`, and `addCurrency()` to help you... with the aid of these functions, this function is a lot easier than it looks!
	- The connection to the data file must be **closed** before exiting the function!


### Function 6:

```c
int loadTransactions(const char* filename, struct ExchangeKiosk kiosks[],int numKiosks);
```

This function is passed the name of the data file (C string), an array of ExchangeKiosk structs and the number of kiosks in the array.  The function must read the data from the data file add store the transaction data to the respective kiosks, updating the `stats` and `profit` information for the kiosk. If the data file could not be opened, the function returns -1, otherwise the function returns the number transactions successfully processed.

Keep the following in mind as each data record/row is processed:
* ensure a matching kiosk exists (if not, move on to the next data row)
* ensure a matching currency exist for the given kiosk (if not, move on to the next data row)

* **Hint**: 
	- Use `findKioskIndex()`, `findCurrencyIndex()`, and `HandleTransactions()` to help you write this function. 
	- The connection to the data file must be **closed** before exiting the function!


### Function 7:

```c
void printReport(const char* filename,const struct ExchangeKiosk kiosks[],int numKiosks);
```
This function is passed the name of a data file (C string), an array of ExchangeKiosk structs and the number of kiosks in the array. The function displays each kiosks "end of day report" and writes the same output to the data file (identically formatted as it shows on the screen).

For each `kiosk`, output the following:
```
Kiosk # <kiosk number>
Commission Earned: <profit>

Summary:
<stats for the kiosk>
--------------------------------------------------
```

The `stats` for kiosk are the stats information for each currency.  Each row of output looks like this:

```
<iso> - <number of transactions>: <CAD to currency>; <CAD from currency>
```

**HINT**:
1. Copy the printStats() function from **Lab-7** and add a `FILE*` pointer parameter to its signature. For each `printf` statement, duplicate it with an `fprintf` using the file pointer!

2. Be sure to manually review the output file with the screen output to make sure the data is properly stored with the same format (the screen output and file contents should look identical!)

```
  ____                                 _             _   _             
 |  _ \  ___ _ __ ___   ___  _ __  ___| |_ _ __ __ _| |_(_) ___  _ __  
 | | | |/ _ \ '_ ` _ \ / _ \| '_ \/ __| __| '__/ _` | __| |/ _ \| '_ \ 
 | |_| |  __/ | | | | | (_) | | | \__ \ |_| | | (_| | |_| | (_) | | | |
 |____/ \___|_| |_| |_|\___/|_| |_|___/\__|_|  \__,_|\__|_|\___/|_| |_|
                                                                       
```

## Getting Started: Demo

Your professor will demonstrate:

* How to create the format string needed to read in the data from the Kiosk Configuration file (`kiosks.csv`)
* Detail how each field is specifically represented and tailored to match the appropriate type etc.

```
  ___ _   _      __   __                 _____                         
 |_ _| |_( )___  \ \ / /__  _   _ _ __  |_   _|   _ _ __ _ __          
  | || __|// __|  \ V / _ \| | | | '__|   | || | | | '__| '_ \         
  | || |_  \__ \   | | (_) | |_| | |      | || |_| | |  | | | |  _ _ _ 
 |___|\__| |___/   |_|\___/ \__,_|_|      |_| \__,_|_|  |_| |_| (_|_|_)
                                                                       
```

## Program the Functions

In the repository you will find 6 files, 3 of which are for the lab source code, and 3 of which are data files:

**Starter Source Code Files:**
* `lab8.h` - struct definition and function prototypes.
* `lab8.c` - function definitions
* `lab8main.c` - main()

**Data Files:**
* `currencies.txt` - Exchange currency data
* `kiosks.csv` - Kiosk configurations
* `transactions.txt` - Currency exchange transactional data

Code all the remaining functions described above and test each one as you complete them. 

You have done this numerous times in previous labs.  To complete this lab, you will need to put the appropriate information into the correct file.

- **lab8.h** : STRUCTURE(s), Function PROTOTYPES with **DOCUMENTATION for each function**
- **lab8.c** : Function DEFINITIONS
- **lab8main.c** : 
    - **Testing**: Testing your function during the development of the solution
    - **Assembly**: Replace all testing code from your development phase with the program solution. This will assemble and implement those functions as required. Refer to the program outline section for the application features and menu operations.

---

## Submission Instructions:

```
  ____        _               _         _             
 / ___| _   _| |__  _ __ ___ (_)___ ___(_) ___  _ __  
 \___ \| | | | '_ \| '_ ` _ \| / __/ __| |/ _ \| '_ \ 
  ___) | |_| | |_) | | | | | | \__ \__ \ | (_) | | | |
 |____/ \__,_|_.__/|_| |_| |_|_|___/___/_|\___/|_| |_|
                                                      
```

* Submit your code (solution to the programming problem)

	- Update your GitHub PRIVATE ipc144 repository with your solution to the programming problem:
		- Here is an EASY [guide on how to push code from Visual Studio Code and Visual Studio](../gitinstructions/gitpush.md)
		- If you are not using the above IDE's, manually perform the 3-git commands (from anywhere within your repository directory structure):
			```
			git add -A
			git commit -am "Completed lab8"
			git push origin main
			```

	- Connect to **matrix**: 
		- Open a command prompt (or terminal) window
		- Type the following connection command and substitute `loginName` with YOUR Seneca login name!
		```
		SSH loginName@matrix.senecapolytechnic.ca
		```
	- Change to the directory where you cloned your ipc144 repository (use the `cd` command accordingly)
	- Update the matrix copy of your PRIVATE ipc144 GitHub repository:
		```
		git pull origin main
		```
	- Change to the `lab8` directory (inside your ipc144 repository):
		```
		cd lab6
		```
	- Submit your code using the submitter. Substitute `professor.name` with your professor\'s account name, and `NQQ` with your course section code:
		```
		~professor.name/submit 144lab8/lab8-NQQ
		```
	- Follow the directions to submit your code.

		- **IMPORTANT**: Your application will be compiled and executed by the submitter. It will be an interactive session meaning it will require you to provide the necessary user input(s) to demonstrate your program works (use the values stated by the submitter).

	- If there are errors or your submission failed to submit, fix the problems **ON YOUR DEVICE**, and repeat the above submission process again from the beginning.
	
 * Lastly, on **Blackboard** paste the URL (link) to the **lab8** directory of your PRIVATE ipc144 GitHub repository by clicking the `Lab-8` assignment under the **Labs** section of your repository.

> [!IMPORTANT]
>
> **DO NOT modify your code directly from matrix** as this will put your repository out of sync
> with the copy of your code on GitHub (unless you push the changes and pull it from all other devices afterwards).
>
> You will learn how to use Git and GitHub properly in your CEP146 course.

> [!CAUTION]	
>
> **Only submissions done from matrix will be accepted and eligible for marks**, see the grading rubrics section.
> 

---

```
   ___        _          ____            _       ____  
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_    |___ \ 
 | | | | | | | |_  /    | |_) / _` | '__| __|____ __) |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____/ __/ 
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|   |_____|
                                                       
```

## Quiz Part-2

* Part-2 of quiz is based on what you did during the lab.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.
* Do NOT copy the question!

---


```
   ____               _ _                  ____        _          _      
  / ___|_ __ __ _  __| (_)_ __   __ _     |  _ \ _   _| |__  _ __(_) ___ 
 | |  _| '__/ _` |/ _` | | '_ \ / _` |    | |_) | | | | '_ \| '__| |/ __|
 | |_| | | | (_| | (_| | | | | | (_| |    |  _ <| |_| | |_) | |  | | (__ 
  \____|_|  \__,_|\__,_|_|_| |_|\__, |    |_| \_\\__,_|_.__/|_|  |_|\___|
                                |___/                                    
```

## Rubric Details:

To be eligible for **FULL MARKS**, you will need to satisfy the following:
 
* Score a minimum 50% on the combined questions from the quiz (parts 1 and 2 combined)
* Code must be pushed (updated) back into your PRIVATE **ipc144** GitHub repository
* Code must be **submitted by the matrix submitter**
* Code must **solve the problem and address all the lab specifications**
* Pasted the **URL to your PRIVATE ipc144 repository's this lab's directory on GitHub** into **Blackboard**

### Rubric Description

> [!WARNING]
> 
> In class participation is mandatory to receive any marks for the lab:
> * If you are not in class, you will get **0 marks even if you submit the code for the lab.**
> * You must have participated in BOTH parts of the in-lab quiz (with submitted answers on lab sheet)
> * You must have provided a walkthrough answer on the provided lab sheet


| Grade | Description|
| ----- | -----------|
| **Unsatisfactory** | 1. Scored 33% or less on the quiz `OR` <br> 2. Code was not submitted using the **matrix submitter** \(must also include the **link submission on Blackboard**\) `OR` <br>3. Did not PUSH at least 50% of the lab code working solution to your PRIVATE GitHub repository before end of lab period |
| **Incomplete** | 1.  Scored more than 33% on the quiz `AND` <br>2. Code was submitted with the **matrix submitter** and **link posted on Blackboard** `AND` <br>3. Repository was updated with a working 50% or more of the solution by the end of class but does not yield a complete solution to the problem \(does not work as it should or is incomplete\)|
| **Satisfactory** |1. Scored 50% or better on the quiz `AND`<br> 2.Code was submitted with the **matrix submitter** and **link posted on Blackboard** `AND` <br>3. Repository was updated by end of the lab `AND`<br> 4. Coded solution **solves the problem and addresses all the lab specifications** \(if a tester is used, it  score 100% pass rate\)|


### Rubric

|  | Level: 0 | Level: 1 | Level: 2 |
| -------- | ------- | ------- | ------- |
| **Grade** | `0.0` | `0.5` | `1.0` |
| **Description** | Unsatisfactory | Incomplete | Satisfactory |

---

```
  _____      _                ____                 _   _          
 | ____|_  _| |_ _ __ __ _   |  _ \ _ __ __ _  ___| |_(_) ___ ___ 
 |  _| \ \/ / __| '__/ _` |  | |_) | '__/ _` |/ __| __| |/ __/ _ \
 | |___ >  <| |_| | | (_| |  |  __/| | | (_| | (__| |_| | (_|  __/
 |_____/_/\_\\__|_|  \__,_|  |_|   |_|  \__,_|\___|\__|_|\___\___|
                                                                 
```


## Extra Practice:

The extra practice tasks rely on some data files also provided with the starter files in this lab:

* lab8Practice1.txt
* lab8Practice2.txt

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

**Source Data File: `lab8Practice1.txt`**

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

**Source Data File: `lab8Practice2.txt`**

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

