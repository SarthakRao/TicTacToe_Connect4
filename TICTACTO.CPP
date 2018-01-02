#include<iostream.h>
#include<conio.h>
#include<process.h>
void print(char board[3][3])                //Function to print the game board
{
	cout<<"   1 2 3"<<endl;
	cout<<"  -------"<<endl;
	cout<<"1 |"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl;
	cout<<"  -------"<<endl;
	cout<<"2 |"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl;
	cout<<"  -------"<<endl;
	cout<<"3 |"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl;
	cout<<"  -------"<<endl;
};
int check(char arr[3][3])                   //Function to check if input move is valid or not
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
int game(char arr[3][3])                    //Function to check if board is full
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
void main()
{
     int choice, ch, cho;
     menu:
     cout<<"*********** GAME ZONE **********"<<endl;                //Main Menu
     cout<<"\nPlay the classic game of TicTacToe "<<endl;
     cout<<"\n1. Play \n2. Instructions \n3. Exit"<<endl;
     select:
     cin>>ch;
     if(ch==1)
     {
         play:
         do{
            clrscr();
            char board[3][3],player[2][50];
            int tx,ty,id=0,p=0;
            for(int i=0;i<=2;i++)
            {
                for(int j=0;j<=2;j++)
                    board[i][j]=' ';
            }

            print(board);
            cout<<"Enter name of player 1: "<<endl;
            cin>>player[0];
            cout<<"Enter name of player 2: "<<endl;
            cin>>player[1];
            char play[2];
            play[0]='X';
            play[1]='O';

            do                     //Loop game play till player wins or draws.
            {
                a:
                cout<<player[p]<<"'s turn: "<<endl<<"Enter row number and column number: [eg. (1-3) for right-top corner] "<<endl;
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
                 cout<<"Its a draw!"<<endl;
             }
             else
             {
                 p=(p+1)%2;
                 cout<<player[p]<<" wins!"<<endl;
             }
             cout<<"1. Play again \n2. Main menu \n3. Exit"<<endl;
             cin>>choice;
        }while(choice==1);
        if (choice==2)
        {
            clrscr();
            goto menu;
        }
        else if(choice==3)
        {
            cout<<"Thank you! \n\nGame by: Sarthak Rao\nVersion: 1.0.0"<<endl;
            exit(0);
        }
     }
     else if(ch==2)
     {
         cout<<"\nINSTRUCTIONS:\nPlayers play their turn alternately. \nThe aim of the game is to fill any full row, column, or diagonal with your shape (X or O). \nTo play your turn, enter the row number and then the column number corresponding to the slot you want to play your move in. \n Enjoy! "<<endl;
         cout<<"\n\n1. Play now \n2. Exit"<<endl;
         cin>>cho;
         if(cho==1)
         {
             clrscr();
             goto play;
         }
         else
         {
             cout<<"Thank you! \n\nGame by: Sarthak Rao\nVersion: 1.0.0"<<endl;
             exit(0);
         }
     }
     else if(ch==3)
     {
         cout<<"Thank you! \n\nGame by: Sarthak Rao\nVersion: 1.0.0"<<endl;
         exit(0);
     }
     else
     {
         cout<<"Invalid input!"<<endl;
         goto select;
     }

	getch();
}
