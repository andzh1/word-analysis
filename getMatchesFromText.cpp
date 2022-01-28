#include "matches.h"

int main() {
    /*
    If you want to get matches from your text file, type it's name instead of "data.txt", 
    and your output file name instead of "MyMatches.txt"
    */
    
    /*
    std::ifstream text("data.txt");
    std::ofstream output("MyMatches.txt");
    getMatchesFromText(text, output);
    text.close();
    output.close();
    */
    // If you want to update file "matches.txt" (it contains matches from previous files), do following:
    
    std::ifstream text("data.txt");
    getMatchesFromText(text);
    text.close();
    
}