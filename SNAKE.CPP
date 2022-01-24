#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void furit(void);
void boundory(void);
int i,a=12,b=12,x=25,y=12,c=0,k=1,sx[100],sy[100],s=2,t=100,z=0;
void main()
{
clrscr();
boundory();
textbackground(WHITE);
textcolor(RED);
gotoxy(35,1);
cprintf("Snake Game");
char ch ;
gotoxy(x,y);
cprintf("%c",s);
gotoxy(70,3);
cprintf("Score:%d",c);
gotoxy(a,b);
printf("O");
while(1)
{
 ch=getch();
 while(!kbhit())
 {
switch(ch)
{
case 's':
x++;
break;
case 'a':
x--;
break;
case 'w':
y--;
break;
case 'z':
y++;
break;
default:
exit(0);
}


// collision

clrscr();
gotoxy(35,1);
printf("Snake Game");
boundory();
textcolor(RED);
if (x==a&&y==b)
{
furit();
c++;
k++;
t=t-2;
}
gotoxy(a,b);
cprintf("O");

gotoxy(70,3);
cprintf("Score:%d",c);

// snake lenth
//Note to give the position of snake head to snke body head will not printed

sx[0]=x;
sy[0]=y;
for(i=k;i>0;i--)
{
 sx[i]=sx[i-1];
 sy[i]=sy[i-1];
}
for(i=1;i<=k;i++)
{
gotoxy(sx[i],sy[i]);
cprintf("%c",s);

}
// collision of snake body

  for(i=3;i<=k+3;i++)
 {
      if(sx[1]==sx[i-1] && sy[1]==sy[i-1])
      {
      clrscr();
      gotoxy(33,8);
      printf("_________________");
      gotoxy(33,9);
      printf("|    game Over  |");
      gotoxy(33,10);
      printf("|  Your score:%d |",c);
      gotoxy(33,11);
      printf("------------------");
      gotoxy(33,12);
      printf("Thanks for playing....");
      sleep(5);
      exit(0);
      }
 }

 // If snak touch the boundry then game over condition

 if(sx[0]==79 ||sx[0]==2 || sy[0]==25||sy[0]==2)
 {
      clrscr();
      gotoxy(33,8);
      printf("_________________");
      gotoxy(33,9);
      printf("|    game Over  |");
      gotoxy(33,10);
      printf("|  Your score:%d |",c);
      gotoxy(33,11);
      printf("------------------");
      gotoxy(33,12);
      printf("Thanks for playing....");
      sleep(5);
      exit(0);
 }


delay(t);

}
}

getch();
}


// This is furit generate function

void furit()
{
int la=3,lb=3,ua=75,ub=24;
srand(time(NULL));
a=(rand()%(ua-la+1)+la);
b=(rand()% (ub-lb+1)+lb);
}

// This is boundory Function

void boundory()
{
int m=223,k=1,b=2;
textcolor(BLUE);
gotoxy(2,2);
while(k<102)
{
if(k>77)
{
gotoxy(1,b++);
cprintf("O");
}
if(k<78)
{
cprintf("%c",m);
}
k=k+1;
}
k=1;
b=24;
gotoxy(82,24);
while(k<102)
{
if(k>78)
{
gotoxy(80,b--);
cprintf("O");
}
if(k<78)
{
cprintf("%c",m);
}
k=k+1;
}
}

