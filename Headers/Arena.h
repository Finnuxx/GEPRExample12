//
// Created by Benjamin Luger on 02.06.2020.
//

#ifndef GEPREXAMPLE12_ARENA_H
#define GEPREXAMPLE12_ARENA_H

#include "Fighters.h"
#include <stdlib.h>
#include "time.h"

using namespace std;


enum action {
    attack = 1,
    block = 2,
    dodge = 3,
    invalid = 4,
};

enum result {
    winA = 1,
    winB = 2,
    tied = 3,
    resume = 4,
};

class Arena {
private:
    Fighter* playerA;
    Fighter* playerB;

    int resolveAction(action playerAction, Fighter* player) {
        switch (playerAction) {
            case attack:
                return player->getAttackAttr();

            case block:
                return player->getBlockAttr();

            case dodge:
                return player->getDodgeAttr();

        }
    }

    string getActionName(action playerAction) {
        switch (playerAction) {
            case attack:
                return "attack";

            case block:
                return "block";

            case dodge:
                return "dodge";

        }
    }

    void printHP() {
        cout << "Player A - HP " << playerA->getName() << ": " << playerA->getHealth() << endl;
        cout << "Player B - HP " << playerB->getName() << ": " << playerB->getHealth() << endl;
    }

    void applyAction(action actionA, action actionB) {
        srand((unsigned) time(0));

        int luckA = (rand() % 10);
        int actionValueA = luckA * resolveAction(actionA, playerA);
        cout << playerA->getName() << " " << getActionName(actionA) << "s with luck " << luckA << "!" << endl << "Value: " << actionValueA << endl << endl;

        int luckB = (rand() % 10);
        int actionValueB = luckB * resolveAction(actionB, playerB);
        cout << playerB->getName() << " " << getActionName(actionB) << "s with luck " << luckB << "!" << endl << "Value: " << actionValueB << endl << endl;

        if (actionA == attack && actionB == attack) {
            playerA->takeDamage(actionValueB);
            playerB->takeDamage(actionValueA);
            printHP();
            return;
        }

        if (actionA == attack && actionB == block) {
            int damage = actionValueA - actionValueB;

            playerB->takeDamage(
                    damage > 0
                    ? damage
                    : 0
            );
            printHP();
            return;
        }

        if (actionA == block && actionB == attack) {
            int damage = actionValueB - actionValueA;

            playerA->takeDamage(
                    damage > 0
                    ? damage
                    : 0
            );
            printHP();
            return;
        }

        if (actionA == attack && actionB == dodge) {
            if (actionValueA > actionValueB) {
                playerB->takeDamage(actionValueA);
                printHP();
                return;
            }
            cout << playerB->getName() << " dodged successfully!" << endl;
            return;
        }

        if (actionA == dodge && actionB == attack) {
            if (actionValueB > actionValueA) {
                playerA->takeDamage(actionValueB);
                printHP();
                return;
            }
            cout << playerA->getName() << " dodged successfully!" << endl;
            return;
        }

        if ((actionA == block || dodge) && (actionB == block || dodge)) {
            cout << "nothing happened" << endl;
        }
    }

public:
    Arena(Fighter* playerA, Fighter* playerB) {
        this->playerA = playerA;
        this->playerB = playerB;
    }

    result engage(action actionA, action actionB) {
        this->applyAction(actionA, actionB);

        if (playerA->getHealth() > 0 && playerB->getHealth() == 0) {
            return winA;
        }

        if (playerB->getHealth() > 0 && playerA->getHealth() == 0) {
            return winB;
        }

        if (playerA->getHealth() == 0 && playerB->getHealth() == 0) {
            return tied;
        }

        return resume;

    }

};

#endif //GEPREXAMPLE12_ARENA_H
