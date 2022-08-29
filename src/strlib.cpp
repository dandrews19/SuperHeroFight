#include "strlib.h"

// strSplit implementation
std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	// creating holder string that will temporarily hold the string being added to the vector
    std::string holder;
    // initializing vector to be returned
    std::vector<std::string> splitVector;
    // looping over characters in string
    for (int i = 0; i < str.length(); i++) {
        // if current character in loop is the split character, add what is in holder
        // to the vector and clear the holder
        if(str[i] == splitChar) {
            splitVector.push_back(holder);
            holder = "";
        }
        // otherwise, add the character to the holder
        else {
            holder.push_back(str[i]);
            
        }
        
    }
    // adding final word to vector
    splitVector.push_back(holder);
    // returning vector
	return splitVector;
}

