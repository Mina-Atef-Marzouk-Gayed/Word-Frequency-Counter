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

    string text = "We are a social media platform designed to help users find and share information about the latest news, events, and trends around the world. We believe in the power of people to share and collaborate on knowledge, and we are committed to fostering a community of curious learners who want to expand their understanding of the world around them. We offer a wide range of features and resources to help users stay up-to-date with the latest trends and developments in their areas of interest, from politics and business to science and culture.";
   cout << "Please input any text you would like : ";
   getline(cin, text); //We are a social media platform designed to help users find and share information about the latest news, events, and trends around the world.We believe in the power of people to share and collaborate on knowledge, and we are committed to fostering a community of curious learners who want to expand their understanding of the world around them.We offer a wide range of features and resources to help users stay up - to - date with the latest trends and developments in their areas of interest, from politics and business to science and culture.
    replaceNonCharactersWithSpace(text);
    splitText(text);

    return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
