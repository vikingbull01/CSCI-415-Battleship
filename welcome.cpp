/***********************************************************
welcome.cpp

CGI script to output initial wait screen
************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include "infoFromHub.hpp"

using namespace std;


main()
{ string user1, user2;

  infoFromHub hubInf;
  hubInf.loadData(1, 100, 2, 2);
	
user1= hubInf[0];
user2 = hubInf[1];

//*** OUTPUT CONTENT TYPE HEADER
cout << "Content-Type: text/html\n\n";
cout << "<!DOCTYPE html><html><head>";
cout << "<meta charset='UTF-8'> <title> 10x10 </title><style type='text/css'>.square {width:40px;height:40px;text-align:center;font-size: 18pt;font-weight:bold;}.tablediv {border: 2px solid black;padding: 10px 40px; background: gray;width: 470px;border-radius: 25px;margin-left: auto;margin-right: auto;}.descrip{font-family: 'Verdana', Times, serif;}.Title{font-family: 'Verdana', Times, serif;}.messages{font-family: 'Verdana', Times, serif;}</style>";
cout << "<script type='text/javascript' src='js/ajaxReq.js'></script><script src='tictac.js'></script></head><body bgcolor='maroon' onload='startGame()'>";
cout << "<div align='center' class='tablediv'><!-- Aligns all the content in a div with borders.-->";
cout << "<h1 class='Title' style='color: white; text-shadow: 2px 2px black' align='center'>10x10 Tic-Tac Toe</h1>";
cout << "<p class='descrip' align='center' style='color: white; text-shadow: 2px 2px black; font-style: italic;'>";
cout << "Player 1 = Blue | Player 2 = Black </p> <!-- Tells the players what color their markers are.-->";
cout << "<a href='javascript:startGame()'><p align='center'> New Game</p> </a><!-- restarts the game.-->";
cout << "<div class='messages' id='message' style='color: white; text-shadow: 2px 2px black' align='center'>message</div><br/>";
cout << "<div id = 'placeholder' style = 'background-color:white; width: 20px; height: 10px;'></div>";
cout << "<table  bgcolor='white' border ='1' id = 'brd' align = 'center'>";
cout << "<tr><td id='s0' class = 'square' ></td><td id='s1' class = 'square' ></td><td id='s2' class = 'square' ></td><td id='s3' class = 'square' ></td><td id='s4' class = 'square' ></td><td id='s5' class = 'square' ></td><td id='s6' class = 'square' ></td><td id='s7' class = 'square' ></td><td id='s8' class = 'square' ></td><td id='s9' class = 'square'></td></tr>";
cout << "<tr><td id='s10' class = 'square' ></td><td id='s11' class = 'square' ></td><td id='s12' class = 'square' ></td><td id='s13' class = 'square' ></td><td id='s14' class = 'square' ></td><td id='s15' class = 'square' ></td><td id='s16' class = 'square' ></td><td id='s17' class = 'square' ></td><td id='s18' class = 'square' ></td><td id='s19' class = 'square' ></td></tr>";
cout << "<tr><td id='s20' class = 'square' ></td><td id='s21' class = 'square' ></td><td id='s22' class = 'square' ></td><td id='s23' class = 'square' ></td><td id='s24' class = 'square' ></td><td id='s25' class = 'square' ></td><td id='s26' class = 'square' ></td><td id='s27' class = 'square' ></td><td id='s28' class = 'square' ></td><td id='s29' class = 'square' ></td></tr>";
cout << "<tr><td id='s30' class = 'square' ></td><td id='s31' class = 'square' ></td><td id='s32' class = 'square' ></td><td id='s33' class = 'square' ></td><td id='s34' class = 'square' ></td><td id='s35' class = 'square' ></td><td id='s36' class = 'square' ></td><td id='s37' class = 'square' ></td><td id='s38' class = 'square' ></td><td id='s39' class = 'square' ></td></tr>";
cout << "<tr><td id='s40' class = 'square' ></td><td id='s41' class = 'square' ></td><td id='s42' class = 'square' ></td><td id='s43' class = 'square' ></td><td id='s44' class = 'square' ></td><td id='s45' class = 'square' ></td><td id='s46' class = 'square' ></td><td id='s47' class = 'square' ></td><td id='s48' class = 'square' ></td><td id='s49' class = 'square' ></td></tr>";
cout << "<tr><td id='s50' class = 'square' ></td><td id='s51' class = 'square' ></td><td id='s52' class = 'square' ></td><td id='s53' class = 'square' ></td><td id='s54' class = 'square' ></td><td id='s55' class = 'square' ></td><td id='s56' class = 'square' ></td><td id='s57' class = 'square' ></td><td id='s58' class = 'square' ></td><td id='s59' class = 'square' ></td></tr>";
cout << "<tr><td id='s60' class = 'square' ></td><td id='s61' class = 'square' ></td><td id='s62' class = 'square' ></td><td id='s63' class = 'square' ></td><td id='s64' class = 'square' ></td><td id='s65' class = 'square' ></td><td id='s66' class = 'square' ></td><td id='s67' class = 'square' ></td><td id='s68' class = 'square' ></td><td id='s69' class = 'square' ></td></tr>";
cout << "<tr><td id='s70' class = 'square' ></td><td id='s71' class = 'square' ></td><td id='s72' class = 'square' ></td><td id='s73' class = 'square' ></td><td id='s74' class = 'square' ></td><td id='s75' class = 'square' ></td><td id='s76' class = 'square' ></td><td id='s77' class = 'square' ></td><td id='s78' class = 'square' ></td><td id='s79' class = 'square' ></td></tr>";
cout << "<tr><td id='s80' class = 'square' ></td><td id='s81' class = 'square' ></td><td id='s82' class = 'square' ></td><td id='s83' class = 'square' ></td><td id='s84' class = 'square' ></td><td id='s85' class = 'square' ></td><td id='s86' class = 'square' ></td><td id='s87' class = 'square' ></td><td id='s88' class = 'square' ></td><td id='s89' class = 'square' ></td></tr>";
cout << "<tr><td id='s90' class = 'square' ></td><td id='s91' class = 'square' ></td><td id='s92' class = 'square' ></td><td id='s93' class = 'square' ></td><td id='s94' class = 'square' ></td><td id='s95' class = 'square' ></td><td id='s96' class = 'square' ></td><td id='s97' class = 'square' ></td><td id='s98' class = 'square' ></td><td id='s99' class = 'square' ></td></tr>";		
cout << "</table>";
cout <<	"<br><div id='chatmsg' class='chatmsg'  style='overflow:auto; background-color:white; width: 250px; height: 100px; border: 2px solid Black;'></div><br>";
cout << "<input id='post' type='text' name='' size='35'>";
cout << "<button type='button' onclick='chatPost()'>Chat</button>"; 
cout << "<div id='ref' class='ref' style='visibility: hidden;'></div>"; 
cout << "	</div>";
cout << "<div id='area'></div>";
cout << "</body></html>";
}