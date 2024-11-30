#include <iostream>
#include <sstream>
#include <string>

int main() {
//    int id = 42;
//    double salary = 12345.67;
//    std::stringstream ss;
//
//    ss << "ID: " << id << ", Salary: $" << salary;
//
//    std::string result = ss.str(); // Extract the string
//    std::cout << result << '\n';
//
//    return 0;

    std::cout << "Enter an expression: ";
    std::string user_input;
    std::getline(std::cin, user_input); // Read the entire line of input from the user

    std::stringstream ss(user_input);

    std::string num;
    while (ss >> num) {
        std::cout << "Parsed number: " <<num << '\n';
    }

    return 0;


}

