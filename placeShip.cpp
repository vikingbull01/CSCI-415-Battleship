#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string 	post;

	ofstream ofl;
	ifstream ifl;
	
	cout<< "Content-Type: text/plain\n\n";
	// This program writes user input into a file.
	
	getline(cin,post);
	writeToFile(post);
	readFromFile();
	
}

int readFromFile()
{
	ifstream inputFile;
	string message;
	
	while(getline(inputFile,message))
	{
		cout<< message << "</br>" <<endl;
	}
	
	inputFile.close(); //close the file
	return 0;
}

void writeToFile(const string &newMessage)
{
	ifstream ifl;
	ofstream ofl;
	
	ofstream outputFile;
	// open an outupt file.
	outputFile.open("TicTacChat.txt", ios::out | ios::app);
	
	//write the message to the file.
	outputFile << newMessage <<endl;
	
	//close the file
	outputFile.close();
}