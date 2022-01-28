#include "wordCheck.h"

int main() {
    std::ifstream matches("LordMatches.txt");
    Text LordOfTHeRings(matches);
    std::string word;
    std::cin >> word;
    std::cout << LordOfTHeRings.decodeCesar(word); 
    // finds most probable word that could be coded with Cesar code (shifts all letters by K, 'a' -> '(a+K)')

    std::cout << LordOfTHeRings.fixLetterIn(word);
    /*
    for given string finds string that differs with given in 1 letter, 
    but it's sum of matches is maximum possible for all such strings
    */
}