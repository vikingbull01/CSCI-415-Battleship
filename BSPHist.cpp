#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include "sqltdb.hpp"


using namespace std;

//took out the variable, because I do not know if we would need this to update the board.
int refreshBoard()
{
string userName, userPass;
int nRows, nCols;

//This is the reference to the sqltdb.hpp file
sqltWrap db;

//opens the database, whatever we name it
db.open("battleshiphist");

//gets the values from the database and updates the board
if (db.doCommand("SELECT black, red,pink,blue,white FROM TableHist") == DB_SUCCESS) 
  {  	
  nRows = db.numRows();
  cout << "SUCCESS" << endl;
     for (int i = 0; i < nRows; i++)
     {
     	//cout << db[i][0] << " ";
     	cout << db[i][0] << endl; //I assume that we would only need to output the first element of the array for this.
 		//cout << db[i][1] << endl;
     }
  }
  else
   	{
   	 cout << "ERROR\nThere was a problem with our database. Try again later." << endl;
   	 exit(0);
    }
//closes the database
db.close();
}//end refreshBoard Function


int main()
{
ofstream ofl;
ifstream ifl;
string black, red, pink, blue, white, turn;
turn = 1;
sqltWrap db;


srand(time(NULL));
vector<string> messages;

cout << "Content-Type: text/plain\n\n";

//open databsae
db.open("battleshiphist");

//getline(cin,skey);
//getline(cin,userName);
//getline(cin,newField);
//getline(cin,post);
//read in the values from the html
getline(cin,black);
getline(cin,red);
getline(cin,pink);
getline(cin,blue);
getline(cin,white);

//Next, inserts the values into the database
//player1HistoryINSERTS

	if (db.doCommand("INSERT INTO Table1Hist (black, red, pink, blue, white) VALUES ('" + black + "','" + red + "','" + pink + "','" + blue + "','" + white + "')") == DB_SUCCESS) 
  		{
   			// cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  		}
  	else
   		{
   	 		cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   	 		exit(0);
    	}

//after the shots and ships are inserted into the table, the board needs to be refreshed.
refreshBoard();//runs the refreshBoard function

return 0;
}// end main function