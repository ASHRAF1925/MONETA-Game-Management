#include<stdlib.h>
//#include <stdlib.h>
//#include <windows.h>
#include <iostream>
#include <stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
//#include <stdio.h>
//#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include<math.h>
#include<graphics.h>
#include<time.h>
#include<cstdlib>
#include<ctime>
using namespace std;
#define ERROR puts("Error");

//using namespace std;



#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A



struct GAMEINFO {
	COORD PlayerOnePosition;
	COORD PlayerTwoPosition;
	COORD PlayerOneBullet;
	COORD PlayerTwoBullet;
	COORD PlayerOneBullet2;
	COORD PlayerTwoBullet2;
	COORD ZeroZero;
};

HANDLE hInput, hOutput;
GAMEINFO GameInfo;

int Movement(GAMEINFO &GameInfo);
void Draw(GAMEINFO);
void Erase(GAMEINFO);
int LaunchBullet(GAMEINFO &GameInfo, int);
int LaunchBullet2(GAMEINFO &GameInfo, int);
int Wait();

int game1()
{
    char ch[100],in1[100];
srand(time(0));
     int i,num=rand(),flag=1,guess,countt=0,prev=0,k=0;
 printf("Guess the number\n");
 scanf("%d",&guess);
 //prev=guess;
do
 {

k++;
  if(num==guess)
  {
   flag=0;
  }
  else if(guess<num)
  {
   flag=1;
   printf("Your guess is lower than the number\n");
   countt++;
  }
  else
  {
    flag=1;
   printf("Your guess is greater than the number\n");
   countt++;
  }

  if(flag==1)
  {
prev=guess;
    printf("Sorry! Please guess it again\n");
    if(k>1){printf("Your previous guess was %d\n",prev);}

   scanf("%d",&guess);
  }
  Sleep(1300);
  system("cls");

 } while(flag);
 system("cls");
 printf("Congrats! You guessed the number %d\n",num);
 printf("Number of trails: %d\n",countt);
 //Sleep(1300);
 FILE *log;
 log=fopen("guess.txt","a");
 printf("Please give your user id:");
 scanf("%s",ch);
 strcat(ch,"\n");
 sprintf(in1,"%d",countt);
 strcat(in1,"\n");

 fputs(ch,log);
 fputs(in1,log);
 fclose(log);
  system("cls");
 return 0;
}
int game2()
 {
 GAMEINFO GameInfo;



	hInput = GetStdHandle(STD_INPUT_HANDLE);
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);



	SetConsoleMode(hOutput, ENABLE_PROCESSED_INPUT);

	GameInfo.PlayerOnePosition.X = 19;
	GameInfo.PlayerOnePosition.Y = 12;
	GameInfo.PlayerTwoPosition.X = 61;
	GameInfo.PlayerTwoPosition.Y = 12;
	GameInfo.PlayerOneBullet.X = 0;
	GameInfo.PlayerOneBullet.Y = 0;
	GameInfo.PlayerTwoBullet.X = 79;
	GameInfo.PlayerTwoBullet.Y = 0;
	GameInfo.PlayerOneBullet2.X = 1;
	GameInfo.PlayerOneBullet2.Y = 0;
	GameInfo.PlayerTwoBullet2.X = 78;
	GameInfo.PlayerTwoBullet2.Y = 0;
	GameInfo.ZeroZero.X = 0;
	GameInfo.ZeroZero.Y = 0;

	int i;
	GameInfo.ZeroZero.Y = 24;
	for(i = 0; i < 79; i++){
		SetConsoleCursorPosition(hOutput, GameInfo.ZeroZero);
		cout << ".";
		GameInfo.ZeroZero.X++;
	}

	Draw(GameInfo);

	while(1){
		if(Movement(GameInfo)==10)return 1;
		if(Movement(GameInfo)==20)return 2;
	}

 }



int Movement(GAMEINFO &GameInfo)
{
	INPUT_RECORD InputRecord;
	DWORD Events = 0;

	ReadConsoleInput(hInput, &InputRecord, 1, &Events);

	if(InputRecord.EventType == KEY_EVENT){

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_Q && InputRecord.Event.KeyEvent.bKeyDown == 1){
			Erase(GameInfo);
			GameInfo.PlayerOnePosition.Y--;
			if(GameInfo.PlayerOnePosition.Y < 0)
				GameInfo.PlayerOnePosition.Y++;
			Draw(GameInfo);
		}

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_A && InputRecord.Event.KeyEvent.bKeyDown == 1){
			Erase(GameInfo);
			GameInfo.PlayerOnePosition.Y++;
			if(GameInfo.PlayerOnePosition.Y > 24)
				GameInfo.PlayerOnePosition.Y--;
			Draw(GameInfo);
		}

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_S && InputRecord.Event.KeyEvent.bKeyDown == 1){
			return LaunchBullet(GameInfo, 1);

		}

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_O && InputRecord.Event.KeyEvent.bKeyDown == 1){
			Erase(GameInfo);
			GameInfo.PlayerTwoPosition.Y--;
			if(GameInfo.PlayerTwoPosition.Y < 0)
				GameInfo.PlayerTwoPosition.Y++;
			Draw(GameInfo);
		}

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_L && InputRecord.Event.KeyEvent.bKeyDown == 1){
			Erase(GameInfo);
			GameInfo.PlayerTwoPosition.Y++;
			if(GameInfo.PlayerTwoPosition.Y > 24)
				GameInfo.PlayerTwoPosition.Y--;
			Draw(GameInfo);
		}

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_K && InputRecord.Event.KeyEvent.bKeyDown == 1){
			return LaunchBullet(GameInfo, 2);
		}

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
			{//exit(0);
			goto exitt;}

	}
	exitt:
	FlushConsoleInputBuffer(hInput);
}

void Draw(GAMEINFO GameInfo)
{
	SetConsoleCursorPosition(hOutput, GameInfo.PlayerOnePosition);
	cout << "|";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerTwoPosition);
	cout << "|";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerOneBullet);
	cout << ".";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerTwoBullet);
	cout << ".";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerOneBullet2);
	cout << ".";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerTwoBullet2);
	cout << ".";

	GameInfo.ZeroZero.X = 0;
	GameInfo.ZeroZero.Y = 0;

	int i;
	for(i = 0; i < 79; i++){
		SetConsoleCursorPosition(hOutput, GameInfo.ZeroZero);
		cout << ".";
		GameInfo.ZeroZero.X++;
	}

}

void Erase(GAMEINFO GameInfo)
{
	SetConsoleCursorPosition(hOutput, GameInfo.PlayerOnePosition);
	cout << " ";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerTwoPosition);
	cout << " ";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerOneBullet);
	cout << " ";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerTwoBullet);
	cout << " ";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerOneBullet2);
	cout << " ";

	SetConsoleCursorPosition(hOutput, GameInfo.PlayerTwoBullet2);
	cout << " ";
}

int LaunchBullet(GAMEINFO &GameInfo, int PlayerNumber)
{
	int i;
	if(PlayerNumber == 1){
		GameInfo.PlayerOneBullet.Y = GameInfo.PlayerOnePosition.Y;
		GameInfo.PlayerOneBullet.X = GameInfo.PlayerOnePosition.X + 1;
		Draw(GameInfo);
		Erase(GameInfo);
		for(i = 0; i < 77; i++){
			GameInfo.PlayerOneBullet.X += 1;
			Draw(GameInfo);

			int move;
			move =	Wait();
			switch(move){
			case 1:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y--;
				if(GameInfo.PlayerOnePosition.Y < 0)
					GameInfo.PlayerOnePosition.Y++;
				break;
			case 2:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y++;
				if(GameInfo.PlayerOnePosition.Y > 24)
					GameInfo.PlayerOnePosition.Y--;
				break;
			case 3:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y--;
				if(GameInfo.PlayerTwoPosition.Y < 0)
					GameInfo.PlayerTwoPosition.Y++;
				break;
			case 4:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y++;
				if(GameInfo.PlayerTwoPosition.Y > 24)
					GameInfo.PlayerTwoPosition.Y--;
				break;
			case 5:
				LaunchBullet2(GameInfo, 1);
				return 0;
				//goto exitt;
				break;
			case 6:
				LaunchBullet2(GameInfo, 2);
				return 0;
				//goto exitt;
				break;
			}

			Draw(GameInfo);
			Erase(GameInfo);
			if(GameInfo.PlayerOneBullet.X == GameInfo.PlayerTwoPosition.X)
				if(GameInfo.PlayerOneBullet.Y == GameInfo.PlayerTwoPosition.Y){
					system("cls");
					cout << "\aPlayer 1 Wins" << endl;
					system("pause");
					return 10;
					//exit(0);
					//goto exitt;
				}
		}
		GameInfo.PlayerOneBullet.Y = 0;
		GameInfo.PlayerOneBullet.X = 0;
		Draw(GameInfo);
	}
	if(PlayerNumber == 2){
		GameInfo.PlayerTwoBullet.Y = GameInfo.PlayerTwoPosition.Y;
		GameInfo.PlayerTwoBullet.X = GameInfo.PlayerTwoPosition.X - 1;
		Draw(GameInfo);
		Erase(GameInfo);
		for(i = 0; i < 77; i++){
			GameInfo.PlayerTwoBullet.X -= 1;
			Draw(GameInfo);

			int move;
			move =	Wait();
			switch(move){
			case 1:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y--;
				if(GameInfo.PlayerOnePosition.Y < 0)
					GameInfo.PlayerOnePosition.Y++;
				break;
			case 2:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y++;
				if(GameInfo.PlayerOnePosition.Y > 24)
					GameInfo.PlayerOnePosition.Y--;
				break;
			case 3:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y--;
				if(GameInfo.PlayerTwoPosition.Y < 0)
					GameInfo.PlayerTwoPosition.Y++;
				break;
			case 4:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y++;
				if(GameInfo.PlayerTwoPosition.Y > 24)
					GameInfo.PlayerTwoPosition.Y--;
				break;
			case 5:
				LaunchBullet2(GameInfo, 1);
				return 0;
				//goto exitt;
				break;
			case 6:
				LaunchBullet2(GameInfo, 2);
				return 0;
				//goto exitt;
				break;
			}

			Draw(GameInfo);
			Erase(GameInfo);
			if(GameInfo.PlayerTwoBullet.X == GameInfo.PlayerOnePosition.X)
				if(GameInfo.PlayerTwoBullet.Y == GameInfo.PlayerOnePosition.Y){
					system("cls");
					cout << "\aPlayer 2 Wins" << endl;
					system("pause");
					//exit(0);
					//goto exitt;
					return 20;
			}
		}
		GameInfo.PlayerTwoBullet.Y = 0;
		GameInfo.PlayerTwoBullet.X = 79;
		Draw(GameInfo);
	}
	//exitt:
	//return 10;

}

int Wait()
{
	INPUT_RECORD InputRecord;
	DWORD Events = 0;

	if(WAIT_TIMEOUT == WaitForSingleObject(hInput,1))
				return 0;
	ReadConsoleInput(hInput, &InputRecord, 1, &Events);

	if(InputRecord.EventType == KEY_EVENT){
		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_Q && InputRecord.Event.KeyEvent.bKeyDown == 1)
			return 1;

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_A && InputRecord.Event.KeyEvent.bKeyDown == 1)
			return 2;

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_O && InputRecord.Event.KeyEvent.bKeyDown == 1)
			return 3;

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_L && InputRecord.Event.KeyEvent.bKeyDown == 1)
			return 4;

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_S && InputRecord.Event.KeyEvent.bKeyDown == 1)
			return 5;

		if(InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_K && InputRecord.Event.KeyEvent.bKeyDown == 1)
			return 6;
	}
	FlushConsoleInputBuffer(hInput);
	return 0;
}

int LaunchBullet2(GAMEINFO &GameInfo, int PlayerNumber)
{
	if(PlayerNumber == 1){
		GameInfo.PlayerOneBullet2.X = GameInfo.PlayerOnePosition.X + 1;
		GameInfo.PlayerOneBullet2.Y = GameInfo.PlayerOnePosition.Y;

		Draw(GameInfo);
		Erase(GameInfo);
		int i;
		for(i = 0; i < 77; i++){
			GameInfo.PlayerOneBullet.X += 1;
			GameInfo.PlayerOneBullet2.X += 1;
			GameInfo.PlayerTwoBullet.X -= 1;
			GameInfo.PlayerTwoBullet2.X -= 1;
			Draw(GameInfo);

			int move;
			move =	Wait();
			switch(move){
			case 1:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y--;
				if(GameInfo.PlayerOnePosition.Y < 0)
					GameInfo.PlayerOnePosition.Y++;
				break;
			case 2:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y++;
				if(GameInfo.PlayerOnePosition.Y > 24)
					GameInfo.PlayerOnePosition.Y--;
				break;
			case 3:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y--;
				if(GameInfo.PlayerTwoPosition.Y < 0)
					GameInfo.PlayerTwoPosition.Y++;
				break;
			case 4:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y++;
				if(GameInfo.PlayerTwoPosition.Y > 24)
					GameInfo.PlayerTwoPosition.Y--;
				break;
			}

			Draw(GameInfo);
			Erase(GameInfo);
			if(GameInfo.PlayerOneBullet.X == GameInfo.PlayerTwoPosition.X)
				if(GameInfo.PlayerOneBullet.Y == GameInfo.PlayerTwoPosition.Y){
					system("cls");
					cout << "\aPlayer 1 Wins" << endl;
					system("pause");
					return 10;
					//exit(0);
					//goto exitt;
				}
			if(GameInfo.PlayerOneBullet2.X == GameInfo.PlayerTwoPosition.X)
				if(GameInfo.PlayerOneBullet2.Y == GameInfo.PlayerTwoPosition.Y){
					system("cls");
					cout << "\aPlayer 1 Wins" << endl;
					system("pause");
					return 10;
					//exit(0);
					//goto exitt;
				}
		}
		GameInfo.PlayerOneBullet.Y = 0;
		GameInfo.PlayerOneBullet.X = 0;
		GameInfo.PlayerOneBullet2.Y = 0;
		GameInfo.PlayerOneBullet2.X = 1;
		Draw(GameInfo);
	}

	if(PlayerNumber == 2){
		GameInfo.PlayerTwoBullet2.Y = GameInfo.PlayerTwoPosition.Y;
		GameInfo.PlayerTwoBullet2.X = GameInfo.PlayerTwoPosition.X - 1;
		Draw(GameInfo);
		Erase(GameInfo);
		int i;
		for(i = 0; i < 77; i++){
			GameInfo.PlayerTwoBullet.X -= 1;
			GameInfo.PlayerTwoBullet2.X -= 1;
			GameInfo.PlayerOneBullet.X += 1;
			GameInfo.PlayerOneBullet2.X += 1;
			Draw(GameInfo);

			int move;
			move =	Wait();
			switch(move){
			case 1:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y--;
				if(GameInfo.PlayerOnePosition.Y < 0)
					GameInfo.PlayerOnePosition.Y++;
				break;
			case 2:
				Erase(GameInfo);
				GameInfo.PlayerOnePosition.Y++;
				if(GameInfo.PlayerOnePosition.Y > 24)
					GameInfo.PlayerOnePosition.Y--;
				break;
			case 3:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y--;
				if(GameInfo.PlayerTwoPosition.Y < 0)
					GameInfo.PlayerTwoPosition.Y++;
				break;
			case 4:
				Erase(GameInfo);
				GameInfo.PlayerTwoPosition.Y++;
				if(GameInfo.PlayerTwoPosition.Y > 24)
					GameInfo.PlayerTwoPosition.Y--;
				break;
			}

			Draw(GameInfo);
			Erase(GameInfo);
			if(GameInfo.PlayerTwoBullet.X == GameInfo.PlayerOnePosition.X)
				if(GameInfo.PlayerTwoBullet.Y == GameInfo.PlayerOnePosition.Y){
					system("cls");
					cout << "\aPlayer 2 Wins" << endl;
					system("pause");
					return 20;
					//exit(0);
					//goto exitt;
			}
			if(GameInfo.PlayerTwoBullet2.X == GameInfo.PlayerOnePosition.X)
				if(GameInfo.PlayerTwoBullet2.Y == GameInfo.PlayerOnePosition.Y){
					system("cls");
					cout << "\aPlayer 2 Wins" << endl;
					system("pause");
					return 20;
					//exit(0);
					//goto exitt;
			}
		}
		GameInfo.PlayerOneBullet.Y = 0;
		GameInfo.PlayerOneBullet.X = 0;
		GameInfo.PlayerOneBullet2.Y = 0;
		GameInfo.PlayerOneBullet2.X = 1;
		Draw(GameInfo);
	}
	//exitt:
	    //return 10;
}







int game3()
{
char choice1,choice2;
int p1,p2,i,j,position,move=1,x=0,y=0,count=0,c=1,d=0,a[8],k=0,flag=1;
for(i=0;i<9;i++)
a[i]=3;
printf("Welcome to TIC-TAC-TOE \n");
printf("for reference to players\n");
printf(" ______________\n");
printf("|  0 |  1 |  2 |\n");
printf("|____|____|____|\n");
printf("|  3 |  4 |  5 |\n");
printf("|____|____|____|\n");
printf("|  6 |  7 |  8 |\n");
printf("|____|____|____|\n");
while(flag==1)
{
printf("Enter X or O for Player1\n");
scanf("%c",&choice1);
if(choice1=='X'||choice1=='x'||choice1=='O'||choice1=='o')
{
    flag=0;
}
else
{
    flag=1;
    printf("Invalid choice\n");
}
}

if(choice1=='X'||choice1=='x')
{
choice2='O';
}
else
{
choice2='X';
}

printf("Player2 choice is %c\n",choice2);
if(choice1=='X'||choice1=='x')
{
p1=1;
p2=0;
}
else
{
p1=0;
p2=1;
}
while(move<3)
{
    Sleep(1300);
    system("cls");
    count=0;
    if(move==1)
    {
        printf("Player1 Enter the position\n");
         scanf("%d",&position);

         if(a[position]==3)
           {
               a[position]=p1;
               k=0;
               for(i=0;i<3;i++)
               {
                   for(j=0;j<3;j++)
                   {
                       if(a[k]==3)
                       printf("\t-");
                       if(a[k]==1)
                       printf("\tX");
                        if(a[k]==0)
                       printf("\tO");
                       k++;
                   }
                   printf("\n");
               }

               if((a[0]==p1&&a[1]==p1&&a[2]==p1)
||(a[3]==p1&&a[4]==p1&&a[5]==p1)||(a[6]==p1&&a[7]==p1&&a[8]==p1)||
(a[0]==p1&&a[3]==p1&&a[6]==p1)||(a[1]==p1&&a[4]==p1&&a[7]==p1)||
(a[2]==p1&&a[5]==p1&&a[8]==p1)||(a[0]==p1&&a[4]==p1&&a[8]==p1)||
(a[2]==p1&&a[4]==p1&&a[6]==p1))
                  {
                     printf("Player1 wins\n");

                      x=1;
                     printf("Thank you for playing this game\n");
                     Sleep(1300);
                      move=3;
                    return 1;
                    break;
                   }
                else
                {
                   move=2;
                }
           }
           else
           {
               printf("This place is not empty.Please give another position\n");

                   move=1;
                 }

      }
      for(i=0;i<9;i++)
      {

        if(a[i]==3)
        count++;
      }
      if(count==0)
      {
          move=3;
          break;
      }
      if(move==2)
      {
              printf("Player2 Enter position\n");
         scanf("%d",&position);

         if(a[position]==3)
           {
              a[position]=p2;
              k=0;
               for(i=0;i<3;i++)
               {
                   for(j=0;j<3;j++)
                   {
                       if(a[k]==3)
                       printf("\t-");
                       else if(a[k]==1)
                       printf("\tX");
                       else
                       printf("\tO");
                       k++;
                   }
                   printf("\n");
               }

              if((a[0]==p2&&a[1]==p2&&a[2]==p2)||
(a[3]==p2&&a[4]==p2&&a[5]==p2)||(a[6]==p2&&a[7]==p2&&a[8]==p2)||
(a[0]==p2&&a[3]==p2&&a[6]==p2)||(a[1]==p2&&a[4]==p2&&a[7]==p2)||(a[2]==p2&&a[5]==p2&&a[8]==p2)||
(a[0]==p2&&a[4]==p2&&a[8]==p2)||
(a[2]==p2&&a[4]==p2&&a[6]==p2))
                  {
                     printf("Player2 wins\n");

                      y=1;
                     printf("Thank you for playing this game\n");
                     Sleep(1300);
                      move=3;
                      return 2;
                    break;
                   }
                else
                {
                   move=1;
                }
           }
           else
           {
           printf("This place is not empty.Please give another position\n");

                   move=2;
                 }
      }


}
if(x!=1&&y!=1)
{
printf("Draw Match\n");
printf("Thank you for playing this game\n");
}

}

