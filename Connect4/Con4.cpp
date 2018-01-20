#include<conio.h>
#include<iostream.h>
int ct=0,i;
void print(char board[5][10])
{
    clrscr();
    cout<<"CONNECT 4"<<endl;
    cout<<"   1   2   3   4   5   6   7   8   9   10 "<<endl;
    cout<<" -----------------------------------------";
    for(int i=0;i<=4;i++)
    {
        cout<<endl;
        for(int j=0;j<=9;j++)
        {
            cout<<" | "<<board[i][j];

        }
        cout<<" |";

    }
    cout<<endl<<" -----------------------------------------";
    cout<<endl;
}
void connect4()
{
    int choice,a=0,X=0,O=0;
    char game[5][10];
    for(int i=0;i<5;i++)
    for(int j=0;j<10;j++)
    game[i][j]=' ';        //to identify the non filled spaces
    clrscr();
    label2:
    print(game);
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
     print(game);
     cout<<"\n\n\n\n\tWrong choice\n";
     goto label1;
    }
    else
    {
         for(i=4;i>=0;i--)
            if(game[i][choice-1]==' ')
             {
                  a=1;
                  break;
             }
         if(a)
         {
              if(ct%2==0)
              game[i][choice-1]='X';
              else
              game[i][choice-1]='O';
         }
         else
         {
              print(game);
              cout<<"\n\n\n\n\tThe column is occupied fully\n";
              goto label1;
         }
         for(i=0;i<10;i++)
         {
             if(((game[0][i]=='X')&&(game[1][i]=='X')&&(game[2][i]=='X')&&(game[3][i]=='X'))||((game[4][i]=='X')&&(game[1][i]=='X')&&(game[2][i]=='X')&&(game[3][i]=='X')))
             {
                  X=1;
                  break;
             }
             else if(((game[0][i]=='O')&&(game[1][i]=='O')&&(game[2][i]=='O')&&(game[3][i]=='O'))||((game[4][i]=='O')&&(game[1][i]=='O')&&(game[2][i]=='O')&&(game[3][i]=='O')))
             {
                  O=1;
                  break;
             }
         }
        if(!X)
        {
             for(i=0;i<5;i++)
             {
                 if(((game[i][0]=='X')&&(game[i][1]=='X')&&(game[i][2]=='X')&&(game[i][3]=='X'))||((game[i][4]=='X')&&(game[i][1]=='X')&&(game[i][2]=='X')&&(game[i][3]=='X'))||((game[i][4]=='X')&&(game[i][5]=='X')&&(game[i][2]=='X')&&(game[i][3]=='X'))||((game[i][4]=='X')&&(game[i][5]=='X')&&(game[i][6]=='X')&&(game[i][3]=='X'))||((game[i][4]=='X')&&(game[i][5]=='X')&&(game[i][6]=='X')&&(game[i][7]=='X'))||((game[i][8]=='X')&&(game[i][5]=='X')&&(game[i][6]=='X')&&(game[i][7]=='X'))||((game[i][8]=='X')&&(game[i][6]=='X')&&(game[i][6]=='X')&&(game[i][7]=='X')))
                 {
                     X=1;
                     break;
                 }
             }
        }
        if(!O)
        {
             for(i=0;i<5;i++)
                 if(((game[i][0]=='O')&&(game[i][1]=='O')&&(game[i][2]=='O')&&(game[i][3]=='O'))||((game[i][4]=='O')&&(game[i][1]=='O')&&(game[i][2]=='O')&&(game[i][3]=='O'))||((game[i][4]=='O')&&(game[i][5]=='O')&&(game[i][2]=='O')&&(game[i][3]=='O'))||((game[i][4]=='O')&&(game[i][5]=='O')&&(game[i][6]=='O')&&(game[i][3]=='O'))||((game[i][4]=='O')&&(game[i][5]=='O')&&(game[i][6]=='O')&&(game[i][7]=='O'))||((game[i][8]=='O')&&(game[i][5]=='O')&&(game[i][6]=='O')&&(game[i][7]=='O'))||((game[i][8]=='O')&&(game[i][6]=='y')&&(game[i][6]=='O')&&(game[i][7]=='O')))
                 {
                     O=1;
                     break;
                 }
        }
        if(!X)
        {
             if(((game[1][0]=='X')&&(game[2][1]=='X')&&(game[3][2]=='X')&&(game[4][3]=='X'))||((game[0][6]=='X')&&(game[1][7]=='X')&&(game[2][8]=='X')&&(game[3][9]=='X')))
             {
                X=1;
             }
             else
             {
                  for(i=0;i<6;i++)
                      if(((game[0][i]=='X')&&(game[1][i+1]=='X')&&(game[2][i+2]=='X')&&(game[3][i+3]=='X'))||((game[4][i+4]=='X')&&(game[1][i+1]=='X')&&(game[2][i+2]=='X')&&(game[3][i+3]=='X')))
                      {
                          X=1;
                          break;
                      }
             }
        }
        if(!O)
        {
             if(((game[1][0]=='O')&&(game[2][1]=='O')&&(game[3][2]=='O')&&(game[4][3]=='O'))||((game[0][6]=='O')&&(game[1][7]=='O')&&(game[2][8]=='O')&&(game[3][9]=='O')))
             {
                O=1;
             }
             else
             {
                  for(i=0;i<6;i++)
                      if(((game[0][i]=='O')&&(game[1][i+1]=='O')&&(game[2][i+2]=='O')&&(game[3][i+3]=='O'))||((game[4][i+4]=='O')&&(game[1][i+1]=='O')&&(game[2][i+2]=='O')&&(game[3][i+3]=='O')))
                      {
                          O=1;
                          break;
                      }
             }
        }
        if(!X)
        {
             if(((game[3][0]=='X')&&(game[2][1]=='X')&&(game[1][2]=='X')&&(game[0][3]=='X'))||((game[4][6]=='X')&&(game[3][7]=='X')&&(game[2][8]=='X')&&(game[1][9]=='X')))
             {
                X=1;
             }
             else
             {
                  for(i=0;i<6;i++)
                      if(((game[4][i]=='X')&&(game[3][i+1]=='X')&&(game[2][i+2]=='X')&&(game[1][i+3]=='X'))||((game[3][i]=='X')&&(game[2][i+1]=='X')&&(game[1][i+2]=='X')&&(game[0][i+3]=='X')))
                      {
                          X=1;
                          break;
                      }
             }
        }
        if(!O)
        {
             if(((game[3][0]=='O')&&(game[2][1]=='O')&&(game[1][2]=='O')&&(game[0][3]=='O'))||((game[4][6]=='O')&&(game[3][7]=='O')&&(game[2][8]=='O')&&(game[1][9]=='O')))
             {
                O=1;
             }
             else
             {
                  for(i=0;i<6;i++)
                      if(((game[4][i]=='O')&&(game[3][i+1]=='O')&&(game[2][i+2]=='O')&&(game[1][i+3]=='O'))||((game[3][i]=='O')&&(game[2][i+1]=='O')&&(game[1][i+2]=='O')&&(game[0][i+3]=='O')))
                      {
                          O=1;
                          break;
                      }
             }
        }

        if(X)
        {
             print(game);
             cout<<"\n\n\n\n\t\t\t Player 1 wins!!";
        }
        else if(O)
        {
             print(game);
             cout<<"\n\n\n\n\t\t\t Player 2 wins!!";
        }
        else
        {
             ct++;
             goto label2;
        }
    }
}
void main()
{
    connect4();
}

