# Lab 3

This lab is worth 1.25% of your final grade


## What you need to do (by the end of the lab class): 

* Quiz: Record your answers to the in-class quiz on the paper provided to you
* Code: Update your GitHub repository:
	* With the solutions to the assigned lab work even if it is not fully functional or completed

## Objectives:

* practice writing a program with functions that involving 
	* input/output 
	* calculations
	* selection statements

## To have the best possible outcome for lab 3:

* Prior to lab, complete all the reading listed for week 4 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
	* [Selection](https://seneca-scpa.github.io/Introduction-To-Programming/F-Selection/intro)


**CODESPACES have been disabled.  Please use your local development environment**


## Lab Repository

### Already did Lab-0?
If you have already have completed Lab-0 and have your **own code repository**, go directly to your repository:

- https://github.com/seneca-ipc-s26
- Navigate to the respective lab folder and code your solution using the provided starter source files.

### Didn't do Lab-0...
You must join the IPC classroom to get your coding repository. Follow these instructions to get your repository for all your assessments:
1. To get started, [click on this link for your work repository](https://classroom.github.com/a/UNEXMgcI)
2. These steps may not be required if you had done this in a previous lab.
	- Enter your **SENECA USERNAME** (the username part of your seneca email)
	<img width=600 src="../enterteam.jpg"/><br>
	- Hit **`Create Team`** button
	- On the next page hit accept assignment.


## Quiz Part-1

* Part-1 of quiz is based on the reading material for week 4 (Chapter on Selection)
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.  No need to copy the question.


## Programming

### Lab Demo:

Your professor will do the following lab demonstration:

* how to write one of the functions
* how to call that function from the main


### File Organization

Your source code repository has a parent directory (folder) for all your **labs** and another parent directory (folder) for all the **extra practice** questions:

```
labs/
    lab1/...
    lab2/...
    lab3/...

practice/...
    lab1practice/...
    lab2practice/...
    lab3practice/...
```
These directories (folders) contain files to help you quickly get started:

#### Lab 3 Starter Files:
* labs/lab3/`lab3.c` - this is where most of your functions go
* labs/lab3/`lab3main.c` - this is where you write a main() function of your program

#### Lab 3 Extra Practice Starter Files:
* practice/lab3practice/`lab3practice.c` - this is where most of your functions go
* practice/lab3practice/`lab3practicemain.c` - this is where you write a main() function of your program

At this point, you should **avoid using Codespaces** that is integrated with your GitHub repository within your browser. **You should be using your own installed IDE on your device.** Download (or clone) the files from your source code repository to your device and work locally using the IDE you installed for your platform (Visual Studio, XCode, or VS Code).


### Overview

In this lab, you will be working on a program that will calculate the price of a night out at the movies.  The program will ask the user to enter information and using that information determine how much they will pay.  The program is decomposed into multiple functions.  You must implement your program by making function calls to these functions. 


#### Documentation

Document each function **prototype**  in the `lab3.c` file (each function is described below after this section):

* Add a comment above each respective function PROTOTYPE that describes:
   * what the function does
   * what the function accepts as arguments (and any assumptions about that data)
   * what the function returns
* Code each function DEFINITION by copying the prototype (**including the comments**) and pasting it after the prototype section in the lab3.c file.
* For each function copied, remove the ending semi-colon `;` and replace with open and closing curly braces `{` ... `}`. **Each curly brace must be on their own respective lines.**
* Code each function's logic accordingly within the set of curly braces (code blocks).


### Write the following functions

Write the functions described below in lab3.c


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
This function is passed nothing.  It will prompts the user to enter the age of person who is buying the ticket and return the age entered.

The prompt to use is:

```
Please enter the age of the customer: 
```
---

#### Function 4

```c
int readDayOfWeek(void);
```
This function is passed nothing.  It prompts the user to enter the day of week using this menu and prompt:

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
This function is passed nothing.  It will prompt the user to enter whether or not they have a coupon using this prompt

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

#### The Program:

In the file `lab3main.c`, write a program using the functions outlined above that will do the following in the order listed here:

1. prompt the user to enter the day of the week
2. if it is not a Monday, prompt the user to enter their age
3. if it is not a Monday, prompt the user to enter whether or not they have coupon.
4. calculate the price of the ticket
5. output the price of the ticket in this format: 
	```
	Your ticket will cost: $<ticket price to 2-decimal places>
	```

You may assume that the user will enter the data correctly.  No error checking is required for this lab.  Here are a few sample runs:


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

---
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
   	* On Blackboard for this course, go to the **Labs Content Area** and click on the **Lab3** assessment link. Paste the URL to your GitHub repository and submit


### Submission testing:

When you submit your code, your program will be put through a series of tests.  Please remember to check your `Actions` tab in your lab repo after you update it with your code.  Remember to expand to ensure the full program is also working as expected.  See lab 2 for more details about submission testing.

## Rubrics:

## Rubric Description

**In class participation is mandatory to receive any marks for the lab.  If you are not in class, you will get 0 marks even if you submit the code for the lab.**

| Grade | Description|
| ----- | -----------|
| **Unsatisfactory** | 1. Scored 0 on the quiz  `OR` <br> 2. Did not update your lab repository with any code before end of lab period |
| **Incomplete** | 1.  Scored more than 0% but less than 50% on the quiz```OR``` <br> 2. Repository was updated by the end of class but did **not pass action tab tester for all parts of the main lab ** having a red X for one or more components of the main lab in the actions tab|
| **Satisfactory** |1. Scored 50% or better on the quiz ```AND```<br> 2. Repository was updated by end of the lab```AND```<br> 3. Coded solution **passed action tab tester** with a green check mark ```AND```<br>4. Expanded run matches the sample runs provided in the lab specifications|




### Rubric

|  | Level: 0 | Level: 1 | Level: 2 |
| -------- | ------- | ------- | ------- |
| **Grade** | `0.0` | `0.5` | `1.0` |
| **Description** | Unsatisfactory | Incomplete | Satisfactory |



## Additional Practice Problems:

These practice problems are provided for you to try on your own time.  Doing them will help re-enforce the material you are learning.  While there are no marks associated with these problems, it is highly recommended that you do it. 

Place your code/answers in the respective practice directory (folder) for this lab located in your code repository:  `practice/lab3practice/`... 

After you complete and test these problems, upload/update your lab3pratice.c file back to your repository without changing the file name (overwrite what is there).  This will trigger a test to verify that your functions work according to spec.  ([see instructions in lab2 if you are not sure about how to do this](../lab2/lab2.md#submission-testing))

### Problem 1

Write the following function:

```c
int absoluteValue(int number)
```
This function is passed a number that can be positive or negative.  If the number is positive, return the number.  If the number is negative return the positive version of that number

For example:
```
absoluteValue(3) returns 3
absoluteValue(-5) returns 5
```

### Problem 2


```c
int rockPaperScissors(int player, int opponent);
```
This function is passed two numbers representing what each player "threw" in a game of rock-paper-scissors.

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
#### Problem 4

```c
int biggest(int first, int second, int third);
```
This function is passed three(3) values and returns the biggest number of the three.

##### Examples:
```
biggest(2, 5, 15) returns 15
biggest(25, 3, 18) returns 25
```
---
