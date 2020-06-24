//
// Created by Benjamin Luger on 02.06.2020.
//

#ifndef GEPREXAMPLE12_FIGHTERS_H
#define GEPREXAMPLE12_FIGHTERS_H

#include "string"

using namespace std;

class Fighter {
private:
    void setDefaults() { //sets default values
        setName("Fighter");
        setHealth(100);
        setAttackAttr(10);
        setBlockAttr(10);
        setDodgeAttr(10);
    }

protected:
    int attackAttr;
    int blockAttr;
    int dodgeAttr;

    string name;
    int health;

public:

    void takeDamage(int damage) { //calculates HP
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

class Tank: public Fighter { //sets tanks default values
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

class Rouge: public Fighter { //sets rouges default values
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

class Mage: public Fighter { //sets mages default values
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
