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

int refresh(string newField)//fireboard
{
string userName, userPass;
int nRows, nCols;
sqltWrap db;

db.open("battleshiphist");

if (db.doCommand("SELECT Player1Ships,Player2Ships, Player1Fire, Player2Fire FROM BattleshipHist WHERE newField = '"+ newField +"'") == DB_SUCCESS) 
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

db.open("chatsiteDATABASE");

getline(cin,skey);
getline(cin,userName);
getline(cin,newField);
getline(cin,post);


if (db.doCommand("insert into messages (userID, message,newField) values ('" + userName + "','" + post + "','"+ newField +"')") == DB_SUCCESS) 
  {
   // cout << "SUCCESS\nDebugging test.............................................\n" << endl;
     
  }
  else
   	{
   	 cout << "ERROR\nThere was a problem with our database. Try again later.1" << endl;
   	 exit(0);
    }
    
refresh(newField);

return 0;
}