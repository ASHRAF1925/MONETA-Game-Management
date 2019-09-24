//IN THE NAME OF ALLAH THE MOST GRACIOUS THE MERCIFUL
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"monettagame.h"
#include"stopwatch3.h"
#include<dos.h>
//#include<time.h>
#include<windows.h>
//int time_moneta;
//int count_moneta;
int moneta;
// a welcome graphics
//login file stucture
struct login{
char fname[100];
char lname[100];
char username[20];
char password[20];
//int time_moneta;
int count_moneta;
};
struct admlogin{
char fname[100];
char lname[100];
char username[20];
char password[20];
};

//register function for administrator
signin()
{
    FILE *log;
    log = fopen("login12.txt","w");
    struct admlogin l;
    printf("Enter the first name: ");
    scanf("%s",l.fname);
    printf("Enter last name :");
    scanf("%s",l.lname);
    printf("Enter user name :");
    scanf("%s",l.username);
    printf("Enter Password: ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);
printf("\n Now login with User ID and Password");
printf("\n Press any key to continue....");
getch();
system("CLS");
login();


}



// log in function for administrator
login()
{
int choice;
    char username[20],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct admlogin l;
    printf("USER ID : ");
    scanf("%s",&username);
    printf("PASSWORD :");
    scanf("%s",&password);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\nlogin successful");
            printf("\nEnter the choice:\n");
       printf("\n1.Input player \n");
       printf("\n2.change Password \n");
       printf("\n press any key to exit");
       printf("\nEnter your choice :");
       scanf("%d",&choice);
       if(choice==1)
       {
         player_signin();
       }
       else if(choice==2)
       {
           signin();
       }
       else {exit(1);}
        }
        else {
            printf("Please enter the correct name and password");

        }
    }
    fclose(log);


}
//register function for player
player_signin()
{
    FILE *log;
    log = fopen("player.txt","w");
    struct login l;
    printf("Enter the player first name: ");
    scanf("%s",l.fname);
    printf("Enter player last name :");
    scanf("%s",l.lname);
    printf("Enter player user name :");
    scanf("%s",l.username);
    printf("Enter player Password: ");
    scanf("%s",l.password);
    //printf("\nEnter the type of Moneta ?\n");
;
    //printf("\n1.Time Moneta");
    //printf("\n 1.Count Moneta");
    //printf("\nEnter your choice :");
    //scanf("%d",&moneta);
    moneta=1;
    if(moneta==2)
    {
        /*printf("\nEnter the amount of time in minute: ");
        scanf("%d",&l.time_moneta);*/
    }
    else if(moneta==1)
    {
        printf("\n Enter the amount of Count Moneta:");
        scanf("%d",&l.count_moneta);
    }

    fwrite(&l,sizeof(l),1,log);
    fclose(log);
printf("\n Now login with Player User ID and Password\n");
printf("\n Press any key to continue....\n");
getch();
system("CLS");
player_login();


}
//login function for player
player_login()

{ printf("\n are you ready to play?\n");

    char username[20],password[20];
    FILE *log;
    log=fopen("player.txt","r");
    struct login l;
    printf("\nUSER YOUR ID\n : ");
    scanf("%s",&username);
    printf(" \nENTER YOUR PASSWORD\n :");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\nlogin successful");
            if(moneta==2)
            {
                /*printf("\n Your time is %d miniute",l.time_moneta);
                play_game_time(l.time_moneta);*/
            }
            else if(moneta==1)
            {
                printf("\n you can play  %d rounds\n",l.count_moneta);
                play_game_count(l.count_moneta);
            }

        }
        else {
            printf("Please enter the correct name and password");
            player_login();

        }
    }
    fclose(log);


}
/*play_game_time(int x)
{
   timer(x);
}*/
play_game_count(int x)
{
    while(x--)
    {
        printf("Choose which game do you want to play:\n");
    printf("Press 1 for guessing number\n");
    printf("Press 2 for winning the toss.\n");
    printf("Press 3 for Tick Tack Toe.\n");
    int q;
    scanf("%d",&q);
    if(q==1)game1();
    if(q==2)game2();
    if(q==3)game3();
    }
    printf("You have spent all your moneta\n");
    printf("You can ask for more moneta to the administrator\n");
    Sleep(1500);
    printf("\n");
    printf("\n");
    login();
}
//main function
main()
{
    printf("\nWELCOME TO MONETA GAME MANAGEMENT SYSTEM\n");
    printf("\n.........Administrator Login.......\n");

//administrator part

//signin();

login();


}
