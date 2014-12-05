/***********************************************************
move.cpp

CGI script to process request for a secret message.  Message
and password are stored internally
************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/***********************************************************
main
main()

Checks password and returns secret message if correct. If not
correct, returns a stern warning.
************************************************************/

main()
{ string accessType,ibuf;
	
//*** OUTPUT CONTENT TYPE HEADER
cout << "Content-Type: text/plain\n\n";

//*** ENSURE THAT POST METHOD USED TO SEND DATA
accessType = getenv("REQUEST_METHOD");
if (accessType != "POST")
   {
   cout << "ACCESS ERROR: Improper request method used..."
        << "black helicopters dispatched to your location..." << endl;
   exit(0);
   }

  ifstream inputFileR;
inputFileR.open("test.txt");
	getline(inputFileR, ibuf);
	cout << ibuf << '|';
	while (getline(inputFileR, ibuf))
	{
		cout << ibuf << '|';
	}

}