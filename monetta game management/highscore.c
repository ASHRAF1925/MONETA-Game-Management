#include<stdio.h>
struct high{
int highscore;
char userid[100];
};
struct login{
char fname[100];
char lname[100];
char username[20];
char password[20];
//int time_moneta;
int count_moneta;
};
int main()
{
    struct high k;
    struct login l;
    int highscore,score;
    FILE *log,*log1;
    log = fopen("highscore.txt","w");
    scanf("%d",&k.highscore);
    fwrite(&k,sizeof(k),1,log);
    fclose(log);
    score=40;
    log=fopen("highscore.txt","r");
    fread(&k,sizeof(k),1,log);
    fclose(log);

    if(score>k.highscore)
    {
        log1=fopen("player.txt","r");
        fread(&l,sizeof(l),1,log1);
        strcpy(l.username,k.userid);
        fclose(log1);

        k.highscore=score;
        FILE *log;
    log = fopen("highscore.txt","w");
    fwrite(&k,sizeof(k),1,log);
    fclose(log);
}
log=fopen("highscore.txt","r");
    fread(&k,sizeof(k),1,log);
    printf("%d\n",k.highscore);
    printf("%s",k.userid);
    fclose(log);
}
