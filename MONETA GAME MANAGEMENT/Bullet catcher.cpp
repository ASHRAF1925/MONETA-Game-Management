#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include<math.h>
#include<graphics.h>
#include<time.h>
using namespace std;
#define ERROR puts("Error");


int maxx=639,maxy=479;
char map[100][100];
int H=20,W=41;
int page=0;


struct coord
{
   int x;
   int y;
};
struct PacMan {
   struct coord position;
   int vx;
   int vy;
   int lives;
   int score;
};
struct Ghost {
    struct coord position;
    int vx;
    int vy;
    int food;
    int pulse;
    int dir;
};
struct PacMan player={
                        {
                            .x=1,
                            .y=1,
                        },
                        .vx=0,
                        .vy=0,
                        .lives=3,
                        .score=0
                     };
struct Ghost ghost1={
                        {
                            .x=14,
                            .y=7,
                        },
                        .vx=0,
                        .vy=0,
                        .food=1,
                        .pulse=2,
                        .dir=0
                    };
struct Ghost ghost2={
                        {
                            .x=1,
                            .y=9,
                        },
                        .vx=0,
                        .vy=0,
                        .food=1,
                        .pulse=2,
                        .dir=0
                    };
struct score
{
    int post;
    char initials[3];
    int scr;
}fp[10];
//34 8
//639 479


void mapread();
void mapping();
void foodinit();
void init();
void user_input();
void move();
void show();
void intro();
void menu();
void ghost_movement();
void ghost_direction();
void game_over();
void scoreadd();
int scorereader();
void highscoredisplay();


int main()
{
    int gd=DETECT,gm;
    char test[100];
    initgraph(&gd,&gm,NULL);
    intro();
    menu();
    init();
    while(1)
    {


        setactivepage(page);
        setvisualpage(1-page);
        setfillstyle(1, 0);
        bar(0,0,640, 480);
        mapping();
        user_input();
        ghost_direction();
        ghost_movement();
        move();
        delay(150);
        page=1-page;
    }
    closegraph();
    return 0;
}
void mapread()
{
    FILE *fp;
    int i=0,j=0;
    char p;
    if((fp=fopen("map1.txt","r"))==NULL)
    {
        ERROR;
        exit(1);
    }
    while(!feof(fp))
    {
        if((p=fgetc(fp))!='\n')
        {
            map[i][j]=p;
            j++;
        }
        else
        {
            map[i][j]=p;
            i++;
            j=0;
        }
    }
    map[i][j]='\0';
    fclose(fp);
    return;
}
void mapping()
{
    int x=0,y=0,i,j;
    char text[100];
    for(i=1;i<=H;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(map[i-1][j-1]=='#')
            {
                setfillstyle(SOLID_FILL,RED);
                bar(x,y,x+20,y+15);
                x+=20;
            }
            else if(map[i-1][j-1]=='.')
            {
                circle(x+5,y+5,1);
                x+=20;
            }
            else if(map[i-1][j-1]==' ')
            {
                x+=20;
            }
            else if(map[i-1][j-1]=='0')
            {
                setcolor(YELLOW);
                circle(x+5,y+8,4);
                setcolor(WHITE);
                x+=20;
            }
            else if(map[i-1][j-1]=='G')
            {
                setcolor(WHITE);
                circle(x+5,y+8,4);
                setcolor(WHITE);
                x+=20;
                ghost1.position.x=j-1;
                ghost1.position.y=i-1;
            }
            else if(map[i-1][j-1]=='P')
            {
                setcolor(WHITE);
                circle(x+5,y+8,4);
                setcolor(WHITE);
                x+=20;
                ghost2.position.x=j-1;
                ghost2.position.y=i-1;
            }
        }
        x=0;y=(15*i);
    }
    settextstyle(2,0,27);
    sprintf(text,"Score: %d    Lives: %d",player.score,player.lives);
    outtextxy(180,350,text);


}
void foodinit()
{
    int i,j;
    for(i=0;i<H;i++)
    {
        for(j=0;j<W;j++)
        {
            if(map[i][j]==' ')
            {
                map[i][j]='.';
            }
        }

    }
}
void init()
{
    mapread();
    foodinit();
    mapping();
}
void user_input()
{
    char choice,c;
    while(1)
    {
        if(GetAsyncKeyState(VK_UP))
        {
            player.vy=-1;
            player.vx=0;
            return;
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            player.vy=1;
            player.vx=0;
            return;
        }
        else if(GetAsyncKeyState(VK_LEFT))
        {
            player.vx=-1;
            player.vy=0;
            return;
        }
        else if(GetAsyncKeyState(VK_RIGHT))
        {
            player.vx=1;
            player.vy=0;
            return;
        }
        else if(GetAsyncKeyState(VK_ESCAPE))
        {
            game_over();
            return;
        }
        else
        {
            return;
        }
    }
}
void move()
{
    int x,y;
    map[player.position.y][player.position.x]=' ';
    x=player.position.x+player.vx;
    y=player.position.y+player.vy;
    if(map[y][x]=='#')
    {
        player.vx=0;
        player.vy=0;
    }
    player.position.x+=player.vx;
    player.position.y+=player.vy;
    if(map[player.position.y][player.position.x]=='.')
    {
        player.score++;
    }
    if(map[player.position.y][player.position.x]=='G'||map[player.position.y][player.position.x]=='P')
    {
        player.lives--;
        player.position.x=1;
        player.position.y=1;
        if(player.lives==0)
        {
            game_over();
        }
    }
    map[player.position.y][player.position.x]='0';
}
void show()
{
    int i,j;
    for(i=0;i<H;i++)
    {
        for(j=0;j<W;j++)
        {
            printf("%c",map[i][j]);
        }
    }
    system("cls");
}
void intro()
{
    /*int gd=DETECT, gm;

initgraph(&gd,&gm,NULL);


    initgraph(&gd,&gm,NULL);*/
    int i=0,key=0;
while(i<450)
{
    if(kbhit())
    {
        key=getch();
        if(key=='s')
        {
            return;
        }
    }
setcolor(BLUE);
       setfillstyle(SOLID_FILL,BLUE);
    circle(100+i,200,70);


//setcolor(BLACK);
//setfillstyle(SOLID_FILL,BLACK);
line(100+i,200,162+i,166);

    line(100+i,200,162+i,237);
    floodfill(98+i,200,BLUE);
    setcolor(BLACK);
    circle(100+i,200,70);
    line(100+i,200,162+i,166);

    line(100+i,200,162+i,237);
    setfillstyle(SOLID_FILL ,BLACK);
floodfill(150+i,200,BLACK);

setcolor(BLACK);
circle(100+i,200,70);
setfillstyle(SOLID_FILL,BLACK);
floodfill(0+i,50,BLACK);
delay(150);

cleardevice();

setcolor(BLUE);
circle(100+i,200,70);
setfillstyle(SOLID_FILL,BLUE);
floodfill(100+i,200,BLUE);
setcolor(BLACK);
circle(100+i,200,70);
setfillstyle(SOLID_FILL,BLACK);
floodfill(0+i,50,BLACK);

i=i+30;
delay(150);
cleardevice();
}
delay(1000);
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
settextstyle(3,HORIZ_DIR,20);
outtextxy(40,170,"PACMAN");
delay(3000);
cleardevice();
//settextstyle(9,HORIZ_DIR,2.5);
//outtextxy(10,180,"TO KNOW THE RULES PRESS 5");
//outtextxy(10,230,"TO GO STRAIGHT TO THE GAME PRESS 6");
/*char choice;
choice=getchar();
if(choice=='6')
{
    return;
}
getch();*/
//closegraph();
return;
}
void menu()
{
  start:
  setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
settextstyle(3,HORIZ_DIR,3);
rectangle(150,150,350,180);
outtextxy(210,150+2,"High score");
rectangle(150,230,350,260);
outtextxy(210,230+2,"Instruction");
rectangle(150,310,350,340);
outtextxy(230,310+2,"Exit");
rectangle(150,70,350,100);
outtextxy(210,70+2,"New Game");



char c;


int k=0;
int s=0;
int j=0,l=0;
int y1=140,y2=190;
   setcolor(RED);
   setfillstyle(SOLID_FILL,RED);
rectangle(140,140,360,190);

while(1)
{

getch();

if(GetAsyncKeyState(VK_UP))
{

if(y1!=60)

{setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(140,y1-80,360,y2-80);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
rectangle(140,y1,360,y2);

s=0;
k++;

y1=y1-80;
y2=y2-80;

/*if(y1==140)
{
    l=0;
}
else if(y1==60)
{
    l=1;
}
else if(y1==220)
{
    l=2;
}
else if(y1==300)
{
    l=3;
}*/
getch();

}



}


else if(GetAsyncKeyState(VK_DOWN))
{

 if(y1!=300)
 {setcolor(RED);
setfillstyle(SOLID_FILL,RED);
rectangle(140,y1+80,360,y2+80);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
rectangle(140,y1,360,y2);
y1=y1+80;
y2=y2+80;
/*if(y1==140)
{
    l=0;
}
else if(y1==60)
{
    l=1;
}
else if(y1==220)
{
    l=2;
}
else if(y1==300)
{
    l=3;
}*/
k=0;
s++;
getch();
}

}
else if(GetAsyncKeyState(VK_RETURN))
{
    if(y1==140) //high score//
    {
     highscoredisplay();
     exit(1);
     //return;
    }

    else if(y1==220)   //220-instruction//
    {

        cleardevice();
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        outtextxy(10,0,"Rules of the game");
        outtextxy(10,50,"Eat the fruits");
        outtextxy(10,100,"Avoid The Ghost");
        outtextxy(10,150,"Set the high Score");
        getch();
        cleardevice();

goto start;

    }
    else if(y1==300) //exit//
    {
        exit(1);
    }
    else if(y1==60) //new game//
    {
        return;

    }

getch();
}
if(l++)
{
    j++;
}



}}
void ghost_direction()
{
    srand(time(0));
    if(ghost1.pulse>=2)
    {
        ghost1.dir=rand()%4;
        if(ghost1.dir==0)
        {
            ghost1.vy=-1;
            ghost1.vx=0;
            //ERROR
        }
        else if(ghost1.dir==1)
        {
            ghost1.vy=1;
            ghost1.vx=0;
            //ERROR
        }
        else if(ghost1.dir==2)
        {
            ghost1.vy=0;
            ghost1.vx=1;
            //ERROR
        }
        else if(ghost1.dir==3)
        {
            ghost1.vy=0;
            ghost1.vx=-1;
            //ERROR
        }
        ghost1.pulse=0;
    }

    //Ghost2 Direction

    if(ghost2.pulse>=2)
    {
        ghost2.dir=rand()%4;
        if(ghost2.dir==0)
        {
            ghost2.vy=-1;
            ghost2.vx=0;
            //ERROR
            return;
        }
        else if(ghost2.dir==1)
        {
            ghost2.vy=1;
            ghost2.vx=0;
            //ERROR
            return;
        }
        else if(ghost2.dir==2)
        {
            ghost2.vy=0;
            ghost2.vx=1;
            //ERROR
            return;
        }
        else if(ghost2.dir==3)
        {
            ghost2.vy=0;
            ghost2.vx=-1;
            //ERROR
            return;
        }
        ghost2.pulse=0;
    }
}
void ghost_movement()
{
    int x1,y1,x2,y2;
    if(ghost1.food)
    {
        map[ghost1.position.y][ghost1.position.x]='.';
    }
    else
    {
        map[ghost1.position.y][ghost1.position.x]=' ';
    }
    x1=ghost1.position.x+ghost1.vx;
    y1=ghost1.position.y+ghost1.vy;
    if(map[y1][x1]=='#')
    {
        ghost1.vx=0;
        ghost1.vy=0;
    }
    ghost1.position.x+=ghost1.vx;
    ghost1.position.y+=ghost1.vy;
    if(map[ghost1.position.y][ghost1.position.x]=='.')
    {
        ghost1.food=1;
    }
    else
    {
        ghost1.food=0;
    }
    map[ghost1.position.y][ghost1.position.x]='G';
    ghost1.pulse++;

    //ghost2 movement

    if(ghost2.food)
    {
        map[ghost2.position.y][ghost2.position.x]='.';
    }
    else
    {
        map[ghost2.position.y][ghost2.position.x]=' ';
    }
    x2=ghost2.position.x+ghost2.vx;
    y2=ghost2.position.y+ghost2.vy;
    if(map[y2][x2]=='#')
    {
        ghost2.vx=0;
        ghost2.vy=0;
    }
    ghost2.position.x+=ghost2.vx;
    ghost2.position.y+=ghost2.vy;
    if(map[ghost2.position.y][ghost2.position.x]=='.')
    {
        ghost2.food=1;
    }
    else
    {
        ghost2.food=0;
    }
    map[ghost2.position.y][ghost2.position.x]='P';
    ghost2.pulse++;
}
void game_over()
{
    //cleardevice();
    setactivepage(1-page);
    setfillstyle(1, 0);
    bar(0,0,640, 480);
    outtextxy(200,200,"GAME OVER");
    delay(2000);
    //cleardevice();
    closegraph();
    scoreadd();
    highscoredisplay();
    //exit(1);
}
int scorereader()
{
    FILE *scoreboard=fopen("score1.txt","r");
    if(scoreboard==NULL)
    {
        printf("couldn't open the scoreboard");
        exit(1);
    }
    struct score ;
    int i=0;
    char str[10];
    while(!feof(scoreboard))
    {
        fgets(str,10,scoreboard);
        //puts(str);
        sscanf(str,"%d %s %d",&fp[i].post,fp[i].initials,&fp[i].scr);
        i++;
    }
    //printf("%d\n",fp[i-1].post);
    fclose(scoreboard);
    //return 0;
    return fp[i-1].post;
}
void scoreadd()
{
    FILE *scoreboard=fopen("score1.txt","a");
    char in[3];
    printf("Enter your initials: ");
    scanf("%s",in);
    struct score fp1;
    fp1.post = scorereader()+1,fp1.scr=player.score;
    strcpy(fp1.initials,in);
    //scoreboard;

    if(scoreboard==NULL)
    {
        printf("couldn't open the scoreboard");
        exit(1);
    }
    //printf("file is open now\n");
    //int x=10;
    //printf("%d %s %d\n",fp.post,fp.initials,fp.scr);
    fprintf(scoreboard,"%d %s %d\n",fp1.post,fp1.initials,fp1.scr);
    //printf("done printing\n");
    fclose(scoreboard);

}

void highscoredisplay()
{
    struct score fp1;
    int x=scorereader();
    for(int i=0;i<x;i++)
    {
        for(int j=i+1;j<x;j++)
        {
            if(fp[i].scr<fp[j].scr)
            {
                fp1.scr=fp[i].scr;
                strcpy(fp1.initials,fp[i].initials);
                fp[i].scr=fp[j].scr;
                strcpy(fp[i].initials,fp[j].initials);
                fp[j].scr=fp1.scr;
                strcpy(fp[j].initials,fp1.initials);
            }
        }

    }
    FILE *scoreboard=fopen("score1.txt","w");
        for(int i=0;i<x;i++)
        {
            fprintf(scoreboard,"%d %s %d\n",fp[i].post,fp[i].initials,fp[i].scr);
        }
    fclose(scoreboard);
    for(int i=0;i<x;i++)
        {
            printf("%d %s %d\n",fp[i].post,fp[i].initials,fp[i].scr);
        }
    return;
}

