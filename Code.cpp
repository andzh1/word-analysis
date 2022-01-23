#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string easyCesar(string input, int key){
    for(int i = 0; i < input.length(); i++){
        input[i] = ((input[i] - 97) + key)%26 + 97;
    }
    return input;
}

string cesarDecoder(string input)
{   
    string output[26];
    for(int i = 0; i < 26; i++) output[i] = easyCesar(input, i);

    int amountsOfMatches[378];
    ifstream matches("FullMatches.txt");
    string inputMatches[378];
    for(int i = 0; i < 378; i++){
        matches >> inputMatches[i];
        matches >> amountsOfMatches[i];
    }
    matches.close();
    int goodMatches[26];
    for(int i = 0; i < 26; i++)
    {
        goodMatches[i] = 0;
        for(int j = 0; j < output[i].length() - 1; j++){
            string pair = "";
            pair += output[i][j];
            pair += output[i][j+1];
            for(int n = 0; n < 378; n++) if(pair == inputMatches[n]) goodMatches[i] += amountsOfMatches[n];
        }
    }
    int max = 0;
    string answer;
    for(int i = 0; i < 26; i++) if(goodMatches[i] > max) {
        answer = output[i];
        max = goodMatches[i];
    }
    return answer;
}


int main(){
    string input, output;
    cin >> input;
    output = easyCesar(input, 2);
    input = cesarDecoder(output);
    cout << input;  
    
}