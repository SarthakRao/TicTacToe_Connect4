#include<iostream.h>
#include<conio.h>
void print(char board[3][3])
{
	cout<<"_______"<<endl;
	cout<<"|"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl;
	cout<<"_______"<<endl;
	cout<<"|"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl;
	cout<<"_______"<<endl;
	cout<<"|"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl;
}
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
	for(int a=0;a<=5;a++)
	{
		cout<<player[p]<<"'s turn: "<<endl;
		p=(p+1)%2;
		cin>>tx>>ty;
		for(int x=1;x<=3;x++)
		{
			for(int y=1;y<=3;y++)
			{
				if(tx==x && ty==y)
				{
					board[x-1][y-1]=play[id];
					id=(id+1)%2;
				}
			}
		}
		print(board);
	 }
	getch();
}




