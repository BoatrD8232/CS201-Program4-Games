#include "Functions.h"

char showMenu() {
	// The string is used to check input.
	string check = "CSREBHQ";
	// Stores the user's choice.
	char choice = '0';
	// The while loop loops until valid input is entered.
	while (check.find_first_of(choice) == string::npos) {
		cout << "Your Games List" << endl;
		cout << "C - Craps" << endl;
		cout << "S - Scraps" << endl;
		cout << "R - Rock, Paper, Scissors" << endl;
		cout << "E - Rock, Paper, Scissors, Spock" << endl;
		cout << "B - Blackjack" << endl;
		cout << "H - Hangman" << endl;
		cout << "Q - Quit" << endl;
		cout << "What game would you like to play? ";
		cin >> choice;
		choice = toupper(choice);
		if (check.find_first_of(choice) == string::npos) {
			cout << "Invalid input." << endl;
		}
	}
	return choice;
}
void craps() {
	srand(time(0));
	// The 1st and 2nd dice, the total of the die, and the point used in the game.
	int d1, d2, total, point;
	// The total money owned and the value of the wager.
	float bank = 50, bet = 60;
	// Controls if the game repeats.
	char contChar = 'Y';
	// Stores user input that will be converted into a wager.
	string input;
	cout << "You are now playing craps." << endl;
	// The outher loop repeats the game until the user quits or bankruptcy.
	while (contChar != 'N' && bank > 0) {
		// This do while loop validates the user inputted bet.
		do {
			try {
				cout << "You have: $" << fixed << setprecision(2) << bank << ". Please enter your bet: ";
				cin >> input;
				bet = stof(input);
				if (bet > bank) {
					cout << "You cannot bet more than you have." << endl;
				}
				else if (bet < 0) {
					cout << "Cannot bet negative numbers" << endl;
				}
			}
			catch (invalid_argument) {
				cout << "Please enter a valid number." << endl;
			}
		} while (bet > bank || bet < 0);
		// Rolls the die, sets the total, and checks if a point is needed.
		d1 = rand() % 6 + 1;
		d2 = rand() % 6 + 1;
		total = d1 + d2;
		cout << "You rolled " << d1 << " + " << d2 << " = " << total << endl;
		if (total == 7 || total == 11) {
			bank += bet;
			cout << "You won. You now have $" << bank << endl;
		}
		else if (total == 2 || total == 3 || total == 12) {
			bank -= bet;
			cout << "You lost. You now have $" << bank << endl;
		}
		// If a point is needed, makes the point and rolls until win or loss.
		else {
			point = total;
			cout << "\tPoint is : " << point << endl;
			do {
				d1 = rand() % 6 + 1;
				d2 = rand() % 6 + 1;
				total = d1 + d2;
				cout << "\tYou rolled " << d1 << " + " << d2 << " = " << total << endl;
			} while (total != point && total != 7);
			if (total == point) {
				bank += bet;
				cout << "You won. You now have $" << bank << endl;
			}
			else {
				bank -= bet;
				cout << "You lost. You now have $" << bank << endl;
			}
		}
		// Checks if bank is small enough to be considered zero.
		if ((!bank > 0)) {
			cout << "You are out of money. The game is over." << endl;
		}
		else {
			cout << "Would you like to play again? (Y/N)";
			cin >> contChar;
			contChar = toupper(contChar);
		}
	}
}

void scraps() {
	srand(time(0));
	// The 1st, 2nd, and 3rd dice, the total of the die, and the point used in the game.
	int d1, d2, d3, total, point;
	// The total money owned and the value of the wager.
	float bank = 50, bet = 60;
	// Controls if the game repeats.
	char contChar = 'Y';
	// Stores user input that will be converted into a wager.
	string input;
	cout << "You are now playing scraps." << endl;
	// The outher loop repeats the game until the user quits or bankruptcy.
	while (contChar != 'N' && bank > 0) {
		// This do while loop validates the user inputted bet.
		do {
			try {
				cout << "You have: $" << fixed << setprecision(2) << bank << ". Please enter your bet: ";
				cin >> input;
				bet = stof(input);
				if (bet > bank) {
					cout << "You cannot bet more than you have" << endl;
				}
				else if (bet < 0) {
					cout << "Cannot bet negative numbers" << endl;
				}
			}
			catch (invalid_argument) {
				cout << "Please enter a valid number." << endl;
			}
		} while (bet > bank || bet < 0);
		// Rolls the die, sets the total, and checks if a point is needed.
		d1 = rand() % 8 + 1;
		d2 = rand() % 8 + 1;
		d3 = rand() % 8 + 1;
		total = d1 + d2 + d3;
		cout << "\tYou rolled " << d1 << " + " << d2 << " + "
			<< d3 << " = " << total << endl;
		if (total == 9 || total == 10 || total == 14) {
			bank += bet;
			cout << "You won. You now have $" << bank << endl;
		}
		else if (d1 == 8 || d2 == 8 || d3 == 8) {
			bank += bet;
			cout << "You won. You now have $" << bank << endl;
		}
		else if (total == 8 || total == 20 || total == 23 || total == 24) {
			bank -= bet;
			cout << "You lost. You now have $" << bank << endl;
		}
		else if (d1 == 1 || d2 == 1 || d3 == 1) {
			bank -= bet;
			cout << "You lost. You now have $" << bank << endl;
		}
		// If a point is needed, makes the point and rolls until win or loss.
		else {
			point = total;
			cout << "\tPoint is : " << point << endl;
			do {
				d1 = rand() % 8 + 1;
				d2 = rand() % 8 + 1;
				d3 = rand() % 8 + 1;
				total = d1 + d2 + d3;
				cout << "\tYou rolled " << d1 << " + " << d2 << " + " 
					 << d3 <<  " = " << total << endl;
			} while (total != point && total != 15 && d1 != 8 && d2 != 8 && d3 != 8);
			if (total == point) {
				bank += bet;
				cout << "You won. You now have $" << bank << endl;
			}
			else {
				bank -= bet;
				cout << "You lost. You now have $" << bank << endl;
			}
		}
		if ((!bank > 0)) {
			cout << "You are out of money. The game is over." << endl;
		}
		else {
			cout << "Would you like to play again? (Y/N)";
			cin >> contChar;
			contChar = toupper(contChar);
		}
	}
}

void rockPaperScissors() {
	srand(time(0));
	// Stores the user's and computer's play as an int.
	int userChoice, compChoice;
	string choices[3] = { "rock", "paper", "scissors"};
	// The user input to be converted to an int.
	string input;
	// Controls if the game repeats.
	char contChar = 'Y';
	cout << "You are now playing rock, paper, scissors" << endl;
	// The outher loop repeats the game until the user quits.
	while (contChar != 'N') {
		// Creates the computers play.
		compChoice = rand() % 3;
		userChoice = -1;
		// This loop continues until the user enters proper input.
		while (userChoice < 0) {
			try {
				cout << "Please enter the number of your choice:" << endl;
				for (int i = 0; i < 3; i++) {
					cout << i + 1 << ": " << choices[i] << endl;
				}
				cin >> input;
				userChoice = stoi(input);
				userChoice--;
				if (userChoice < 0 || userChoice > 2) {
					throw invalid_argument("Out of range");
				}
			}
			catch (invalid_argument) {
				cout << "Please enter 1, 2, or 3." << endl;
				userChoice = -1;
			}
		}
		// This branching structure checks if the user wins or loses.
		if (((userChoice + 2) % 3) == compChoice) {
			cout << "You chose: " << choices[userChoice]
				 << ", The computer chose: " << choices[compChoice] << endl;
			cout << "You won" << endl;
		}
		else if (((userChoice + 1) % 3) == compChoice) {
			cout << "You chose: " << choices[userChoice]
				<< ", The computer chose: " << choices[compChoice] << endl;
			cout << "The computer won" << endl;
		}
		else {
			cout << "You chose: " << choices[userChoice]
				<< ", The computer chose: " << choices[compChoice] << endl;
			cout << "Tie" << endl;
		}
		cout << "Play again? Y/N" << endl;
		cin >> contChar;
		contChar = toupper(contChar);
	}
}

void rockPaperScissorsSpock() {
	srand(time(0));
	// Stores the user's and computer's play as an int.
	int userChoice, compChoice;
	string choices[4] = { "rock", "paper", "scissors", "spock"};
	// The user input to be converted to an int.
	string input;
	// Controls if the game repeats.
	char contChar = 'Y';
	cout << "You are now playing rock, paper, scissors, spock" << endl;
	// The outher loop repeats the game until the user quits.
	while (contChar != 'N') {
		srand(time(0));
		// Creates the computers play.
		compChoice = rand() % 4;
		userChoice = -1;
		// This loop continues until the user enters proper input.
		while (userChoice < 0) {
			try {
				cout << "Please enter the number of your choice:" << endl;
				for (int i = 0; i < 4; i++) {
					cout << i + 1 << ": " << choices[i] << endl;
				}
				cin >> input;
				userChoice = stoi(input);
				userChoice--;
				if (userChoice < 0 || userChoice > 3) {
					throw invalid_argument("Out of range");
				}
			}
			catch (invalid_argument) {
				cout << "Please enter 1, 2, 3, or 4." << endl;
				userChoice = -1;
			}
		}
		// The outer checks if the input is rock or scissors. 
		// Those choices only have one victory match-up, so they can be handled with the same logic.
		if (userChoice == 0 || userChoice == 2) {
			// This branching structure checks if the user wins or loses.
			if ((userChoice + 2) % 3 == compChoice) {
				cout << "You chose: " << choices[userChoice]
					<< ", The computer chose: " << choices[compChoice] << endl;
				cout << "You won" << endl;
			}
			else if (userChoice == compChoice) {
				cout << "You chose: " << choices[userChoice]
					<< ", The computer chose: " << choices[compChoice] << endl;
				cout << "Tie" << endl;
			}
			else {
				cout << "You chose: " << choices[userChoice]
					<< ", The computer chose: " << choices[compChoice] << endl;
				cout << "The computer won" << endl;
			}
		}
		// Paper and spock both have 2 winning match-ups, so again they can be handled with the same logic.
		else {
			// This branching structure checks if the user wins or loses.
			if ((userChoice + 1) % 3 == compChoice) {
				cout << "You chose: " << choices[userChoice]
					<< ", The computer chose: " << choices[compChoice] << endl;
				cout << "The computer won" << endl;
			}
			else if (userChoice == compChoice) {
				cout << "You chose: " << choices[userChoice]
					<< ", The computer chose: " << choices[compChoice] << endl;
				cout << "Tie" << endl;
			}
			else {
				cout << "You chose: " << choices[userChoice]
					<< ", The computer chose: " << choices[compChoice] << endl;
				cout << "You won" << endl;
			}
		}
		cout << "Play again? Y/N" << endl;
		cin >> contChar;
		contChar = toupper(contChar);
	}
}
/*
	class - Player: simulates a blackjack player and stores things like their current cards.
*/
class player {
	private:
		// The current cards held by the player.
		// cards[i][0] is the suit of the ith card.
		// cards[i][1] is the face value of the ith card.
		vector<vector<int>> cards;
		int numCards;
		// Stores the number of aces held. User in the case of a bust.
		int numAce;
		int total;
	public:
		player(vector<vector<int>>& deck, int& lastInd) {
			numCards = 0;
			numAce = 0;
			total = 0;
			drawCard(deck, lastInd);
		}
		// Simulates a card draw.
		void drawCard(vector<vector<int>>& deck, int& lastInd) {
			// If the card is a J, Q, or K
			if (deck.at(lastInd).at(1) > 9) {
				total += 10;
			}
			// If the card isn't an ace.
			else if (deck.at(lastInd).at(1) > 0) {
				total += deck.at(lastInd).at(1) + 1;
			}
			// If the card is an ace.
			else {
				total += 11;
				numAce++;
			}
			// IF the user goes over 21 and has an ace, switches that ace value to 1.
			if (numAce && total > 21) {
				total -= 10;
				numAce--;
			}
			cards.push_back(deck.at(lastInd));
			lastInd--;
			numCards++;
		}
		int getTotal() {
			return total;
		}
		int getNumCards() {
			return numCards;
		}
		int getSuit(int i) {
			return cards.at(i).at(0);
		}
		int getFace(int i) {
			return cards.at(i).at(1);
		}
};
void blackJackNew() {
	// randInd is a randomly chosen index for use with shuffling
	// lastInd is the index of the card of the of of the deck. This simuates drawing from the deck without actually changing the vector.
	int randInd, lastInd;
	// Stores a face and suit to be pushed to the deck vector.
	vector<int>temp;
	// Contols the looping of the whole game, and the looping of the draw phase.
	char contChar = 'Y', drawAgain = 'Y';
	// The list of possible faces for the cards, for use in displaying.
	string faces[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	// The list of possible suits for the cards, for use in displaying.
	string suits[] = { "club", "diamond", "spade", "heart" };
	// The deck of cards.
	vector<vector<int>> deck;
	deck.clear();
	// Fills the empty deck.
	for (int i = 0; i < 52; i++) {
		temp.clear();
		temp.push_back(i % 4);
		temp.push_back(i % 13);
		deck.push_back(temp);
	}

	cout << "You are now playing blackjack." << endl;
	// The outer loop controls if the game runs multilpe times.
	while (contChar != 'N') {
		lastInd = deck.size() - 1;
		// Shuffle the deck.
		for (int i = 0; i < deck.size(); ++i) {
			do {
				randInd = rand() % 52;
			} while (randInd == i);
			swap(deck[i], deck[randInd]);
		}
		// Creates the user player object.
		player You(deck, lastInd);
		drawAgain = 'Y';
		// Continues to draw until the user stands or busts.
		while (drawAgain != 'N' && You.getTotal() < 21) {
			You.drawCard(deck, lastInd);
			cout << "You have: " << endl;
			for (int i = 0; i < You.getNumCards(); i++) {
				if (You.getSuit(i) % 2 != 0) {
					// All instances of this function adapted from https://cplusplus.com/forum/beginner/92586/
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				}
				cout << suits[You.getSuit(i)] << " " << faces[You.getFace(i)] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			cout << "\nTotal: " << You.getTotal() << endl;
			if (You.getTotal() < 21) {
				cout << "Draw another card? Y/N" << endl;
				cin >> drawAgain;
				drawAgain = toupper(drawAgain);
			}
		}
		// Checks if the user has busted and skips computer's turn.
		if (You.getTotal() > 21) {
			cout << "You bust." << endl;
		}
		else {
			cout << "\nComputer's turn." << endl;
			// Creates the computer player object.
			player computer(deck, lastInd);
			// Draws until the computer's total is 18 or higher.
			while (computer.getTotal() < 18) {
				computer.drawCard(deck, lastInd);
				for (int i = 0; i < computer.getNumCards(); i++) {
					if (computer.getSuit(i) % 2 != 0) {
						// All instances of this function adapted from https://cplusplus.com/forum/beginner/92586/
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					}
					cout << suits[computer.getSuit(i)] << " " << faces[computer.getFace(i)] << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				cout << "\nTotal: " << computer.getTotal() << endl;
				if (computer.getTotal() < 18) {
					cout << "The computer draws again." << endl;
				}
			}
			if (computer.getTotal() > 21) {
				cout << "The computer busts. You win." << endl;
			}
			// Compares the user and computer totals and declares the winner.
			else {
				if (You.getTotal() > computer.getTotal()) {
					cout << "\nYou win." << endl;
				}
				else if (You.getTotal() < computer.getTotal()) {
					cout << "\nYou Lose." << endl;
				}
				else {
					cout << "You and the computer tied - Push";
				}
			}
		}
		cout << "\nPlay again? Y/N" << endl;
		cin >> contChar;
		contChar = toupper(contChar);
	}
}


void hangman() {
	srand(time(0));
	// The list of words to be filled.
	vector<string> words;
	// THe current word to be guessed.
	string word;
	// Stores a string that will be revealed as they user guesses.
	string hiddenWord = "";
	// Used the in the input from file.
	string line;
	// The letter the user guessed.
	char guess;
	// The number of gusses left.
	int counter = 6;
	// Handles the reading of words from words.txt
	ifstream myfile("words.txt");
	while (getline(myfile, line)) {
		words.push_back(line);
	}
	myfile.close();
	// Chooses a random word.
	word = words.at(rand() % words.size());
	// Creates a string of ? that is the same length as the word to be gusssed.
	for (int i = 0; i < word.size(); i++) {
		hiddenWord += '?';
	}
	cout << "Hangman- your word is " << hiddenWord << endl;
	// Uncomment the next line to cheat
	// cout << word << endl;
	// Loops until the user is out of guesses or guesses the word.
	while (counter > 0 && hiddenWord != word) {
		cout << "Guess a letter: ";
		cin >> guess;
		// Searches if the guess is in the word.
		if (word.find_first_of(guess) == string::npos) {
			cout << "Letter not in word.Your current word: " << hiddenWord;
			counter--;
		}
		// Reveals the correctly guessed letters on the hidden word.
		else {
			for (int j = 0; j < word.length(); j++) {
				if (guess == word.at(j)) {
					hiddenWord.at(j) = guess;
				}
			}
			cout << "Letter found in word. Your current word: " << hiddenWord;
		}
		if (hiddenWord != word) {
			cout << " You have " << counter << " guesses left." << endl;
		}
		else {
			cout << "\nYou win." << endl;
		}
	}
	if (counter == 0) {
		cout << "You lose. The word is " << word << endl;
	}
}

