# Project 1: ASCII Art Train Generator


## Due: Week 7, please ask your professor for exact due date for your section

* Late penalty -10% (2 marks) submitted 1 day after the stated due date
* Late penalty of -50% (10 marks) after 1 day later date and on or before June 27
* Project will not be accepted after June 27

For your first project this semester, you will be creating an ASCII Art Train Generator.  You have some freedom as to how you implement the details of your program, but your program must meet the following basic specifications.  Make sure you pay attention to the Rubrics section of this project so you know how you will be graded.  Producing the correct results does not guarantee you will receive a perfect score as part of your grade will be related to program design as well as any additional efforts you make that go beyond the basic requirements.

## Starter files:


### Already did Lab-0?
If you have already have completed Lab-0 and have your **own code repository**, go directly to your repository:

- https://github.com/seneca-ipc-s26
- Navigate to the **projects/project1/** folder and code your solution using the provided starter source files.

### Didn't do Lab-0...
You must join the IPC classroom to get your coding repository. Follow these instructions to get your repository for all your assessments:
1. To get started, [click on this link for your work repository](https://classroom.github.com/a/UNEXMgcI)
2. These steps may not be required if you had done this in a previous lab.
	- Enter your **SENECA USERNAME** (the username part of your seneca email)
	<img width=600 src="../labs/enterteam.jpg"/><br>
	- Hit **`Create Team`** button
	- On the next page hit accept assignment.


> [!WARNING]
> You are NOT to rename or add additional files to this repository. The automated checker requires exactly these files to be in your repository therefore it is expected you will implement all your program logic in these files only.




## Inputs:

Your program will read the following information interactively from the user in **EXACTLY THIS ORDER** (you must read a correct value for number of trains before reading direction):

1. **number of train cars** - an integer representing the number of train cars not including the engine.  This integer must be a number between `0` and `5` inclusive
2. **direction** - The direction is either `L` or `R` (or their lower case versions).  It indicates if the train is heading toward the left or right side of the screen.

> [!IMPORTANT]
> 
> Your program must validate the data entered. If the data is incorrect, your program must present an appropriate error message, prompting the user to entered the data again.  This needs to be repeated until the data is valid.


## Output:

The output of this program is an ASCII art drawing of a train.  The exact look of the train is up to you.  It need not be original.  Some examples can be found here: https://www.asciiart.eu/vehicles/trains.  You are not limited to the examples on that page. It is there as examples.

> [!WARNING]
> 
> Ensure that you **cite** any art that you did not create on your own in your **file header comment**.

The program will always generate the engine of the train and there can only be one engine, but you must also generate the other attached cars of the train. The number of cars you need to generate (again, not including the engine), depends on the value entered by the user. 

>[!Note]
>**While the valid input is restricted to a maximum of 5 cars to ensure that it prints nicely for our platform, your solution for drawing the train must work for any positive number entered.  For example,  if I had a giant display capable of showing 800 cars, your code for drawing the trains must work for 800 cars.  Only the input checking would need to change for your program to work correctly**

The train may also be traveling towards the right hand side of the screen or towards the left hand side of the screen.  Your train engine must face the correct direction and be the "front" of the train (first car). 

> [!NOTE]
> 
> Note that it is allowed for the train cars and engine to look slightly different depending on which way the train is heading but it should be as similar as possible

### Train heading right with 1 car
```
__________	 ____
|o o o o |	 |DD|____T_
|________|-*-|_ |_____|<
 @ @ @ @ 	  @-@-@-oo\
```

### Same Train heading left with 1 car


```
       ____   __________
 _T____|DD|   |o o o o |	 
>|_____| _|-*-|________|
 /oo-@-@-@      @ @ @ @ 	 

```

Train engine art came from: https://www.asciiart.eu/vehicles/trains

> [!CAUTION]
> 
> Your art must resemble a train and there must be a distinct uniqueness between the train engine car and the other train cars.  The train engine car must have a clear "front" and "back"

### Invalid Trains


Trains drawn must resemble trains as they would normally operate.  Your result is considered to be wrong if your program generates trains that look like these.  Here are some invalid trains:

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

#### INVALID: Right facing train that is stacked Pancakes.. trains don't travel on top of each other

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

## Rubrics

* [Rubric Explanation Video](https://youtu.be/uv4ol7VRKg4)

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
> * You are limited to applying **only the concepts covered in the course to-date**. Implementation of any concepts not yet covered in the course will attract `-50% (10 marks)`.
> * Random number generation is exempt from this if you choose to do that as your "custom" feature.  A discussion of random number generation can be found here in the course notes: https://seneca-scpa.github.io/Introduction-To-Programming/M-Libraries/stdlib#rand


### Grading rubric

>[!IMPORTANT]
> * Project is graded out of 20.
> * If you incur a penalty because you have a late submission or you got a grade penalty from the deductions section, **each penalty will be deducted from the calculated general rubrics grade.**
> * For example, suppose your rubric score was 17/20 but you used a global variable and had multiple returns in a function, your grade would be reduced to 0/20.

| Description | Level 4 | Level 3 | Level 2 | Level 1 | Level 0 |
|---|---|---|---|---|---|
|Documentation - 20% | For all functions state what parameters are (and any assumptions of what is allowed), what return value is, what it does. | 1 or 2 functions documentation missing. or function description comments lack some detail. Over documentation. documenting every line of code is not a good... let the code speak| 3 or 4 function documentation missing or severe lack of details for function description or documentation is done only at code level (within the code) and not as an overall intention| only a few functions got documented and documentation tends to be code description as opposed to code intention.| Almost no documentation of any type|
|Coding Style - 10% | Code follows posted styling guide perfectly and consistently | Coding style does not follow posted styling guide but the styling is consistent and differences are slight stylistic variations as opposed to poor styling choices. For example, all variables use of snake_case as opposed to the specified camelCase | 1 to 3 cases of inconsistent or bad styling | 4 to 6 instances of inconsistent or bad styling decisions | more than 6 cases of inconsistent or bad styling | 
| Correctness and Completeness of Program  - 40%| Program is able to generate a correct and consistent output for all test cases and showed additional customization without violating the the specifications | Program is able to generate a correct and consistent output for all test cases without violating the specifications | 1 or 2 of the test case outputs were not correct or small violation of specification (your train engine doesn't look the same when facing different directions) | at least one test case output is correct but more than 2 incorrect test case outputs or large violation of specification (such as ignoring a requirement) | No test case output is correct|
| Follows Appropriate Choices in Implementation - 30%| Used the most appropriate construct for required task consistently throughout the program | 1 instance of poor construct choice for required task | 2 instance of poor construct choice for required task | 3 instance of poor construct choice for required task | 4 or more instance of poor construct choice for required task |

### Checking Your runs

To check your run
* Go to the actions tab of your repository.
* Click on the top most item then click the build button.
* Click the section that says "Run Project - EXPAND TO SEE RESULT"

Double check that the output is valid for each test case.

## Submission

Submit a link to your project repository to blackboard.  Note that no alterations are to be made to your repository once you submit to blackboard.  Any changes to your repository after the due date will make your project late and subject to the late penalties of that submission
