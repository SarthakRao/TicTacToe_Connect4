#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
void print(char board[3][3])                //Print TicTacToe board
{
	cout<<"\n\t    1   2   3 "<<endl;
	cout<<"\t  -------------"<<endl;
	cout<<"\t1 | "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |"<<endl;
	cout<<"\t  -------------"<<endl;
	cout<<"\t2 | "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |"<<endl;
	cout<<"\t  -------------"<<endl;
	cout<<"\t3 | "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |"<<endl;
	cout<<"\t  -------------"<<endl;
};
int check(char arr[3][3])                   //Function to check if input move is valid or not (TTT)
{
    int flag = 1;
    for(int i=0;i<=2;i++)
    {

            if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[1][1]!=' ')
            {
                flag = 0;
            }
            else if(arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2] && arr[1][1]!=' ')
            {
                flag = 0;
            }
            else if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] && arr[i][0]!=' ')
            {
                flag = 0;
            }
            else if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[0][i]!=' ')
            {
                flag = 0;
            }

    }
    return flag;
};
int game(char arr[3][3])                    //Function to check if board (TTT) is full
{
    int flag = 1;
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(arr[i][j]==' ')
            {
                flag = 0;
            }
        }
    }
    return flag;
}
int ct=0,i;
void printcon4(char board[5][10])                                                       //Print C4 board
{
    clrscr();
    cout<<"\n\tCONNECT 4\n\n"<<endl;
    cout<<"   1   2   3   4   5   6   7   8   9   10 "<<endl;
    cout<<" _________________________________________";
    for(int i=0;i<=4;i++)
    {
        cout<<endl;
        for(int j=0;j<=9;j++)
        {
            cout<<" | "<<board[i][j];

        }
        cout<<" |";

    }
    cout<<endl<<" _________________________________________";

    cout<<endl;
}
int boardfull(char arr[5][10])
{
    int flag = 1;
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(arr[i][j]==' ')
            {
                flag = 0;
            }
        }
    }
    return flag;
}
void main()
{
    mainmenu:
    clrscr();
    int c;
    cout<<"\n\t<><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<"\t||              GAME ZONE               ||"<<endl;
    cout<<"\t<><><><><><><><><><><><><><><><><><><><><>"<<endl;                                          //Main Menu
    cout<<"\n\n\tSelect the game you want to play : \n\n\t1. TicTacToe \n\t2. Connect 4 \n\t3. Exit"<<endl;
    cin>>c;
    if(c==1)                                                                                    //TicTacToe
    {
                int choice, ch, cho;
             menu:
             clrscr();
             cout<<" -------------------"<<endl;
             cout<<" | Tic | Tac | Toe |"<<endl;
             cout<<" -------------------"<<endl;
             cout<<"\n\n1. Play \n2. Instructions \n3. Back to main menu"<<endl;
             select:
             cin>>ch;
             if(ch==1)
             {
                    tttstart:
                    clrscr();
                    char board[3][3],player[2][50];
                    int numb,pl[2];
                    pl[0]=0;pl[1]=0;
                    for(int i=0;i<=2;i++)
                    {
                        for(int j=0;j<=2;j++)
                            board[i][j]=' ';
                    }
                    print(board);
                    cout<<"\nEnter name of player 1: "<<endl;
                    cin>>player[0];
                    cout<<"Enter name of player 2: "<<endl;
                    cin>>player[1];
                    cout<<"How many games do you want to play?"<<endl;
                    cin>>numb;
                    char play[2];
                    play[0]='X';
                    play[1]='O';
                        for(int k=1;k<=numb;k++)
                        {
                            clrscr();
                            int tx,ty,id=0,p=0;
                            for(int i=0;i<=2;i++)
                            {
                                for(int j=0;j<=2;j++)
                                    board[i][j]=' ';
                            }

                            print(board);


                            do                     //Loop game play till player wins or draws.
                            {
                                a:
                                cout<<"\n"<<player[p]<<"'s turn: "<<endl<<"Enter row number and column number: [eg. (1-3) for right-top corner] "<<endl;
                                cin>>tx>>ty;
                                if(tx<1 || tx>3 || ty<1 || ty>3)
                                {
                                    cout<<"Invalid input!"<<endl;
                                    goto a;
                                }

                                for(int x=1;x<=3;x++)
                                {
                                    for(int y=1;y<=3;y++)
                                    {
                                        if(tx==x && ty==y)
                                        {
                                            if(board[x-1][y-1]==' ')
                                            {
                                                board[x-1][y-1]=play[id];
                                                id=(id+1)%2;
                                            }
                                            else
                                            {
                                                cout<<"Location already occupied!"<<endl;
                                                goto a;
                                            }
                                        }
                                    }
                                }
                                p=(p+1)%2;

                                clrscr();
                                print(board);

                             }while(check(board) == 1 && game(board) == 0);
                             if(check(board) == 1 && game(board)==1)
                             {
                                 cout<<"\n\nIts a draw!\n\n\n"<<endl;
                             }
                             else
                             {
                                 p=(p+1)%2;
                                 pl[p]++;
                             }
                                cout<<"Score: \n"<<player[0]<<": "<<pl[0]<<"\n"<<player[1]<<": "<<pl[1]<<"\n";
                                delay(2000);
                        }

                cout<<"\n\n\n1. Play again \n2. Game menu \n3. Main menu"<<endl;
                cin>>choice;
                if (choice==1)
                {
                    goto tttstart;
                }
                else if (choice==2)
                {
                    clrscr();
                    goto menu;
                }
                else if(choice==3)
                {
                    goto mainmenu;
                }
             }
             else if(ch==2)
             {
                 clrscr();
                 cout<<"\nINSTRUCTIONS FOR TICTACTOE:\nPlayers play their turn alternately. \nThe aim of the game is to fill any full row, column, or diagonal with your shape (X or O). \nTo play your turn, enter the row number and then the column number corresponding to the slot you want to play your move in. \n Enjoy! "<<endl;
                 cout<<"\n\n1. Play now \n2. Back to main menu"<<endl;
                 cin>>cho;
                 if(cho==1)
                 {
                     clrscr();
                     goto tttstart;

                 }
                 else
                 {
                     goto mainmenu;

                 }
             }
             else if(ch==3)
             {
                 goto mainmenu;
             }
             else
             {
                 cout<<"Invalid input!"<<endl;
                 goto select;
             }

            getch();


    }
    else if(c==2)                                                   //Connect 4
    {
            int cho;
            clrscr();
            cout<<"\nConnect 4 \n\n1. Play \n2. Instructions \n3. Back to main menu\n";
            gamemenu:
            cin>>cho;
            if(cho==1)
            {
                    c4start:
                    char game[5][10],gamer[2][50],ch;
                    for(int i=0;i<5;i++)
                    for(int j=0;j<10;j++)
                    game[i][j]=' ';
                    clrscr();
                    printcon4(game);
                    cout<<"\nEnter name of player 1: "<<endl;
                    cin>>gamer[0];
                    cout<<"Enter name of player 2: "<<endl;
                    cin>>gamer[1];
                    start:
                    int choice,a=0,X=0,O=0,id=0;
                    for( i=0;i<5;i++)
		            for(int j=0;j<10;j++)
                    game[i][j]=' ';
                    clrscr();
                    label2:
                    printcon4(game);
                    cout<<"\n"<<gamer[id]<<"'s turn: "<<endl;
                    label1:
                    cout<<"\tEnter 0 to exit or enter the place to drop the coin: ";
                    cin>>choice;
                    if(choice==0)
                    {
                        ays:
                        cout<<"\nAre you sure? <Y/N>"<<endl;
                        cin>>ch;
                        if(ch=='n'||ch=='N')
                        {
                            goto label2;
                        }
                        else if(ch=='y'||ch=='Y')
                        {
                            goto mainmenu;
                        }
                        else
                            goto ays;
                    }
                    else if(choice<0||choice>10)
                    {
                     printcon4(game);
                     cout<<"\n\n\n\n\tWrong choice\n";
                     goto label1;
                    }
                    else
                    {
                         a=0;
                         for(i=4;i>=0;i--)
                            if(game[i][choice-1]==' ')
                             {
                                  a=1;
                                  break;
                             }
                         if(a==1)
                         {
                              if(ct%2==0)
                              game[i][choice-1]='X';
                              else
                              game[i][choice-1]='O';
                         }
                         else
                         {
                              printcon4 (game);
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
                             printcon4(game);
                             cout<<"\n"<<gamer[0]<<" wins!";
                        }
                        else if(O)
                        {
                             printcon4(game);
                             cout<<"\n"<<gamer[1]<<" wins!";
                        }
                        else if(boardfull(game)==1)
                        {
                            cout<<"\n\n\tIt's a draw!"<<endl;
                        }
                        else
                        {
                             ct++;
                             id=(id+1)%2;
                             goto label2;
                        }
                        char ch;
                        cout<<"\n\nPlay again? (Y/N)"<<endl;
                        option:
                        cin>>ch;
                        if(ch=='y' || ch=='Y')
                            goto start;
                        else if(ch=='N' || ch=='n')
                        {
                            goto mainmenu;
                        }
                        else
                            {cout<<"Invalid input!"<<endl;
                            goto option;}
                   }
            }
            else if(cho==2)
            {
                clrscr();
                int ch;
                cout<<"INSTRUCTIONS: \n\nConnect 4 is a game played vertically. The aim, similar to that of TicTacToe, is to get any 4 of your coins consecutively in the same row, column, or diagonal. On selecting to column number, your coin will fall on top of whichever coin is already in that column. Game ends when 4 of any coin are in a line in whichever direction. \n\n\n1. Play now \n2. Main menu"<<endl;
                opt:
                cin>>ch;
                if(ch==1)
                    goto c4start;
                else if(ch==2)
                    goto mainmenu;
                else
                {
                    cout<<"Invalid input!"<<endl;
                    goto opt;
                }
            }
            else if(cho==3)
            {
                goto mainmenu;
            }
            else
            {
                cout<<"Invalid input!"<<endl;
                goto gamemenu;
            }
    }
    else if(c==3)
        cout<<"Thank you! \n\nGame by: RaoBot\nVersion 1.0.0"<<endl;
    else
        cout<<"Invalid input!"<<endl;
    getch();
}

