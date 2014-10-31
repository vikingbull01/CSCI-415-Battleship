#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include "sqltdb.hpp"
#include "sqltdb.cpp"
using namespace std;

//took out the variable, because I do not know if we would need this to update the board.
int refreshBoard()
{
string userName, userPass;
int nRows, nCols;
sqltWrap db;

db.open("battleshiphist");

if (db.doCommand("SELECT Player1Hist.Player1Ships,Player2Ships, Player1Hist.Player1Fire, Player2Fire FROM Player1Hist,Player2Hist") == DB_SUCCESS) 
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
db.close();
}


int main()
{
ofstream ofl;
ifstream ifl;
string p1ships, p1fire, p2ships, p2fire,turn;
turn = 1;
sqltWrap db;


srand(time(NULL));
vector<string> messages;

cout << "Content-Type: text/plain\n\n";

db.open("battleshiphist");

//getline(cin,skey);
//getline(cin,userName);
//getline(cin,newField);
//getline(cin,post);
getline(cin,p1ships);
getline(cin,p1fire);
getline(cin,p2ships);
getline(cin,p2fire);

//player1HistoryINSERTS
//if(turn = 1)
//{
	if (db.doCommand("INSERT INTO Player1Hist (Player1Ships, Player1Fire) VALUES ('" + p1ships + "','" + p1fire + "')") == DB_SUCCESS) 
  		{
   			// cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  		}
  	else
   		{
   	 		cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   	 		exit(0);
    	}
	turn = 2;
//}   

//player2HistoryINSERTS
//else
//{
	if (db.doCommand("INSERT INTO Player2Hist (Player2Ships, Player2Fire) VALUES ('" + p2ships + "','" + p2fire + "')") == DB_SUCCESS) 
  		{
   			// cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  		}
  	else
   		{
   	 		cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   			exit(0);
    	}
	turn = 1;
//}
	
refreshBoard();//runs the refreshBoard function

return 0;
}