#include<iostream>
#include<conio.h>
using namespace std;
char board[3][3]={'1','2','3','4','5','6','7','8','9'};
char player='X';
char won='D';
void toggle();
void input();
void display();
int check();
int main()
{
          int flag=0;
          cout<<"TIC TAC TOE\n";
          display();
          do
          {
                    input();
                    display();
                    if(flag>=3)
                              if(check())
                                        break;
                    flag++;
          }while(flag<9);
          if(won=='D')
                    cout<<"Draw....\n";
          else
                    cout<<"Player '"<<won<<"' has won the match....\n";
          getch();
          return 0;
}
void display()
{
          cout<<"\n  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<"\n";
          cout<<"-----|-----|-----"<<"\n";
          cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<"\n";
          cout<<"-----|-----|-----"<<"\n";
          cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<"\n\n";
}
void input()
{
          int poi;
          invalid:
          cout<<"Enter position:";
          cin>>poi;
          switch(poi)
          {
          case 1:
                    board[0][0]=player;           break;
          case 2:
                    board[0][1]=player;           break;
          case 3:
                    board[0][2]=player;           break;
          case 4:
                    board[1][0]=player;           break;
          case 5:
                    board[1][1]=player;           break;
          case 6:
                    board[1][2]=player;           break;
          case 7:
                    board[2][0]=player;           break;
          case 8:
                    board[2][1]=player;           break;
          case 9:
                    board[2][2]=player;           break;
          default:
                    cout<<"Invalid Selection....\n";
                    goto invalid;
          }
          toggle();
}
void toggle()
{
          if(player=='X')
                    player='O';
          else
                    player='X';
}
int check()
{
          int flag=0;
          if(board[0][0]==board[1][0] && board[2][0]==board[1][0])
          {
                    won=board[0][0];
                    flag=1;
          }
          else if(board[0][1]==board[1][1] && board[2][1]==board[1][1])
          {
                    won=board[0][1];
                    flag=1;
          }
          else if(board[0][2]==board[1][2] && board[1][2]==board[2][2])
          {
                    won=board[0][2];
                    flag=1;
          }
          else if(board[0][0]==board[0][1] && board[0][1]==board[0][2])
          {
                    won=board[0][0];
                    flag=1;
          }
          else if(board[1][0]==board[1][1] && board[1][1]==board[1][2])
          {
                    won=board[1][0];
                    flag=1;
          }
          else if(board[2][0]==board[2][1] && board[2][1]==board[2][2])
          {
                    won=board[2][0];
                    flag=1;
          }
          else if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
          {
                    won=board[0][0];
                    flag=1;
          }
          else if(board[1][1]==board[2][0] && board[1][1]==board[0][2])
          {
                    won=board[1][1];
                    flag=1;
          }
          return flag;
}
