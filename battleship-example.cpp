#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <vector>

const int empty    = 0;  // contains water
const int occupied = 1;  // contains a ship
const int missed   = 2;  // shot into ocean
const int hit      = 3;  // shot and hit 

using namespace std;

int board[ 10 ][ 10 ]; // Two-dimensional array for gameboard.

void initialize_board( int array1[ 10 ][ 10 ] ) // Function to initialize the gameboard.
{
  // create a blank board   
  for (int x=0; x<10; x++) {
     for (int y=0; y<10; y++) {
          array1[x][y] = occupied;
           }     
     }     
}

void print_board(int array2[10][10]) {
    for(char a = 'A'; a <= 'J'; a++) { //letter coordinates
		cout << setw(5) << a;
    }
    cout << endl;
 
    for(int i = 1; i <= 10; i++) { //number coordinates
        if(i == 10)
		cout << i;
	else
		cout << " " << i ;
 
        for(int j = 0; j < 10 ; j++) {
 
	    if(array2[i][j] == occupied || array2[i][j] == empty){
				cout << setw(5) << " |" ;
			}
            else if(array2[i][j] == missed ) {
                cout << setw(5) << "O|";
			}
	    else if(array2[i][j] == hit ) {
		cout << setw(5) << "X|";
	    }
	}
        cout << "\n";
    }
}

class cShip //Unused so far
{
	int x1, y1, x2, y2; // The position of the front and back of the ship
	int size;
	int damage[]; // for storing the damage. 
	public:
	cShip(int x1, int y1, int x2, int y2, int size); // constructor
	~cShip(); // destructor for destroying the damage array
	bool isDestroyed(); // for polling the destroyed
	bool is3(int x, int y); // for polling the 3		
};

int main()
{
	initialize_board(board);
	determine_player_choice();
	print_board(board);
	
	return 0;
}