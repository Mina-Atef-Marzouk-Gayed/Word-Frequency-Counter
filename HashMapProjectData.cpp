// HashMapProjectData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <sstream>
#include "hashmap.h"
using namespace std;
long wordsfile(string filename){
ifstream file;
file.open(filename);
string line; int counter= 0;
while(getline(file,line,' '))
    counter = counter+1;

return counter;
}
void countSymbolsLettersDigitsWordsSentences(const string& input) {
    HashMap symbolsMap(128); 
    HashMap lettersMap(26);  
    HashMap digitsMap(10);   
    HashMap wordsMap;
    HashMap sentencesMap;

    char ch;
    string word;
    int symbolsCount = 0;
    int lettersCount = 0;
    int digitsCount = 0;
    int wordsCount = 0;
    int sentencesCount = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        ch = input[i];
        if (isalpha(ch)) {
            lettersCount++;
        }
        else if (isdigit(ch)) {
            digitsCount++;
        }
        else if (!isspace(ch)) {  // Count symbols only if not a space
            symbolsCount++;
        }

        if (isalnum(ch)) {
            word += ch;
        }
        else if (!word.empty()) {
            wordsCount++;
            wordsMap.put(word);
            word.clear();
        }

        if (ch == '.' || ch == '!' || ch == '?') {
            sentencesCount++;
            sentencesMap.put(to_string(sentencesCount));
        }
    }
    cout << endl << endl;
    cout << "Symbols count: " << symbolsCount << endl;
    cout << "Letters count: " << lettersCount << endl;
    cout << "Digits count: " << digitsCount << endl;
    cout << "Words count: " << wordsCount << endl;
    cout << "Sentences count: " << sentencesCount << endl;
    cout << endl << endl;

}

void replaceNonCharactersWithSpace(string& text) {
    for (char& c : text) {
        if (!isalnum(c)) {
            c = ' ';
        }
    }
}
int splitTextCounter(const string text) {
    int wordCounter = 0;
    istringstream separate(text);
    string word;
    while (separate >> word) {
        wordCounter++;
    }
    return (int)wordCounter * 1.5;
}
void splitText(string& text)
{
    HashMap mapping(splitTextCounter(text));
    istringstream separate(text);
    string word;
    while (separate >> word) {
        mapping.put(word);
    }
    mapping.display();
    cout << "\n\ntest copy constructor and sorting" << endl;
    HashMap map2(mapping);
    map2.display();

}

int main() {

    HashMap hashMap;

    cout << "Enter text \n";
    string input;
    getline(cin, input);

    countSymbolsLettersDigitsWordsSentences(input);
    replaceNonCharactersWithSpace(input);
    splitText(input);


}

