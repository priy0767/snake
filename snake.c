#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int height=20,width=20,x,y,fruitx,fruity,flag,gameEnd,score;
int tailx[100],taily[100];
int piece =0;
void makeLogic()
{
     int i;
     int prevx,prevy,prev2x,prev2y;
     prevx=tailx[0];
     prevy=taily[0];
     tailx[0]=x;
     taily[0]=y;
     for(i=1;i<=piece;i++)
     {
       prev2x=tailx[i];
       prev2y=taily[i];
       tailx[i]=prevx;
       taily[i]=prevy;
       prevx=prev2x;
       prevy=prev2y;
     }
    switch(flag)
    {
        case 1:
        {
            x--;
            break;
        }
         case 2:
        {
            x++;
            break;
        }
         case 3:
        {
            y++;
            break;
        }
         case 4:
        {
            y--;
            break;
        }
    }
    if(x==0||x==height||y==0||y==height)
    {
      gameEnd=1;
    }
    if(x==fruitx && y==fruity)
    {
           label3:
    fruitx=rand()%20;
    if(fruitx==0)
    goto label3;
    
    label4:
    fruity=rand()%20;
    if(fruity==0)
    goto label4;
    score++;
    piece++;       
    }
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'w':
            {
                flag=1;
                break;
            }
            case 's':
            {
                flag=2;
                break;
            }
            case 'a':
            {
                flag=3;
                break;
            }
            case 'd':
            {
                flag=4;
                break;
            }
        }
    }
}
void setup()
{
    x=height/2;
    y=width/2;
    
    label1:
    fruitx=rand()%20;
    if(fruitx==0)
    goto label1;
    
    label2:
    fruity=rand()%20;
    if(fruity==0)
    goto label2;
    gameEnd=0;
    score=0;
    piece++;
}
void draw()
{
    // getch();
     //clrscr();
   //  system("cls"); //alternative of clrscr()
    int i,j,k,ch;
     system("cls");
     system("clear");
     for(i=0;i<=height;i++)
     {
         for(j=0;j<=width;j++)
         {
             if(i==0||i==height||j==0||j==width) 
              
             {
                 printf("*");
             }
             else
             {
                 if(i==x&&j==y)
                 {
                    printf("0"); 
                 }
                 else if(i==fruitx && j==fruity)
                 {
                     printf("@");
                 }
                 else
                 {
                                 ch=0;
                 for(k=0;k<piece;k++)
                    {
                         if(i==tailx[k]&& j==taily[k])
                         {
                             printf("o");
                             ch=1;
                         }
                    }
                    if(ch==0)
             printf(" ");
                 }
             }
        
         }
         printf("\n");
         
     }
  printf("Your score is %d",score);  
}
int main()
{
      setup(); //for finding value of initial position of fruit and snake and also later value of random position of fruit
     // input(); //input kbhit to getting w,s, a,d fot direction input
   // draw(); ///for makng drawing of snake amd fruit
   // makeLogic(); //for changing direction of snake
  
  while(gameEnd!=1)
  {
      input();
      draw();
      makeLogic();
  }
}
