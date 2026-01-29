/*
Program to implement Operator Precedence Parsing.
------------------------------------------------------------

Theory:
Operator Precedence Parsing is a bottom-up parsing technique
used for expression grammars where operators and operands
have defined precedence and associativity.

This parser works using:
- Operator precedence table
- Stack
- Shift and Reduce operations

It:
- Handles expressions like i+i*i
- Uses precedence rules to decide parsing actions
- Is suitable for expression-based grammars

------------------------------------------------------------

Grammar Used:
E → E + E
E → E * E
E → i

Where:
i  → identifier
+  → addition operator
*  → multiplication operator
$  → end marker

Operator Precedence:
*  >  +

------------------------------------------------------------

Algorithm:
1. Initialize stack with '$'
2. Append '$' to the input string
3. Repeat until stack and input both contain '$':
   - Compare precedence of stack top and input symbol
   - If stack precedence < input precedence → Shift
   - If stack precedence > input precedence → Reduce
   - If both are '$' → Accept
4. Otherwise → Reject

------------------------------------------------------------

Sample Input:
i+i*i$

Sample Output:
Accept

------------------------------------------------------------
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
char stack[20],ip[20],opt[10][10][1],ter[10];
int i,j,k,n,top=0,row,col;
int len;
for(i=0;i<10;i++)
{
stack[i]=NULL;
ip[i]=NULL;
for(j=0;j<10;j++)
{ opt[i][j][1]=NULL;
}
}
printf("Enter the no.of terminals:");
scanf("%d",&n);
printf("\nEnter the terminals:");
scanf("%s",ter);
printf("\nEnter the table values:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("Enter the value for %c %c:",ter[i],ter[j]);
scanf("%s",opt[i][j]);
}
}
printf("\nOPERATOR PRECEDENCE TABLE:\n");
for(i=0;i<n;i++)
{
printf("\t%c",ter[i]);
}
printf("\n ");
printf("\n");
for(i=0;i<n;i++)
{
printf("\n%c |",ter[i]);
for(j=0;j<n;j++)
{
printf("\t%c",opt[i][j][0]);
}
}
stack[top]='$';
printf("\n\nEnter the input string(append with $):");
scanf("%s",ip);
i=0;
printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
printf("\n%s\t\t\t%s\t\t\t",stack,ip);
len=strlen(ip);
while(i<=len)
{
for(k=0;k<n;k++)
{
if(stack[top]==ter[k])
row=k;
if(ip[i]==ter[k])
col=k;
}
if((stack[top]=='$')&&(ip[i]=='$'))
{
printf("String is ACCEPTED");
break;
}
else if((opt[row][col][0]=='<') ||(opt[row][col][0]=='='))
{
stack[++top]=opt[row][col][0];
stack[++top]=ip[i];
ip[i]=' ';
printf("Shift %c",ip[i]);
i++;
}else
{
if(opt[row][col][0]=='>')
{
while(stack[top]!='<')
{
--top;
}
top=top-1;
printf("Reduce");
}
else
{
printf("\nString is not accepted");
break;
}
}
printf("\n");
printf("%s\t\t\t%s\t\t\t",stack,ip);
}
getch();
}