#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

/*
	Function showMenu- Displays the main menu, and allows a user to select a game.
	Return- A char representing the user's choice.
*/
char showMenu();
/*
	Function- craps: Simulates a game of craps.
*/
void craps();
/*
	Function- scraps: Simulates a game of scraps.
*/
void scraps();
/*
	Function- rockPaperScissors: Simaulates a game of rock, paper, scissors against a computer.
*/
void rockPaperScissors();
/*
	Function- rockPaperScissorsSpock: Simulates a game of rock, paper, scissors, spock against a computer.
*/
void rockPaperScissorsSpock();

/*
	Function- blackJackNew: Simluates a simple game of blackjack.
*/
void blackJackNew();

/*
	Function- hangman: Reads in a list of words from a file, 
	randomly selects one of the words, and allows the user to play hangman with that word
*/
void hangman();