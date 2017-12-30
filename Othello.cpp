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
    char arr[10][10],player[2][50];
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            arr[i][j]=' ';
        }
    }
    arr[4][4]='X';arr[5][5]='X';
    arr[4][5]='O';arr[5][4]='O';
    print(arr);
    cout<<"Player 1: "<<endl;
    cin>>player[0];
    cout<<"Player 2: "<<endl;
    cin>>player[1];
    char play[2];
    play[0]='X';
    play[1]='O';

    getch();
}
