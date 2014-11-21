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


/**
Another way of doing the select statement from 2 tables

SELECT black, red, pink, blue, white FROM TableHist1
UNION ALL
SELECT black, red, pink, blue, white FROM TableHist2;


UNION ALL essentially gets the data from similar columns/tables/rows. same thing as what we have done below but more refined.  
**/

//gets the values from the database and updates the board
if (db.doCommand("SELECT TableHist1.black, TableHist2.black, TableHist1.red, TableHist2.red, TableHist1.pink, TableHist2.pink, TableHist1.blue, TableHist2.blue, TableHist1.white, TableHist2.white FROM TableHist1, TableHist2;") == DB_SUCCESS) 
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
//this might be correct, 
//this is the actual delete function:     DELETE * FROM TableHist1, TableHist2;
/*if(db.doCommand("DELETE * FROM TableHist1, TableHist2;") == DB_SUCCESS)
{
db.close();
}*/
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

	if (db.doCommand("INSERT INTO TableHist1 (black, red, pink, blue, white) VALUES ('" + black + "','" + red + "','" + pink + "','" + blue + "','" + white + "');") == DB_SUCCESS) 
  		{
   			// cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  		}
  	else
   		{
   	 		cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   	 		exit(0);
    	}
		
		
//player2HistoryINSERTS
		if (db.doCommand("INSERT INTO TableHist2 (black, red, pink, blue, white) VALUES ('" + black + "','" + red + "','" + pink + "','" + blue + "','" + white + "');") == DB_SUCCESS) 
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