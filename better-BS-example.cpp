#include <iostream>
#include <string>
using namespace std;


																				//As a reminder, if we change anything at all, need to check elsewhere.  
																				//Plenty of correlation and borrowing values from other functions.  Which makes sense.  
const int BOARD_WIDTH = 10;														  
const int BOARD_HEIGHT = 10;													//board size right here.  can adjust for fun.
const int SHIP_TYPES = 3;  														//I am taking this as how many ship TYPES.  as in, not the same kind.  making it the same though.  will see.

const char isWATER = 247; //ASCII Character Code
const char isHIT = 'X';
const char isSHIP = 'S';
const char isMISS = '0';

struct POINT {																		//grid coordinates
	//A location on the grid defined
	//by X(horizontal) Y(vertical) coordinates
	int X;
	int Y;
};

struct SHIP {															//This handles the ships characteristics.  As in, the name, length and points on grid.  
	//Ship name
	string name;
	//Total points on the grid
	int length;
	//Coordinates of those points
	POINT onGrid[4]; //0-3 max length of biggest ship   Should only be 4 spots
	//Whether or not those points are a "hit"
	bool hitFlag[4];
}ship[SHIP_TYPES];

struct PLAYER {
	char grid[BOARD_WIDTH][BOARD_HEIGHT];
}player[3]; //Ignore player 0, just using player's 1 & 2

enum DIRECTION {HORIZONTAL,VERTICAL};
struct PLACESHIPS {
	DIRECTION direction;
	SHIP shipType;
};

bool gameRunning = false;

//Functions
void LoadShips();
void ResetBoard();
void DrawBoard(int);
PLACESHIPS UserInputShipPlacement();
bool UserInputAttack(int&,int&,int);
bool GameOverCheck(int);

int main()
{
	LoadShips();
	ResetBoard();

	//"PLACE SHIPS" phase of game
	//Loop through each player... 
	for (int aplyr=1; aplyr<3; ++aplyr)												//this entire function (loop) can be reused.  may need to adjust for the boards though.  
	{
		//Loop through each ship type to place
		for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
		{
			//Display gameboard for player
			system("cls");
			DrawBoard(aplyr);
			//Give instructions
			cout << "\n";
			cout << "INSTRUCTIONS (Player " << aplyr << ")\n\n";
			cout << "You are about to place your ships.  Format should be:\n";
			cout << "Facing (0:Horizontal,1:Vertical), X (top-row) coords, Y (left-side) coords\n";
			cout << "Example: 0 7 2    This would place a ship beginning at X:7 Y:2 going horizontal\n\n";
			cout << "Ship to place: " << ship[thisShip].name << " which has a length of " << ship[thisShip].length  << "\n";
			cout << "Where do you want it placed? ";
			
			//Get input from user and loop until good data is returned
			PLACESHIPS aShip;
			aShip.shipType.onGrid[0].X = -1;
			while (aShip.shipType.onGrid[0].X == -1)
			{
				aShip = UserInputShipPlacement();
			}

			//Combine user data with "this ship" data
			aShip.shipType.length = ship[thisShip].length;
			aShip.shipType.name = ship[thisShip].name;

			//Add the FIRST grid point to the current player's game board
			player[aplyr].grid[aShip.shipType.onGrid[0].X][aShip.shipType.onGrid[0].Y] = isSHIP;

			//Determine ALL grid points based on length and direction
			for (int i=1; i<aShip.shipType.length; ++i)
			{
				if (aShip.direction == HORIZONTAL){
					aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i-1].X+1;
					aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i-1].Y; }
				if (aShip.direction == VERTICAL){
					aShip.shipType.onGrid[i].Y = aShip.shipType.onGrid[i-1].Y+1;
					aShip.shipType.onGrid[i].X = aShip.shipType.onGrid[i-1].X; }

				//Add the REMAINING grid points to our current players game board
				player[aplyr].grid[aShip.shipType.onGrid[i].X][aShip.shipType.onGrid[i].Y] = isSHIP;
			}
			//Loop back through each ship type
		}
		//Loop back through each player
	}

	//********* FINISHED WITH "PLACE SHIPS" PHASE *********************************
	//*****************************************************************************

	//Ready to play the game
	gameRunning = true;
	int thisPlayer = 1;
	do {															//This function can be extremely useful if we use cpp instead of JS.
		//Because we are ATTACKING now, the 
		//opposite players board is the display board					THIS AREA MAY NOT AGREE WITH OUR SETUP FOR BOARDS!!!!!
		int enemyPlayer;
		if (thisPlayer == 1) enemyPlayer = 2;
		if (thisPlayer == 2) enemyPlayer = 1;
		system("cls");
		DrawBoard(enemyPlayer);

		//Get attack coords from this player
		bool goodInput = false;
		int x,y;
		while (goodInput == false) {
			goodInput = UserInputAttack(x,y,thisPlayer);
		}

		//Check board; if a ship is there, set as HIT.. otherwise MISS
		if (player[enemyPlayer].grid[x][y] == isSHIP) player[enemyPlayer].grid[x][y] = isHIT;
		if (player[enemyPlayer].grid[x][y] == isWATER) player[enemyPlayer].grid[x][y] = isMISS;

		//Check to see if the game is over
		//If 0 is returned, nobody has won yet
		int aWin = GameOverCheck(enemyPlayer);
		if (aWin != 0) {
			gameRunning = false;
			break;
		}
		//Alternate between each player as we loop back around
		thisPlayer = (thisPlayer == 1) ? 2 : 1;
	} while (gameRunning);

	system("cls");
	cout << "\n\nCONGRATULATIONS!!!  PLAYER " << thisPlayer << " HAS WON THE GAME!\n\n\n\n";

	system("pause");
	return 0;
}


/*bool GameOverCheck(int enemyPLAYER)															//Already have this function in JS
{
	bool winner = true;
	//Loop through enemy board
	for (int w=0; w<BOARD_WIDTH; ++w){
			for (int h=0; h<BOARD_HEIGHT; ++h){
				//If any ships remain, game is NOT over
				if (player[enemyPLAYER].grid[w][h] = isSHIP)					//Again, due to how boards are set up, this may create problems.  We also have this done in JS anyway.
					{															//so don't worry
						winner = false;
						return winner;
					}
		}}
	//If we get here, somebody won, game over!
	return winner;
}*/


bool UserInputAttack(int& x, int& y, int theplayer)													//This function is good.  
{
	cout << "\nPLAYER " << theplayer << ", ENTER COORDINATES TO ATTACK: ";
	bool goodInput = false;
	cin >> x >> y;
	if (x<0 || x>=BOARD_WIDTH) return goodInput;
	if (y<0 || y>=BOARD_HEIGHT) return goodInput;
	goodInput = true; 
	return goodInput;
}

PLACESHIPS UserInputShipPlacement()																	//Also good.  PLACE SHIPS funtion here
{
	int d, x, y;
	PLACESHIPS tmp;
	//Using this as a bad return
	tmp.shipType.onGrid[0].X = -1;
	//Get 3 integers from user
	cin >> d >> x >> y;
	if (d!=0 && d!=1) return tmp;
	if (x<0 || x>=BOARD_WIDTH) return tmp;
	if (y<0 || y>=BOARD_HEIGHT) return tmp;
	//Good data
	tmp.direction = (DIRECTION)d;
	tmp.shipType.onGrid[0].X = x;
	tmp.shipType.onGrid[0].Y = y;
	return tmp;
}

void LoadShips()
{
	//Sets the default data for the ships
	//we plan to include in the game
	//IMPORTANT!! > MUST MATCH SHIP_TYPES -Default=5 (0-4)
	ship[0].name = "Battleship"; ship[0].length = 4;												//Set to one ship as specified on moodle. 
	ship[1name = "Battleship"; ship[1].length = 4;
	ship[2].name = "Battleship"; ship[2].length = 4;
}																									//Battleship.  4 for length.  3 ships
void ResetBoard()
{
	//Loop through each player																	Already set to clear BOTH boards so will use this.  JS one only does one board.
	for (int plyr=1; plyr<3; ++plyr)
	{
		//For each grid point, set contents to 'water'
		for (int w=0; w<BOARD_WIDTH; ++w){
			for (int h=0; h<BOARD_HEIGHT; ++h){
				player[plyr].grid[w][h] = isWATER;
		}}
		//Loop back to next player
	}
}

/*void DrawBoard(int thisPlayer)//													This function could be deleted but keeping for now.  may be useful.  		
{
	//Draws the board for a player (thisPlayer)									
	cout << "PLAYER " << thisPlayer << "'s GAME BOARD\n";
	cout << "----------------------\n";

	//Loop through top row (board_width) and number columns
	cout << "   ";
	for (int w=0; w<BOARD_WIDTH; ++w) {
		if (w < 10)
			//Numbers only 1 character long, add two spaces after
			cout << w << "  ";
		else if (w >= 10)
			//Numbers 2 characters long, add only 1 space after
			cout << w << " ";
	}*/
	cout << "\n";

	/*//Loop through each grid point and display to console						This function could also be deleted.  Keeping for now until html works.  
	for (int h=0; h<BOARD_HEIGHT; ++h){
		for (int w=0; w<BOARD_WIDTH; ++w){
			
			//If this is the FIRST (left) grid point, number the grid first
			if (w==0) cout << h << " ";
			//If h was 1 character long, add an extra space to keep numbers lined up
			if (w<10 && w==0) cout << " ";
			//Display contents of this grid (if game isn't running yet, we are placing ships
			//so display the ships
			if (gameRunning == false) cout << player[thisPlayer].grid[w][h] << "  ";
			//Don't show ships, BUT show damage if it's hit
			if (gameRunning == true && player[thisPlayer].grid[w][h] != isSHIP) 
			{cout << player[thisPlayer].grid[w][h] << "  ";}
			else if (gameRunning == true && player[thisPlayer].grid[w][h] == isSHIP)
			{cout << isWATER << "  ";}	
			//If we have reached the border.. line feed
			if (w == BOARD_WIDTH-1) cout << "\n";
		}
	}*/
}