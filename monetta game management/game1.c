#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
main()
{
 int i,num=51,flag=1,guess,count=0,s=0,m=0,x=3;
 printf("Guess the number\n");
 scanf("%d",&guess);
do
 {
if(s>59)
{
    m=m+1;
    s=0;
}
Sleep(900);
s=s+1;
  if(num==guess)
  {
   flag=0;
  }
  else if(guess<num)
  {
   flag=1;
   printf("Your guess is lower than the number\n");
   count++;
  }
  else
  {
    flag=1;
   printf("Your guess is greater than the number\n");
   count++;
  }

  if(flag==1)
  {
    printf("Sorry! Please guess it again\n");
   scanf("%d",&guess);
  }
  if(m==x)break;
 } while(flag);

 printf("Congrats! You guessed the number %d\n",num);
 printf("Number of trails: %d\n",count);
}


