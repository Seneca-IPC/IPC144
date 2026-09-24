# Lab 2

This lab is worth 1.25% of your final grade

## What you need to do (by the end of the lab class): 

* Quiz: Record your answers to the in-class quiz on the paper provided to you
* Walkthrough: Set up tables to track variables for a walkthrough and provide the expected output of the walkthrough
* Code: Update your PRIVATE GitHub ipc144 repository:
	* With the solutions to the assigned lab work even if it is not fully functional or completed
 
## Objectives:

* Practice writing functions involving calculations
* Practice reading programs that have functions and function calls

## To have the best possible outcome for Lab-2:

* **Prior** to the lab, you should have completed all the reading listed for week 3 in your Weekly Content section on blackboard (the entire chapter including exercises): 
	* [Functions](https://seneca-scpa.github.io/Introduction-To-Programming/E-Functions/intro)

* Completed **installing an IDE on your own personal device**, and if not, must be done by the next lab.


## Lab Preparation

To submit your work for this lab, **YOU MUST HAVE SUCCESSFULLY COMPLETED [Lab-0](../lab0/README.md)** where you configure the tooling and learn the process involved in completing a lab and how to submit your work!


## Lab Quiz Part-1

```
   ___        _          ____            _        _ 
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_     / |
 | | | | | | | |_  /    | |_) / _` | '__| __|____| |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____| |
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|    |_|
```

* Part-1 of the lab quiz is based on the reading material for week 3.
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  
	- **Do NOT copy the question to your paper**
	- **Only write down the question number and the answer**
	
* **The lab quiz is part of the lab mark**
* Keep the paper for the walkthrough and the second part of the lab quiz.  
* Be sure to submit this to your professor at the end of class.  


## Walkthroughs (30 minutes):

Do the walkthrough on the reverse side of your worksheet.

Perform a walkthrough of the following code to trace the program execution including variable values and determining what output is generated:

 <img width=425 src="./_images/lab2walk1.png"/>

---

```
  ____                                 _             _   _             
 |  _ \  ___ _ __ ___   ___  _ __  ___| |_ _ __ __ _| |_(_) ___  _ __  
 | | | |/ _ \ '_ ` _ \ / _ \| '_ \/ __| __| '__/ _` | __| |/ _ \| '_ \ 
 | |_| |  __/ | | | | | (_) | | | \__ \ |_| | | (_| | |_| | (_) | | | |
 |____/ \___|_| |_| |_|\___/|_| |_|___/\__|_|  \__,_|\__|_|\___/|_| |_|
                                                                       
```

### Getting Started:

Your professor will help you get started by demonstrating how to set up the tables for keeping track of the variables. Your professor will demonstrate the walkthrough process up to and including **line 10**.  

```
  ___ _   _      __   __                 _____                         
 |_ _| |_( )___  \ \ / /__  _   _ _ __  |_   _|   _ _ __ _ __          
  | || __|// __|  \ V / _ \| | | | '__|   | || | | | '__| '_ \         
  | || |_  \__ \   | | (_) | |_| | |      | || |_| | |  | | | |  _ _ _ 
 |___|\__| |___/   |_|\___/ \__,_|_|      |_| \__,_|_|  |_| |_| (_|_|_)
                                                                       
```

Complete the rest of the walkthrough **on your own**


## Programming

```
  ____                                 _             _   _             
 |  _ \  ___ _ __ ___   ___  _ __  ___| |_ _ __ __ _| |_(_) ___  _ __  
 | | | |/ _ \ '_ ` _ \ / _ \| '_ \/ __| __| '__/ _` | __| |/ _ \| '_ \ 
 | |_| |  __/ | | | | | (_) | | | \__ \ |_| | | (_| | |_| | (_) | | | |
 |____/ \___|_| |_| |_|\___/|_| |_|___/\__|_|  \__,_|\__|_|\___/|_| |_|
                                                                       
```

### Getting Started:

Your professor will guide you on how to get started with the programming part of this lab:

* How to **PULL** your private GitHub repository to ensure your device is in sync with GitHub
* How to work with multiple source code files (starting with the provided two source code files that come with this lab)
* How to begin coding your solution (addressing the function return types so you can compile)
* Implement the first function `readLengthInInches()` coded in **lab2.c**
* How to **call** `readLengthInInches()` from **lab2main.c**
* How to update your GitHub repository with the changes made on your device (use commit comment: "readLengthInInches function done")


### Programming Problems (1.5 hours)

In this lab's repository you will find in the code directory 2-source code files and some other files for Visual Studio Community users:

* lab2.c - this is where your function definitions will be coded
* lab2main.c - this is where you write a main() function to test and implement your program
* lab2.vcxproj - Visual Studio (VS) Community users ONLY (double-click this file to start your VS IDE)
* lab2.vcxproj.filters - Visual Studio (VS) Community users ONLY (needed for the solution "view" in the IDE)

Download these files to your device (if you are not a VS community user, then don't bother with the .vcxproj files) and work on it locally in the IDE you have installed (xCode users  will need to manually add the .c source code files to the project).

**NOTE**: To manually compile this lab on matrix, you will need to specify each .c file in the gcc command:

```bash
gcc -Wall lab2.c lab2main.c -o lab2
```

#### Documentation

For each function described below:
* Add a comment above the function PROTOTYPES in the lab2.c file that describes:
   * what the function accepts as arguments (and any assumptions about that data)
   * what the function does (Not HOW)
   * what the function returns
* Write all the function DEFINITIONS **after** all the prototypes the in the **lab2.c** file.

#### Function 1

```c
int readLengthInInches();
```

This function accepts no arguments.  It will prompt the user to enter a length measurement in inches and return the value entered by the user.
```
Please enter the length measurement to the nearest inch: 
```
The function will read and return the length entered by the user.

---

```
  ___ _   _      __   __                 _____                         
 |_ _| |_( )___  \ \ / /__  _   _ _ __  |_   _|   _ _ __ _ __          
  | || __|// __|  \ V / _ \| | | | '__|   | || | | | '__| '_ \         
  | || |_  \__ \   | | (_) | |_| | |      | || |_| | |  | | | |  _ _ _ 
 |___|\__| |___/   |_|\___/ \__,_|_|      |_| \__,_|_|  |_| |_| (_|_|_)
                                                                       
```


#### Function 2:

```c
int numFeet(int lengthInInches);
```

This function is passed a length measurement in inches. It returns the converted number of whole feet based on the received length in inches. 

Hint: ```1 foot = 12 inches```

---

#### Function 3:

```c
int numYards(int lengthInFeet);
```

This function is passed a length measurement in feet.  It returns the converted number of whole yards based on the received number of feet.  

Hint: ```1 yard = 3 feet```

---

#### Function 4:

```c
double inchesToMeters(int lengthInInches);
```

This function is passed the total length in inches and returns the converted length in meters.

Hint:

```
1 inch  = 2.54 centimeters
1 meter = 100 centimeters
```

---

#### Function 5:

```c
void printResults(int lengthInInches, int lengthInFeet, int lengthInYards, double lengthInMeters);
```

This function is passed the total length in inches, the number of whole feet in the measurement, the number of yards and the total length in meters. This function will output the following on separate lines using the format provided:

* total length in inches, format: ```Total length: <length in inches>```
* number of whole feet in the length measurement, format: ```Length rounded to number of feet: <length in feet>```
* number of whole yards in the length measurement, format: ```Length rounded to number of yards: <length in yards>```
* total length in imperial, format: ```Total length (imperial): <yards>yd <feet>' <inch>"```
* total length in metric to 2 decimal places, format: ```Total length (metric): <lengthInMeters> m```

> [!NOTE]
> Regarding the `total length in imperial` line: the numbers for yards, feet, amd inches 
> are not the same values in the first 3 lines of the output - you will need to apply 
> the `lengthInInches` variable to determine these (3) number parts.

EXAMPLE OUTPUT if the total inches was: ```161```

```
Total length: 161
Length rounded to number of feet: 13
Length rounded to number of yards: 4
Total length (imperial): 4yd 1' 5"
Total length (metric): 4.09 m
```
---

#### The Program:

In the file lab2main.c, write a program that starts with displaying a title: ```Imperial Length Measurement Converter```.  It will prompt the user for a length in inches, use the input length value to make all the necessary conversion calculations and display a summary of the results.  **This program must call and use the functions described above.**

**Example Application Execution:**

```
Imperial Length Measurement Converter
Please enter the length measurement to the nearest inch: 161
Total length: 161
Length rounded to number of feet: 13
Length rounded to number of yards: 4
Total length (imperial): 4yd 1' 5"
Total length (metric): 4.09 m
```

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
			git commit -am "Completed lab2"
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
	- Change to the `lab2` directory (inside your ipc144 repository):
		```
		cd lab2
		```
	- Submit your code using the submitter. Substitute `professor.name` with your professor\'s account name, and `NQQ` with your course section code:
		```
		~professor.name/submit 144lab2/lab2-NQQ
		```
	- Follow the directions to submit your code.

		- **IMPORTANT**: Your application will be compiled and executed by the submitter. It will be an interactive session meaning it will require you to provide the necessary user input(s) to demonstrate your program works (use the values stated by the submitter).

	- If there are errors or your submission failed to submit, fix the problems **ON YOUR DEVICE**, and repeat the above submission process again from the beginning.
	
> [!IMPORTANT]
>
> **DO NOT modify your code directly from matrix** as this will put your repository out of sync
> with the copy of your code on GitHub.
>
> You will learn later in the semester in your course CEP146 how to use Git and GitHub properly.

> [!CAUTION]	
>
> **Only submissions done from matrix will be accepted and eligible for marks**

 * Lastly, on **Blackboard** paste the URL (link) to the **lab2** directory of your PRIVATE ipc144 GitHub repository by clicking the `Lab-2` assignment under the **Labs** section of your repository.


## Quiz Part-2

```
   ___        _          ____            _       ____  
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_    |___ \ 
 | | | | | | | |_  /    | |_) / _` | '__| __|____ __) |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____/ __/ 
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|   |_____|
                                                       
```

Part 2 of the quiz is based on the work you have just done for lab-2.

* Your professor will project the question(s) for quiz part-2 on the screen
* Record your answers on the same worksheet used from quiz part-1
	- **Do NOT copy the question to your paper**
	- **Only write down the question number and the answer**

* Submit to your professor your paper worksheet containing your answers to the quiz questions
	- It **must be submitted to get any marks** for the lab

---

```
   ____               _ _                  ____        _          _      
  / ___|_ __ __ _  __| (_)_ __   __ _     |  _ \ _   _| |__  _ __(_) ___ 
 | |  _| '__/ _` |/ _` | | '_ \ / _` |    | |_) | | | | '_ \| '__| |/ __|
 | |_| | | | (_| | (_| | | | | | (_| |    |  _ <| |_| | |_) | |  | | (__ 
  \____|_|  \__,_|\__,_|_|_| |_|\__, |    |_| \_\\__,_|_.__/|_|  |_|\___|
                                |___/                                    
```

## Rubric:

To be eligible for **FULL MARKS**, you will need to satisfy the following:
 
* Score a minimum 50% on the combined questions from the quiz (parts 1 and 2 combined)
* Code must be pushed (updated) back into your PRIVATE **ipc144** GitHub repository
	* Even if if it is not working or is incomplete (timestamped no later then by end of lab class)
* Pasted the **URL to your PRIVATE ipc144 repository's lab1 directory on GitHub** into **Blackboard**

## Rubric Description

> [!WARNING]
> 
> In class participation is mandatory to receive any marks for the lab.
> If you are not in class, you will get **0 marks even if you submit the code for the lab.**

| Grade | Description|
| ----- | -----------|
| **Unsatisfactory** | 1. Scored 0 on the quiz  `OR` <br> 2. Did not update your lab 1 repository with any code before end of lab period |
| **Incomplete** | 1.  Scored more than 0% but less than 50% on the quiz```OR``` <br> 2. Repository was updated by the end of class but does not yield a complete solution to the problem \(does not work as it should or is incomplete\)|
| **Satisfactory** |1. Scored 50% or better on the quiz ```AND```<br> 2. Repository was updated by end of the lab```AND```<br> 3. Coded solution **solves the problem and addresses all the lab specifications**|


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

## Additional practice problems:


### Walkthrough 2

What is the output of the following program?

<img width=300 src="./_images/lab2walk2.png"/><br>


### Coding Problems
As with the other programming problems, create a tester to go along with this function.
* Write your functions in lab2practice.c. **DO NOT WRITE A main() function in lab2practice.c**
* Make function calls to the functions below to test them by writing a main in lab2practicemain.c


### Problem 1

Write the following function in the file lab2practice.c:

```c
int numSeconds(int hours, int minutes, int seconds);
```
This function is passed a duration of times in terms of hours minutes and seconds.  It will return the total number of seconds in that duration.

For example:
```
suppose hours = 2, minutes = 3, seconds = 4

2 hours = 120 minutes = 7200 seconds
3 minutes = 180 seconds

Thus the total number of seconds = 7200 + 180 + 4 = 7384

```


#### Problem 2


```c
int lastDigit(int number);
```
This function is passed a whole number called **number** and it will return the last digit of that number.

For example: 

Suppose that number = 12345, function would return 5.  If number == 35361, function would return 1.  You may assume that number will be non-negative.

>**Hint: think about what mathematical operators you have... perhaps one of them will be useful to you**


---
#### Problem 3

```c
int wholeMinutes(int seconds);
```

Given an amount of time in seconds, return the number of whole minutes in that amount of time.

For example:

If seconds is 75, the function would return 1 because 75 seconds has 1 whole minute.
If seconds is 155, the function would return 2 because 155 has 2 whole minutes.
