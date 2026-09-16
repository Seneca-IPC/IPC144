# Lab 1

This lab is worth 1.25% of your final grade

## What you need to do (by the end of the lab class): 

* Quiz: Record your answers to the in-class quiz on the paper provided to you
* Code: Update your PRIVATE GitHub ipc144 repository:
	* With the solutions to the assigned lab work even if it is not fully functional or completed
 
## Objectives:

* Practice writing a simple program that involves: 
	- input and output
	- coding simple calculations

## Expectations Going into this Lab:

To successfully complete this lab it is expected you have done the following:

* Prior to the lab, have read the listed topics for weeks 1 and 2 (see Weekly Content item on blackboard).
	* [Background](https://seneca-scpa.github.io/Introduction-To-Programming/A-Introduction/intro)
	* [Data Types](https://seneca-scpa.github.io/Introduction-To-Programming/A-Introduction/intro)
	* [Mathematical Operators](https://seneca-scpa.github.io/Introduction-To-Programming/C-Math/intro)
	* [Introduction to Code Reading](https://seneca-scpa.github.io/Introduction-To-Programming/D-ReadingAndDebugging/intro)
* Complete or nearing completion **installing an IDE on your own personal device**.


> [!WARNING]  
>
> **Work like a professional!**
> Professionals use various IDE development tools and don't rely on browser-based environments.
>
> It is important and expected you will be coding using a professional-grade IDE installed on your own device. This permits you to work offline and will not incur any surprising **\$costs\$**!
>

## Lab Preparation

To submit your work for this lab, **YOU MUST COMPLETE [Lab-0](../lab0/README.md)** where you configure the tooling and learn the process involved in completing a lab and how to submit your work!

> [!IMPORTANT]
>
> **Ohhh Ohhh - You Didn't complete Lab-0?**
>
> You must complete lab-0 from Week-1 before you can `submit` this weeks lab. However, if 
> you have not completed [Lab-0](../lab0/README.md), you should still participate and complete 
> this lab at least up to the point where your code works on your device. 
>
> You will need to complete [Lab-0](../lab0/README.md) on your own time and come back to this 
> lab to `submit` when you have your device environment all set-up and configured.



## Lab Quiz Part-1

```
   ___        _          ____            _        _ 
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_     / |
 | | | | | | | |_  /    | |_) / _` | '__| __|____| |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____| |
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|    |_|
```

* Part-1 of the lab quiz is based on the reading material for week 1 and week 2.
* Your professor will provide you with a piece of paper and project the lab quiz on the lab screen.
* Provide the answer to the questions on your paper.  
	- **Do NOT copy the question to your paper**
	- **Only write down the question number and the answer**
	
* Keep the paper until the end of class so you can do the post-lab quiz on the same paper and submit this to your professor at the end of class.  
* **The lab quiz is part of the lab mark**



## Programming

```
  ____                                 _             _   _             
 |  _ \  ___ _ __ ___   ___  _ __  ___| |_ _ __ __ _| |_(_) ___  _ __  
 | | | |/ _ \ '_ ` _ \ / _ \| '_ \/ __| __| '__/ _` | __| |/ _ \| '_ \ 
 | |_| |  __/ | | | | | (_) | | | \__ \ |_| | | (_| | |_| | (_) | | | |
 |____/ \___|_| |_| |_|\___/|_| |_|___/\__|_|  \__,_|\__|_|\___/|_| |_|
                                                                       
                             
```

### Professor Demonstration

Your professor will demonstrate the following:
* How to **PULL** updates from your PRIVATE `ipc144` GitHub repository to your local copy of the repository
* Guide you on creating a new source code file **`lab1demo.c`** [starter file here](./code/lab1demo.c) for this lab and saving it to your **`lab1` directory**
* Code the solution for **Problem-A**  \(first part of this lab\)
* Guide you on how to **compile** and **execute** the program (depends on your device operating system and IDE you are using)
* How to **PUSH** the changes you made on your device to the GitHub PRIVATE `ipc144` repository
* `SSH` into Seneca\'s Linux server **matrix**
* How to **PULL** updates from your PRIVATE `ipc144` GitHub repository to your matrix account
* How to **compile** and **execute** the program on matrix to confirm it is working on Linux


**It is important you follow your professor during this demo and work along with them as they do the demo.  If they are going too fast, please make sure to speak up so you can catch up.  Also if you have trouble, raise your hand to flag down your lab monitor to help you out**


### Problem A: Done with your professor (45 minutes):

Please do this problem in the file: `lab1/lab1demo.c`

> [!CAUTION]
>
> **Follow the file structure and naming convention exactly (case-sensitive). 
> The submitter will not work if the files are not named correctly and stored in the correct directory!**


Follow your professors demonstration of how to write this program.

* Prompt the user to enter a temperature in degrees Celsius (a whole number)
* Calculate the Fahrenheit equivalent of that temperature, a floating point value
* Display the result including the user entered value (show the Fahrenheit result to **2 decimal places**).

Use the following for the prompt

```
Please enter the temperature in Celsius: 
```

The formula for calculating the temperature is as follows:

$$F = ( {9\over5} * C) + 32$$

```
Where:

F represents the calculated temperature in degrees Fahrenheit
C represents the user-input value for the temperature in degrees Celsius

```

Display the result using the following format (substituting the \<userinput\> and \<result in Fahrenheit\>):

```
<userinput> degrees Celsius is <result in Fahrenheit> degrees Fahrenheit
```

A sample run of the program is as follows (note the 0 in the first line is entered by the user).

```
Please enter the temperature in Celsius: 0
0 degrees Celsius is 32.00 degrees Fahrenheit
```

### Testing your program

* Use [Google's Celsius to Fahrenheit converter](https://www.google.com/search?client=firefox-b-d&q=Celsius+to+farenheit) to get the correct conversion to find the correct Fahrenheit value for each of your Celsius values and record them in the Fahrenheit column.
* Now it's time to test your program! Run your program using the following 5 inputs and compare the results with what you get from the online converter:
	* 0
	* 100
	* -273
	* 25
	* -17
* if your program did not work, try to fix it... check the following:
	* did you consider the data type and how the operators would work in your formula.

### SAVE your changes to GitHub

**`push`** your code changes from your device to your GitHub PRIVATE repository:

**Method-1** (easy quick method)

Use the **helper script** (if you successfully installed this from **lab0**): 

```
gitpush "lab1 demo complete"
```
---

**Method-2** (longer manual method)

Manually execute all the git commands to update GitHub:

```
git add -A
git commit -am "lab1 demo complete"
git push origin main
```

### Programming Problem B

```
  ___ _   _      __   __                 _____                         
 |_ _| |_( )___  \ \ / /__  _   _ _ __  |_   _|   _ _ __ _ __          
  | || __|// __|  \ V / _ \| | | | '__|   | || | | | '__| '_ \         
  | || |_  \__ \   | | (_) | |_| | |      | || |_| | |  | | | |  _ _ _ 
 |___|\__| |___/   |_|\___/ \__,_|_|      |_| \__,_|_|  |_| |_| (_|_|_)
                                                                       
```

You are now responsible for coding the remainder of the lab!

Code your solution in a new source code file in the lab1 directory: `lab1/lab1.c` [starter file here](./code/lab1.c)

Write a program that will ask the user for a **radius** of a circle (a floating point number) using the prompt:

```
Please enter a radius of a circle: 
```

The data is to be read on the same line as the prompt.

The program will calculate and print the **diameter**, **circumference**, and **area** given the formulas:

$$diameter = 2 * radius$$
$$circumference = PI * diameter$$
$$area = PI * (radius)^2$$

> [!NOTE]
>
> `PI` is approximately **3.14159**

Output all results to **2-decimal places**. Refer to the sample execution below for output formatting.


#### Sample Execution

```
Please enter a radius of a circle: 123.45
The diameter of the circle with radius of 123.45 is 246.90
The circumference of the circle with radius of 123.45 is 775.66
The area of the circle with radius of 123.45 is 47877.53
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
	- Update your GitHub repository with your code solution even if it is not complete or functional.  Use either **Method-1** or **Method-2** as demonstrated by your professor earlier in the demo section.
		- Note: Apply an appropriate commit message to describe the completion of your lab code
	
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
	- Change to the `lab1` directory (inside your ipc144 repository):
		```
		cd lab1
		```
	- Submit your code using the submitter. Substitute `professor.name` with your professor\'s account name, and `NQQ` with your course section code:
		```
		~professor.name/submit 144lab1/lab1-NQQ
		```
	- Follow the directions to submit your code.

		- **IMPORTANT**: Your application will be compiled and executed by the submitter. It will be an interactive session meaning it will require you to provide the necessary user input(s) to demonstrate your program works. Choose any appropriate value(s) of your liking.

	- If there are errors or your submission failed to submit, fix the problems **ON YOUR DEVICE**, `push` the changes to GitHub, and repeat the above submission process again from the beginning. 
	
> [!IMPORTANT]
>
> **DO NOT modify your code directly from matrix** as this will put your repository out of sync
> with the copy of your code on GitHub.
>
> You will learn later in the semester in your course CEP146 how to use Git and GitHub properly.

> [!CAUTION]	
>
> **Only submissions done from matrix will be accepted and eligible for marks**

 * Lastly, on **Blackboard** paste the URL (link) to the lab1 directory of your PRIVATE ipc144 GitHub repository by clicking the `Lab-1` assignment under the **Labs** section.


## Quiz Part-2

```
   ___        _          ____            _       ____  
  / _ \ _   _(_)____    |  _ \ __ _ _ __| |_    |___ \ 
 | | | | | | | |_  /    | |_) / _` | '__| __|____ __) |
 | |_| | |_| | |/ /     |  __/ (_| | |  | ||_____/ __/ 
  \__\_\\__,_|_/___|    |_|   \__,_|_|   \__|   |_____|
                                                       
```

Part 2 of the quiz is based on the work you have just done for lab-1.

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

```
  _____      _                ____                 _   _          
 | ____|_  _| |_ _ __ __ _   |  _ \ _ __ __ _  ___| |_(_) ___ ___ 
 |  _| \ \/ / __| '__/ _` |  | |_) | '__/ _` |/ __| __| |/ __/ _ \
 | |___ >  <| |_| | | (_| |  |  __/| | | (_| | (__| |_| | (_|  __/
 |_____/_/\_\\__|_|  \__,_|  |_|   |_|  \__,_|\___|\__|_|\___\___|
                                                                 
```

## Additional Practice Problems (NOT graded):

The following problems are for extra practice. It is highly advised you complete these either in-lab if you complete the main lab early, or at home. Learning to be a programmer demands a lot of practice! These extra problems will get you started, but we encourage even more practice. After completing the extra practice questions - try to come up with some of your own challenges and see if you can do it.

### Problem 1

Code your solution in a new source code file in the `extraPractice` sub-directory: `lab1/extraPractice/lab1practice1.c` [starter file here](./extraPractice/lab1practice1.c)

Write a program that will ask the user to enter 3 whole numbers.  The program will calculate the average of these three numbers.

#### Sample run:

```
Please enter the first number: 15
Please enter the second number: 18
Please enter the third number: 20
The average of 15, 18, and 20 is 17.67
```

### Problem 2a

Code your solution in a new source code file in the `extraPractice` sub-directory: `lab1/extraPractice/lab1practice2a.c` [starter file here](./extraPractice/lab1practice2a.c)

Write a program that will calculate a weighted-grade for a course where the marks come from 3 tests.  Each test has a different weight towards the final grade as listed below:

* Test-1: 20%
* Test-2: 30%
* Test-3: 50%

Write a program that will ask the user to enter their **percentage** grade for each test then use the entered values to calculate their final grade

#### Sample run:

```
Please enter the percentage grade of the first test: 90.3
Please enter the percentage grade of the second test: 22.7
Please enter the percentage grade of the third test: 60.3
The final grade is: 55.02 %
```

### Problem 2b.  

Code your solution in a new source code file in the `extraPractice` sub-directory: `lab1/extraPractice/lab1practice2b.c` [starter file here](./extraPractice/lab1practice2b.c)

Expanding on problem 3a, suppose each test was graded out of 50 (**raw marks**).  All scores are whole numbers out of 50 however each test is worth it's respective percentage of the course grade. Rewrite the previous problem so that it takes in the raw scores out of 50 and calculate their final grade
#### Sample run:

```
Please enter the grade of the first test out of 50: 36
Please enter the grade of the second test out of 50: 44
Please enter the grade of the third test out of 50: 33
The final grade is: 73.80 %
```

### Walkthrough 1

####  What is the output of the following program?

<img width=500 src="./_images/lab1walk1.png"/>

> [!TIP]
>
> To find out if you were correct, code the program, compile it, and execute it to see!

### Walkthrough 2


#### What is the output of the following program?

<img width=550 src="./_images/lab1walk2.png"/>

> [!TIP]
>
> To find out if you were correct, code the program, compile it, and execute it to see!
