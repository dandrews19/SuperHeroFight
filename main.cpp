
#include "fight.h"
#include "strlib.cpp"
#include <iostream>

int main(int argc, const char* argv[])
{
	// Main function takes command line arguments
	// Then passes it to ProcessCommandArgs in "srcmain.h"
	fight(std::cin, std::cout, time(nullptr));
    
    
    return 0;
}
