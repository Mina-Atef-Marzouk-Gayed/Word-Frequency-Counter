// HashMapProjectData.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <sstream>
#include "hashmap.h"
using namespace std;

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
   // cout << "Please input any text you would like : ";
   // getline(cin, text); //We are a social media platform designed to help users find and share information about the latest news, events, and trends around the world.We believe in the power of people to share and collaborate on knowledge, and we are committed to fostering a community of curious learners who want to expand their understanding of the world around them.We offer a wide range of features and resources to help users stay up - to - date with the latest trends and developments in their areas of interest, from politics and business to science and culture.
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
