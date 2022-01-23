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

int integerCesarDecoder(string input)
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
    // Считали из файла "FullMatches.txt" все частоты и записали их в 2 массива - сами буквосочетания в inputMatches[], их количества - в amountsOfMatches[]



    int goodMatches[26];
    for(int i = 0; i < 26; i++)
    {
        goodMatches[i] = 0;
        for(int j = 0; j < output[i].length() - 1; j++){
            string pair = "";
            pair += output[i][j];
            pair += output[i][j+1];
            // pair += output[i].substr(j, j+1);
            for(int n = 0; n < 378; n++) if(pair == inputMatches[n]) goodMatches[i] += amountsOfMatches[n];
        }
    }
    int max = 0;
    int answer;
    for(int i = 0; i < 26; i++) if(goodMatches[i] > max) {
        answer = i;
        max = goodMatches[i];
    }
    return answer;
}

int integerCesarDecoder2(string input)
{   
    

    int amountsOfMatches[378];
    ifstream matches("FullMatches.txt");
    string inputMatches[378];
    for(int i = 0; i < 378; i++){
        matches >> inputMatches[i];
        matches >> amountsOfMatches[i];
    }
    matches.close();
    // Считали из файла "FullMatches.txt" все частоты и записали их в 2 массива - сами буквосочетания в inputMatches[], их количества - в amountsOfMatches[]

    string output;
    int max = 0, answer;
    for(int i = 0; i < 26; i++)
    {
         output = easyCesar(input, i);
        int goodMatches = 0;
        for(int j = 0; j < output.length() - 1; j++){
            string pair = "";
            pair += output[j];
            pair += output[j+1];
            for(int n = 0; n < 378; n++) if(pair == inputMatches[n]) goodMatches += amountsOfMatches[n];
        }
        if(goodMatches > max) {
            answer = i;
            max = goodMatches;
        }
    }
    return answer;
}
    

int main(){
    string input, output;
    int shift, amount = 1;
    // cin >> input;
    getline(cin, input);
    cin >> shift;
    for(int i = 0; i < input.length(); i++) if(input[i] == 32) amount ++; // Ищем количество слов
    string goodMatches[amount];
    int pointer = 0;
    for(int i = 0; i < input.length(); i++) // Разбиваем строку на слова
    {
        if(input[i] == 32) pointer ++;
        else goodMatches[pointer] += input[i];
    }

    int keys[amount]; //Делаем массив для сохранения ключей, которые получим после расшифровки каждого слова
    for(int i = 0; i < amount; i++){
        output = easyCesar(goodMatches[i], shift);
        keys[i] = integerCesarDecoder2(output);
        goodMatches[i] = output;
    }
    
    //Находим, какой ключ встречается чаще всего
    int amountsOfKeys[26];
    for(int i = 0; i < 26; i++) amountsOfKeys[i] = 0;

    for(int i = 0; i < amount; i++) amountsOfKeys[keys[i]] ++;

    pointer = 0;
    int max = 0;
    for(int i = 0; i < 26; i++)
    if(amountsOfKeys[i] > max){
        max = amountsOfKeys[i];
        pointer = i;
    }

    cout << 26 - pointer << endl;
    //Если ответ совпал с shift - числом, которое мы вводили с клавиатуры, - то алгоритм успешно декодировал сообщение

    for(int i = 0; i < amount; i++)
    {
        output = easyCesar(goodMatches[i], pointer);
        cout << output << " ";
    }// Выводим расшифрованное ключом сообщение
}