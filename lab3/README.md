# Lab 3

This lab is worth 1.25% of your final grade


## What you need to do (by the end of the lab class): 

* Quiz: Record your answers to the in-class quiz on the paper provided to you
* Code: Update your PRIVATE GitHub ipc144 repository:
	* With the solutions to the assigned lab work even if it is not fully functional or completed
 

## Objectives:

* practice writing a program with functions that involving 
	* input/output 
	* calculations
	* selection statements

## To have the best possible outcome for lab 3:

* Prior to lab, complete all the reading listed for week 4 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
	* [Selection](https://seneca-scpa.github.io/Introduction-To-Programming/F-Selection/intro)


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


## Programming

In this lab, you will be working on a program that will calculate the price of a night out at the movies.  The program will ask the user to enter information and using that information determine how much they will pay.  The program is decomposed into multiple functions.  You must implement your program by making function calls to these functions. 

### Documentation

Document each function **prototype**  in the `lab3.c` file (each function is described below after this section):

* Add a comment above each respective function PROTOTYPE that describes:
   * what the function does
   * what the function accepts as arguments (and any assumptions about that data)
   * what the function returns
* Code each function DEFINITION by copying the prototype and pasting it after the prototype section in the lab3.c file.
* For each function copied, remove the ending semi-colon `;` and replace with open and closing curly braces `{` ... `}`. **Each curly brace must be on their own respective lines.**
* Code each function's logic accordingly within the set of curly braces (code blocks).

---

### Write the following functions

Write the functions described below in the **`lab3.c`** source code file.


#### Function 1
```c
int isLower(char letter);
```
Function returns a 1 if **_letter_** is a lower case alphabetic character, 0 otherwise.

##### Examples:

```
isLower('5') returns 0
isLower('T') returns 0
isLower('a') returns 1
```
---

#### Function 2
```c
char toUpper(char letter);
```
Function returns the upper case version of **_letter_** if **_letter_** is a lower case alphabetic character.  Otherwise, function returns **_letter_**.

##### Examples:

```
toUpper('5') returns '5'
toUpper('a') returns 'A'
toUpper('B') returns 'B'
```
---

#### Function 3
```c
int readAge(void);
```
This function is passed nothing.  It prompts the user to enter the age of person who is buying the ticket and return the age entered.

The prompt to use is:

```
Please enter the age of the customer: 
```
---

#### Function 4

```c
int readDayOfWeek(void);
```
This function is passed nothing.  It prompts the user to enter the day of week using this menu:

```
Days of the week
	1) Sunday
	2) Monday
	3) Tuesday
	4) Wednesday
	5) Thursday
	6) Friday
	7) Saturday
Please enter the day of the week you wish to see the movie (1 to 7): 
```
The function returns the number entered by the user.

**Note:** You may assume the user will always enter a number between 1 and 7 inclusive.

---

#### Function 5

```c
int readHasCoupon(void);
```
This function is passed nothing.  It prompts the user to enter whether or not they have a coupon:

```
Do you have a coupon? (Y or N): 
```

This function will accept the user's input in both upper case or lower case form.  Thus `y` or `Y` indications that there is a coupon, while `n` or `N` are indications that they do not have a coupon.  The function returns 0 if the user does not have have a coupon and a 1 if they do have a coupon.  (hint: the toUpper() may be useful here)

**Note:** You may assume the user will always enter a `y` or `Y` or `n` or `N` value.

---

#### Function 6

```c
double ticketPrice(int age, int hasCoupon,int dayOfWeek);
```
This function is passed the age of a customer and whether or not they have a coupon and the day of the week as an integer (1 is Sunday, 2 is Monday, 3 is Tuesday and so on...). The following table outlines the ticket pricing. No coupons are allowed on Monday's because it's cheap ticket day, Thus the value of hasCoupon is irrelevant. However coupons are allowed on all the other days. A coupon provides a 20% discount off the listed ticket price.

| Age Group | Pricing on Monday(no coupons)| Pricing on Tuesday to Thursdays | Pricing on Weekends Friday-Sun | 
|---|---|---|---|
| Children (12 and Under) | $5.00 | $7.00 | $8.00 |
| Seniors (65 and Over) | $5.00 | $9.00 | $10.00|
| General Admission | $5.00 | $12.00 | $15.00 |

The function returns the price of the movie ticket

---

```
  ____                                 _             _   _             
 |  _ \  ___ _ __ ___   ___  _ __  ___| |_ _ __ __ _| |_(_) ___  _ __  
 | | | |/ _ \ '_ ` _ \ / _ \| '_ \/ __| __| '__/ _` | __| |/ _ \| '_ \ 
 | |_| |  __/ | | | | | (_) | | | \__ \ |_| | | (_| | |_| | (_) | | | |
 |____/ \___|_| |_| |_|\___/|_| |_|___/\__|_|  \__,_|\__|_|\___/|_| |_|
                                                                       
```

### Getting Started:

Your professor will do the following lab demonstration:

* how to write one of the functions
* how to call that function from the main (and perform basic testing)

Now that you have a starting point...

### Complete the outstanding functions
```
  ___ _   _      __   __                 _____                         
 |_ _| |_( )___  \ \ / /__  _   _ _ __  |_   _|   _ _ __ _ __          
  | || __|// __|  \ V / _ \| | | | '__|   | || | | | '__| '_ \         
  | || |_  \__ \   | | (_) | |_| | |      | || |_| | |  | | | |  _ _ _ 
 |___|\__| |___/   |_|\___/ \__,_|_|      |_| \__,_|_|  |_| |_| (_|_|_)
                                                                       
```

Complete the remaining functions and be sure to test each function as you complete them! 

> [! TIP]
>
> As you complete each function, do a **unit test**:
> * Use the `main` function in **lab3main.c** to call the respective function with different data
> * Apply predictive testing where you manually determine what the outcome should be from the function and compare the actual execution of your function to that expectation.

---

#### The Program:

In the file `lab3main.c`, replace any testing code you had from your function unit tests and write a program using the functions outlined above that will do the following in the order listed here:

1. prompt the user to enter the day of the week
2. if it is not a Monday, prompt the user to enter their age
3. if it is not a Monday, prompt the user to enter whether or not they have coupon.
4. calculate the price of the ticket
5. output the price of the ticket in this format: 
	```
	Your ticket will cost: $<ticket price to 2-decimal places>
	```

You may assume the user will enter the data correctly.  No input error checking is required for this lab.  Here are a few sample runs you should try:


##### Test 1: general admission (64), sunday, no coupon (n)
```
Days of the week
    1) Sunday
    2) Monday
    3) Tuesday
    4) Wednesday
    5) Thursday
    6) Friday
    7) Saturday
Please enter the day of the week you wish to see the movie (1 to 7): 1
Please enter the age of the customer: 64
Do you have a coupon? (Y or N): n
Your ticket will cost: $15.00
```
##### Test 2: Tuesday, child(12), coupon (Y)
```
Days of the week
    1) Sunday
    2) Monday
    3) Tuesday
    4) Wednesday
    5) Thursday
    6) Friday
    7) Saturday
Please enter the day of the week you wish to see the movie (1 to 7): 3
Please enter the age of the customer: 12
Do you have a coupon? (Y or N): Y
Your ticket will cost: $5.60
```

##### Test 3: Monday
```
Days of the week
    1) Sunday
    2) Monday
    3) Tuesday
    4) Wednesday
    5) Thursday
    6) Friday
    7) Saturday
Please enter the day of the week you wish to see the movie (1 to 7): 2
Your ticket will cost: $5.00
```

##### Test 4: senior(65), Satuday, coupon (y)
```
Days of the week
    1) Sunday
    2) Monday
    3) Tuesday
    4) Wednesday
    5) Thursday
    6) Friday
    7) Saturday
Please enter the day of the week you wish to see the movie (1 to 7): 7
Please enter the age of the customer: 65 
Do you have a coupon? (Y or N): y
Your ticket will cost: $8.00
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
			git commit -am "Completed lab3"
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
	- Change to the `lab3` directory (inside your ipc144 repository):
		```
		cd lab3
		```
	- Submit your code using the submitter. Substitute `professor.name` with your professor\'s account name, and `NQQ` with your course section code:
		```
		~professor.name/submit 144lab3/lab3-NQQ
		```
	- Follow the directions to submit your code.

		- **IMPORTANT**: Your application will be compiled and executed by the submitter. It will be an interactive session meaning it will require you to provide the necessary user input(s) to demonstrate your program works (use the values stated by the submitter).

	- If there are errors or your submission failed to submit, fix the problems **ON YOUR DEVICE**, and repeat the above submission process again from the beginning.
	
 * Lastly, on **Blackboard** paste the URL (link) to the **lab3** directory of your PRIVATE ipc144 GitHub repository by clicking the `Lab-3` assignment under the **Labs** section of your repository.

> [!IMPORTANT]
>
> **DO NOT modify your code directly from matrix** as this will put your repository out of sync
> with the copy of your code on GitHub.
>
> You will learn later in the semester in your course CEP146 how to use Git and GitHub properly.

> [!CAUTION]	
>
> **Only submissions done from matrix will be accepted and eligible for marks**


## Quiz Part-2

```
   ___        _          ____            _       ____  
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_    |___ \ 
 | | | | | | | |_  /    | |_) / _` | '__| __|____ __) |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____/ __/ 
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|   |_____|
                                                       
```

Part 2 of the quiz is based on the work you have just done for lab-3.

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

## Additional Practice Problems:

These practice problems are provided for you to try on your own time.  Doing them will help re-enforce the material you are learning.  While there are no marks associated with these problems, it is highly recommended that you do it. 

Place your code/answers in the respective practice directory (folder) for this lab located in your code repository:  `practice/lab3practice/` 

After you complete and test these problems, `PUSH` your changes from `lab3practice.c` file back to your repository.

---

### Problem 1

Write the following function:

```c
int absoluteValue(int number)
```

This function is passed a number that can be positive or negative.  If the number is positive, return the number.  If the number is negative return the positive version of that number.

For example:

```
absoluteValue(3) returns 3
absoluteValue(-5) returns 5
```

### Problem 2

```c

int rockPaperScissors(int player, int opponent);

```

This function is passed two numbers representing what each player \"threw\" in a game of rock-paper-scissors.

* 0 represents rock
* 1 represents paper
* 2 represents scissors

In a game of rock scissors paper, 
  * rock wins over scissors
  * scissors wins over paper
  * paper wins over rock.

This function returns 1 if player won the game, 0 if they either tied or lost the game

For example:

```
rockPaperScissors(0,2) - returns 1, player threw rock, opponent threw scissors player won
rockPaperScissors(1,1) - returns 0, player and opponent both threw paper, tie game
rockPaperScissors(1,2) - returns 0, player threw paper, opponent threw scissors, player lost
```

### Problem 3

```c
int dayOfWeekJan2025(int day);
```

This function returns the day of the week represented as follows:

* 0 - Sunday
* 1 - Monday
* 2 - Tuesday
* ...
* 6 - Saturday

January 1 2025 occurred on a Wednesday.  Given a number representing the day of the month in January, function returns the day of the week.  If day is invalid, function returns -1:

Examples

```
dayOfWeekJan2025(1) - returns 3 because Jan. 1 is on Wednesday
dayOfWeekJan2025(21) - returns 2 because Jan. 21 is on Tuesday
dayOfWeekJan2025(32) - returns -1 because Jan. 32 doesn't exist
dayOfWeekJan2025(-1) - returns -1 because Jan. -1 doesn't exist
dayOfWeekJan2025(26) - returns 0
``` 

### Problem 4

```c
int biggest(int first, int second, int third);
```

This function is passed three(3) values and returns the biggest number of the three.

Examples:

```
biggest(2, 5, 15) returns 15
biggest(25, 3, 18) returns 25
```
