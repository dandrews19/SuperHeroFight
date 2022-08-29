#include "fight.h"

// loadHeroes implementation
bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
    // if the vector has data in it, clear the vector so new data can be stored
    if (heroVector.size() > 0) {
        heroVector.clear();
    }
    
    // creating a file input stream from parameter
    std::ifstream fileInput(fileName);
    
    // checking if filek opened
    if (fileInput.is_open()) {
        // while its not the end of file
        while (!fileInput.eof()) {
            // initializing line string
            std::string line;
            // getting line from file and storing it in line string
            std::getline(fileInput, line);
            // creating new Hero pointer
            Hero* newHero = new Hero(line);
            // adding pointer to vector
            heroVector.push_back(newHero);
            
        }
        // closing filel and returning true indicating success
        fileInput.close();
        return true;
    }
    // returning false if file is unable to be opened
    else {
    std::cout << "Error: unable to load file!" << std::endl;
        return false;
    }
    
	return true;
}

// is_number implementation
bool is_number(const std::string& num) {
    // iterating over string
    for (int i = 0; i < num.size(); i++) {
        // if a character that is non-numerical is found, return false
        if (!isdigit(num[i])) {
            return false;
        }
    }
    // if all characters are found to be digits, return true
    return true;
}

// selectHero implementation
Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
    // integer that will hold users choice
    int choice;
    // string that will represent initial user input
    std::string selection = "-1";
    
    // keep prompting while user does not enter number in range
    while (choice < 0 or choice >= heroVector.size()) {
        // display prompt
        out << prompt;
        // receive input
        in >> selection;
        
        // if input is a number, convert to integer
        if (is_number(selection)) {
            choice = stoi(selection);
        }
        else {
            // otherwise, assign choice to -1 so user is prompted again
            choice = -1;
        }
    }
	// returning hero pointer based on user selection
	return heroVector[choice];

}
// heroCombat implementation
void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
	// resetting hero'a health
    heroA->resetHealth();
    heroB->resetHealth();
    // initializing result integer to hold result of fights
    int result;
    // run loop while both heros have health
    while (heroA->getHealth() > 0 and heroB->getHealth() > 0) {
        
        output << "---------------------------------------" << std::endl;
        // displaying health
        output << heroA->getName() << " has " << heroA->getHealth() << " health" << std::endl;
        output << heroB->getName() << " has " << heroB->getHealth() << " health" << std::endl;
        // choosing random power for each hero
        Power* powerA = heroA->useRandomPower();
        Power* powerB = heroB->useRandomPower();
        // displaying what power each hero uses
        std::cout << heroA->getName() << " " << powerA->use() << std::endl;
        
        std::cout << heroB->getName() << " " << powerB->use() << std::endl;
        // getting result of round
        result = powerA->fight(powerB);
        // applying damage based on result
        if (result == 1) {
            heroB->takeDamage();
        }
        else if (result == -1) {
            heroA->takeDamage();
        }
        else {
            heroA->takeDamage();
            heroB->takeDamage();
        }
        // displaying winner if a hero reaches 0 health
        if (heroA->getHealth() == 0 and heroB ->getHealth() == 0) {
            output << "---------------------------------------" << std::endl;
            output << "It's a tie!" << std::endl << std::endl;
        }
        else if (heroA->getHealth() == 0) {
            output << "---------------------------------------" << std::endl;
            output << heroB->getName() << " WINS!!!" << std::endl << std::endl;
        }
        else if (heroB->getHealth() == 0) {
            output << "---------------------------------------" << std::endl;
            output << heroA->getName() << " WINS!!!" << std::endl << std::endl;
        }
        
    }
}
// displayMenu implementation
int displayMenu(std::istream& input, std::ostream& output) {
    
    // initializing selection to -1 so loop is entered
    int selection = -1;
    // creating a string that will represent the initial user input
    std::string choice;
    // keep prompting while selection not in range
    while (selection < 1 or selection > 4) {
        // outputting menu to stream
        output << "Choose an option: " << std::endl;
        output << "1. Load Heroes " << std::endl;
        output << "2. Print Hero Roster " << std::endl;
        output << "3. Hero Fight! " << std::endl;
        output << "4. Quit" << std::endl;
        output << "> ";
        // getting user input
        input >> choice;
        output << std::endl;
        
        // if user input is not a number or out of range, reprompt, otherwise cast to int
        if (!is_number(choice)) {
            output << "Invalid Input!" << std::endl;
            selection = -1;
        }
        else {
            selection = stoi(choice);
            if (selection < 1 or selection > 4) {
                output << "Invalid Input!" << std::endl;
            }
        }

    }
    // return menu selection
    return selection;
    
}

// fight implementation
int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
    // creating file input and output streams
    std::ifstream fileInput(inputFileName);
    std::ofstream fileOutput(outputFileName);
    
    // calling other fight function
    fight(fileInput, fileOutput, seed);
    
	return 0;
}

// fight implementation
int fight(std::istream& input, std::ostream& output, unsigned seed)
{
    // setting seed
    std::srand(seed);
    
    // outputting seed
    output << "Seed: " << seed << std::endl << std::endl;
    
    // initializing booleans
    bool quit = false;
    bool success;
    
    // initialzing menu selection
    int selection = -1;
    // initializing choice string
    std::string choice;
    // initializing heroVector - a vector storing pointers of Hero objects
    std::vector<Hero*> heroVector;
    // run the loop while the user doesn't want to quit
    while (!quit) {
        // displaying the menu
        selection = displayMenu(input, output);
        // running different functions based on user selection
        if (selection == 1) {
            std::string fileName;
            output << "Enter the file to load: ";
            input >> fileName;
            output << std::endl;
            // loading heroes fromk user file
            success = loadHeroes(fileName, heroVector);
            
            
            
        }
        else if (selection == 2) {
            // displaying loaded heroes if there are any
            if (heroVector.size() == 0) {
                output << "Error: Please load heroes!" << std::endl;
            }
            else {
                output << "The following " << heroVector.size() << " heroes are loaded... "<<std::endl;
                
                output << "---------------------------------------" << std::endl;
                // looping and displaying hero descriptions
                for (int i = 0; i < heroVector.size(); i++) {
                    
                    output << *heroVector[i];
                    output << "---------------------------------------" << std::endl;
                    
                }
                
            }
            
        }
        else if (selection == 3) {
            int heroChoice;
            
            // displaying possible heros
            for (int i = 0; i < heroVector.size(); i++) {
                output << i << ": "<< heroVector[i]->getName() << std::endl;
            }
            // prompting user to select two heroes to fight with
            Hero* firstHeroChoice = selectHero(heroVector, "Select your first hero: ", output, input);
            
            Hero* secondHeroChoice = selectHero(heroVector, "Select your second hero: ", output, input);
            
            // running the fight simulation
            heroCombat(firstHeroChoice, secondHeroChoice, output);
            
            
            
        }
        else {
            // quitting the program if user enters 4
            quit = true;
            
            output << "Goodbye" << std::endl;
        }
        
    }
    
	return 0;
}
