#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include "bestweight.hpp"

using namespace std;

//*******
//http://gimli.morningside.edu/~jph004/foxAndHounds.html     You can only play as the hounds in order to get the fox to move on its
//own, so basically, if you play as the fox, the hounds won't move at all. 
//********

main()
{  string buffer; //HOLDS USER INPUT FROM THE WEBPAGE AJAX
	
	bool playerFox = false; //BECOMES TRUE IF PLAYER IS PLAYING AS FOX
	bool playerHound = false; //BECOMES TRUE IF PLAYER IS PLAYING AS HOUND
	bool taken = false; //BECOMES TRUE WHEN A POSSIBLE SPOT IS TAKEN BY ANOTHER PLAYER
	
	int houndPositions[4] = {}; //HOLDS THE POSITIONS OF HOUNDS, 0 - 3
	vector<int> possibleHoundMoves[4] = {}; //Array of vectors //HOLDS ALL POSSIBLE POSITIONS THAT HOUNDS CAN MOVE TO, ONE VECTOR FOR EACH HOUND
	
	int foxPosition; //HOLDS CURRENT POSITION OF THE FOX
	int row; //HOLDS THE ROW THE PLAYER IS IN
	int column; //HOLDS THE COLUMN THE PLAYER IS IN
	int greatestHoundWeight; //HOLDS THE HOUND MOVE WEIGHT THAT IS THE LARGEST
	int houndWeight; //HOLDS A HOUND MOVE WEIGHT
	int houndToMove = 0; //HOLDS WHICH HOUND WILL MOVE, DEFAULT TO FIRST HOUND
	
	vector<int> possibleMoves; //HOLDS ALL POSSIBLE POSITIONS THAT A PLAYER COULD MOVE TO
	vector<int> houndsBestMove; //HOLDS THE BEST MOVE OF EACH HOUND 1 - 4
	
	ofstream foxHistory;
	ofstream houndHistory;

//***OUTPUT CONTENT TYPE HEADER
cout << "Content-Type: text/html\n\n";

	//***PROCESS INPUTS
	getline( cin, buffer ); //WHETHER THE PLAYER WILL PLAY FOX OR HOUND
	
	if ( buffer == "0" )
		playerFox = true;
	else if ( buffer == "1" )
		playerHound = true;
	else
		{
		cout << "Game cannot be played. Player type undetermined!\n" << endl; 
		} //END ELSE STATEMENT
	
		//***FIND POSITION OF PLAYERS
		for ( int i = 0; i < 4; i++ )
			{
			getline( cin, buffer );
			houndPositions[i] = strtol(buffer.c_str(), NULL, 10);
			} //END FOR LOOP
			
		getline( cin, buffer );
		foxPosition = strtol(buffer.c_str(), NULL, 10);
	
		if ( playerHound ) //COMPUTER WILL PLAY AS FOX
			{
			row = foxPosition / 4;
			column = foxPosition % 4;
			
			if ( row > 0 && row < 7 ) //FOX IS NOT IN THE TOP OR BOTTOM ROW
				{
				if ( column > 0 && column < 3 ) //FOX IS IN AN INNER COLUMN, EITHER 1 OR 2
					{
					if ( (row % 2) == 0 ) //EVEN ROW
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED IF STATEMENT
					else //ODD ROW
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED ELSE STATEMENT
					} //END 2 NESTED IF STATEMENT
				else //FOX IS ON THE OUTER EDGE COLUMN
					{
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition - 4) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition - 4);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
						
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition + 4) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition + 4);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
						
					if (  (row % 2) == 0 && column == 3 ) //ROW IS EVEN
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
							
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED IF STATEMENT
					else  if ( (row % 2) == 1 && column == 0 ) //ROW IS ODD
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
							
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED ELSE STATEMENT
					} //END 2 NESTED ELSE STATEMENT
				} //END NESTED IF STATEMENT
			else  //FOX IS IN TOP OR BOTTOM ROW, EITHER 0 OR 7
				{
				if ( column > 0 && column < 3 ) //FOXPOSITION IS 29 OR 30
					{
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition - 4) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition - 4);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition - 3) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition - 3);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
					} //END 2 NESTED IF STATEMENT
				else //FOX IS IN A CORNER
					{
					if ( (foxPosition == 31) )
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == 27 )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
							if ( !taken )
								{
								possibleMoves.push_back(27);
								} //END 4 NESTED IF STATEMENT
							else
								taken = false;
						} //END 3 NESTED IF STATEMENT
					else //FOXPOSITION IS 28
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == 24 )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							possibleMoves.push_back(24);
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == 25 )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							possibleMoves.push_back(25);
						else
							taken = false;	
						} //END 3 NESTED ELSE STATEMENT
					} //END 2 NESTED ELSE STATEMENT
				} //END NESTED ELSE STATEMENT
			
			//***CHECK FOR LOSS
		if ( possibleMoves.size() == 0 )
			{
			cout << "Hounds win! The fox cannot move." << endl;
			} //END IF STATEMENT
		
			//***MAKE A MOVE
			//foxPosition = possibleMoves[0]; //temporary move until we get weights added in
			foxPosition = bestfox(possibleMoves, foxPosition, houndPositions[0], houndPositions[1], houndPositions[2], houndPositions[3]);
			
			cout << foxPosition << endl;
			for ( int i = 0; i < 4; i++ )
				{
				cout << houndPositions[i] << endl;
				} //END FOR LOOP
				
			//***WRITE TO FILE
			foxHistory.open("foxHistory.txt", ios::in|ios::app); //OPEN FILE FOR APPENDING
			if ( !foxHistory )
				{
				cout << "Error! File could not be opened for some reason." << endl;
				exit (0);
				} //END IF STATEMENT
			else
				{
				foxHistory << foxPosition << endl;
				for ( int i = 0; i < 4; i++ )
					{
					foxHistory << houndPositions[i] << endl; //WILL OUTPUT ONLY THE NUMBER FOR THE FOX POSITION, STARTING WITH THE FIRST FOX AND CONTINUING TO THE LAST
					} //END FOR LOOP
				} //END ELSE STATEMENT
			foxHistory.close();
			
			//***CHECK FOR WIN
			row = foxPosition / 4;
			if ( row == 0 ) //WIN POSITION
					{
					cout << "The Fox Wins! The Fox says Yay!" << endl;
					} //END NESTED IF STATEMENT
			} //END IF STATEMENT
		
		if ( playerFox ) //COMPUTER WILL PLAY AS HOUND
			{
			//***CHECK FOR LOSS
			if ( foxPosition > 0 && foxPosition < 4 )
				{
				cout << "The Fox Wins! The Fox says Yay!" << endl;
				exit(0);
				} //END IF STATEMENT
			
			for ( int i = 0; i < 4; i++ ) //LOOP THROUGH EACH HOUND
				{
				row = houndPositions[i] / 4;
				column = houndPositions[i] % 4;
				
				if (  row < 7 )
					{
					
				if ( (row % 2) == 0 ) //ROW IS EVEN
					{
					if ( column > 0 && column < 4 ) //COLUMN IS 1, 2, OR 3
						{
						for ( int j = 0; j < 4; j++ )
							{						
							if ( houndPositions[j] == (houndPositions[i] + 4) ) //ANOTHER HOUND IS ALREADY THERE
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( foxPosition == (houndPositions[i] + 4) )
							{
							taken = true;
							} //END IF STATEMENT
						if ( !taken )
							possibleHoundMoves[i].push_back(houndPositions[i] + 4);
						else
							taken = false;
						
						for ( int j = 0; j < 4; j++ )
							{						
							if ( houndPositions[j] == (houndPositions[i] + 3) ) //ANOTHER HOUND IS ALREADY THERE
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( foxPosition == (houndPositions[i] + 3) )
							{
							taken = true;
							} //END IF STATEMENT
						if ( !taken )
							possibleHoundMoves[i].push_back(houndPositions[i] + 3);
						else
							taken = false;
						} //END NESTED IF STATMENT
					else //COLUMN IS 0
						{
						for ( int j = 0; j < 4; j++ )
							{						
							if ( houndPositions[j] == (houndPositions[i] + 4) ) //ANOTHER HOUND IS ALREADY THERE
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( foxPosition == (houndPositions[i] + 4) )
							{
							continue; //CONTINUE TO NEXT HOUND SINCE THERE IS ONLY 1 POSSIBLE MOVE IN COLUMN 0 FROM AN EVEN ROW
							} //END IF STATEMENT
						if ( !taken )
							possibleHoundMoves[i].push_back(houndPositions[i] + 4);
						else
							taken = false;
						} //END NESTED ELSE STATEMENT
					} //END NESTED IF STATEMENT
				else //ROW IS ODD
					{
					if ( column < 3 ) //COLUMN IS 0, 1, OR 2
						{
						for ( int j = 0; j < 4; j++ )
							{						
							if ( houndPositions[j] == (houndPositions[i] + 4) ) //ANOTHER HOUND IS ALREADY THERE
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( foxPosition == (houndPositions[i] + 4) )
							{
							taken = true;
							} //END IF STATEMENT
						if ( !taken )
							possibleHoundMoves[i].push_back(houndPositions[i] + 4);
						else
							taken = false;
						
						for ( int j = 0; j < 4; j++ )
							{						
							if ( houndPositions[j] == (houndPositions[i] + 5) ) //ANOTHER HOUND IS ALREADY THERE
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( foxPosition == (houndPositions[i] + 5) )
							{
							taken = true;
							} //END IF STATEMENT
						if ( !taken )
							possibleHoundMoves[i].push_back(houndPositions[i] + 5);
						else
							taken = false;
						} //END NESTED IF STATEMENT
					else //COLUMN IS 3
						{
						for ( int j = 0; j < 4; j++ )
							{						
							if ( houndPositions[j] == (houndPositions[i] + 4) ) //ANOTHER HOUND IS ALREADY THERE
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( foxPosition == (houndPositions[i] + 4) )
							{
							continue; //CONTINUE TO NEXT HOUND SINCE THERE IS ONLY 1 POSSIBLE MOVE IN COLUMN 3 FROM AN ODD ROW
							} //END IF STATEMENT
						if ( !taken )
							possibleHoundMoves[i].push_back(houndPositions[i] + 4);
						else
							taken = false;
						} //END NESTED ELSE STATEMENT
					} //END NESTED ELSE STATEMENT
				} //END IF STATEMENT
				} //END FOR LOOP
				
			//***MAKE A MOVE
			//houndPositions[2] = possibleHoundMoves[2][0]; //temporary move until we figure out weights
			
			for ( int i = 0; i < 4; i++ ) //POPULATES VECTOR HOLDING THE SINGLE BEST MOVE FOR EACH INDIVIDUAL HOUND
				{
				if ( possibleHoundMoves[i].size() > 0 )
					{
					houndsBestMove.push_back( besthound(possibleHoundMoves[i], foxPosition, houndPositions[0], houndPositions[1], houndPositions[2], houndPositions[3], i) );
					}
				else
					{
					houndsBestMove.push_back(-1);
					}
				} //END FOR LOOP
			
			if ( houndsBestMove[0] != -1 )
				greatestHoundWeight = calchound(houndsBestMove[0], foxPosition, houndPositions[0], houndPositions[1], houndPositions[2], houndPositions[3], 0); //Primer
			else 
				greatestHoundWeight = -10000000;
				
			for ( int i = 1; i < 4; i++ )
				{
				if ( houndsBestMove[i] != -1 )
					houndWeight = calchound(houndsBestMove[i], foxPosition, houndPositions[0], houndPositions[1], houndPositions[2], houndPositions[3], i);
					if ( houndWeight > greatestHoundWeight )
					{
						greatestHoundWeight = houndWeight;
						houndToMove = i;
					}
				 //END IF STATEMENT
				} //END FOR LOOP
				
			houndPositions[houndToMove] = houndsBestMove[houndToMove]; //ACTUAL MOVE
			
			cout << foxPosition << endl;
			for ( int i = 0; i < 4; i++ )
				{
				cout << houndPositions[i] << endl;
				} //END FOR LOOP
			
			//***WRITE TO FILE
			houndHistory.open("houndHistory.txt", ios::in|ios::app); //OPEN FILE FOR APPENDING
			if ( !houndHistory )
				{
				cout << "Error! File could not be opened for some reason." << endl;
				exit (0);
				} //END IF STATEMENT
			else
				{
				houndHistory << foxPosition << endl;
				
				for ( int i = 0; i < 4; i++ )
					{
					houndHistory << houndPositions[i] << endl;
					} //END FOR LOOP
				} //END ELSE STATEMENT
			houndHistory.close();
				
			//***CHECK FOR WIN BY SEEING IF THE FOX CAN MOVE ANYWHERE
			row = foxPosition / 4;
			column = foxPosition % 4;
			
			if ( row > 0 && row < 7 ) //FOX IS NOT IN THE TOP OR BOTTOM ROW
				{
				if ( column > 0 && column < 3 ) //FOX IS IN AN INNER COLUMN, EITHER 1 OR 2
					{
					if ( (row % 2) == 0 ) //EVEN ROW
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED IF STATEMENT
					else //ODD ROW
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 4) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 4);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED ELSE STATEMENT
					} //END 2 NESTED IF STATEMENT
				else //FOX IS ON THE OUTER EDGE COLUMN
					{
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition - 4) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition - 4);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
						
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition + 4) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition + 4);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
						
					if (  (row % 2) == 0 && column == 3 ) //ROW IS EVEN
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
							
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED IF STATEMENT
					else  if ( (row % 2) == 1 && column == 0 ) //ROW IS ODD
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition + 5) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition + 5);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
							
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == (foxPosition - 3) )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							{
							possibleMoves.push_back(foxPosition - 3);
							} //END 3 NESTED IF STATEMENT
						else
							taken = false;
						} //END 3 NESTED ELSE STATEMENT
					} //END 2 NESTED ELSE STATEMENT
				} //END NESTED IF STATEMENT
			else  //FOX IS IN TOP OR BOTTOM ROW, EITHER 0 OR 7
				{
				if ( column > 0 && column < 3 ) //FOXPOSITION IS 29 OR 30
					{
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition - 4) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition - 4);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
					for ( int i = 0; i < 4; i++ )
						{						
						if ( houndPositions[i] == (foxPosition - 3) )
							{
							taken = true;
							break;
							} //END 4 NESTED IF STATEMENT
						} //END FOR LOOP
					if ( !taken )
						{
						possibleMoves.push_back(foxPosition - 3);
						} //END 3 NESTED IF STATEMENT
					else
						taken = false;
					} //END 2 NESTED IF STATEMENT
				else //FOX IS IN A CORNER
					{
					if ( (foxPosition == 31) )
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == 27 )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
							if ( !taken )
								{
								possibleMoves.push_back(27);
								} //END 4 NESTED IF STATEMENT
							else
								taken = false;
						} //END 3 NESTED IF STATEMENT
					else //FOXPOSITION IS 28
						{
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == 24 )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							possibleMoves.push_back(24);
						else
							taken = false;
						for ( int i = 0; i < 4; i++ )
							{						
							if ( houndPositions[i] == 25 )
								{
								taken = true;
								break;
								} //END 4 NESTED IF STATEMENT
							} //END FOR LOOP
						if ( !taken )
							possibleMoves.push_back(25);
						else
							taken = false;	
						} //END 3 NESTED ELSE STATEMENT
					} //END 2 NESTED ELSE STATEMENT
				} //END NESTED ELSE STATEMENT

			if ( possibleMoves.size() == 0 )
				{
				cout << "Hounds win! The fox cannot move." << endl;
				} //END IF STATEMENT
			} //END IF STATEMENT

} //END FUNCTION MAIN