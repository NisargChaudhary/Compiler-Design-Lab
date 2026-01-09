#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char str[25],pwd[20];
int a,i=0,j=0,h=0,m=0;
FILE *fp,*fp1;
char ch,ch1;
fp = fopen("user.txt", "r");
if (fp == NULL)
{
printf("File not opened ");
exit(1);
}
ch = fgetc(fp);
printf("Your Username is :\n");
while (!feof(fp))
{
str[i++]=ch;
ch = fgetc(fp);
}
str[i]='\0';
printf("%s",str);
fclose(fp);
if(strcmp(str,"JayDepani")==0 || strcmp(str,"DepaniJay")==0 || strcmp(str,"JayPatel")==0 ||
strcmp(str,"PatelJay")==0){
printf("\n This Username is Already there,please try to other Username.");
return 0;
}
if(str[0]<'A' || str[0]>'Z'){
printf("\n First character of the Username should be Capital.");
}
for(i=0;str[i]!='\0';i++){
if(str[i]>='0' &&
str[i]<='9'){ m=1;
break;
}
m=0;
}
if(m==1){
printf("\n Digit is not Allow in the Username.");
}for(i=0;str[i]!='\0';i++){
if(str[i]=='~' || str[i]=='!' || str[i]=='@' || str[i]=='#' || str[i]=='$' || str[i]=='%' || str[i]=='^'
|| str[i]=='&' || str[i]=='*'){
m=1;
break;
}
m=0;
}
if(m==1){
printf("\n Spacial Symbols are not Allow in Username.");
return 0;
}
fp1 = fopen("pass.txt", "r");
if (fp1 == NULL)
{
printf("File not opened ");
exit(1);
}
ch1 = fgetc(fp1);
printf("\nYour Password is :\n");
while (!feof(fp1))
{
pwd[j++]=ch1;ch1 = fgetc(fp1);
}
pwd[j]='\0';
printf("%s",pwd);
fclose(fp1);
a=strlen(pwd);
if(a<8 || a>15){
printf("\n Password length should be 8 to 15 characters.");
}
for(i=0;pwd[i]!='\0';i++){
if(pwd[i]>='0' &&
pwd[i]<='9'){ h=0;
break;
}
h=1;
}
if(h==1){
printf("\n Minimum one digit is complasary to use in password like 1,2,3...");
}
for(i=0;pwd[i]!='\0';i++){
if(pwd[i]=='~' || pwd[i]=='!' || pwd[i]=='@' || pwd[i]=='#' || pwd[i]=='$' || pwd[i]=='%'
|| pwd[i]=='^' || pwd[i]=='&' || pwd[i]=='*')
{
    h=0;
break;
}
h=1;    
}
if(h==1){
printf("\n Must be use one Spacial Symbols in Password like ~,!,@,#,$,%,^,&,*.");
return 0;
}
for(i=0;pwd[i]!='\0';i++){ 
if(pwd[i]==' '){
h=1;
break;
}
h=0;
}
if(h==1){
printf("\n Password should not contain any space.");
return 0;
}
printf("\n Now Your Username is Created.\n Your Username is:%s",str);
printf("\n Now your Password is Created.\n your Password is :%s",pwd);
return 0;
}