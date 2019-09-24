#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
main()

{
int choice, h,m,s; h=0; m=0; s=0; //--variable declaration--//
/*char p= 'p';
printf("Press 1 to start the timer\nPress 2 to exit\n");
printf("\nEnter your choice\n");
scanf("%d",&choice);*/
choice=1;
switch(choice) //--switch case --//
{
case 1:
{
while(1) //--while condition is true//
{
if(s>59) //--if seconds(s) is > 59--//
{
m=m+1; //--increment minute by 1--//
s=0;
}
/*if(m>59) //--if minutes(s) is > 59--//
{
h=h+1; //--increment hour by 1--//
m=0;
}
if(h>11) //--if hour(h) is > 11--//
{
h=0; //-Hour to 0--//
m=0;
s=0;
}*/
Sleep(1000); //--inbuilt function for 1sec delay--//
s=s+1;
/*system("cls"); //--Clear screen--//
printf("DIGITAL CLOCK");
printf("\n\nHOUR:MINUTE:SECOND");
printf("\n\n%d:%d:%d",h,m,s); //--Print time--//
printf("\n\nTo pause : press P\n");*/
/*if(kbhit()) //--Check if any button is pressed on keyboard--//
{
if(p==getch()) //--Check if P is pressed--//
{
system("pause"); //--Inbuilt function for pause and resume--//
}
}*/
if(s==3)break;//--This part can be improvised--//
}
break;
}
case 2:
exit(0); //--Exit --//
default:
{
printf("Wrong Choice");
}
}
system("cls");
printf("You have spent all your time moneta\n");
getch(); //--Holding the screen--//
return 0;
}

