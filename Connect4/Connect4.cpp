#include<iostream.h>
#include<conio.h>

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>


int ct=0;
void drawc(char game[5][10])
{
 clrscr();
 cout<<"CONNECT  4";
 cout<<"\n   1     2     3     4      5     6     7     8      9    10";

 for(int i=0;i<5;i++)
 for(int j=0;j<10;j++)
 {
  if(game[i][j]=='x')
  {
   setcolor(9);
   setfillstyle(1,9);
  }
  else if(game[i][j]=='r')
  {
   setcolor(4);
   setfillstyle(1,4);
  }
  else if(game[i][j]=='y')
  {
   setcolor(14);
   setfillstyle(1,14);
  }
  pieslice(50+(j*60),180+(i*60),0,360,20);
 }
}
void connectfour()
{
int choice,a=0,r=0,y=0;
char game[5][10];
for(int i=0;i<5;i++)
for(int j=0;j<10;j++)
game[i][j]='x';        //to identify the non filled spaces
clrscr();
label2:
drawc(game);
cout<<"\n\n\n\n\tPlayer ";
if(ct%2==0)
cout<<"1: \n";
else
cout<<"2: \n";
label1:
cout<<"\tEnter 0 to exit or enter the place to drop the coin: ";
cin>>choice;
if(choice==0)
exit(0);
else if(choice<0||choice>10)
{
 drawc(game);
 cout<<"\n\n\n\n\tWrong choice\n";
 goto label1;
}
else
{
 for(i=4;i>=0;i--)
 if(game[i][choice-1]=='x')
 {
  a=1;
  break;
 }
 if(a)
 {
  if(ct%2==0)
  game[i][choice-1]='r';
  else
  game[i][choice-1]='y';

 }
 else
 {
  drawc(game);
  cout<<"\n\n\n\n\tThe column is occupied fully\n";
  goto label1;
 }
 for(i=0;i<10;i++)
{
 if(((game[0][i]=='r')&&(game[1][i]=='r')&&(game[2][i]=='r')&&(game[3][i]=='r'))||((game[4][i]=='r')&&(game[1][i]=='r')&&(game[2][i]=='r')&&(game[3][i]=='r')))
 {
  r=1;
  break;
 }
 else if(((game[0][i]=='y')&&(game[1][i]=='y')&&(game[2][i]=='y')&&(game[3][i]=='y'))||((game[4][i]=='y')&&(game[1][i]=='y')&&(game[2][i]=='y')&&(game[3][i]=='y')))
 {
  y=1;
  break;
 }
}
if(!r)
{
 for(i=0;i<5;i++)
 if(((game[i][0]=='r')&&(game[i][1]=='r')&&(game[i][2]=='r')&&(game[i][3]=='r'))||((game[i][4]=='r')&&(game[i][1]=='r')&&(game[i][2]=='r')&&(game[i][3]=='r'))||((game[i][4]=='r')&&(game[i][5]=='r')&&(game[i][2]=='r')&&(game[i][3]=='r'))||((game[i][4]=='r')&&(game[i][5]=='r')&&(game[i][6]=='r')&&(game[i][3]=='r'))||((game[i][4]=='r')&&(game[i][5]=='r')&&(game[i][6]=='r')&&(game[i][7]=='r'))||((game[i][8]=='r')&&(game[i][5]=='r')&&(game[i][6]=='r')&&(game[i][7]=='r'))||((game[i][8]=='r')&&(game[i][6]=='r')&&(game[i][6]=='r')&&(game[i][7]=='r')))
 {
 r=1;
 break;
 }
}
if(!y)
{
 for(i=0;i<5;i++)
 if(((game[i][0]=='y')&&(game[i][1]=='y')&&(game[i][2]=='y')&&(game[i][3]=='y'))||((game[i][4]=='y')&&(game[i][1]=='y')&&(game[i][2]=='y')&&(game[i][3]=='y'))||((game[i][4]=='y')&&(game[i][5]=='y')&&(game[i][2]=='y')&&(game[i][3]=='y'))||((game[i][4]=='y')&&(game[i][5]=='y')&&(game[i][6]=='y')&&(game[i][3]=='y'))||((game[i][4]=='y')&&(game[i][5]=='y')&&(game[i][6]=='y')&&(game[i][7]=='y'))||((game[i][8]=='y')&&(game[i][5]=='y')&&(game[i][6]=='y')&&(game[i][7]=='y'))||((game[i][8]=='y')&&(game[i][6]=='y')&&(game[i][6]=='y')&&(game[i][7]=='y')))
 {
 y=1;
 break;
 }
}
if(!r)
{
 if(((game[1][0]=='r')&&(game[2][1]=='r')&&(game[3][2]=='r')&&(game[4][3]=='r'))||((game[0][6]=='r')&&(game[1][7]=='r')&&(game[2][8]=='r')&&(game[3][9]=='r')))
 {
  r=1;
 }
 else
 {
  for(i=0;i<6;i++)
  if(((game[0][i]=='r')&&(game[1][i+1]=='r')&&(game[2][i+2]=='r')&&(game[3][i+3]=='r'))||((game[4][i+4]=='r')&&(game[1][i+1]=='r')&&(game[2][i+2]=='r')&&(game[3][i+3]=='r')))
  {
  r=1;
  break;
  }
 }
}
if(!y)
{
 if(((game[1][0]=='y')&&(game[2][1]=='y')&&(game[3][2]=='y')&&(game[4][3]=='y'))||((game[0][6]=='y')&&(game[1][7]=='y')&&(game[2][8]=='y')&&(game[3][9]=='y')))
 {
  y=1;
 }
 else
 {
  for(i=0;i<6;i++)
  if(((game[0][i]=='y')&&(game[1][i+1]=='y')&&(game[2][i+2]=='y')&&(game[3][i+3]=='y'))||((game[4][i+4]=='y')&&(game[1][i+1]=='y')&&(game[2][i+2]=='y')&&(game[3][i+3]=='y')))
  {
  y=1;
  break;
  }
 }
}
if(!r)
{
 if(((game[3][0]=='r')&&(game[2][1]=='r')&&(game[1][2]=='r')&&(game[0][3]=='r'))||((game[4][6]=='r')&&(game[3][7]=='r')&&(game[2][8]=='r')&&(game[1][9]=='r')))
 {
  r=1;
 }
 else
 {
  for(i=0;i<6;i++)
  if(((game[4][i]=='r')&&(game[3][i+1]=='r')&&(game[2][i+2]=='r')&&(game[1][i+3]=='r'))||((game[3][i]=='r')&&(game[2][i+1]=='r')&&(game[1][i+2]=='r')&&(game[0][i+3]=='r')))
  {
  r=1;
  break;
  }
 }
}
if(!y)
{
 if(((game[3][0]=='y')&&(game[2][1]=='y')&&(game[1][2]=='y')&&(game[0][3]=='y'))||((game[4][6]=='y')&&(game[3][7]=='y')&&(game[2][8]=='y')&&(game[1][9]=='y')))
 {
  y=1;
 }
 else
 {
  for(i=0;i<6;i++)
  if(((game[4][i]=='y')&&(game[3][i+1]=='y')&&(game[2][i+2]=='y')&&(game[1][i+3]=='y'))||((game[3][i]=='y')&&(game[2][i+1]=='y')&&(game[1][i+2]=='y')&&(game[0][i+3]=='y')))
  {
  y=1;
  break;
  }
 }
}

if(r)
{
 drawc(game);
 cout<<"\n\n\n\n\t\t\t Player 1 wins!!";
}
else if(y)
{
 drawc(game);
 cout<<"\n\n\n\n\t\t\t Player 2 wins!!";
}
else
{
 ct++;
 goto label2;
}
}
}
