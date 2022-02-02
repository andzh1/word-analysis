#include "matches.h"

const int ALPHABET_SIZE = 26;

bool isCapital(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

std::string shifted(std::string word, int shift) {
    std::string answer = word;
    for(int i = 0; i < answer.size(); ++i) {
        char smallestLetter = isCapital(answer[i])? 'A' : 'a';
        answer[i] = (answer[i] - smallestLetter + shift) % ALPHABET_SIZE + smallestLetter;
    }
    return answer;
}

std::string shiftedOnIndex(std::string word, int shift, int index) {
    std::string answer = word;
    char smallestLetter = isCapital(answer[index])? 'A' : 'a';
    answer[index] = (answer[index] - smallestLetter + shift) % ALPHABET_SIZE + smallestLetter;
    return answer;
}

class Text {
    std::map<std::string, int> matches;
public:
    Text(std::ifstream& matchesList);
private:
    int countMatches(std::string word);
public:
    std::string CesarDecrypted(std::string word);
    // Returns most probable word that could be coded with Cesar code (shifts all letters by K, 'a' -> '(a+K)')
        

private:
    int sumAround(std::string word, int index);
        // returns total number of matches for all substrings of length SEQUENCE_SIZE, that include our index

public:

    std::string fixIndex(std::string word, int index);
    /*
    for given string finds string that differs with given in given position, 
    but it's sum of matches is maximum possible for all such strings
    */

    std::string fixLetterIn(std::string word);
    /*
    for given string finds string that differs with given in 1 letter, 
    but it's sum of matches is maximum possible for all such strings
    */

};

Text::Text(std::ifstream& matchesList) {
    matches = readMatches(matchesList);
}

int Text::countMatches(std::string word) {
    int answer = 0;
    for (int leftPointer = 0; leftPointer < word.size() - SEQUENCE_SIZE + 1; ++leftPointer) {
        answer += matches[word.substr(leftPointer, SEQUENCE_SIZE)];
    }
    return answer;
}

std::string Text::CesarDecrypted(std::string word) {
    // Returns most probable word that could be coded with Cesar code (shifts all letters by K, 'a' -> '(a+K)')
    int maxNumberOfMatches = countMatches(word);
    std::string decodedWord = word;
    for (int shift = 1; shift < ALPHABET_SIZE; ++shift) {
        std::string currentWord = shifted(word, shift);
        int currentNumberOfMatches = countMatches(currentWord);
        if (currentNumberOfMatches > maxNumberOfMatches) {
            maxNumberOfMatches = currentNumberOfMatches;
            decodedWord = currentWord;
        }
    }
    return decodedWord;
}

int Text::sumAround(std::string word, int index) {
    int leftEdge = std::max(0, index - SEQUENCE_SIZE + 1);
    int rightEdge = std::min(static_cast<int>(word.size() - SEQUENCE_SIZE), index);
    int answer = 0;
    for (int currentLeftEdge = leftEdge; currentLeftEdge <= rightEdge; ++currentLeftEdge) {
        answer += matches[word.substr(currentLeftEdge, SEQUENCE_SIZE)];
    }
    return answer;
    // returns total number of matches for all substrings of length SEQUENCE_SIZE, that include our index
}

std::string Text::fixIndex(std::string word, int index) {
    int maxSumOfMatches = sumAround(word, index);
    std::string fixedWord = word;
    for (int shift = 1; shift < ALPHABET_SIZE; ++shift) {
        std::string currentWord = shiftedOnIndex(word, shift, index);
        int currentSumOfMatches = sumAround(currentWord, index);
        if (currentSumOfMatches > maxSumOfMatches) {
            maxSumOfMatches = currentSumOfMatches;
            fixedWord = currentWord;
        }
    }

    return fixedWord;
}

std::string Text::fixLetterIn(std::string word) {
    /*
    for given string finds string that differs with given in 1 letter, 
    but it's sum of matches is maximum possible for all such strings
    */

    int maxSumOfMatches = countMatches(word);
    std::string fixedWord = word;
    for (int pos = 0; pos < word.size(); ++pos) {
        std::string currentFixedWord = fixIndex(word, pos);
        int currentSumOfMatches = countMatches(currentFixedWord);
        if (currentSumOfMatches > maxSumOfMatches) {
            maxSumOfMatches = currentSumOfMatches;
            fixedWord = currentFixedWord;
        }
    }
    
    return fixedWord;
}

