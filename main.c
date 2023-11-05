#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void title()
{
 printf(" --------------------------------------------\n");
 printf(" | #   #   ##   #   #  #####  #    #   ##   #   # |\n");
 printf(" | #   #  #  #  ##  #  #      ##  ##  #  #  ##  # |\n");
 printf(" | #####  ####  # # #  # ###  # ## #  ####  # # # |\n");
 printf(" | #   #  #  #  #  ##  # # #  #    #  #  #  #  ## |\n");
 printf(" | #   #  #  #  #   #  ### #  #    #  #  #  #   # |\n");
 printf(" --------------------------------------------\n\n");
}
void logo()
{
 printf(" ---------------\n");
 printf(" Hangman Game!\n");
 printf(" ---------------\n\n");
 printf(" |----| \n");
 printf(" |  O\n");
 printf(" | \\|/ \n");
 printf(" |  | \n");
 printf(" | / \\ \n");
 printf(" | \n");
 printf(" ___|_________\n\n");
}
int main()
{
 system("color 6f");
 Beep(600,600);
 int i,kk;
 while(1)
 {
 system("cls");
 title();
 logo();
 printf(" (s)Start Game\n");
 printf(" (e)EXIT\n");
 printf(" Press 's' to start the game or 'e' to exit:");
 char press;
 scanf(" %c",&press);
 system("cls");
 if(press!='s')
 break;
 else if(press=='s')
 {
 printf("\n");
 printf(" Select Word Category:\n");
 int ch2;
 printf(" (1)Fruit\n");
 printf(" (2)Flower\n");
 printf(" (3)Country\n");
 printf(" (ANY KEY without(1-3) TO EXIT)\n");
 printf(" Enter Command:");
 scanf("%d",&ch2);
 char *fname[100];
 if(ch2==1)
 {
 *fname="fruit.txt";
 }
 else if(ch2==2)
 {
 *fname="flower.txt";
 }
 else if(ch2==3)
 {
 *fname="country.txt";
 }
 else
 {
 printf("\n EXITING...........!\n");
 exit(1);
 }
 int score=0;
 for(kk=1; kk<=10; kk++)
 {
 FILE *file;
 file=fopen(*fname,"r");
 char string[500][500];
 int k=0,k1=0;
 int k2=130;
 while(fgets(string[k],k2,file))
 {
 string[k][strlen(string[k])-1]='\0';
 k++;
 }
 k1=k;
 int v;
 srand(time(0));
 int x=rand()%k1;
 char string2[100];
 strcpy(string2,string[x]);
 v=strlen(string2);
 char guess[v+1];
 for(i=0; i<v; i++)
 guess[i]='_';
 guess[i]='\0';
 fclose(file);
 int c=v+v/2,xy=c,win=0;
 int flg=-1;
 while(c--)
 {
 char ch;
 system("cls");
 printf("\n You got %d Chances to guess the word\n\n",xy--);
 printf(" Round:%d Score:%d\n",kk,score);
 if(flg==1)
 printf(" Correct guessing\n");
 else if(flg==0)
 printf(" Wrong guessing\n");
 printf(" ");
 for(i=0; i<v; i++)
 printf("%c ",guess[i]);
 printf("\n\n");
 printf(" Guess a letter:");
 scanf(" %c",&ch);
 int tmp=0;
 flg=0;
 for(i=0; i<v; i++)
 {
 if(guess[i]=='_' && ch==string2[i])
 guess[i]=string2[i],flg=1,score+=5;
 if(guess[i]!='_')
 tmp++;
 }
 if(flg==0)
 score-=5;
 if(tmp==v)
 {
 Beep(500,800);
 printf(" Finally : %s\n",guess);
 printf("\n Congrats!!!\n");
 printf(" You have guess the word successfully\n");
 printf(" Press any key to go to next\n");
 win=1;
 scanf(" %c",&ch);
 break;
 }
 }
 if(win==0)
 {
 printf("\n Opps!!!\a\n");
 printf(" You have been hanged to guess the word successfully\n");
printf(" |----| \n");
 printf(" |  X\n");
 printf(" | \\|/ \n");
 printf(" |  | \n");
 printf(" | / \\ \n");
 printf(" | \n");
 printf(" ___|_________\n\n");
 printf(" Press any key to go to next\n");
 char ch;
 scanf(" %c",&ch);
 }
 }
 system("cls");
 Beep(700,500);
 printf(" Game is finished!!\n");
 printf(" Your Score:%d\n",score);
 printf(" Press any key to go to the homepage\n");
 char ch;
 scanf(" %c",&ch);
 }
 }
 return 0;
 }
