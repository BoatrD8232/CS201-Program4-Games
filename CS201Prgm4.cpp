/*
    Name- David Boatright
    Date- 9/18/2024
    Program- CS201 Program 4- Games
*/
#include "Functions.h"

int main()
{
    char choice = '0';
    // Takes a choice from showMenu and chooses the corresponding game.
    while (choice != 'Q') {
        choice = showMenu();
        switch(choice) {
            case 'C':
                craps();
                break;
            case 'S':
                scraps();
                break;
            case 'R':
                rockPaperScissors();
                break;
            case 'E':
                rockPaperScissorsSpock();
                break;
            case 'B':
                blackJackNew();
                break;
            case 'H':
                hangman();
                break;
        }
    }

}


