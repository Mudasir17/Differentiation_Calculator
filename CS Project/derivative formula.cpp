//#include <iostream>
//#include <regex>
//#include <string>
//
//int main() {
//    std::string function = "f(x)";
//    std::string delta_x = "delta_x";
//
//    // Define the regex to find "f(x)"
//    std::regex func_regex("f\\(x\\)");
//
//    // Replace "f(x)" with "f(x + delta_x)"
//    std::string modified_function = std::regex_replace(function, func_regex, "f(x + " + delta_x + ")");
//
//    // Construct the derivative formula
//    std::string derivative_formula = "( " + modified_function + " - f(x) ) / " + delta_x;
//
//    std::cout << "Derivative formula: " << derivative_formula << std::endl;
//
//    return 0;
//}
//
//



#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Function to differentiate terms like "ax^b"
string differentiate_term(const string& term) {
    regex term_regex(R"((\s*[-+]?\s*\d*)x\^(\d+\s*))"); // Matches terms like "3x^2" or "-x^5"
    smatch match;

    if (regex_match(term, match, term_regex)) {
        int coefficient = (match[1].str().empty() || match[1].str() == "+") ? 1 :
                          (match[1].str() == "-") ? -1 : stoi(match[1].str());
        int exponent = stoi(match[2].str());

        if (exponent == 1) {
            return to_string(coefficient); // Result is just the coefficient
        }

        int new_coefficient = coefficient * exponent;
        int new_exponent = exponent - 1;
        if (new_exponent == 1) {
            return to_string(new_coefficient) + "x";
        } else {
            return to_string(new_coefficient) + "x^" + to_string(new_exponent);
        }
    }

    // Handle linear terms like "ax" (x^1)
    regex linear_regex(R"((\s*[-+]?\s*\d*)+[a-z]\s*)");
    if (regex_match(term, match, linear_regex)) {
        int coefficient = (match[1].str().empty() || match[1].str() == "+") ? 1 :
                          (match[1].str().empty() || match[1].str() == "-") ? -1 : stoi(match[1].str());
        return to_string(coefficient);
    }

    // Handle constants (derivative is 0)
    regex constant_regex(R"(\s*[-+]?\s*\d+\s*)");
    if (regex_match(term, match, constant_regex)) {
        return "0";
    }

    throw invalid_argument("Unsupported term: " + term);
}

// Function to differentiate an entire polynomial
string differentiate(const string& expression) {
    regex term_splitter(R"(([-+]?\d*x\^\d+|\s*\[-+]?\d*x|[-+]?\\s*d+))"); // Matches individual terms
    auto terms_begin = sregex_iterator(expression.begin(), expression.end(), term_splitter);
    auto terms_end = sregex_iterator();

    string result;
    for (sregex_iterator i = terms_begin; i != terms_end; ++i) {
        string term = i->str();
        string differentiated_term = differentiate_term(term);

        // Skip adding "0" terms
        if (differentiated_term != "0") {
            if (!result.empty() && differentiated_term[0] != '-') {
                result += " + "; // Add "+" for positive terms
            }
            result += differentiated_term;
        }
    }

    return result.empty() ? "0" : result;
}

int main() {
    string expression = "3x^3 + 2x^2 + x + 5"; // Example polynomial

    try {
        string derivative = differentiate(expression);
        cout << "Derivative of " << expression << " is " << derivative << endl;
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}

