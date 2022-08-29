#include "hero.h"
#include "strlib.h"
#include <iostream>

// Hero constructor
Hero::Hero(const std::string& heroDef)
{
	// splitting up string to get Hero attributes
    std::vector<std::string> heroVec = strSplit(heroDef, '|');
    mMaxHealth = stoi(heroVec[2]);
    mName = heroVec[0];
    mHealth = mMaxHealth;
    
    // splitting another string to get hero powers
    std::vector<std::string> heroPowers = strSplit(heroVec[1], ',');
    
    std::vector<Power*> powerPtrs;
    // adding hero's powers to a vector
    for (int i = 0; i < heroPowers.size(); i++) {
        powerPtrs.push_back(powerFactory(heroPowers[i]));
    }
    
    mPowers = powerPtrs;
    
}

// getter for Hero's name
std::string Hero::getName()
{
    return mName;
}

// Hero method to use a random power from mPowers vector
Power* Hero::useRandomPower()
{
    // getting random number based on size of power vector, and returning Power pointer
    int randValue = rand() % (mPowers.size());
    return mPowers[randValue];
}

// getter for hero's health
int Hero::getHealth()
{
	return mHealth;
}

// method to take damage, decrements health by 1
void Hero::takeDamage()
{
    mHealth -= 1;
}

// reselt health method: restores health to maximum
void Hero::resetHealth()
{
    mHealth = mMaxHealth;
}

// overloading << operator to return hero's name and description of powers
std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;
	
	for (int i = 0; i < h.mPowers.size(); i++)
	{
		std::cout << "\t" << *(h.mPowers[i]) << std::endl;
	}

	return out;
}
