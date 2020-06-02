//
// Created by Benjamin Luger on 02.06.2020.
//

#ifndef GEPREXAMPLE12_FIGHTERS_H
#define GEPREXAMPLE12_FIGHTERS_H

#include "string"

using namespace std;

class Fighter {
protected:
    int attackAttr;
    int blockAttr;
    int dodgeAttr;

    string name;
    int health;

public:

    void takeDamage(int damage) {
        int tmpHealth = health - damage;
        if (tmpHealth <= 0) {
            health = 0;
            return;
        }
        health = tmpHealth;
    }


    int getAttackAttr() const {
        return attackAttr;
    }

    int getBlockAttr() const {
        return blockAttr;
    }

    int getDodgeAttr() const {
        return dodgeAttr;
    }

    void setAttackAttr(int attackAttr) {
        Fighter::attackAttr = attackAttr;
    }

    void setBlockAttr(int blockAttr) {
        Fighter::blockAttr = blockAttr;
    }

    void setDodgeAttr(int dodgeAttr) {
        Fighter::dodgeAttr = dodgeAttr;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Fighter::name = name;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Fighter::health = health;
    }
};

class Tank: public Fighter {
public:
    Tank() {
        setDefaults();
    }

    Tank(int health) {
        setDefaults();
        setHealth(health);
    }

private:
    void setDefaults() {
        setName("Tank");
        setHealth(500);
        setAttackAttr(20);
        setBlockAttr(40);
        setDodgeAttr(30);
    }
};

class Rouge: public Fighter {
public:
    Rouge() {
        setDefaults();
    }

    Rouge(int health) {
        setDefaults();
        setHealth(health);

    }

private:
    void setDefaults() {
        setName("Rouge");
        setHealth(400);
        setAttackAttr(40);
        setBlockAttr(20);
        setDodgeAttr(30);
    }
};

class Mage: public Fighter {
public:
    Mage() {
        setDefaults();
    }

    Mage(int health) {
        setDefaults();
        setHealth(health);

    }

private:
    void setDefaults() {
        setName("Mage");
        setHealth(400);
        setAttackAttr(30);
        setBlockAttr(20);
        setDodgeAttr(40);
    }
};

#endif //GEPREXAMPLE12_FIGHTERS_H
