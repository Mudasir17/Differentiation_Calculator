#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// A function to parse the polynomial terms using vectors
vector<string> parseExpression(const string expression) {
    vector<string> terms;
    string currentTerm = "";

    for (size_t i = 0; i < expression.size(); i++) {
        char c = expression[i];

        // Start a new term if a '+' or '-' is found (not the first character)
        if ((c == '+' || c == '-') && !currentTerm.empty()) {
            terms.push_back(currentTerm);
            currentTerm = c; // Start a new term with the current sign
        } else {
            currentTerm += c; // Add character to the current term
        }
    }

    // Add the last term if it's not empty
    if (!currentTerm.empty()) {
        terms.push_back(currentTerm);
    }

    return terms;
}

int main() {
    string expression = "3x^2 - 4x + 5";
    vector<string> terms = parseExpression(expression);

    cout << "Parsed terms:" << endl;
    for (const string term : terms) {
        cout << term << endl;
    }

    return 0;
}

