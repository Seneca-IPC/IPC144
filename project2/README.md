# Project 2: Baby Name Data Viewer


## Due: Week 13 - your professor will specify your specific due date

* Late penalty -10% (2 marks) submitted on before one day after your due date
* Late penalty of -50% (10 marks) submitted within 5 days after your due date
* Project will not be accepted after 

For your second project this semester you will be working with data files to create a Baby Name Data Aggregator. This Aggregator will allow the user of the program to view the data in different ways.  The data for this program comes from two data files created from information found in the the Ontario Open Data Catalog.

## Starter files:


To get your Project repostory:
1. go to: https://classroom.github.com/a/Hs4cA1Xu
2. These steps may not be required if you had done this in a previous lab.
  * Enter your **SENECA USERNAME** (the username part of your seneca email)
  * Hit Create button
  <img width=400 src="../labs/enterteam.jpg"/>
3. On the next page hit accept assignment.

Video Instructions here: https://youtu.be/OgtMIU3vG2M


> [!WARNING]
> You are NOT to rename or add additional files to this repository. The automated checker requires only these files to be in your repository therefore it is expected you will implement all your program logic in the supplied .h/.c files


## Inputs:

### Data files

Your program will read data from two data files.  These files can be found in your repository.  You may assume there are no more than 1000 rows of data (not including the header) in each of these files:

* femalebabynames.csv
* malebabynames.csv

The first row of each file contains this header:
```
Year,Name,Frequency
```
After the header, each row of these files contains 3 values separarated by commas:

* year  - the year the data was recorded - for this project, only the data for the years 2015 to 2019 inclusive are provided
* name - the first name of the baby.  The name may contain spaces.  You can assume the name is no more than 12 characters long
* frequency - the number of babies with the given first name born in the given year.

Both files have the same format for the data

These files contain the data that your program will need to process.

### Interactive Input

Your program must provide a menu that allows the user to choose one of the following things to do:

1. Find the number of people born with a given name.
	* read in a string for a name next if this is chosen.
	* the name may have a space in it.
2. Find top most popular name in a given year
	* read in a year next if this it this is chosen.
3. Draw histogram of a given name's popularity over the time period provided
	* read in a string for a name next if this is chosen.
	* the name may have a space in it.
4. Exit program

Note that the numbering of the menu given above must be maintained.  The exact phrasing in the menu system is up to you but the numbering must be maintained

For example a user input of 1 must mean **Find the number of people born with a given name**. Your exact menu can say "Find number of babies named ..." or "How many babies named ... were born in Ontario?".  You cannot however change an input of 1 to mean "find top 5 babynames". You also cannot use other labeling for the menu. (for example having user enter a, b, c or d would be viewed as wrong)


#### Interactive Input Validation

Your program is expected to do basic error checking of the following nature:

1. Menu selection must be value between 1 to 4 inclusive.  Any other value should rejected with error message and reread
2. The valid years are 2015 to 2019.  Any other year value should be rejected with appropriate error message and reread
3. Names entered by user can contain alphabetic characters, space or hyphens.  The user can enter the names using any casing they wish. A name comparison is done in a case insentive manner.  For example:  "Austin", "AUSTIN", "AuStIn" are all considered to be matching 


## Basic Run of program.

Your program must use the information from the the two input files as data to answer the user query.  
Your program:

* must read in the data files and the data must then be stored into variables of an aggregate data type of your design.
* print out the menu and ask the user what they are interested in looking at.
	* 1 Find the number of people born with a given name.
		* read in a string for a name next if this is chosen.
	* 2 Find top most popular name in a given year
		* read in a year next if this it this is chosen
	* 3 Draw histogram of a given name's popularity over time
		* read in a string for a name next if this is chosen.
	* 4 Exit program
* read in and validate the user input
* perform the task chosen (more details for each task described below)
* after the task is completed, the program prints out the above menu again and repeats the process until the user chooses 4 from the menu to exit
* Program then creates a new output file named "combined.txt" that combines and organizes the data results into a data file before exiting.  Details on this last task is below.


## Tasks:

The user has 3 options to choose from using the menu system. This section describes each of these tasks in more details

### Find the number of people born with a given name.

If the user chooses this option, your program must prompt for a name from the user.

Your program will need to look through the data to find how many babies were born each year with a matching name.

The output must include:

* number of babies born for each year with a non-zero value with a matching name, sorted by year in ascending order.
* total number of female babies born with that name
* total number of male babies born with that name
* total number of babies born with that name 


### Find top most popular baby name in a given year

If the user chooses this option, your program must prompt for a year.

Your program must find the most popular names in a year for:

* female babies
* male babies


### Draw histogram of a given name's popularity over time

If the user chooses this option, your program must prompt for a name from the user.  Again, some names are in both files so the total must be gathered.

A histogram is bar chart.  In this case we are going to chart the frequency of a name within a population. Using ASCII Art to draw a histogram of the percentage of population for a given name.

As the data has a range of only 5 years, your histogram must consist of exactly 5 bars, 1 per year.  use one symbol per 25 people, rounding down.  For example, if the frequency for a particular year was 120, you graph would have a length of 4 symbols because 120/25 = 4 (when rounded down).

The simplest bar graph is to use a single bar with one type of symbol.  However this can be the area for extra customization.

For example, you can draw the bars vertically instead of horizontally.  The bars can also be any width you want. You can also use different symbols.  That decision is yours. 

For example, the name `ELENA` has frequencies: `112, 106, 139, 149, 140` listed form 2015 to 2019.

Here are some examples of the histograms that could be created
```
2019 |*****
     |*****
     |
2018 |*****
     |*****
     |
2017 |*****
     |*****
     |
2016 |****
     |****
     |
2015 |****
     |****
```

```
2015 |****
     |
2016 |####
     |
2017 |%%%%%
     |
2018 |@@@@@
     | 
2019 |^^^^^
```
```
                ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
 --------------------------------
    2015  2016  2017  2018  2019
```



### Combined output

When the program exits, the data must be combined and stored into a file called "combined.txt".  This file has 3 fields.
* year
* name
* frequency

Each row of the output is formated in the following manner:

```
<year>,<name>,<frequency>
```
Note that if a record with the same year and name was found in both of the original files, they must be combined into one single entry in the combined file.

For example if the original record files had these records for the name RILEY:

male baby name file:

```
2015,RILEY,108
2016,RILEY,114
2017,RILEY,85
2018,RILEY,86
2019,RILEY,73
```

female baby name file:
```
2015,RILEY,146
2016,RILEY,200
2017,RILEY,215
2018,RILEY,179
2019,RILEY,166
```
in the combined file you would have these records for RILEY:

```
2015,RILEY,254
2016,RILEY,314
2017,RILEY,300
2018,RILEY,265
2019,RILEY,239
```

### Sample Run

This is a sample run.  The data output is faked/missing in this run.  The menu items are also **really bad so please don't use them**.  Your program must actually process the data to find the results:

```
Baby Name Data Viewer

1. number of babies
2. top baby name
3. histogram
4. exit
Enter your choice: 1
Enter the Name: RILEY
Total number of male babies named RILEY: 466
Total number of female babies named RILEY: 906
Total number of babies named RILEY: 1372

-----------------------------------------------------
Baby Name Data Viewer

1. number of babies
2. top baby name
3. histogram
4. exit
Enter your choice: 2
Enter the Year: 2001
Number entered was invalid.  Number must be between 2015 to 2019 inclusive
Please re-enter: 2015
Top male baby name in 2015 <top male baby name in 2015>
Top male baby name in 2015 <top female baby name in 2015>

-----------------------------------------------------
Baby Name Data Viewer

1. number of babies
2. top baby name
3. histogram
4. exit
Enter your choice: 3
Enter the Name: Elena

     Number of Babies named Elena

                ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
 --------------------------------
    2015  2016  2017  2018  2019

-----------------------------------------------------
Baby Name Data Viewer

1. number of babies
2. top baby name
3. histogram
4. exit
Enter your choice: 4
Finished, writing data to combined.txt
```

## Allowed Libraries:

You do not have to use any of the following libraries but you are allowed to use any functions in the following C libraries:

* string.h
* stdio.h
* ctype.h
* math.h

**No other libraries are allowed in your solution.**


## Style Guide

Please familiarize your self with the [IPC 144 Style Guide](https://seneca-scpa.github.io/Introduction-To-Programming/styleguide) and be sure to implement this styling in your program.  Part of your grade is on documentation and code styling (see rubrics below)


## Rubrics

### Time Allowance

Your program must complete going through the tests in the action runner within 60 seconds. If it does not complete in time, your program correctness and completeness grade will be assessed based only on what shows as completed within the action run.


### Deductions

There are some constructs and/or design choices in programming that are syntactically and logically correct (will compile and the program works) but go against best practices and/or are considered poor design. 

 > [!CAUTION]
 >
 > Your work will be flagged with a **HEAVY DEDUCTION** if you implement any of the **MUST BE AVOIDED**  items listed below:
>
> * Use of **global variables** - any variable that is not declared INSIDE a function or a function's prototype are global variables.  These are absolutely forbidden:  `-50%(10 marks)`
> * Use of **continue**, **goto** and **break** (outside of a switch): `-50% (10 marks)`
> * Use of **multiple return statements** from a function.  Each function can only have one single return statement.  If you have more than one, that is multiple returns.  Multiple returns violate structured programming practices: `-50% (10 marks)`

Additionally...

> [!IMPORTANT]
>
> * You are limited to applying **only the concepts covered in the course**. Implementation of any concepts not covered in the course will attract `-50% (10 marks)`.
> * Any use of libraries outside those in the allowed list above will also result in a -50% (10 marks) penalty


### Grading rubric

>[!IMPORTANT]
> * Project is graded out of 20.
> * If you incur a penalty because you have a late submission or you got a grade penalty from the deductions section, **each penalty will be deducted from the calculated general rubrics grade.**
> * For example, suppose your rubric score was 17/20 but you used a global variable and had multiple returns in a function, your grade would be reduced to 0/20.

| Description | Level 4 | Level 3 | Level 2 | Level 1 | Level 0 |
|---|---|---|---|---|---|
|Documentation - 20% | For all functions state what parameters are (and any assumptions of what is allowed), what return value is, what it does. | 1 or 2 functions documentation missing. or function description comments lack some detail. Over documentation. documenting every line of code is not a good... let the code speak| 3 or 4 function documentation missing or severe lack of details for function description or documentation is done only at code level (within the code) and not as an overall intention| only a few functions got documented and documentation tends to be code description as opposed to code intention.| Almost no documentation of any type|
|Coding Style - 10% | Code follows posted styling guide perfectly and consistently | Coding style does not follow posted styling guide but the styling is consistent and differences are slight stylistic variations as opposed to poor styling choices. For example, all variables use of snake_case as opposed to the specified camelCase | 1 to 3 cases of inconsistent or bad styling | 4 to 6 instances of inconsistent or bad styling decisions | more than 6 cases of inconsistent or bad styling | 
| Correctness and Completeness of Program  - 40%| Program is able to complete all tasks correctly with correct outputs for all test cases and generate final combined file correctly | One of the features does not work correctly or small errors exists in multiple features  | Two of the features does not work correctly |  Three of the features do not work correctly | All features are flawed|
| Follows Appropriate Choices in Implementation - 30%| Used the most appropriate construct for required task consistently throughout the program | 1 instance of poor construct choice for required task | 2 instance of poor construct choice for required task | 3 instance of poor construct choice for required task | 4 or more instance of poor construct choice for required task |

### Checking Your runs

To check your run
* Go to the actions tab of your repository.
* Click on the top most item then click the build button.
* Click the section that says "Run Project - EXPAND TO SEE RESULT"
	* Double check that the output is valid for each test case
* Look for a green checkmark in the section called "Check Output File"


## Submission

Submit a link to your project repository to blackboard.  Note that no alterations are to be made to your repository once you submit to blackboard.  Any changes to your repository after the due date will make your project late and subject to the late penalties of that submission
