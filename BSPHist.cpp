#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include "randomStr.hpp"
#include "tstamp.hpp"
#include "sqltdb.hpp"
using namespace std;

int refresh(string FireBoard)//fireboard
{
string userName, userPass;
int nRows, nCols;
sqltWrap db;

db.open("battleshiphist");

if (db.doCommand("SELECT Player1Hist.Player1Ships,Player2Ships, Player1Hist.Player1Fire, Player2Fire FROM Player1Hist,Player2Hist WHERE newField = '"+ newField +"'") == DB_SUCCESS) 
  {  	
  nRows = db.numRows();
  cout << "SUCCESS" << endl;
     for (int i = 0; i < nRows; i++)
     {
     	cout << db[i][0] << " ";
 		cout << db[i][1] << endl;
   
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
string post,line, path, username, skey, skey2, randStr,timeStamp, password, future,board,userName,userPass,userNameLog,newField;
int year, mon, day, hour, min, sec, nRows, nCols;
sqltWrap db;

tstamp ts1, ts2;
srand(time(NULL));
vector<string> messages;

cout << "Content-Type: text/plain\n\n";

db.open("battleshiphist");

getline(cin,skey);
getline(cin,userName);
getline(cin,newField);
getline(cin,post);

//player1HistoryINSERTS
if (db.doCommand("INSERT INTO Player1Hist (Player1Ships, Player1Fire) VALUES ('" + p1ships + "','" + p1fire + "')") == DB_SUCCESS) 
  {
   // cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  }
  else
   	{
   	 cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   	 exit(0);
    }
    
//player2HistoryINSERTS
if (db.doCommand("INSERT INTO Player1Hist (Player1Ships, Player1Fire) VALUES ('" + p1ships + "','" + p1fire + "')") == DB_SUCCESS) 
  {
   // cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  }
  else
   	{
   	 cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   	 exit(0);
    }
    
refresh(FireBoard);

return 0;
}