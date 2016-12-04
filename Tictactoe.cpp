#include <iostream>
#include <stdlib.h>
#include "class_tictactoe.h"
using namespace std;

int main()
{
	tictactoe tt;	
	tt.player = 1;	
	int i, number, choice;
	char mark;
	bool success;
	do
	{
		tt.board();
		tt.player=(tt.player%2)?1:2;
		cout << "player " << tt.player << ", enter a number:  ";
		cin >> choice;
		number = choice;
		mark=(tt.player == 1) ? 'X' : 'O';
		success = tt.mark_square(number, choice, tt.square[number], mark); //Decrement the player for invalid choice
		if (success == false)
			tt.player--;		
		i=tt.checkwin();
		tt.switch_player();

	}while(i==-1); //While game is not over

	tt.board();

	if(i==1) //One of them wins the game
		cout<<"==>\aplayer "<<--tt.player<<" win ";
	else //Game ended in a draw
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	return 0;
}
