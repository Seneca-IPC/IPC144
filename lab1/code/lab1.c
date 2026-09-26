/***************************************************************** 

    File: lab1.c

    Author:       [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program on matrix type:
        gcc -Wall lab1.c -o lab1
    To run program on matrix type:
        ./lab1
        
***************************************************************/

// Uncomment the line below IF you are using Visual Studio (MSVC compiler)
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
     int C;
    float F;
    printf("Enter the Temperature in Celsius:");
    scanf("%d",&C);
    F=(9.0 / 5.0) * C + 32;
    printf("%d of Celsius is %.2f in Fahrenhiet", C, F);
    return 0;
}

