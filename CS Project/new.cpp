/*#include<iostream>
#include<regex>
#include<string>
using namespace std;
int main(){
string n;
cout << "Enter the senta to be seprated" << endl;
getline (cin,n);
regex number_regex("\\ d+");*/


#include <iostream>  // For printing
#include <regex>     // For pattern matching
#include <string>    // For using strings

int main() {
    std::string input = "123 apples and 456 oranges";  // The text to search in

    // Patterns to search for
    std::regex number_regex("\\d+");  // Find numbers
    std::regex word_regex("[a-zA-Z]+");  // Find words

    std::smatch match;  // Stores the result of each match

    // Find and print all numbers
    std::cout << "Numbers:" << std::endl;
    auto search_start = input.begin();
    while (std::regex_search(search_start, input.end(), match, number_regex)) {
        std::cout << match[0] << std::endl;  // Print the number found
        search_start = match.suffix().first;  // Move to the rest of the text
    }

    // Find and print all words
    std::cout << "Words:" << std::endl;
    search_start = input.begin();  // Start from the beginning again
    while (std::regex_search(search_start, input.end(), match, word_regex)) {
        std::cout << match[0] << std::endl;  // Print the word found
        search_start = match.suffix().first;  // Move to the rest of the text
    }

    return 0;
}
