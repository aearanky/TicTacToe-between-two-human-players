#include <iostream>
#include <stdlib.h>
#include "class_tictactoe.h"
#include "qlearning.h"
using namespace std;

map<string, double> Q;

int main()
{
	tictactoe tt;
	qlearning ql;	
	ql.player = 1;	
	int i, number, choice;
	char mark;
	bool success;
	do
	{
		tt.board();
		ql.player=(ql.player%2)?1:2;
		cout << "Player " << ql.player << ", enter a number:  ";
		cin >> choice;
		number = choice;
		mark=(ql.player == 1) ? 'X' : 'O';
		success = tt.mark_square(number, choice, tt.square[number], mark); //Decrement the player for invalid choice
		if (success == false)
			ql.player--;		
		i=tt.checkwin();
		ql.switch_player();

	}while(i==-1); //While game is not over

	tt.board();

	if(i==1) //One of them wins the game
		cout<<"==>\aPlayer "<<--ql.player<<" win ";
	else //Game ended in a draw
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	return 0;
}
