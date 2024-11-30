#include <iostream>
#include <regex>
#include <string>

// Function to calculate the derivative of a polynomial term
std::string derivativePolynomial(const std::string& term) {
    std::regex poly_regex(R"(([+-]?\s*\d*)x\^(\d+))");
    std::smatch match;

    if (std::regex_match(term, match, poly_regex)) {
        int coefficient = match[1].str().empty() ? 1 : std::stoi(match[1].str());
        int power = std::stoi(match[2].str());

        int new_coefficient = coefficient * power;
        int new_power = power - 1;

        if (new_power == 0) return std::to_string(new_coefficient); // Constant
        if (new_power == 1) return std::to_string(new_coefficient) + "x"; // Linear
        return std::to_string(new_coefficient) + "x^" + std::to_string(new_power); // Higher powers
    }

    // Handle cases like "5x" or constants
    std::regex linear_regex(R"(([+-]?\s*\d*)x)");
    if (std::regex_match(term, match, linear_regex)) {
        return match[1].str().empty() ? "1" : match[1].str(); // Derivative of "5x" is "5"
    }

    return "0"; // Constants
}

// Function to calculate the derivative of trigonometric functions
std::string derivativeTrig(const std::string& term) {
    std::regex trig_regex(R"((sin|cos|tan|sec|csc|cot)??([^)]+)??)");
    std::smatch match;

    if (std::regex_match(term, match, trig_regex)) {
        std::string func = match[1].str();
        std::string argument = match[2].str(); // e.g., "x"

        if (func == "sin") return "cos(" + argument + ")";
        if (func == "cos") return "-sin(" + argument + ")";
        if (func == "tan") return "sec^2(" + argument + ")";
        if (func == "sec") return "sec(" + argument + ")tan(" + argument + ")";
        if (func == "csc") return "-csc(" + argument + ")cot(" + argument + ")";
        if (func == "cot") return "-csc^2(" + argument + ")";
    }

    return "";
}

// Function to calculate the derivative of logarithmic functions
std::string derivativeLog(const std::string& term) {
    std::regex log_regex(R"((log|ln)??([^)]+)??)");
    std::smatch match;

    if (std::regex_match(term, match, log_regex)) {
        std::string func = match[1].str();
        std::string argument = match[2].str(); // e.g., "x"

        if (func == "ln") return "1/(" + argument + ")";
        if (func == "log") return "1/(" + argument + " * ln(10))";
    }

    return "";
}

// Function to calculate the derivative of exponential functions
std::string derivativeExp(const std::string& term) {
    std::regex exp_regex(R"(e\^([^)]+))");
    std::smatch match;

    if (std::regex_match(term, match, exp_regex)) {
        std::string argument = match[1].str(); // e.g., "x"
        return "e^(" + argument + ")";
    }

    return "";
}

int main() {
    std::string function = "3x^2+4x^2+1"; // Example input function

    // Regex patterns for different function types
    std::regex pattern(R"(([+-]?\s*\d*x\^\d+|[+-]?\s*\d*x|[+-]?\s*\d+)|\b(sin|cos|tan|sec|csc|cot)??[^??]+??|\b(log|ln)??[^??]+??|\be\^([^??]+))");
    std::smatch match;

    std::cout << "Original function: " << function << std::endl;
    std::cout << "Derivative: ";

    while (std::regex_search(function, match, pattern)) {
        std::string term = match[0];
        std::string derivative;

        if (std::regex_match(term, std::regex(R"([+-]?\s*\d*x\^\d+|[+-]?\s*\d*x|[+-]?\s*\d+)")))
            derivative = derivativePolynomial(term);
        else if (std::regex_match(term, std::regex(R"(\b(sin|cos|tan|sec|csc|cot)??[^??]+??)")))
            derivative = derivativeTrig(term);
        else if (std::regex_match(term, std::regex(R"(\b(log|ln)??[^??]+??)")))
            derivative = derivativeLog(term);
        else if (std::regex_match(term, std::regex(R"(\be\^([^??]+))")))
            derivative = derivativeExp(term);

        std::cout << derivative << " ";
        function = match.suffix().str(); // Continue searching the rest of the string
    }

    return 0;
}
