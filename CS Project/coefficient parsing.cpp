#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main() {
    
    string input;
    cout << "Enter the equation: ";
    getline(cin, input);

    
    regex parse(R"(([+-]?\s*[0-9]+|[+-]?\s*[\d+/\d+]+)(?=[a-z]))");
    smatch match; 

    
    while (std::regex_search(input, match, parse)) {
        
        std::cout << "Match found: " << match[0] << endl;

        
        input = match.suffix().str();
    }

    return 0;
}