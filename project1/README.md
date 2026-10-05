# Project 1: ASCII Art Train Generator


## Due: Week 7, please ask your professor for exact due date for your section

* Late penalty -10% (2 marks) submitted 1 day after the stated due date (as per your professor)
* Late penalty of -50% (10 marks) AFTER the 1 day later date (above) and on or **BEFORE October 31**
* Project will not be accepted **AFTER October 31**

## Project Preparation

As with your labs, to submit your work for this project, **YOU MUST HAVE SUCCESSFULLY COMPLETED [Lab-0](../lab0/README.md)** where you configure the tooling and learn the process involved in completing a project and how to submit your work!

> [! WARNING]
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

## Project Overview

Your first project this term will be to create an ASCII Art Train Generator.  You have **some** freedom as to how you implement the details of your program, but your program must meet basic specifications outlined throughout this document and in the rubrics section (make sure you thoroughly review the rubrics so you know how you will be graded).  Producing the correct results does not guarantee you a perfect grade because part of your grade will be related to program design as well as any additional efforts you make that go beyond the basic requirements.

## Project and Starter Files:

You **must use the original starter files provided with this project** from which you will build your solution.

> [!WARNING]
> 
> **You are NOT to rename or add additional files to this repository.**
> 
> The automated checker requires exactly these files to be in your repository therefore it is expected you will implement all your program logic in these files only.


## Inputs:

Your program will read the following information interactively from the user in **EXACTLY THIS ORDER** (you must read a correct value for the number of trains before reading the direction):

1. **Number of train cars** : an integer representing the number of train cars **NOT including the ENGINE**.  This integer must be a number between `0` and `5` **inclusive**

2. **Direction** : The direction in which the train is traveling which can be either `L`eft or `R`ight (case insensitive meaning it can also be lowercase `l` or `r`).  It indicates if the train is heading toward the left or right side of the screen.

> [!IMPORTANT]
> 
> Your program must validate the data entered. If the data is incorrect, your program must present an 
> appropriate error message, prompting the user to entered the data again.  This needs to be repeated 
> until the data is valid.


## Output:

The output of this program is an ASCII art drawing of a train.  The exact look of the train is up to you.  It need not be original. A good reference for some examples can be found here: https://www.asciiart.eu/vehicles/trains.  You are not limited to the examples on that page. It is there to save you some time on the artistic side of this project.

> [!WARNING]
> 
> You MUST **`cite` ANY art** you did not create on your own \(even if you modified it from the original\). The citing 
> must be placed within the **top comment section** for every source \(.c\) / header \(.h\) code file 
> in the project.

The program will always generate the ENGINE of the train and there can only be **ONE engine**, but you must also generate the other attached **CARS** of the train. The number of cars you need to generate depends on the value entered by the user (cars are always in ADDITION to the engine).

> [!NOTE]
> 
> The project specifications state to enforce a **maximum of 5 cars \(1 engine, plus 5 cars\)**. 
> This is only because we want the train to 'fit' the standard 80-character terminal screen width. 
>
> However, the **logic and design** of your solution **must work for ANY POSITIVE NUMBER of cars 
> entered**. Make sure you solution can easily be extended to accommodate any number of cars even 
> though we are capping it at 5 cars.

The ENGINE of the train must always be the first car (and should look distinctly different and appropriately as an engine car). The DIRECTION of the train impacts the placement of your cars. When the train is going RIGHT, the engine will be the right-most car and facing towards the right. The opposite is also true if the direction is LEFT, the engine will be the left-most car and facing the left.

> [!NOTE]
> 
> Note:
>
> Be sure to observe any symbol characters that will need to be **REVERSED** depending on the 
> direction. If you look at the examples below, the less-than symbol `<` when going in the right 
> direction, becomes a greater-than symbol `>` when going in the left direction.
>
> Also, some characters will require extra **escape** characters to ensure it is displayed 
> correctly using printf.
>
> The **ALIGNMENT** across lines and columns (ie: wheels) should be consistent

### Train heading right with 1 car (1 engine, 1 car)
```
__________	 ____
|o o o o |	 |DD|____T_
|________|-*-|_ |_____|<
 @ @ @ @ 	  @-@-@-oo\
```

### Same Train heading left with 1 car (1 engine, 1 car)


```
       ____   __________
 _T____|DD|   |o o o o |	 
>|_____| _|-*-|________|
 /oo-@-@-@      @ @ @ @ 	 

```

Train engine art came from: https://www.asciiart.eu/vehicles/trains

> [!CAUTION]
> 
> Your art **must resemble a train** and there must be a **distinct uniqueness between 
> the train engine car and the other train cars**.  The train engine car must have a **clear 
> \"front\" and \"back\"**

### Invalid Trains

Trains drawn must resemble trains as they would normally operate.  Your result is considered to be wrong if your program generates trains that look like these:

#### INVALID: Right facing train where Engine pushes the train.
```
____          __________
|DD|____T_    |o o o o |
|_ |_____|<-*-|________|
 @-@-@-oo\     @ @ @ @ 	
```

#### INVALID: Right facing train where Engine is facing the wrong way
```
__________          ____   
|o o o o |    _T____|DD|
|________|-*->|_____| _|
  @ @ @ @ 	  /oo-@-@-@
```

#### INVALID: Right facing train that is stacked Pancakes.. trains don't travel on top of each other!

```
   __________ 
   |o o o o |   
-*-|________|
    @ @ @ @ 	 
____      
|DD|____T_
|_ |_____|
 @-@-@-oo\
```

These are just some examples of invalid trains, there may be other invalid configurations.  You need to check your own output!


## Additional customizations

To qualify for full marks, your program must meet the above specifications and also show additional customizations without violating the original specs.  The customization function correctly for all input for it to qualify(see correctness and completeness of program section of rubrics) Here are some things that you can do to meet those customization requirements:

* add smoke that comes out of the engine and extends toward the back of the train
* generate randomly the number of windows on each train car from 0 to 4, draw windows based on that randomly generated number
* use an array and store 5 fixed values between 0 to 4 in each element.  Use those values to determine the number of windows
* if you wish to do something else, please verify with your prof that it is considered an additional customization

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

* [Rubric Explanation Video](https://youtu.be/uv4ol7VRKg4)

### Deductions

There are some constructs and/or design choices in programming that are syntactically and logically correct (will compile and the program works) but go against best practices and/or are considered poor design. 

> [!CAUTION]
>
> Your work will be flagged with a **HEAVY DEDUCTION** if you implement any of the **MUST BE AVOIDED**
> items listed below:
>
> * Use of **global variables**: `-50% (10 marks deducted)`
>   - Any variable that is not declared INSIDE a function or a function's prototype (parameters) are global variables.  These are **ABSOLUTELY FORBIDDEN**
>
> * Use of **`continue`**, **`goto`** and **`break`** (outside of a switch construct): `-50% (10 marks deducted)`
>
> * Use of **multiple `return` statements** from a function: `-50% (10 marks deducted)`
>   - Each function can only have one **SINGLE return** statement.  If you have more than one, 
>     you have violated the \"Single-entry, single-exit Principle\".  Multiple returns violate 
>     structured programming practices.

Additionally...

> [!IMPORTANT]
>
> * Topics NOT yet covered: `-50% (10 marks deducted)`
>   - You are limited to applying **only the concepts covered in the course to-date**. You must 
>     not implement any concepts not yet covered in the course! 
>
> * NOTE: **Topic Exception**
>   - Random number generation is exempt from this if you choose to do that as your "custom" 
>     feature.  A discussion of random number generation can be found here in the course 
>     notes: https://seneca-scpa.github.io/Introduction-To-Programming/M-Libraries/stdlib#rand


### Grading rubric

> [!IMPORTANT]
> * Project is graded out of 20.
> * If you incur a penalty because you have a late submission or you got a grade penalty from the deductions section, **each penalty will be deducted from the calculated general rubrics grade.**
> * For example, suppose your rubric score was 17/20 but you used a global variable and had multiple returns in a function, your grade would be reduced to 0/20.

| Description | Level 4 | Level 3 | Level 2 | Level 1 | Level 0 |
|---|---|---|---|---|---|
|Documentation - 20% | For all functions state what parameters are (and any assumptions of what is allowed), what return value is, what it does. | 1 or 2 functions documentation missing. or function description comments lack some detail. Over documentation. documenting every line of code is not a good... let the code speak| 3 or 4 function documentation missing or severe lack of details for function description or documentation is done only at code level (within the code) and not as an overall intention| only a few functions got documented and documentation tends to be code description as opposed to code intention.| Almost no documentation of any type|
|Coding Style - 10% | Code follows posted styling guide perfectly and consistently | Coding style does not follow posted styling guide but the styling is consistent and differences are slight stylistic variations as opposed to poor styling choices. For example, all variables use of snake_case as opposed to the specified camelCase | 1 to 3 cases of inconsistent or bad styling | 4 to 6 instances of inconsistent or bad styling decisions | more than 6 cases of inconsistent or bad styling | 
| Correctness and Completeness of Program  - 40%| Program is able to generate a correct and consistent output for all test cases and showed additional customization without violating the the specifications | Program is able to generate a correct and consistent output for all test cases without violating the specifications | 1 or 2 of the test case outputs were not correct or small violation of specification (your train engine doesn't look the same when facing different directions) | at least one test case output is correct but more than 2 incorrect test case outputs or large violation of specification (such as ignoring a requirement) | No test case output is correct|
| Follows Appropriate Choices in Implementation - 30%| Used the most appropriate construct for required task consistently throughout the program | 1 instance of poor construct choice for required task | 2 instance of poor construct choice for required task | 3 instance of poor construct choice for required task | 4 or more instance of poor construct choice for required task |



## Submission

The same submission process is required for this project as is done for your labs, only the directory you will be pin-pointing will be `project1` and not a lab directory and the submission command is slightly different as well.

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
	- Change to the `project1` directory (inside your ipc144 repository):
		```
		cd project1
		```
	- Submit your code using the submitter. Substitute `professor.name` with your professor\'s account name, and `NQQ` with your course section code:
		```
		~professor.name/submit 144project1/project1-NQQ
		```
	- Follow the directions to submit your code.

		- **IMPORTANT**: Your application will be compiled and executed by the submitter. It may require an interactive session meaning it could require you to provide the necessary user input(s) to demonstrate your program works (use the values stated by the submitter).

	- If there are errors or your submission failed to submit, fix the problems **ON YOUR DEVICE**, and repeat the above submission process again from the beginning.
	
 * Lastly, on **Blackboard** paste the URL (link) to the **project1** directory of your PRIVATE ipc144 GitHub repository by clicking the **`Project 1 - Submission`** item in the main content page.

> [!IMPORTANT]
>
> **DO NOT modify your code directly from matrix** as this will put your repository out of sync
> with the copy of your code on GitHub.
>
> You will learn later in the semester in your course CEP146 how to use Git and GitHub properly.

> [!CAUTION]	
>
> **Only submissions done from matrix will be accepted and eligible for marks**

