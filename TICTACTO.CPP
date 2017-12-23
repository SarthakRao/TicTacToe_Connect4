#include<iostream.h>
#include<conio.h>
void print(char board[3][3])
{
	cout<<"-------"<<endl;
	cout<<"|"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl;
	cout<<"-------"<<endl;
	cout<<"|"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl;
	cout<<"-------"<<endl;
	cout<<"|"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl;
	cout<<"-------"<<endl;
};
int check(char arr[3][3])
{
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[1][1]!=' ')
            {
                return 0;
                j=10;
                i=10;
            }
            else if(arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2] && arr[1][1]!=' ')
            {
                return 0;
                j=10;
                i=10;
            }
            else if(arr[i][j]==arr[i][j+1] && arr[i][j]==arr[i][j+2] && arr[i][j]!=' ')
            {
                return 0;
                j=10;
                i=10;
            }
            else if(arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i+2][j] && arr[i][j]!=' ')
            {
                return 0;
                j=10;
                i=10;
            }
            else
                return 1;
        }
    }
};
void main()
{
	clrscr();
	char board[3][3],player[2][50];
	int tx,ty,id=0,p=0;
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
			board[i][j]=' ';
	}
	print(board);
	cout<<"Player 1: "<<endl;
	cin>>player[0];
	cout<<"Player 2: "<<endl;
	cin>>player[1];
	char play[2];
	play[0]='X';
	play[1]='O';
	do                     //Loop game play till player wins or draws.
	{
		a:
		cout<<player[p]<<"'s turn: "<<endl<<"Enter row number and column number:"<<endl;
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
	 }while(check(board) == 1);
	 p=(p+1)%2;
	 cout<<player[p]<<" wins!"<<endl;
	getch();
}




