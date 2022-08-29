#include "strlib.h"
#include "powers.h"
#include "hero.h"
#include <iostream>
#include <ctime>
#include <fstream>

// Name:
//        loadHeroes
// Input:
//        1. A string (passed as constant reference) contining the file name to load
//        2. A vector of Hero pointers to be filled with the new heroes
// Output:
//        A boolean to indicate success or failure
// Side effects:
//        Dynamically creates new heroes and adds their memory addresses to the vector
// Summary:
//        Calls the hero constructor to make all the heroes
bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector);

// Name:
//        is_number
// Input:
//        1. A string passed by constant reference
// Output:
//        A boolean to indicate whether string is a (positive) digit
// Side effects:
//        None
// Summary:
//        Checks whether or not string is a digit
bool is_number(const std::string& num);

// Name:
//        selectHero
// Input:
//        1. A vector of hero pointers
//		  2. The prompt to display to the user when asking for a selection
//		  3. The output stream to use to prompt
//		  4. The input stream to use to get a response
// Output:
//        The selected hero pointer
// Side effects:
//        Works with inputted streams to prompt for a selection
// Summary:
//        Used when picking heroes to fight
Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in);

// Name:
//        heroCombat
// Input:
//        1. Two hero pointers are passed in
//        2. The output stream to display fight progress
// Output:
//        None
// Side effects:
//        Displays fight results to stream and COUT
// Summary:
//        Selects a random power from each hero using the "useRandomPower" function
//		  Fights the two powers (using the stream and COUT to display results)
//		  Fights the two heroes until someone wins
void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output);


// Name:
//        displayMenu
// Input:
//        1. input stream passed by reference
//        2. output stream passed by reference
// Output:
//        None
// Side effects:
//        None
// Summary:
//       Displays the menu for user and gathers input
int displayMenu(std::istream& input, std::ostream& output);

// Name:
//        fight
// Input:
//        1. An input stream to get user input from
//        2. An output stream to put user output to
//		  3. An unsigned int to use as the random number generator seed
// Output:
//        An integer with the return code (0 for success)
// Side effects:
//        Interacts with user
// Summary:
//        After setting the std::srand with the seed, the ostream gets the menu
//		  Function interacts with user through menu options until quit is selected
//		  See the writeup for menu details and functionality
int fight(std::istream& input, std::ostream& output, unsigned seed);

// Name:
//        fight
// Input:
//        1. An file to generate an input stream to pass to the other fight function
//        2. An file to generate an output stream to pass to the other fight function
//		  3. An unsigned int to use as the random number generator seed
// Output:
//        A boolean to indicate success or failure
// Side effects:
//        Calls other fight function that interacts with user
// Summary:
//        Generates input and output streams then calls the other fight function
int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed);

