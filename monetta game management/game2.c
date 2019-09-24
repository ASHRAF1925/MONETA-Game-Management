#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 main ()
 {
 int number,guess;
 srand ( time(NULL) );
 number = rand() % 2;
 printf("Guess 1 for tail or 0 for head\n");
 scanf("%d",&guess);
 printf("Result of toss is\n");
 if(number==0)
 {
  printf("Head\n");
 }
 else
 {
  printf("Tail\n");
 }
 printf("You guessed\n");
 if(guess==0)
 {
  printf("Head\n");
 }
 else
 {
  printf("Tail\n");
 }
 if(number==guess)
 {
      printf("Hurray! You won the toss\n");
 }
 else
 {
  printf("Oops! Better Luck Next Time\n");
 }
 }

