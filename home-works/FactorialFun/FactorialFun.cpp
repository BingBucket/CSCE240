#include<string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <chrono>
#include <iomanip>
#include <vector>

std::regex comparison("[C|c]ompare");

int factorial(int n) {
    //Returns 1 if n is 0 (stops recursion), throws an exception if n is negative, and returns n * factorial(n - 1) otherwise
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers");
    }
    else {
        return n * factorial(n - 1);
    }
}

int combination(int n, int r) {
    //Returns the combination of n and r using the factorial function.
    return factorial(n) / (factorial(r) * factorial(n - r));
}

//Used to return both the factorial and combination of n and r.
std::string compare(int n, int r) {
    std::string message;
    auto start = std::chrono::steady_clock::now();
    int value1 = factorial(n);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTaken = end - start;
    std::cout << "The factorial of " << n << " is " << factorial(n) << ". It took " << timeTaken.count() << " seconds to complete." << std::endl;
    auto start2 = std::chrono::steady_clock::now();
    int value2 = combination(n, r);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeTaken2 = end2 - start2;
    std::cout << "The combination of " << n << " and " << r << " is " << combination(n, r) << ". It took " << timeTaken2.count() << " seconds to complete." << std::endl;
    if(timeTaken > timeTaken2) {
        message = "\nIt took longer to calculate the factorial than the combination.";
    }
    else if(timeTaken < timeTaken2) {
        message = "\nIt took longer to calculate the combination than the factorial.";
    }
    else {
        message = "\nIt took the same amount of time to calculate the factorial and the combination.";
    }
    return message;
}

double measureTimeTakenFactorial(int n) {
    //Measures the time taken to calculate the factorial and combination of n and r.
    auto start = std::chrono::steady_clock::now();
    factorial(n);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

double measureTimeTakenCombination(int n, int r) {
    //Measures the time taken to calculate the combination of n and r.
    auto start = std::chrono::steady_clock::now();
    combination(n, r);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(end - start).count();

}

int main() {
    bool loop = true;
    std::string userResponse;
    std::vector<std::string> inputs;
    std::string word;
    do{
        std::cout << "Enter up to two numbers. Type 'compare' after to compare the time of calculation. Type 'exit' to quit the program." << std::endl;
        std::getline(std::cin, userResponse);
        std::stringstream query(userResponse);
        inputs.clear();
            while(std::getline(query, word, ' ')){
        inputs.push_back(word);
        }
        if(inputs.size() < 2){
                measureTimeTakenFactorial(std::stoi(inputs[0]));
                std::cout << "The factorial of " << inputs[0] << " is " << factorial(std::stoi(inputs[0])) << ". It took " << measureTimeTakenFactorial(std::stoi(inputs[0])) << " seconds to complete." << std::endl;
            }
        else if(inputs.size() > 1){
            if(regex_search(userResponse, comparison)){
                    std::cout << compare(std::stoi(inputs[0]), std::stoi(inputs[1])) << std::endl;
            }
            else{
                    measureTimeTakenCombination(std::stoi(inputs[0]), std::stoi(inputs[1]));
                    std::cout << "The combination of " << inputs[0] << " and " << inputs[1] << " is " << combination(std::stoi(inputs[0]), std::stoi(inputs[1])) << ". It took " << measureTimeTakenCombination(std::stoi(inputs[0]), std::stoi(inputs[1])) << " seconds to complete." << std::endl;
            }
            }
        if(regex_search(userResponse, std::regex("exit"))){
            loop = false;
        }



    }
    while(loop == true);
    return 0;
}