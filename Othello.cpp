#include<iostream.h>
#include<conio.h>
void print(char arr[][10])
{
    cout<<"---------------------";
    for(int i=0;i<=9;i++)
    {
        cout<<endl;
        for(int j=0;j<=9;j++)
        {
            cout<<"|"<<arr[i][j];

        }
        cout<<"|";
        cout<<endl<<"---------------------";
    }
    cout<<endl;
}
void main()
{
    char board[10][10],player[2][50];
    int tx,ty,id=0,p=0;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            board[i][j]=' ';
        }
    }
    board[4][4]='X';board[5][5]='X';
    board[4][5]='O';board[5][4]='O';
    print(board);
    cout<<"Player 1: "<<endl;
    cin>>player[0];
    cout<<"Player 2: "<<endl;
    cin>>player[1];
    char play[2];
    play[0]='X';
    play[1]='O';
    do{
            a:
            cout<<player[p]<<"'s turn: "<<endl<<"Enter row number and column number:"<<endl;
            cin>>tx>>ty;
            if(tx<1 || tx>10 || ty<1 || ty>10)
            {
                cout<<"Invalid input!"<<endl;
                goto a;
            }

            for(int x=1;x<=10;x++)
            {
                for(int y=1;y<=10;y++)
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
    }while(1);

    getch();
}
