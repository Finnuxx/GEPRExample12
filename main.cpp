#include <iostream>
#include <stdlib.h>
#include "Headers/Fighters.h"
#include "Headers/Arena.h"

using namespace std;

int mainMenu() {
    int input;

    cout << "Menu:" << endl;
    cout << "1. Choose fighter" << endl;
    cout << "2. Exit Game" << endl;

    cin >> input;

    return input;
}

int playerMenu() {
    int input;

    cout << "Which fighter do you choose?" << endl;
    cout << "1. Tank - High HP" << endl;
    cout << "2. Rouge - High attack" << endl;
    cout << "3. Mage - High dodge" << endl;

    cin >> input;

    return input;
}

Fighter* getPlayerBySelection(int selection) {
    switch (selection) {
        case 1:
            return new Tank();
        case 2:
            return new Rouge();
        case 3:
            return new Mage();
        default:
            exit(-1);
    }
}



action actionMenu() {
    int input;

    cout << "1. attack" << endl;
    cout << "2. block" << endl;
    cout << "3. dodge" << endl;

    cin >> input;

    switch (input) {
        case 1:
            return attack;
        case 2:
            return block;
        case 3:
            return dodge;
        default:
            return invalid;
    }
}

action getValidAction() {
    while (true) {
        action a = actionMenu();
        if (invalid != a) {
            return a;
        }
    }
}

result play(Arena* arena) {

    while (true) {
        action actionA = getValidAction();
        action actionB = getValidAction();

        result r = arena->engage(actionA, actionB);

        if (r != resume) {
            return r;
        }
    }
}

int exitScreen() {
    cout << "left game" << endl;
}

int main() {
    bool isRunning = true;

    cout << "Welcome to the Fightclub!" << endl;

    while (isRunning) {
        int input = mainMenu();

        if (input == 1) {
            int playerASelection = playerMenu();
            int playerBSelection = playerMenu();
            Fighter *fighterA = getPlayerBySelection(playerASelection);
            Fighter *fighterB = getPlayerBySelection(playerBSelection);

            Arena *arena = new Arena(fighterA, fighterB);

            result matchResult = play(arena);
            switch (matchResult) {
                case winA:
                    cout << "Congratulations! Player A won the game!" << endl << endl;
                    break;
                case winB:
                    cout << "Congratulations! Player B won the game!" << endl << endl;
                    break;
                case tied:
                    cout << "HAHAHA! Both of you failed!" << endl << endl;
                    break;
            }
        } else {
            isRunning = false;
        }
    }

    exitScreen();

    return 0;
}




