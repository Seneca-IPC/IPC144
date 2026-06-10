# Lab 5

This lab is worth 1.25% of your final grade

## Due Date: 

* End of lab period in week 8

## Objectives:

* practice writing functions involving arrays and C strings
* practice writing programs involving arrays and C strings

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


## To have the best possible outcome for lab 5:

* Prior to lab, complete all the reading listed for week 6 and 8 in your Weekly Content item on blackboard. Please read the entire chapter.  Link repeated below
    * [Arrays and C strings](https://seneca-scpa.github.io/Introduction-To-Programming/H-Arrays/intro)



**CODESPACES have been disabled.  Please use your local development environment**

## Quiz Part-1

* Part-1 of quiz is based on the reading material for week 6-8 (Chapters on arrays, C string)
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  You only need to number the question and write down the answer.  No need to copy the question.


## Programming Problem Overview

In this lab you will write a "secret message" creator.  The program will provide the user with 2 options:

* create a secret message
* decode a secret message

In both cases the program will read in a message from the user.  depending if they chose to create or decode the secret message, the program will either scramble or unscramble the entered text from the user and output the result.

You may assume that the user will not enter more than 200 characters for the message.

### To scramble a message:

* In the main you will find a secret key (`int secretKey[KEYCAP]={...}`) in the form of an array of integers (you can assume them to all be positive).  We will use the numbers in this array to shift the alphabetic and numeric characters in our message.
* To ensure we don't always use the same secret key, we will pick a starting position from the secretKey based on the properties of the message.
* To determine the start position count the number of alphabetic characters in the string (either upper or lower case)
* The starting position is the index of the secret key we start with.
* Scrambling process:
    * take each character of the message and adjust the characters according to the following rules:
        * any non-alphabetic, non-numeric characters are not modified.
        * for any alphabetic character, add the number from the corresponding element of the secretKey starting at the start position to the alphabetic character, rounding back to start of the alphabet when the sum exceeds 'z'.
        * for any numeric character, add the number from the corresponding element of the secretKey starting at start position to the numeric character rounding back to '0' if the sum exceeds '9'
        * here is an example:
		 <img width="400" src="./_images/lab5encoding.png"/>
    * reverse the string


### Unscrambling process:

* unscrambling process is essentially the scramble process applied in reverse
    * reverse the string 
    * determine the start position
    * subtract the corresponding secret key value rounding to 'z' if needed.




**Note: the methods used to scramble/unscramble messages described in this assignment are known to be breakable and does not constitute any sort of actual encryption process.**




## Lab Demo

Your professor will demonstrate how to write Function 1 and call this in your main to determine the starting Position.


## Program Breakdown

To complete this program, you will need two implement a number of functions and call them to complete the implementation.  Below, are a listing of all the functions that you must implement along 

### Function 1:

```c
int countAlpha(const char message[]);
```
This function is passed `message`, a null terminated character string.  It will return the number of alphabetic characters in `message`.  

---

### Function 2:

```c
int numChars(const char message[]);
```

This function is passed `message`, a null terminated character string.  It will return the number of characters in `message` before `'\0'` (the null character)


### Function 3:

```c
void reverse(char message[]);
```

This function is passed `message`, a null terminated character string. The function will reverse the characters in the string.

Example


```c
char msg[6] = "hello";
reverse(msg); //msg will become "olleh"
```

**Hint: One way to reverse a string is to swap characters: the first/last, second/second last, etc. do this all the way to the middle of the string and all string will be reversed**

---

### Function 4:

```c
char encode(char ch, int key);
```

This is passed a character and a key value.  It applies the encoding rule:

* if ch is alphabetic, add key to ch but go around if we go past 'z'
```
ch = 'a', key = 2 --> returns 'c'
ch = 'z', key = 2 --> returns 'b' because 'z' + 2 go pass z so we go back to start of the alphabet. 
ch = 'Y', key = 2 --> returns 'A' again, we are going around if needed.
```
* if ch is numeric, add key to ch but go around if we go past '9'
```
ch = '5', key = 2 --> returns '7'
ch = '7', key = 4 --> returns '1'
```


**Hint, there are different ways to do this.. you can use if statments to determine if you go past end of the character group ('z', 'Z', '9'), then determine how much you have gone past and add that to the starting charcter of the character group ('a', 'A' , '0').  You can also use a purely mathematical approach using modulus, and addition/subtraction.**


### Function 5:

```c
char decode(char ch, int key);
```

This function applies the decoding rule to ch by subtracting key from ch "rounding" back from 'z' if needed.

Examples:
* if ch is alphabetic, subtract key from ch but go around if we go past 'a'
```
ch = 'z', key = 2 --> returns 'x'
ch = 'a', key = 2 --> returns 'y' because 'a' - 2 go pass 'a' so we go around to back of the alphabet. 
ch = 'b', key = 2 --> returns 'z' again, we are going around to the end of the alphabet.
```
* if ch is numeric, subtract key from ch but go around if we go past '0'
```
ch = '5', key = 2 --> returns '3'
ch = '4', key = 7 --> returns '7'
```

### Function 6:

```c
void scramble(char message[], const int key[], int start);
```

This function ecodes the message by:
* encoding each letter of message with an element of key array. 
    * The first character of message is encoded with key[start]
    * The second character of message is encoded with key[start + 1]
    * The third character of message is encoded with key[start + 2] etc.
* reverse the message

### Function 7:

```c
void unscramble(char message[], const int key[], int start);
```
This function decodes the message by:
* reversing the message
* decoding each letter of message with an element of key array. 
    * The first character of message is encoded with key[start]
    * The second character of message is encoded with key[start + 1]
    * The third character of message is encoded with key[start + 2] etc.


### Program:

Aside from the functions above, you are provided with the following function:

```c
void readMessage(char message[],int max);
```
This function will read and store user entered text up to max characters or newline whichever is encountered first.  It cleans up the input buffer to ensure future reads continue to work.

The function is provided in lab5.h/lab5.c and you do not need to write it yourself but you will need to use it where appropriate in your program.

Your program will:

* Print this banner at start of program:
```
IPC Secret Message Machine
==========================
```
* Ask user if they wish to encode or decode a message using a menu system:
```
1) Encode a message
2) Decode a message

Your choice (1 or 2):
```
* The input must be validated using methods previously discussed.  If user enters invalid information, be sure to ask them to re-enter.
    * the process of doing this has been done many times in the past.  You can look back to your previous labs on how to do this.  Ensure that user enters either a 1 or a 2
* Ask user to enter their message:
```
Enter message:
```
* Perform scramble/unscramble as appropriate:
* Print one of the following depending on whether you are encoding or decoding:
```
Encoded message:
```
or
```
Decoded message:
```
* Print the resulting text
---
#### Sample Run 1:

```
IPC Secret Message Machine
==========================
1) Encode a message
2) Decode a message

Your choice (1 or 2): 1
Enter message: r2d2 and C3PO or is it C3P0? The quick brown fox jumped over the lazy dog. THIS IS A SECRET! shhhhhhhhhh.
Encoded Message:
.nohpoihonpz !ZFRKGU G XP VLNU .osi zffr gna rfws kkqtzj yug vevyg qhkzt eiB ?2P6C zp yp zr OX9H hnh 4i2w
```

#### Sample Run 2:
```
IPC Secret Message Machine
==========================
1) Encode a message
2) Decode a message
Your choice (1 or 2): 0
That was not valid
Your choice (1 or 2): 3
That was not valid
Your choice (1 or 2): 2
Enter message: .nohpoihonpz !ZFRKGU G XP VLNU .osi zffr gna rfws kkqtzj yug vevyg qhkzt eiB ?2P6C zp yp zr OX9H hnh 4i2w
Encoded Message:
r2d2 and C3PO or is it C3P0? The quick brown fox jumped over the lazy dog. THIS IS A SECRET! shhhhhhhhhh.
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

---


### Extra Practice Problems

All programming extra practice providing can be tested by updating lab5practice.c/lab5practice.h files in your repository and looking at the action tabs.  While it is not required for grades, extra practice problems provides you with a chance to practice what you learned in class.




Write the following functions:

#### Extra Practice Problem 1:

```c
int findSmallest(int array[], int size);
```

This function returns the smallest value in an array.


#### Extra Practice Problem 2:

```c
double average(int array[],int size);

```

This function returns the average of the values in the array.


#### Extra Practice Problem 3:

This function is passed a key value as well as an array and the size of the array.  The function returns the index where key was found within the array.  If the key does not exist within the array, function returns -1.  If there are multiple values in the array that match the key, return the index of the first value that matches.

```c
int linearSearch(int key, const int array[], int size);

```

Example:

```c
int array[6] = {2,1,3,1,7,6};

linearSearch(1, array, 6); // returns 1 because key (1) is found 
                           // in index 1 (also found in index 3, but 
                           // that we return index of first match)

```


#### Extra Practice Problem 4:

```c
void capitalize(char str[]);
```
This function will capitalize the first character of every "word" in the sentence if the word begins with an alphabetic character. Words are separated by 1 or more whitespace character (spaces, tabs, newlines).

Example:
```c
char mystring[100]="the quick brown Fox jumped\tover r2d2 but c 3po was\n too tall"
char capitalize(mystring);
```
mystring would be:
```c
"The Quick Brown Fox Jumped\tOver R2d2 But C 3po Was\n Too Tall"
```
tip: feel free to use/modify code you wrote in earlier labs to help you do this.


#### Extra Practice Problem 5:

```c
void removeTrailingWhitespace(char str[]);

```
This function removes all trailing whitespaces (spaces, tabs and newlines) from str


Example:

```c
char mystring[50] = "hello  \t world \n\t\n"; 
removeTrailingWhitespace(mystring)
```
mystring will be: 
```c
"hello  \t world"
```

#### Extra Practice Problem 6:

This function is passed an array and the size of the array.  The function returns the sum of the values from the array.

```c
int sum(const int array[], int size);

```

Example:

```c
int array[4] = {1,2,3,1};

sum(array,4);   //  returns 7

```


#### Extra Practice 7:
```c
int countChar(char ch,const char str[]);
```
This function returns the number of times ch shows up in str.

Example:
```c
char mystring[100]="the quick brown Fox jumped\tOver r2d2 but c 3po was\n Too tall"
int numTs = countChar('t',mystring);
The function would return 3
```


### Function 8:
```c
int countAllCase(char ch,const char str[]);
```
This function returns the number of times ch shows up.  If ch is an alphabetic character, count both the upper and lower case versions of this character.

Example:
```c
char mystring[100]="the quick brown Fox jumped\tOver r2d2 but c 3po was\n Too tall"
int numTs = countAllCase('o',mystring);
function would return 6
```

Tip: feel free to use/modify code you wrote in lab3 to help you do this.


## Walkthrough

Programs that involve structs are tracked in a similar way as those that involve arrays.  In your table, each instance of a struct has a column for each of the data members of the struct.

For example see: https://seneca-scpa.github.io/Introduction-To-Programming/I-Structs/walkthrough

<img width="475" src="./_images/lab5walk.png"/>

