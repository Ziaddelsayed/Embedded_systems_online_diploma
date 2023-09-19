/*
 ============================================================================
 Name        : ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char alphabet;
   printf("Enter an alphabet:");
   fflush(stdin);fflush(stdout);
   scanf("%c",&alphabet);
   switch(alphabet)
   {
   case'a':
   case'A':
   case'e':
   case'E':
   case'i':
   case'I':
   case'o':
   case'O':
   case'u':
   case'U':
   {
	   printf("%c is vowel",alphabet);

   }
   break;
   default:
	   printf("%c is consonant",alphabet);
	   break;
   }
	return 0;
}
