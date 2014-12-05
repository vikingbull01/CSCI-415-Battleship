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
cout << "<head><style>.square {width:40px;height:40px;text-align:center;font-size: 18pt;font-weight:bold;}";
cout << ".tablediv {border: 2px solid black;padding: 10px 40px; background: gray;width: 1000px;border-radius: 25px;margin-left: auto;margin-right: auto;}";
cout << ".descrip{	font-family: 'Verdana', Times, serif;}";
cout << ".Title{font-family: 'Verdana', Times, serif;}";
cout << ".messages{font-family: 'Verdana', Times, serif;}";
cout << ".tdBoard{width: 500px;}";
cout << "</style>";
cout << "<script type='text/javascript' src='ajaxReq.js'></script>";
cout << "<script src = 'Battle.js'></script>";
cout << "</head>";
cout << "<body bgcolor='maroon' onload='startGame()'>";
cout << "<div  class='tablediv'><!-- Aligns all the content in a div with borders.-->";
cout << "<h1 class='Title' style='color: white; text-shadow: 2px 2px black' align='center'>Realtime Battleship</h1>";
cout << "<p class='descrip' align='center' style='color: white; text-shadow: 2px 2px black; font-style: italic;'>";
cout << "Left Board = Your Ships | Right Board = Your Attacks </p> <!-- Tells the players what color their markers are.-->";
cout << "<a href='javascript:startGame()'><p align='center'> New Game</p> </a><!-- restarts the game.-->";
cout << "<div class='messages' id='message' style='color: white; text-shadow: 2px 2px black' align='center'>message</div>"; 
cout << "<br />";
cout << "<button id='update'>update</button>";
cout << "<table><tr><td class='tdBoard'>";
cout << "<table  bgcolor='white' border ='1' style='width:500px;' id = 'brd'>";
cout << "<th class = 'square'></th> <th class = 'square'>A</th> <th class = 'square'>B</th><th class = 'square'>C</th><th class = 'square'>D</th><th class = 'square'>E</th><th class = 'square'>F</th><th class = 'square'>G</th><th class = 'square'>H</th><th class = 'square'>I</th><th class = 'square'>J</th>";
cout << "<tr><td id='1' class = 'square'>1</td><td id='s0' class = 'square' ></td><td id='s1' class = 'square' ></td><td id='s2' class = 'square' ></td><td id='s3' class = 'square' ></td><td id='s4' class = 'square' ></td><td id='s5' class = 'square' ></td><td id='s6' class = 'square' ></td><td id='s7' class = 'square' ></td><td id='s8' class = 'square' ></td><td id='s9' class = 'square' ></td></tr>";
cout << "<tr><td id='2' class = 'square'>2</td><td id='s10' class = 'square' ></td><td id='s11' class = 'square' ></td><td id='s12' class = 'square' ></td><td id='s13' class = 'square' ></td><td id='s14' class = 'square' ></td><td id='s15' class = 'square' ></td><td id='s16' class = 'square' ></td><td id='s17' class = 'square' ></td><td id='s18' class = 'square' ></td><td id='s19' class = 'square' ></td></tr>";
cout << "<tr><td id='3' class = 'square'>3</td><td id='s20' class = 'square' ></td><td id='s21' class = 'square' ></td><td id='s22' class = 'square' ></td><td id='s23' class = 'square' ></td><td id='s24' class = 'square' ></td><td id='s25' class = 'square' ></td><td id='s26' class = 'square' ></td><td id='s27' class = 'square' ></td><td id='s28' class = 'square' ></td><td id='s29' class = 'square' ></td></tr>";
cout << "<tr><td id='4' class = 'square'>4</td> <td id='s30' class = 'square' ></td><td id='s31' class = 'square' ></td><td id='s32' class = 'square' ></td><td id='s33' class = 'square' ></td><td id='s34' class = 'square' ></td><td id='s35' class = 'square' ></td><td id='s36' class = 'square' ></td><td id='s37' class = 'square' ></td><td id='s38' class = 'square' ></td><td id='s39' class = 'square' ></td></tr>";
cout << "<tr><td id='5' class = 'square'>5</td><td id='s40' class = 'square' ></td><td id='s41' class = 'square' ></td><td id='s42' class = 'square' ></td><td id='s43' class = 'square' ></td><td id='s44' class = 'square' ></td><td id='s45' class = 'square' ></td><td id='s46' class = 'square' ></td><td id='s47' class = 'square' ></td><td id='s48' class = 'square' ></td><td id='s49' class = 'square' ></td></tr>";
cout << "<tr><td id='6' class = 'square'>6</td><td id='s50' class = 'square' ></td><td id='s51' class = 'square' ></td><td id='s52' class = 'square' ></td><td id='s53' class = 'square' ></td><td id='s54' class = 'square' ></td><td id='s55' class = 'square' ></td><td id='s56' class = 'square' ></td><td id='s57' class = 'square' ></td><td id='s58' class = 'square' ></td><td id='s59' class = 'square' ></td></tr>";
cout << "<tr><td id='7' class = 'square'>7</td><td id='s60' class = 'square' ></td><td id='s61' class = 'square' ></td><td id='s62' class = 'square' ></td><td id='s63' class = 'square' ></td><td id='s64' class = 'square' ></td><td id='s65' class = 'square' ></td><td id='s66' class = 'square' ></td><td id='s67' class = 'square' ></td><td id='s68' class = 'square' ></td><td id='s69' class = 'square' ></td></tr>";
cout << "<tr><td id='8' class = 'square'>8</td><td id='s70' class = 'square' ></td><td id='s71' class = 'square' ></td><td id='s72' class = 'square' ></td><td id='s73' class = 'square' ></td><td id='s74' class = 'square' ></td><td id='s75' class = 'square' ></td><td id='s76' class = 'square' ></td><td id='s77' class = 'square' ></td><td id='s78' class = 'square' ></td><td id='s79' class = 'square' ></td></tr>";
cout << "<tr><td id='9' class = 'square'>9</td><td id='s80' class = 'square' ></td><td id='s81' class = 'square' ></td><td id='s82' class = 'square' ></td><td id='s83' class = 'square' ></td><td id='s84' class = 'square' ></td><td id='s85' class = 'square' ></td><td id='s86' class = 'square' ></td><td id='s87' class = 'square' ></td><td id='s88' class = 'square' ></td><td id='s89' class = 'square' ></td></tr>";
cout << "<tr><td id='10' class = 'square'>10</td><td id='s90' class = 'square' ></td><td id='s91' class = 'square' ></td><td id='s92' class = 'square' ></td><td id='s93' class = 'square' ></td><td id='s94' class = 'square' ></td><td id='s95' class = 'square' ></td><td id='s96' class = 'square' ></td><td id='s97' class = 'square' ></td><td id='s98' class = 'square' ></td><td id='s99' class = 'square' ></td></tr>";
cout << "</table></td>";
cout << "<td class='tdBoard'><table  bgcolor='white' border ='1' style='width:500px;' id = 'brd2'>";
cout << "<th class = 'square'></th> <th class = 'square'>A</th> <th class = 'square'>B</th><th class = 'square'>C</th><th class = 'square'>D</th><th class = 'square'>E</th><th class = 'square'>F</th><th class = 'square'>G</th><th class = 'square'>H</th><th class = 'square'>I</th><th class = 'square'>J</th>";
cout << "<tr><td id='1' class = 'square'>1</td>	<td id='m0' class = 'square' ></td><td id='m1' class = 'square' ></td><td id='m2' class = 'square' ></td><td id='m3' class = 'square' ></td><td id='m4' class = 'square' ></td><td id='m5' class = 'square' ></td><td id='m6' class = 'square' ></td><td id='m7' class = 'square' ></td><td id='m8' class = 'square' ></td><td id='m9' class = 'square' ></td></tr>";
cout << "<tr><td id='2' class = 'square'>2</td><td id='m10' class = 'square' ></td><td id='m11' class = 'square' ></td><td id='m12' class = 'square' ></td><td id='m13' class = 'square' ></td><td id='m14' class = 'square' ></td><td id='m15' class = 'square' ></td><td id='m16' class = 'square' ></td><td id='m17' class = 'square' ></td><td id='m18' class = 'square' ></td><td id='m19' class = 'square' ></td></tr>";
cout << "<tr><td id='3' class = 'square'>3</td><td id='m20' class = 'square' ></td><td id='m21' class = 'square' ></td><td id='m22' class = 'square' ></td><td id='m23' class = 'square' ></td><td id='m24' class = 'square' ></td><td id='m25' class = 'square' ></td><td id='m26' class = 'square' ></td><td id='m27' class = 'square' ></td><td id='m28' class = 'square' ></td><td id='m29' class = 'square' ></td></tr>";
cout << "<tr><td id='4' class = 'square'>4</td><td id='m30' class = 'square' ></td><td id='m31' class = 'square' ></td><td id='m32' class = 'square' ></td><td id='m33' class = 'square' ></td><td id='m34' class = 'square' ></td><td id='m35' class = 'square' ></td><td id='m36' class = 'square' ></td><td id='m37' class = 'square' ></td><td id='m38' class = 'square' ></td><td id='m39' class = 'square' ></td></tr>";
cout << "<tr><td id='5' class = 'square'>5</td><td id='m40' class = 'square' ></td><td id='m41' class = 'square' ></td><td id='m42' class = 'square' ></td><td id='m43' class = 'square' ></td><td id='m44' class = 'square' ></td><td id='m45' class = 'square' ></td><td id='m46' class = 'square' ></td><td id='m47' class = 'square' ></td><td id='m48' class = 'square' ></td><td id='m49' class = 'square' ></td></tr>";
cout << "<tr><td id='6' class = 'square'>6</td> <!-- Just a reference for playing the game--><td id='m50' class = 'square' ></td><td id='m51' class = 'square' ></td><td id='m52' class = 'square' ></td><td id='m53' class = 'square' ></td><td id='m54' class = 'square' ></td><td id='m55' class = 'square' ></td><td id='m56' class = 'square' ></td><td id='m57' class = 'square' ></td><td id='m58' class = 'square' ></td><td id='m59' class = 'square' ></td></tr>";
cout << "<tr><td id='7' class = 'square'>7</td> <!-- Just a reference for playing the game--><td id='m60' class = 'square' ></td><td id='m61' class = 'square' ></td><td id='m62' class = 'square' ></td><td id='m63' class = 'square' ></td><td id='m64' class = 'square' ></td><td id='m65' class = 'square' ></td><td id='m66' class = 'square' ></td><td id='m67' class = 'square' ></td><td id='m68' class = 'square' ></td><td id='m69' class = 'square' ></td></tr>";
cout << "<tr><td id='8' class = 'square'>8</td><td id='m70' class = 'square' ></td><td id='m71' class = 'square' ></td><td id='m72' class = 'square' ></td><td id='m73' class = 'square' ></td><td id='m74' class = 'square' ></td><td id='m75' class = 'square' ></td><td id='m76' class = 'square' ></td><td id='m77' class = 'square' ></td><td id='m78' class = 'square' ></td><td id='m79' class = 'square' ></td></tr>";
cout << "<tr><td id='9' class = 'square'>9</td> <!-- Just a reference for playing the game--><td id='m80' class = 'square' ></td><td id='m81' class = 'square' ></td><td id='m82' class = 'square' ></td><td id='m83' class = 'square' ></td><td id='m84' class = 'square' ></td><td id='m85' class = 'square' ></td><td id='m86' class = 'square' ></td><td id='m87' class = 'square' ></td><td id='m88' class = 'square' ></td><td id='m89' class = 'square' ></td></tr>";
cout << "<tr><td id='10' class = 'square'>10</td> <!-- Just a reference for playing the game--><td id='m90' class = 'square' ></td><td id='m91' class = 'square' ></td><td id='m92' class = 'square' ></td><td id='m93' class = 'square' ></td><td id='m94' class = 'square' ></td><td id='m95' class = 'square' ></td><td id='m96' class = 'square' ></td><td id='m97' class = 'square' ></td><td id='m98' class = 'square' ></td><td id='m99' class = 'square' ></td></tr>";
cout << "</table></td></tr>";
cout << "<tr><td><h4 style='color: white; text-shadow: 2px 2px black; font-style: italic;' class='descrip'>Move Units</h4><button type='button' onclick='placeShips()'>Place Ships</button> </td>";
cout << "<td><h4 style='color: white; text-shadow: 2px 2px black; font-style: italic;' class='descrip'>Send Attacks:</h4> ";
cout << "<button type='button' onclick='sendAttack()'>Fire!</button> ";
cout << "<button type = 'button' onclick = 'sendShipData()'>Test</button></td></tr>";
cout << "</table>";
cout << "<div id='area'></div>";
cout << "</body>";
cout << "</html>";
}