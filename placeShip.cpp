#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
int placeShipStart();
void seeMoves();

int main()
{
	string 	data;

	ofstream ofl;
	ifstream ifl;
	
	cout<< "Content-Type: text/plain\n\n";
	// This program writes user input into a file.
	
	getline(cin,data);
	placeShipStart(data);
	
}

int placeShipStart(const string &shipPlacement)
{
	if (shipPlacement == "brd")
		alert ("You can't place a ship there!!");
	else if (getComputedStyle("s" + shipPlacement).backgroundColor == "rgba(0, 0, 0, 0)")
	{
		if(document.winner != null)
		{
			alert("Player" + document.winner + " already won the game!!!!");
		}
		else if (counter <= 3)
		{
			string str = shipPlacement;
			string cellString = str.substr(1);
			int cellNumber = parseFloat(cellString);
			seeMoves(cellNumber);
		}
		else
		{
			$eid("brd").removeEventListener('mousedown', placeShipStart);
			alert("All three ships placed. ");
		}
	}
}

void seeMoves(cellNumber)
{
	int north = (cellNumber - 30);
	int south = (cellNumber + 30);
	int west = (cellNumber - 3);
	int east = (cellNumber + 3);
	int northwest = (cellNumber - 33);
	int northeast = (cellNumber - 27);
	int southwest = (cellNumber + 27);
	int southeast = (cellNumber + 33);
		
	if ((north >= 0) && (north <= 99))
	{
		if (($eid("s" + north).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (north + 10)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (north + 20)).style.backgroundColor == "rgba(0, 0, 0, 0)"))
		{
			$eid("s" + north).style.backgroundColor = "gray";
			$eid("s" + north).addEventListener('mousedown', setShipNorth);
			$eid("s" + cellNumber).style.backgroundColor = "black";
		}
	}
	if ((south >= 0) && (south <= 99))
	{
		if (($eid("s" + south).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (south - 10)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (south - 20)).style.backgroundColor == "rgba(0, 0, 0, 0)"))
		{
			$eid("s" + south).style.backgroundColor = "gray";
			$eid("s" + south).addEventListener('mousedown', setShipSouth);
			$eid("s" + cellNumber).style.backgroundColor = "black";
		}
	}
	if ((west >= 0) && (west <= 99))
	{
		if (west % 10 < cellNumber % 10)
		{
			if (($eid("s" + west).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (west + 1)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (west + 2)).style.backgroundColor == "rgba(0, 0, 0, 0)"))
			{
				$eid("s" + west).style.backgroundColor = "gray";
				$eid("s" + west).addEventListener('mousedown', setShipWest);
				$eid("s" + cellNumber).style.backgroundColor = "black";
			}
		}
	}
	if ((east >= 0) && (east <= 99))
	{
		if (east % 10 > cellNumber % 10)
		{
			if (($eid("s" + east).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (east - 1)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (east - 2)).style.backgroundColor == "rgba(0, 0, 0, 0)"))
			{
				$eid("s" + east).style.backgroundColor = "gray";
				$eid("s" + east).addEventListener('mousedown', setShipEast);
				$eid("s" + cellNumber).style.backgroundColor = "black";
			}
		}
	}
	if ((northwest >= 0) && (northwest <= 99))
	{
		if (northwest % 10 < cellNumber % 10)
		{
			if (($eid("s" + northwest).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northwest + 11)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northwest + 22)).style.backgroundColor == "rgba(0, 0, 0, 0)") && (($eid("s" + (northwest + 10)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northwest + 1)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (northwest + 21)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northwest + 12)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (northwest + 23)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northwest + 32)).style.backgroundColor == "rgba(0, 0, 0, 0)")))
			{
				$eid("s" + northwest).style.backgroundColor = "gray";
				$eid("s" + northwest).addEventListener('mousedown', setShipNorthWest);
				$eid("s" + cellNumber).style.backgroundColor = "black";
			}
		}
	}
	if ((northeast >= 0) && (northeast <= 99))
	{
		if (northeast % 10 > cellNumber % 10)
		{
			if (($eid("s" + northeast).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northeast + 9)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northeast + 18)).style.backgroundColor == "rgba(0, 0, 0, 0)") && (($eid("s" + (northeast + 10)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northeast - 1)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (northeast + 19)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northeast + 8)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (northeast + 28)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (northeast + 17)).style.backgroundColor == "rgba(0, 0, 0, 0)")))
			{
				$eid("s" + northeast).style.backgroundColor = "gray";
				$eid("s" + northeast).addEventListener('mousedown', setShipNorthEast);
				$eid("s" + cellNumber).style.backgroundColor = "black";
			}
		}
	}
	if ((southwest >= 0) && (southwest <= 99))
	{	
		if (southwest % 10 < cellNumber % 10)
		{
			if (($eid("s" + southwest).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southwest - 9)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southwest - 18)).style.backgroundColor == "rgba(0, 0, 0, 0)") && (($eid("s" + (southwest - 10)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southwest + 1)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (southwest - 19)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southwest - 8)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (southwest - 28)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southwest - 17)).style.backgroundColor == "rgba(0, 0, 0, 0)")))
			{
				$eid("s" + southwest).style.backgroundColor = "gray";
				$eid("s" + southwest).addEventListener('mousedown', setShipSouthWest);
				$eid("s" + cellNumber).style.backgroundColor = "black";
			}
		}
	}
	if ((southeast >= 0) && (southeast <= 99))
	{	
		if (southeast % 10 > cellNumber % 10)
		{
			if (($eid("s" + southeast).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southeast - 11)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southeast - 22)).style.backgroundColor == "rgba(0, 0, 0, 0)") && (($eid("s" + (southeast - 1)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southeast - 10)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (southeast - 21)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southeast - 12)).style.backgroundColor == "rgba(0, 0, 0, 0)")) && (($eid("s" + (southeast - 32)).style.backgroundColor == "rgba(0, 0, 0, 0)") && ($eid("s" + (southeast - 23)).style.backgroundColor == "rgba(0, 0, 0, 0)")))
			{
				$eid("s" + southeast).style.backgroundColor = "gray";
				$eid("s" + southeast).addEventListener('mousedown', setShipSouthEast);
				$eid("s" + cellNumber).style.backgroundColor = "black";
			}
		}
	}
	if (($eid("s" + north).style.backgroundColor == "gray") || ($eid("s" + south).style.backgroundColor == "gray") || ($eid("s" + east).style.backgroundColor == "gray") || ($eid("s" + west).style.backgroundColor == "gray") || ($eid("s" + northwest).style.backgroundColor == "gray") || ($eid("s" + northeast).style.backgroundColor == "gray") || ($eid("s" + southwest).style.backgroundColor == "gray") || ($eid("s" + southeast).style.backgroundColor == "gray"))
	{
		$eid("brd").removeEventListener('mousedown', placeShipStart);
	}
	else
	{
		alert("Cannot place a ship here, try again!!!!");
	}
}