# Project 2: Baby Name Data Viewer


## Due: Week 13 - your professor will specify your specific due date

* Late penalty -10% (2 marks) submitted 1 day after the stated due date (as per your professor)
* Late penalty of -50% (10 marks) AFTER the 1 day late date (above) and on or **BEFORE December 14**
* Project will not be accepted **AFTER December 14**

For your second project this semester you will be working with data files to create a **Baby Name Data Viewer**. This Aggregator will allow the user of the program to view the data in different ways.  The data for this program comes from two data files created from information found in the the Ontario Open Data Catalog.

## Project Preparation

As with your labs, to submit your work for this project, **YOU MUST HAVE SUCCESSFULLY COMPLETED [Lab-0](../lab0/README.md)** where you configure the tooling and learn the process involved in completing a project and how to submit your work!

> [!WARNING]
> 
> Your submission will not be accepted unless you have minimally done the following:
> 
> * Source code has been pushed to your private GitHub ipc144 repository
> * Solution was submitted using the matrix submitter
> * A URL link to your private GitHub project directory was posted on Blackboard
> * Submitted within the grading window as set by the deadlines above (or as stated by your professor)

<br>

---

<br>

```
  ____            _           _        ____       _        _ _     
 |  _ \ _ __ ___ (_) ___  ___| |_     |  _ \  ___| |_ __ _(_) |___ 
 | |_) | '__/ _ \| |/ _ \/ __| __|    | | | |/ _ \ __/ _` | | / __|
 |  __/| | | (_) | |  __/ (__| |_     | |_| |  __/ || (_| | | \__ \
 |_|   |_|  \___// |\___|\___|\__|    |____/ \___|\__\__,_|_|_|___/
               |__/                                                
```

## Starter files:

The easiest method to getting the starter files for your project is to clone this repository. 

Copy the contents of `project2/code` directory to your private repository `project2` directory.

> [!WARNING]
>
> You are NOT to rename or add additional files for this project. The matrix tester requires only these files so it is expected you will implement all your program logic in the supplied .h/.c files.
>


## Data files

Your program will read data from two data files.  These files are included with your starter code.  You may **assume there are no more than 1000 rows of data** (not including the header) in each of these files:

- **femalebabynames.csv**
- **malebabynames.csv**

Both files have the same format for the data. The first row of each file contains this header:
```
Year,Name,Frequency
```
After the header, each row (line) of these files contains 3 values separated by **commas**:

* year  - the year the data was recorded - for this project, only the data for the years **2015 to 2019 inclusive** are provided
* name - the first name of the baby.  The name may contain spaces.  You can assume the name is no more than **12 characters long**
* frequency - the number of babies with the given first name born in the given year.


## Application Requirements

### Allowed Libraries:

You do not have to use any of the following libraries but you are allowed to use any functions in the following C libraries:

* string.h
* stdio.h
* ctype.h
* math.h

**No other libraries are allowed in your solution.**

---

### Data and Error Checking

- The first task your program must do is read-in and store the data from the two files into a custom data type (supporting aggregation).  This data is used as the source information to answer all user queries in the application.

- Your program is expected to do basic error checking for the following:

1. Menu selection must be value between 1 to 4 inclusive.  Any other value should rejected with error message and reread
2. The valid years are 2015 to 2019. Any other year value should be rejected with appropriate error message and reread

**Note** <br>
- Name values entered by the user can only contain **alphabetic characters, spaces or hyphens**. The user can enter the names using any casing they wish. A name comparison is done in a **case insensitive** manner.  For example:  "Austin", "AUSTIN", and "AuStIn" are all considered equivalent.

---

### Menu
Your program must provide a looping menu (until #4 is entered) that allows the user to choose one of the following things to do per loop:

1. Find the **number of babies born with a given name**.
2. Find **top most popular baby name in a given year**
3. Draw a **histogram for a given name's popularity** over the time period of the data (**2015-2019 inclusive**)
4. Exit program

> [!WARNING]
>
> Menu options must be numeric from 1-4 and their respective purpose/task as described above must be maintained.
> The exact word phrasing in each menu option is up to you - but it must reflect its purpose.
>

---

#### Menu Option Tasks

**1. Find the number of people born with a given name**

- Prompt the user to enter a `baby name`
- Look through the data to find how many babies were born each year with a matching name.

The output must include:

* number of babies born for each year with a non-zero value with a matching name, sorted by year in ascending order.
* total number of female babies born with that name
* total number of male babies born with that name
* total number of babies born with that name 

---

**2. Find top most popular baby name in a given year**

- Prompt the user to enter a `year`

Your program must find the most popular names in a year for:

* female babies
* male babies

---

**3. Draw histogram of a given name's popularity over time**

Your program must prompt the user for a `name`.  Again, some names are in both files so the total must be gathered.

A histogram is a bar chart. In this case we are going to chart the frequency of a name within a population using ASCII Art to represent the "bars".

Since the data has a range of only 5 years, your histogram must consist of exactly 5 bars (1 per year). Use one character symbol to represent 25 people, rounding down.  For example, if the frequency for a particular year was 120, the bar graph would have a length of 4 symbols because 120/25 = 4 (when rounded down).

The simplest bar graph is to use a single bar with one type of symbol.  However this can be the area for extra customization.

For example, you can draw the bars vertically instead of horizontally.  The bars can also be any width you want. You can also use different symbols.  That decision is yours. 

For example, the name `ELENA` has frequencies: `112, 106, 139, 149, 140` listed form 2015 to 2019.

Here are some examples of the histograms that could be created

Horizontal MULTI-CHARACTER bars ascending years 2015-2019:
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

Horizontal DOUBLE-THICK bars descending years 2019-2015:
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
VERTICAL THICK bars ascending years 2015-2019:
```
                ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
    ***   ***   ***   ***   ***
 --------------------------------
    2015  2016  2017  2018  2019
```

---

**4. Exit program**

Before the program ends, the original source data from both files must be combined and stored into a single-file called "`combined.txt`".  This file has 3 fields:
* year
* name
* frequency

Each row of data is formatted as follows:

```
<year>,<name>,<frequency>
```

> [!IMPORTANT]
>
> Duplicated year and name data must be merged into a single-entry (if the same `year` and `name` was found in **BOTH of the original files**).
>
> For example if the source data files had these records for the name **RILEY**:
> 
> File: **malebabynames.csv**
>
> 2015,RILEY,108<br>
> 2016,RILEY,114<br>
> 2017,RILEY,85<br>
> 2019,RILEY,73<br>
>
> File: **femalebabynames.csv**
>
> 2015,RILEY,146<br>
> 2016,RILEY,200<br>
> 2017,RILEY,215<br>
> 2018,RILEY,179<br>
> 2019,RILEY,166<br>
>
> The resulting `combined.txt` file would have these records for **RILEY**:
>
> 2015,RILEY,254<br>
> 2016,RILEY,314<br>
> 2017,RILEY,300<br>
> 2018,RILEY,179<br>
> 2019,RILEY,239


## Sample Application Execution

This is a sample execution using fabricated/made-up data. The menu item descriptions are also purposely **HORRIBLY BRIEF** - you must supply your own worded concise but meaningful descriptions. Your program must also generate accurate results based on the file data:

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
Top female baby name in 2015 <top female baby name in 2015>

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

## Style Guide

Please familiarize your self with the [IPC 144 Style Guide](https://seneca-scpa.github.io/Introduction-To-Programming/styleguide) and be sure to implement this styling in your program.  Part of your grade is on documentation and code styling (see rubrics below)


```
  ____  _   _ ____  ____  ___ ____ ____  
 |  _ \| | | | __ )|  _ \|_ _/ ___/ ___| 
 | |_) | | | |  _ \| |_) || | |   \___ \ 
 |  _ <| |_| | |_) |  _ < | | |___ ___) |
 |_| \_\\___/|____/|_| \_\___\____|____/ 
```

## Rubrics

### Application Performance

The testing of your program must complete within 60 seconds. If it does not complete within this time, your program correctness and completeness grade will be impacted.


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


## Submission

The same submission process is required for this project as is done for your labs, only the directory you will be pin-pointing will be `project2` and not a lab directory and the submission command is slightly different as well.

> [!CAUTION]
> 
> No alterations are to be made to your repository after you have submit to blackboard. 
> Any changes to your repository made after the due date and/or your blackboard submission 
> date will make your project late and subject to the late penalty policy as described at 
> the beginning of this document.


```
  ____        _               _         _             
 / ___| _   _| |__  _ __ ___ (_)___ ___(_) ___  _ __  
 \___ \| | | | '_ \| '_ ` _ \| / __/ __| |/ _ \| '_ \ 
  ___) | |_| | |_) | | | | | | \__ \__ \ | (_) | | | |
 |____/ \__,_|_.__/|_| |_| |_|_|___/___/_|\___/|_| |_|
                                                      
```

* Submit your code (solution to the project problem)

	- Update your GitHub PRIVATE ipc144 repository with your solution to the programming problem:
		- Here is an EASY [guide on how to push code from Visual Studio Code and Visual Studio](../gitinstructions/gitpush.md)
		- If you are not using the above IDE's, manually perform the 3-git commands (from anywhere within your repository directory structure):
			```
			git add -A
			git commit -am "Completed project-2"
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
	- Change to the `project2` directory (inside your ipc144 repository):
		```
		cd project2
		```
	- Submit your code using the submitter. Substitute `professor.name` with your professor\'s account name, and `NQQ` with your course section code:
		```
		~professor.name/submit 144project2/project2-NQQ
		```
	- Follow the directions to submit your code.

		- **IMPORTANT**: Your application will be compiled and executed by the submitter. It may require an interactive session meaning it could require you to provide the necessary user input(s) to demonstrate your program works (use the values stated by the submitter).

	- If there are errors or your submission failed to submit, fix the problems **ON YOUR DEVICE**, and repeat the above submission process again from the beginning.
	
 * Lastly, on **Blackboard** paste the URL (link) to the **project2** directory of your PRIVATE ipc144 GitHub repository by clicking the **`Project 2 - Submission`** item in the main content page.

> [!IMPORTANT]
>
> **DO NOT modify your code directly from matrix** as this will put your repository out of sync
> with the copy of your code on GitHub.
>
> You will learn later in the semester in your course CEP146 how to use Git and GitHub properly.

> [!CAUTION]	
>
> **Only submissions done from matrix will be accepted and eligible for marks**

