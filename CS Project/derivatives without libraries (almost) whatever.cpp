#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

// A function to parse the polynomial terms
vector<string> parseExpression(const string& expression) {
    vector<string> terms;
    regex term_regex(R"(([+-]?\s*\d*x\^\d+|[+-]?\s*\d*x|[+-]?\s*\d+))");
    sregex_iterator iter(expression.begin(), expression.end(), term_regex);
    sregex_iterator end;

    while (iter != end) {
        terms.push_back(iter->str());
        ++iter;
    }
    return terms;
}

// A function to compute the derivative of a term
string differentiateTerm(const string& term) {
    regex power_regex(R"(([+-]?\d*)x\^(\d+))");
    regex linear_regex(R"(([+-]?\d*)x)");
    regex constant_regex(R"(([+-]?\d+))");

    smatch match;
    if (regex_match(term, match, power_regex)) {
        // Term is of the form ax^n
        int coefficient = match[1].str().empty() || match[1].str() == "+" ? 1 : (match[1].str() == "-" ? -1 : stoi(match[1].str()));
        int power = stoi(match[2].str());
        int new_coefficient = coefficient * power;
        int new_power = power - 1;
        if (new_power == 0) {
            return to_string(new_coefficient);
        } else if (new_power == 1) {
            return to_string(new_coefficient) + "x";
        } else {
            return to_string(new_coefficient) + "x^" + to_string(new_power);
        }
    } else if (regex_match(term, match, linear_regex)) {
        // Term is of the form ax
        int coefficient = match[1].str().empty() || match[1].str() == "+" ? 1 : (match[1].str() == "-" ? -1 : stoi(match[1].str()));
        return to_string(coefficient);
    } else if (regex_match(term, match, constant_regex)) {
        // Term is a constant
        return "0";
    }
    return "";
}

// A function to compute the derivative of the entire expression
string differentiateExpression(const string& expression) {
    vector<string> terms = parseExpression(expression);
    string result;
    for (const auto& term : terms) {
        string derivative = differentiateTerm(term);
        if (!derivative.empty() && derivative != "0") {
            if (!result.empty() && derivative[0] != '-') {
                result += "+";
            }
            result += derivative;
        }
    }
    return result;
}

int main() {
    // Predefined expression
    string expression = "sin(x)+x^6+3";
    cout << "Original expression: " << expression << '\n';

    // Compute its derivative
    string derivative = differentiateExpression(expression);
    cout << "Derivative: " << derivative << '\n';

    return 0;
}

