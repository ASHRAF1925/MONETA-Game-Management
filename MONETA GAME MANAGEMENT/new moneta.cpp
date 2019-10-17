#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"monettagame.h"
#include"monettagame2.h"
//#include"stopwatch3.h"
#include<dos.h>
//#include<time.h>
#include<windows.h>
#include <iostream>
#include <string>


void signin();
void login();
void player_signin();
void player_login();
void play_game_count(int x,int d);
void play_game_count2(int x,int y,int d,int d1);
void leaderboard(int x,int n);
void leader();
void highscore();
void highscore2();

struct admlogin{
char fname[100];
char lname[100];
char username[100];
char password[100];
};

struct login{
//char fname[100];
//char lname[100];
char username[100];
char password[100];
//int time_moneta;
int count_moneta;
};

void signin()
{
    char adminid[100],adminpwd[100];
    FILE *log;
    log = fopen("login12.txt","w");
    scanf("%s",adminid);
    strcat(adminid,"\n");
    fputs(adminid,log);
    scanf("%s",adminpwd);
    strcat(adminpwd,"\n");
    fputs(adminpwd,log);

    fclose(log);
printf("\n Now login with User ID and Password");
printf("\n Press any key to continue....");
//getch();
system("CLS");
login();


}

void login()
{
int choice,f=0,z=0;
char adminid[100],adminpwd[100],ch;
    char username[20],password[20]={0};
    FILE *log;
    log=fopen("login12.txt","r");
    //struct admlogin l;
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    printf("USER ID : ");
    scanf("%s",username);
    strcat(username,"\n");

for(int j=0;j<5;j++)
    printf("     ");
    printf("PASSWORD :");
    while(1)
    {

        ch=_getch();
        if(ch==13){
            password[z]='\n';
        z++;
                break;
        }
        else
            {
              password[z]=ch;
              z++;
              printf("*");
            }
    }
    //strcat(password,"\n");


    system("cls");
    fgets(adminid,50,log);
    fgets(adminpwd,50,log);
    fclose(log);
    //printf("%d\n",strcmp(username,adminid));
   //printf("%d\n",strcmp(password,adminpwd));
if((strcmp(username,adminid))==0&&(strcmp(password,adminpwd))==0)
{
    f=1;
}
if(f==1)
{ for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    system("color E4");

    printf("Login Successfull!!!!\n");
    Sleep(1000);
    system("cls");
    while(1)
    {
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    printf("1 for Player input\n");

for(int j=0;j<5;j++)
    printf("     ");
    printf("2 for Signing.\n");

for(int j=0;j<5;j++)
    printf("     ");
    printf("3 for Leader of The Moneta.\n");
for(int j=0;j<5;j++)
    printf("     ");
      printf("4 for Highscorer in PACMAN.\n");
for(int j=0;j<5;j++)
    printf("     ");
    printf("5 for Highscore in Guess the number.\n");
for(int j=0;j<5;j++)
    printf("     ");
    printf("6 for exit from the system.\n");

for(int j=0;j<5;j++)
    printf("     ");
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    system("cls");


    if(choice==1)player_signin();
    if(choice==2)signin();
    if(choice==3)leader();
    if(choice==4)highscore();
    if(choice==5)highscore2();
    if(choice==6)return ;
}
}
else {
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
        printf("Wrong ID or Password.Please try again!\n");
Sleep(2000);
system("cls");
login();
}
}
void player_signin()
{
    int x,z=0;
    char c[100],username[100],password[100],count_moneta[100],ch;
    FILE *log,*log1,*log2;
    log=fopen("playid.txt","w");
    log1=fopen("playpwd.txt","w");
    log2=fopen("counting.txt","w");

    struct login l;
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<7;j++)
    printf("     ");
    system("color F0");
    printf("How many players do you want to input?\n");
    for(int j=0;j<7;j++)
    printf("     ");
    printf("Choose:");
    scanf("%d",&x);
    system("cls");
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<2;j++)
    printf("     ");
    printf("Give the user ids and passwords and amount of moneta respectively,without space.\n");
Sleep(1000);
system("cls");
    for(int i=0;i<x;i++)
    {
for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<7;j++)
    printf("     ");
        printf("Give user ID:");
        scanf("%s",username);
        strcat(username,"\n");
        fputs(username,log);

for(int j=0;j<7;j++)
    printf("     ");
        printf("Give passwords:");
        while(1)
    {

        ch=_getch();
        if(ch==13){
            password[z]='\n';
        z++;
                break;
        }
        else
            {
              password[z]=ch;
              z++;
              printf("*");
            }
    }
        /*scanf("%s",password);
        strcat(password,"\n");*/
        fputs(password,log1);
printf("\n");
for(int j=0;j<7;j++)
    printf("     ");

        printf("Give the amount of moneta:");
        scanf("%s",count_moneta);
        strcat(count_moneta,"\n");
        fputs(count_moneta,log2);

        system("CLS");
    }
    fclose(log2);
    fclose(log1);
    fclose(log);
    player_login();
}

void player_login()
{
    int f=0,c=0,c1=0,d,d1,num,num1,e=0,p,z=0;
    char ch[1000]={0},ch1[1000]={0},g;
    struct login l;
    FILE *log,*log1,*log2;
    log=fopen("playid.txt","r");
    log1=fopen("playpwd.txt","r");
    log2=fopen("counting.txt","r");
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<2;j++)
    printf("     ");
    system("color 90");
    printf("One player will be logged in or Two player will be logged in?\n");
    for(int j=0;j<2;j++)
    printf("     ");
    printf("Please choose:");
    scanf("%d",&p);
    system("cls");
    if(p==1)
    {
        for(int i=0;i<9;i++)
{
    printf("\n");
}
        while(1)
    {
        for(int j=0;j<7;j++)
    printf("     ");
    printf("Player 1:\n");
for(int j=0;j<7;j++)
    printf("     ");
        printf("Give user id:");
    scanf("%s",ch);
    strcat(ch,"\n");
    do
    {
        fgets(l.username,50,log);
        //printf("%d\n",strcmp(ch,l.username));
        if(!feof(log))
        {
           if((strcmp(l.username,ch))==0)f=1;
        }
    }while(!feof(log));
    if(f==1)break;
    else {
            for(int i=0;i<9;i++)
{
    printf("\n");
}
            for(int j=0;j<7;j++)
    printf("     ");
            printf("WRONG USER ID.PLEASE TRY AGAIN.\n");
    Sleep(1500);
    system("cls");
    }
}

while(1)
{ for(int j=0;j<7;j++)
    printf("     ");
    printf("Give password:");
    while(1)
    {

        g=_getch();
        if(g==13){
            ch[z]='\n';
        z++;
                break;
        }
        else
            {
              ch[z]=g;
              z++;
              printf("*");
            }
    }


    do
    {

        fgets(l.password,10,log1);
        if(!feof(log1))
        {
            if((strcmp(l.password,ch))==0){f=1;d=c;}
            c++;
        }

    }while(!feof(log1));
    if(f==1)break;
    else {

        for(int j=0;j<7;j++)
    printf("     ");
            printf("WRONG PASSWORD.PLEASE TRY AGAIN.\n");
    Sleep(1500);
    system("cls");
    }
}
system("cls");
//printf("d er value %d\n",d);
while(!feof(log2))
{
    char ch3[100];
     fgets(ch3,80,log2);
     num=stoi(ch3);
if(d==e)
{

    play_game_count(num,d);
}
e++;
}

system("cls");
//play_game_count(num);
}
else if(p==2)
{
    for(int i=0;i<9;i++)
{
    printf("\n");
}
while(1)
    {
        for(int j=0;j<7;j++)
    printf("     ");
printf("Player 1:\n");
for(int j=0;j<7;j++)
    printf("     ");
        printf("Give user id:");
    scanf("%s",ch);

    strcat(ch,"\n");

    do
    {
        fgets(l.username,50,log);
        //printf("%d\n",strcmp(ch,l.username));
        if(!feof(log))
        {
           if((strcmp(l.username,ch))==0)f=1;
        }
    }while(!feof(log));
    if(f==1)break;
    else printf("WRONG USER ID.PLEASE TRY AGAIN.\n");
    }
    while(1)
{
for(int j=0;j<7;j++)
    printf("     ");
    printf("Give password:");
   while(1)
    {

        g=_getch();
        if(g==13){
            ch[z]='\n';
        z++;
                break;
        }
        else
            {
              ch[z]=g;
              z++;
              printf("*");
            }
    }
    printf("\n");
    do
    {

        fgets(l.password,10,log1);
        if(!feof(log1))
        {
            if((strcmp(l.password,ch))==0){f=1;d=c;}
            c++;
        }

    }while(!feof(log1));
    if(f==1)break;
    else printf("WRONG PASSWORD.PLEASE TRY AGAIN.\n");
}
    while(1)
    {
        for(int j=0;j<7;j++)
    printf("     ");
    printf("Player 2:\n");
for(int j=0;j<7;j++)
    printf("     ");
        printf("Give user id:");
    scanf("%s",ch1);
    strcat(ch1,"\n");
    do
    {
        fgets(l.username,50,log);
       // printf("%d\n",strcmp(ch1,l.username));
        if(!feof(log))
        {
           if((strcmp(l.username,ch1))==0)f=1;
        }
    }while(!feof(log));
    if(f==1)break;
    else printf("WRONG USER ID.PLEASE TRY AGAIN.\n");
}

while(1)
    {
for(int j=0;j<7;j++)
    printf("     ");
    printf("Give password:");
    while(1)
    {

        g=_getch();
        if(g==13){
            ch1[z]='\n';
        z++;
                break;
        }
        else
            {
              ch1[z]=g;
              z++;
              printf("*");
            }
    }
    printf("\n");
    do
    {

        fgets(l.password,10,log1);
        if(!feof(log1))
        {
            if((strcmp(l.password,ch))==0){f=1;d1=c1;}
            c1++;
        }

    }while(!feof(log1));
    if(f==1)break;
    else printf("WRONG PASSWORD.PLEASE TRY AGAIN.\n");
}
system("cls");
 while(!feof(log2))
{
    char ch3[100];
     fgets(ch3,80,log2);
     num=stoi(ch3);
if(d==e)
{
break;
}
e++;
}
fclose(log2);
log2=fopen("counting.txt","r");
   while(!feof(log2))
{
    char ch3[100];
     fgets(ch3,80,log2);
     num1=stoi(ch3);
if(d1==e)
{
break;
}
e++;
}
fclose(log2);
fclose(log1);
fclose(log);
play_game_count2(num,num1,d,d1);
}
}

void play_game_count(int x,int d)
{
    int k,z;
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<7;j++);
printf("     ");
 system("color 90");
    printf("The number of the times you can play %d\n",x);
    while(x--)
    {for(int j=0;j<7;j++);
printf("     ");
        printf("WHICH GAME DO YOU WANT TO PLAY??\n");
        for(int j=0;j<7;j++);
printf("     ");
        printf("Press 1 for Guess the Number.\n");
        for(int j=0;j<7;j++);
printf("     ");
        printf("And there is no position in leaderboard for Guess The Number.\n");
        for(int j=0;j<7;j++);
printf("     ");
printf("But there is a Highscore option in Login operation\n");
        /*printf("Press 2 for Shooting is Fun.\n");
        for(int j=0;j<7;j++);
printf("     ");
        printf("Press 3 for Tik Tac Toe.\n");*/
        for(int j=0;j<7;j++);
printf("     ");
printf("Press 2 for PACMAN.\n");
for(int j=0;j<7;j++);
printf("     ");
printf("And there is no position in leaderboard for PACMAN but there is a highscore option in\n");
for(int j=0;j<7;j++);
printf("     ");
printf("Login operation\n");
for(int j=0;j<7;j++);
printf("     ");
printf("Enter Your choice :");
        scanf("%d",&k);
        system("cls");
        if(k==1){
                game1();
                //highscore2();
        }
        //else if(k==2)game2();
        //else if(k==3)game3();
        else if(k==2){game4();}
    }
    system("cls");
    printf("You have spent all your moneta.You can ask administrator for more.\n");

    Sleep(2000);
    system("cls");
    login();
}
void play_game_count2(int x,int y,int d,int d1)
{ system("color B0");
    int k,minm,l;
    minm=min(x,y);
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<9;j++);
printf("     ");
    printf("The number of the times you can play %d\n",minm);
    Sleep(1000);
    system("cls");
    while(x--&&y--)
    {
        for(int i=0;i<9;i++)
        {
            printf("\n");
        }
        for(int j=0;j<9;j++);
printf("     ");
        printf("WHICH GAME DO YOU WANT TO PLAY??\n");
        /*for(int j=0;j<9;j++);
printf("     ");
        printf("Press 1 for Guess the Number.\n");
                for(int j=0;j<9;j++);
printf("     ");
                printf("And there is no position in leaderboard for Guess The Number.\n");*/
      for(int j=0;j<9;j++);
printf("     ");
        printf("Press 1 for Shooting is Fun.\n");
        for(int j=0;j<9;j++);
printf("     ");
        printf("Press 2 for Tik Tac Toe.\n");
        /*for(int j=0;j<9;j++);
printf("     ");
printf("Press 4 for PACMAN.\n");*/
for(int j=0;j<9;j++);
printf("     ");
printf("Enter Your Choice :");
        scanf("%d",&k);
        system("cls");
        /*if(k==1){ system("color E4");
                game1();}
        else*/ if(k==1)
        {
            l=game2();
            if(l==1)leaderboard(2,d);
            else if(l==2)leaderboard(2,d1);
        }
        else if(k==2){
                l=game3();
                 if(l==1)leaderboard(3,d);
            else if(l==2)leaderboard(3,d1);
        }
        /*else if(k==4)
        {
            l=game4();
        }*/
    }
    system("cls");
    printf("You have spent all your moneta.You can ask administrator for more.\n");
    if(x>y){printf("PLayer 2 should get more moneta.\n");}
    if(x<y){printf("Player 1 should get more moneta.\n");}

    Sleep(2000);
    system("cls");
    login();
}
void leaderboard(int x,int n)
{
    FILE *log,*log1,*log2;
    log=fopen("leader.txt","a");
    log2=fopen("leader1.txt","a");
    log1=fopen("playid.txt","r");
    char ch[1000];
    for(int i=0;i<=n;i++)
    {
        fgets(ch,100,log1);
    }
    fputs(ch,log);
    fputs(ch,log2);
    fclose(log1);
    fclose(log2);
    fclose(log);
}
void leader()
{
    int d=0,maxm=0;
    char ch[1000],ch1[1000],ch2[1000];
    FILE *log,*log1;
    log=fopen("leader.txt","r");
    log1=fopen("leader1.txt","r");
    while(!feof(log))
    {
        fgets(ch,100,log);
        //printf("%s\n",ch);
        while(!feof(log1))
        {
            fgets(ch1,100,log1);

            if(strcmp(ch,ch1)==0)
                {
                    //printf("%s ch1 \n",ch1);
                    d=d+5;
            }
        }
        if(d>maxm)
        {
            strcpy(ch2,ch);
        }
    }
    for(int i=0;i<9;i++)
    {
        printf("\n");
    }
    for(int j=0;j<9;j++);
printf("     ");
    printf("The Leader of The Moneta is:%s\n",ch2);
Sleep(2000);
system("cls");
fclose(log);
fclose(log1);
}
void highscore()
{
    system("cls");
    FILE *log=fopen("score1.txt","r");
    int maxm=0,num;
    char ch[100],ch1[100],maxmch[100];

    while(!feof(log))
    {
        fgets(ch,80,log);
        for(int i=0;i<100;i++)
    {
        if(ch[i]=='\n')ch[i]='\0';
    }
        fgets(ch1,80,log);
        num=stoi(ch1);
        if(num>maxm)
        {
            maxm=num;
            strcpy(maxmch,ch);
        }
    }
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    printf("%s is the highscorer in PACMAN And the score is %d\n",maxmch,maxm);
    fclose(log);
    Sleep(2000);
    system("cls");
    login();
}
void highscore2()
{
    char maxmch[100],ch[100],ch1[100];
    int maxm=0,num;
    FILE *log;
    log=fopen("guess.txt","r");
    while(!feof(log))
    {
        fgets(ch,80,log);
        for(int i=0;i<100;i++)
    {
        if(ch[i]=='\n')ch[i]='\0';
    }
        fgets(ch1,80,log);
        num=stoi(ch1);
        if(num>maxm)
        {
            maxm=num;
            strcpy(maxmch,ch);
        }
    }
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    //printf("%s\n",maxmch);
    printf("%s is the highscorer in GUESS And the score is %d\n",maxmch,maxm);
    fclose(log);
    Sleep(3000);
    system("cls");
}
int main()
{   for(int i=0;i<22;i++)
{
    printf("\n");
}
for(int j=0;j<3;j++)
    printf("     ");
    system("color B0");
  printf("In The Name Of Allah The Most Gracious The Most Merciful\n");
Sleep(2000);
system("cls");
for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    system("color E4");
    printf("WELCOME TO MONETA GAME MANAGEMENT SYSTEM\n");
    Sleep(2000);
    system("cls");
    for(int i=0;i<9;i++)
{
    printf("\n");
}
for(int j=0;j<5;j++)
    printf("     ");
    system("color 90");
    printf(".........Administrator Login..........\n");
    Sleep(2000);
    system("cls");

//administrator part

//signin();

login();

return 0;
}
