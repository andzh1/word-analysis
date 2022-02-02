#include "wordCheck.h"
#include <iomanip>

void checkCorrectnessOf(std::ifstream& listOfWords, Text database) {
    std::ofstream statistics("statistics.txt");
    std::map<int, int> correctlyDecrypted; // correctlyDecrypted
    std::map<int, int> incorrectlyDecrypted; // incorrectlyDecrypted
    std::string word;
    while(listOfWords >> word) {
        bool thisCorrectlyDecrypted = (database.CesarDecrypted(word) == word);
        if (thisCorrectlyDecrypted) {
            correctlyDecrypted[word.size()]++;
        } else {
            incorrectlyDecrypted[word.size()]++;
        }
    }

    for (auto elem : correctlyDecrypted) {
        statistics << elem.first << ' ' << /*std::setprecision(0) <<*/ static_cast<float>(elem.second) / (elem.second + incorrectlyDecrypted[elem.first]) * 100 << '\n';
        // statistics << elem.first << ' ' << elem.second << ' ' << incorrectlyDecrypted[elem.first] << '\n';
    }
}

int main() {
    std::ifstream matches("LordMatches.txt");
    Text LordOfTHeRings(matches);
    std::ifstream listOfWords("words.txt");
    checkCorrectnessOf(listOfWords, LordOfTHeRings);
    // finds most probable word that could be coded with Cesar code (shifts all letters by K, 'a' -> '(a+K)')

}