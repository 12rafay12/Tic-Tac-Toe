#include<iostream>
using namespace std;
char num[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int row,column;
	char turns='X';           // globally decleared variables
	bool draw = false;
void display_board()         //  function for displaying table of game
{
	system("cls");
	
	

	
	cout<<"\t\t ******** T I C  _ T A C _ T O E _ G A M E:********\n\n";
	cout<<"Project by : Abdul Rafay 190901, Muhammad Amjad 190913, Rashid 190907 "<<endl;
	cout<<"\tRafay[x]\n";
	cout<<"\tAmjad [O]\n";
	cout<<"\t\t\t\t      |      |     \n";
	cout<<"\t\t\t\t  "<<num[0][0]<<"   |   "  <<num[0][1]<<   "  |  "<<num[0][2]<<   "\n";
	cout<<"\t\t\t\t______|______|______\n";
	cout<<"\t\t\t\t      |      |     \n";
	cout<<"\t\t\t\t  "<<num[1][0]<<"   |   "  <<num[1][1]<<   "  |  "<<num[1][2]<<   "\n";
	cout<<"\t\t\t\t______|______|______\n";
	cout<<"\t\t\t\t      |      |     \n";
	cout<<"\t\t\t\t  "<<num[2][0]<<"   |   "  <<num[2][1]<<   "  |  "<<num[2][2]<<   "\n";
	cout<<"\t\t\t\t      |      |     \n";
}
void player_turns()         // function to take the turns by players
{
	int choice;
	if(turns=='X')
	cout<<"\n\tRafay's turn :";
	else if(turns=='O')
	cout<<"\n\tAmjad's turn :";
	cin>>choice;
		switch(choice)                    // a switch statement used to take the values for
	{                                     // rows and coloumns of the table these values used in
		case 1:                           // the programe in next lines 
			row=0; column=0; break;    
		case 2:
			row=0; column=1; break;        
		case 3:
			row=0; column=2; break;
		case 4:
			row=1; column=0; break;
		case 5:
			row=1; column=1; break;
		case 6:
			row=1; column=2; break;
		case 7:
			row=2; column=0; break;
		case 8:
			row=2; column=1; break;
		case 9:
			row=2; column=2; break;
		default:
		cout<<"Invalid input\n"; break;		
 }
	if(turns=='X' && num[row][column]!='X' && num[row][column]!='O')
	  {
	num[row][column]='X';
	turns='O';
      }
	else if(turns=='O'&& num[row][column]!='X' && num[row][column]!='O')
	  {
	num[row][column]='O';
	turns='X';
      }	
      else
      {
      	cout<<"Box is already filled!!! \n Please try aagin...!!\n";
      	player_turns();
	  }
	  display_board();   
 }
 
bool gameover()            // a function to over the game 
      {
      	// game over
      	for(int i=0;i<3;i++)
      	if(num[i][0]==num[i][1]&&num[i][0]==num[i][2] || num[0][i]==num[1][i]&&num[0][i]==num[2][i])
      	return false;
      	
      	if(num[0][0]==num[1][1]&&num[0][0]==num[2][2] || num[0][2]==num[1][1]&&num[0][2]==num[2][0])
      	return false;
      	
      	// game continue
      	for(int i=0;i<3;i++)
      	{
      	for(int j=0;j<3;j++)
      	if(num[i][j]!='X' && num[i][j]!= 'O')
      	return true;
      }
      // draw
      draw = true;
      return false;
	   
      	
	  }
int main()                      // the main function
{
	while(gameover())
	{
	display_board();
	player_turns();            //caling of the function in main
	gameover();
    }
    
    if(turns=='O' && draw==false )
    cout<<"Rafay [X] wins!! congratulation\n";
    else if(turns=='X' && draw==false)
     cout<<"Amjad [O] wins!! congratulation\n";
     else
     cout<<"GAME DRAW!!\n";
}
//***********************************BEST OF LUCK ************************************************
//************************************ THE END ***************************************************
