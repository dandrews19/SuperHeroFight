#include "powers.h"

#include <iostream>

// getter for POWER_ID enum
POWER_ID Power::getID()
{
	
    return mPowerID;
}

// powerFactory that assigns a string to a power, and returns
// a pointer to that power
Power* powerFactory(const std::string& powerName)
{
    if (powerName == "strength") {
        Power* pow = new StrengthPower();
        return pow;
    }
    else if (powerName == "flight") {
        Power* pow = new FlightPower();
        return pow;
    }
    else if (powerName == "laser") {
        Power* pow = new LaserPower();
        return pow;
    }
    else if (powerName == "intel") {
        Power* pow = new IntelPower();
        return pow;
    }
    else if (powerName == "gadget") {
        Power* pow = new GadgetPower();
        return pow;
    }
    else if (powerName == "national") {
        Power* pow = new NationalPower();
        return pow;
    }
    else {
        std::cout << "invalid power name \"" << powerName << "\" returning null pointer" << std::endl;
        return nullptr;
    }
}
// overloading the << operator to output the description
// of a power
std::ostream& operator<<(std::ostream& out, const Power& p)
{
	out << p.mDescription;
	return out;
}


// Constructors: each power constructor assigns a description
// and ID for each power

// StrengthPower constructor
StrengthPower::StrengthPower() {
    mDescription = "Uses superhuman strength";
    mPowerID = POWER_STRENGTH;
    
}

// FlightPower constructor
FlightPower::FlightPower() {
    mDescription = "Activates ability to soar thru the skies";
    mPowerID = POWER_FLIGHT;
}

// LaserPower constructor
LaserPower::LaserPower(){
    mDescription = "Uses alien-like laser";
    mPowerID = POWER_LASER;
}

//IntelPower constructor
IntelPower::IntelPower() {
    mDescription = "Utilizes all-worldy knowledge";
    mPowerID = POWER_INTEL;
}

//GadgetPower constructor
GadgetPower::GadgetPower() {
    mDescription = "Makes use of Tony Stark gadgets";
    mPowerID = POWER_GADGETS;
}

//NationalPower constructor
NationalPower::NationalPower() {
    mDescription = "Summons never-before-seen levels of Patriotism";
    mPowerID = POWER_NATIONAL;
}

// use() functions: each Power has a use function that
// describes what the power does when used

// StrengthPower use() function
std::string StrengthPower::use() {
    
    std::string phrase = "uses steroid-induced strength as a result of childhood body insecurity!";
    
    return phrase;
}

// FlightPower use() function
std::string FlightPower::use() {
    
    std::string phrase = "flies through the air like MJ!";
    
    return phrase;
    
}

// LaserPower use() function
std::string LaserPower::use() {
    
    std::string phrase = "shoots laser out of fear of getting too close!";
    
    return phrase;
    
}

// IntelPower use() function
std::string IntelPower::use() {
    
    std::string phrase = "summons intelligence gained by having no childhood";
    
    return phrase;
    
}

// GadgetPower use() function
std::string GadgetPower::use() {
    
    std::string phrase = "uses very innovative gadget to hack the mainframe! (or whatever they say in the movies)";
    
    return phrase;
    
}

// NationalPower use() function
std::string NationalPower::use() {
    std::string phrase = "recites the national anthem they were forced to memorize in elementary school";
    
    return phrase;
    
}

// fight() functions: each Power has a fight function,
// which returns the result for when it goes up against another
// power(1 for win, -1 for loss, 0 for tie), and displays
// a description of the result

// StrengthPower fight() function
int StrengthPower::fight(Power *other) {
    
    // results against other powers
    if (other->getID() == POWER_FLIGHT) {
        std::cout << "FLIGHT WINS - you can't use all that muscle to fly!" << std::endl;
        
        return -1;
        
    }
    else if (other->getID() == POWER_INTEL) {
        std::cout << "INTELLIGENCE WINS - brains > brawns!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_GADGETS) {
        std::cout << "STRENGTH WINS - gadget has been ripped apart!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_LASER) {
        std::cout << "STRENGTH WINS - silly lights mean nothing for all this muscle!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_NATIONAL) {
        std::cout << "STRENGTH WINS - your patriotism can't handle these guns!" << std::endl;
        return 1;
    }
    else {
        std::cout << "TIE - too much strength for a winner!" << std::endl;
        return 0;
    }
    
}

// FlightPower fight() function
int FlightPower::fight(Power *other) {
    
    // results against other powers
    if (other->getID() == POWER_GADGETS) {
        std::cout << "GADGET WINS - you can't outfly my gps!" << std::endl;
        return -1;
        
    }
    else if (other->getID() == POWER_LASER) {
        std::cout << "LASER WINS - only takes a little green light to take down a 737!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_INTEL) {
        std::cout << "FLIGHT WINS - can't outsmart this altitude!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_STRENGTH) {
        std::cout << "FLIGHT WINS - you can't use all that muscle to fly!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_NATIONAL) {
        std::cout << "FLIGHT WINS - your flag doesn't wave this high!" << std::endl;
        return 1;
    }
    else {
        std::cout << "TIE - flew away from each other!" << std::endl;
        return 0;
    }
    
   
    
}

// LaserPower fight() function
int LaserPower::fight(Power *other) {
    // results against other powers
    if (other->getID() == POWER_GADGETS) {
        std::cout << "GADGET WINS - the gadget deflects the laser!" << std::endl;
        return -1;
        
    }
    else if (other->getID() == POWER_STRENGTH) {
        std::cout << "STRENGTH WINS - silly lights mean nothing for all this muscle!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_FLIGHT) {
        std::cout << "LASER WINS - only takes a little green light to take down a 737!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_INTEL) {
        std::cout << "LASER WINS - you can't outsmart the speed of light!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_NATIONAL) {
        std::cout << "LASER WINS - lights > flags any day!" << std::endl;
        return 1;
    }
    else {
        std::cout << "TIE - too many lights!" << std::endl;
        return 0;
    }
    
    
    
}
// IntelPower fight() function
int IntelPower::fight(Power *other) {
    // result against other powers
    if (other->getID() == POWER_FLIGHT) {
        std::cout << "FLIGHT WINS - can't outsmart this altitude!" << std::endl;
        return -1;
        
    }
    else if (other->getID() == POWER_LASER) {
        std::cout << "LASER WINS - you can't outsmart the speed of light!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_GADGETS) {
        std::cout << "INTELLIGENCE WINS - a glitch in the gadget was discovered!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_STRENGTH) {
        std::cout << "INTELLIGENCE WINS - brains > brawns!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_NATIONAL) {
        std::cout << "INTELLIGENCE WINS - was this really in question?" << std::endl;
        return 1;
    }
    else {
        std::cout << "TIE - too much intelligence is never a good thing!" << std::endl;
        return 0;
    }
    
    
}
// GadgetPower fight() function
int GadgetPower::fight(Power *other) {
    // result against other powers
    if (other->getID() == POWER_STRENGTH) {
        std::cout << "STRENGTH WINS - gadget has been ripped apart!" << std::endl;
        return -1;
        
    }
    else if (other->getID() == POWER_INTEL) {
        std::cout << "INTELLIGENCE WINS - a glitch in the gadget was discovered!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_FLIGHT) {
        std::cout << "GADGET WINS - you can't outfly my gps!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_LASER) {
        std::cout << "GADGET WINS - the gadget deflects the laser!" << std::endl;
        return 1;
    }
    else if (other->getID() == POWER_NATIONAL) {
        std::cout << "GADGET WINS - a bomb was stuck inside of the flag!" << std::endl;
        return 1;
    }
    else {
        std::cout << "TIE - the gadgets broke each other!" << std::endl;
        return 0;
    }
    
    
}
// NationalPower fight() function
int NationalPower::fight(Power *other) {
    // result against other powers
    if (other->getID() == POWER_STRENGTH) {
        std::cout << "STRENGTH WINS - your patriotism can't handle these guns!" << std::endl;
        return -1;
        
    }
    else if (other->getID() == POWER_INTEL) {
        std::cout << "INTELLIGENCE WINS - was this really in question?" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_FLIGHT) {
        std::cout << "FLIGHT WINS - your flag doesn't wave this high!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_LASER) {
        std::cout << "LASER WINS - lights > flags any day!" << std::endl;
        return -1;
    }
    else if (other->getID() == POWER_GADGETS) {
        std::cout << "GADGET WINS - a bomb was stuck inside of the flag!" << std::endl;
        return -1;
    }
    else {
        std::cout << "TIE - the only thing nationalism doesn't lose to: nationalism!" << std::endl;
        return 0;
    }
}




