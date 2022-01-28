#include <iostream>
#include <string>
#include <fstream>
#include <map>

const int SEQUENCE_SIZE = 2;

bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

std::string lowercase(std::string input) {
    // makes every letter of given string of letters lowercase
    std::string answer;
    for (auto ch: input) {
        if (ch >= 'A' && ch <= 'Z') ch -= ('A' - 'a');
        answer += ch;
    }
    return answer;
}

std::pair<std::string, int> parseMatch(std::string input) { 
    /* we have a string like that: "aa - 123", "aa" - any pair of chars, 123 - number of matches of that pair,
    and we want to parse it into pair <"aa", 123>
    */
    std::string pairOfChars = input.substr(0, SEQUENCE_SIZE);
    int numberOfMatches = std::atoi(input.substr(3 + SEQUENCE_SIZE).c_str());
    return {pairOfChars, numberOfMatches};
}

std::map<std::string, int> readMatches(std::istream& matchesList) {
    // Converts file of matches - every string of this file looks like "aa - 123" - into map<> of matches
    std::map<std::string, int> matches;

    std::string currentMatch;
    while(std::getline(matchesList, currentMatch)) {
        auto parsedMatch = parseMatch(currentMatch);
        matches[parsedMatch.first] = parsedMatch.second;
    }
    return matches;
}

bool isStrOfLetters(std::string s) {
    for (auto ch: s) {
        if (!isLetter(ch)) return false;
    }
    return true;
}

void getMatchesFromText(std::istream& text) {
    std::ifstream matchesList("matches.txt");

    std::map<std::string, int> matches = readMatches(matchesList); 
    // for each sequence of letters (such as "fg", "aa", etc.) we calculate number of it's matches in the text

    std::string currentSequence;
    char symbolToAppend;
    while(currentSequence.size() < SEQUENCE_SIZE && !text.eof()) {
        symbolToAppend = text.get();
        currentSequence.push_back(symbolToAppend);
    }
    while(!text.eof()) {
        if (isStrOfLetters(currentSequence)) {
            ++matches[lowercase(currentSequence)];
        }
        symbolToAppend = text.get();
        currentSequence = currentSequence.substr(1) + symbolToAppend;
    }
    std::ofstream newMatches("matches.txt");
    for (auto x: matches) newMatches << x.first << " - " << x.second << '\n';
}

void getMatchesFromText(std::istream& text, std::ofstream& output) {

    std::map<std::string, int> matches; 
    // for each pair of letters (such as "fg", "aa", etc.) we calculate number of it's matches in the text

    char first, second;
    text >> first;
    while(text >> second) {
        if (isLetter(first) && isLetter(second)) {
            std::string currentPair;
            currentPair += first;
            currentPair += second;
            ++matches[lowercase(currentPair)];
        }
        first = second;
    }
    for (auto x: matches) output << x.first << " - " << x.second << '\n';
}
