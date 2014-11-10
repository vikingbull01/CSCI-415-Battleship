var cellNumber;
var counter = 0;
var shot1;
var shot2;
var shot3;
var ShipCounter = 0;
var NumberShots;

function startGame(){
	//clears the gameboard to start a new game
	for(var i = 0; i < 100; i++)
		{
			clearBoard(i);
		}
	document.winner = null;
	setMessage("You have 60 seconds to place your ships!!! \n GO!!!!" );
	ShipCounter = 0;
	counter = 0;
}

function setMessage(msg)
{
	document.getElementById("message").innerText = msg;
}

function sendShots(cellNumber)
{
	$eid("s" + cellNumber).style.backgroundColor = "red";
}



function setShipNorth(ev)
{
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber += 30;
	clearSpots(cellNumber);
		$eid("s" + (cellNumber - 10)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 20)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 30)).style.backgroundColor = "black";
		
}

function setShipSouth(ev)
{
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber -= 30;
	clearSpots(cellNumber);
		$eid("s" + (cellNumber + 10)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 20)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 30)).style.backgroundColor = "black";
}	

function setShipWest(ev)
{
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber += 3;
	clearSpots(cellNumber);
		$eid("s" + (cellNumber - 1)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 2)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 3)).style.backgroundColor = "black";
}

function setShipEast(ev)
{	
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber -= 3;
	clearSpots(cellNumber);
		$eid("s" + (cellNumber + 1)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 2)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 3)).style.backgroundColor = "black";
}

function setShipNorthWest(ev)
{	
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber += 33;
		clearSpots(cellNumber);
		$eid("s" + (cellNumber - 11)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 22)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 33)).style.backgroundColor = "black";
}

function setShipNorthEast(ev)
{	
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber += 27;
		clearSpots(cellNumber);
		$eid("s" + (cellNumber - 9)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 18)).style.backgroundColor = "black";
		$eid("s" + (cellNumber - 27)).style.backgroundColor = "black";
}

function setShipSouthEast(ev)
{	
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber -= 33;
	clearSpots(cellNumber);
		$eid("s" + (cellNumber + 11)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 22)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 33)).style.backgroundColor = "black";
}

function setShipSouthWest(ev)
{	
	var str = ev.target.id;
	var cellString = str.substr(1);
	var cellNumber = parseFloat(cellString);
	cellNumber -= 27;
		clearSpots(cellNumber);
		$eid("s" + (cellNumber + 9)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 18)).style.backgroundColor = "black";
		$eid("s" + (cellNumber + 27)).style.backgroundColor = "black";
}

function clearSpots(cellNumber)
{
	var cellNumber;
	var north = (cellNumber - 30);
	var south = (cellNumber + 30);
	var west = (cellNumber - 3);
	var east = (cellNumber + 3);
	var northwest = (cellNumber - 33);
	var northeast = (cellNumber - 27);
	var southwest = (cellNumber + 27);
	var southeast = (cellNumber + 33);
	
	if ((north >= 0) && (north <= 99))
	{
		if ($eid("s" + north).style.backgroundColor == "gray")
		{
			$eid("s" + north).style.backgroundColor = "rgba(0, 0, 0, 0)";
			$eid("s" + north).removeEventListener('mousedown', setShipNorth);
		}
	}
	if ((south >= 0) && (south <= 99))
	{
		if ($eid("s" + south).style.backgroundColor == "gray")
		{
			$eid("s" + south).style.backgroundColor = "rgba(0, 0, 0, 0)";
			$eid("s" + south).removeEventListener('mousedown', setShipSouth);
		}
	}
	if ((west >= 0) && (west <= 99))
	{
		if ($eid("s" + west).style.backgroundColor == "gray")
		{
			if (west % 10 < cellNumber % 10)
			{
				$eid("s" + west).style.backgroundColor = "rgba(0, 0, 0, 0)";
			$eid("s" + west).removeEventListener('mousedown', setShipWest);
			}
		}
	}
	if ((east >= 0) && (east <= 99))
	{
		if ($eid("s" + east).style.backgroundColor == "gray")
		{
			if (east % 10 > cellNumber % 10)
			{
				$eid("s" + east).style.backgroundColor = "rgba(0, 0, 0, 0)";
				$eid("s" + east).removeEventListener('mousedown', setShipEast);
			}
		}
	}
	if ((northwest >= 0) && (northwest <= 99))
	{
		if ($eid("s" + northwest).style.backgroundColor == "gray")
		{
			if (northwest % 10 < cellNumber % 10)
			{
				$eid("s" + northwest).style.backgroundColor = "rgba(0, 0, 0, 0)";
				$eid("s" + northwest).removeEventListener('mousedown', setShipNorthWest);
			}
		}
	}
	if ((northeast >= 0) && (northeast <= 99))
	{
		if ($eid("s" + northeast).style.backgroundColor == "gray")
		{
			if (northeast % 10 > cellNumber % 10)
			{
				$eid("s" + northeast).style.backgroundColor = "rgba(0, 0, 0, 0)";
				$eid("s" + northeast).removeEventListener('mousedown', setShipNorthEast);
			}
		}
	}
	if ((southwest >= 0) && (southwest <= 99))
	{
		if ($eid("s" + southwest).style.backgroundColor == "gray")
		{
			if (southwest % 10 < cellNumber % 10)
			{
				$eid("s" + southwest).style.backgroundColor = "rgba(0, 0, 0, 0)";
				$eid("s" + southwest).removeEventListener('mousedown', setShipSouthWest);
			}
		}
	}
	if ((southeast >= 0) && (southeast <= 99))
	{
		if ($eid("s" + southeast).style.backgroundColor == "gray")
		{
			if (southeast % 10 > cellNumber % 10)
			{
				$eid("s" + southeast).style.backgroundColor = "rgba(0, 0, 0, 0)";
				$eid("s" + southeast).removeEventListener('mousedown', setShipSouthEast);
			}
		}
	}
	$eid("brd").addEventListener('mousedown', placeShipStart);
	counter++;
}

function clearBoard(number)
{
    $eid("s" + number).style.backgroundColor = "rgba(0, 0, 0, 0)";
	$eid("m" + number).style.backgroundColor = "rgba(0, 0, 0, 0)";
}

function $eid(id)
{
return document.getElementById(id);
}

function sendAttack()
{
	if (NumberShots == "1")
	{
		if($eid("s" + shot1).style.backgroundColor == "black")
		{
			$eid("m" + shot1).style.backgroundColor = "red";
			$eid("s" + shot1).style.backgroundColor = "red";
		}
		else
		{
			$eid("m" + shot1).style.backgroundColor = "blue";
			$eid("s" + shot1).style.backgroundColor = "blue";
		}
	}
	else
	{
		if($eid("s" + shot1).style.backgroundColor == "black")
		{
			$eid("m" + shot1).style.backgroundColor = "pink";
			$eid("m" + shot2).style.backgroundColor = "pink";
			$eid("m" + shot2).style.backgroundColor = "pink";
		}
		else if($eid("s" + shot2).style.backgroundColor == "black")
		{
			$eid("m" + shot1).style.backgroundColor = "pink";
			$eid("m" + shot2).style.backgroundColor = "pink";
			$eid("m" + shot2).style.backgroundColor = "pink";
		}
		else if($eid("s" + shot3).style.backgroundColor == "black")
		{
			$eid("m" + shot1).style.backgroundColor = "pink";
			$eid("m" + shot2).style.backgroundColor = "pink";
			$eid("m" + shot2).style.backgroundColor = "pink";
		}
		else
		{
			$eid("m" + shot1).style.backgroundColor = "blue";
			$eid("m" + shot2).style.backgroundColor = "blue";
			$eid("m" + shot3).style.backgroundColor = "blue";
			$eid("s" + shot1).style.backgroundColor = "blue";
			$eid("s" + shot2).style.backgroundColor = "blue";
			$eid("s" + shot3).style.backgroundColor = "blue";
		}
	}
	ShipCounter = 0;
}

function cellClick(ev)
{
var str = ev.target.id;
if (ev.target.id == "brd2")
	alert ("You aren't going to hit anything there!!");
else if ((getComputedStyle(ev.target).backgroundColor == "rgba(0, 0, 0, 0)") || ($eid(str).style.backgroundColor == "pink"))
   {
	if(document.winner != null)
	{
		alert("Player" + document.winner + " already won the game!!!!")
	}
	else
		{
			switch (ShipCounter)
			{
			case 0:
				{
					ev.target.style.backgroundColor = "pink";
					var str = ev.target.id;
					var cellString = str.substr(1);
					shot1 = parseFloat(cellString);
					ShipCounter++;
					NumberShots = 1;
					break;
				}
			case 1:
				{
					ev.target.style.backgroundColor = "pink";
					var str = ev.target.id;
					var cellString = str.substr(1);
					shot2 = parseFloat(cellString);
					ShipCounter++;
					NumberShots = 2;
					break;
				}
			case 2:
				{
					ev.target.style.backgroundColor = "pink";
					var str = ev.target.id;
					var cellString = str.substr(1);
					shot3 = parseFloat(cellString);
					ShipCounter++;
					NumberShots = 3;
					break;
				}
			default:
				alert("You already selected all your shots.");
			}
		}
	}
	else 
   		alert("You already shot there!!!");
}

//****************************************
window.onload = function()
{
var choice = prompt("Are you player 1 or Player 2?");
}

//*********************

function beginAttacks()
{
	if (counter < 4)
		alert("You havent placed all your ships yet!! \n Place all three ships then you can attack")
	else
	$eid("brd2").addEventListener('mousedown', cellClick);
}

function placeShips()
{
	if (counter < 1)
	{
		$eid("brd").addEventListener('mousedown', placeShipStart);
		counter++;
	}
	else 
	alert("Don't click on this button again, place your ships!!. \n If you already placed all three of your ships just wait for the game to start!!");
}

function PlaceShipStart(ev)
{
		var data;
		data = ev.target.id + '|' + eid("s" + 0).style.backgroundColor;
                          
		ajaxRequestPost("test.cgi", data, "text/plain", true, 
		document.getElementById("brd"),document.getElementById("brd"),sucessPlaceShip, webServerError); 
}

function sendTest()
{
	var data;
	data = $eid("s0").style.backgroundColor;
	
	ajaxRequestPost("test.cgi", data, "text/plain", true, document.getElementById("brd"),document.getElementById("brd"), sucessPlaceShip, webServerError);
}

function sucessPlaceShip(color)
{
	alert(" returned values are" + color);
}

function webServerError(status, statusText, area)
	{
		area.innerHTML = "Web Server Error with status number: " + status + " and Status Text: " + statusText;
	}