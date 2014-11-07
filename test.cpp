#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string 	tid,
			color;

	ofstream ofl;
	ifstream ifl;
	
	cout<< "Content-Type: text/plain\n\n";
	// This program writes user input into a file.
	getline(cin,tid, '|');
	getline(cin,color);
	cout << color <<endl;
	
}