/*
Program to implement Recursive Descent Parsing.
-------------------------------------------------

Grammar:
E  -> i E'
E' -> + i E' | ε

Valid Strings:
i$
i+i$
i+i+i$

-------------------------------------------------
*/
#include<stdio.h>
static char c[10];
char input;
void E(),EPRIME();
int main()
{
printf("Enter a String: ");
scanf("%s",c);
E();
if(c[input]=='$')
printf("Valid String\n");
else
printf("Invalid String\n");
return 0;
}
void E()
{
if (c[input] == 'i')
input++;
EPRIME();
}
void EPRIME()
{
if (c[input]== '+')
{ input++;
if(c[input]=='i')
input++;
EPRIME();
}
else
return;
}