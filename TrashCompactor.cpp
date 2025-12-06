#include <iostream>
#include <string>
#include <vector>
#include <sstream>
long long sumMathsOperations(std::vector<std::vector<long long>>& probNumbers, std::vector<std::string>& operators) {
    long long ans = 0;
    for(long long i = 0; i < operators.size(); i++) {
        long long sum = 0;
        long long prod = 1;
        for(const auto& numbers : probNumbers) {
            if(operators[i] == "+") {
                    sum += numbers[i];
            } else if(operators[i] == "*") {
                    prod *= numbers[i];
            }
        }
        if(operators[i] == "+") {
            ans += sum;
        } else if(operators[i] == "*") {
            ans += prod;
        }
    }
    return ans;
}
int main() {
    std::vector<std::vector<long long>> probNumbers;
    std::vector<std::string> operators;

    std::vector<std::string> inputlines;
    std::string str;
    while(std::getline(std::cin, str)) {
        inputlines.push_back(str);
    }
    
    for(long long i = 0; i < inputlines.size(); i++) {
        std::istringstream iss(inputlines[i]);
        if(i!=inputlines.size()-1){
            std::vector<long long> numbers;
            long long number;
            while(iss >> number) {
                numbers.push_back(number);
            }
            probNumbers.push_back(numbers);
        }else{
            std::string op;
            while(iss >> op) {
                operators.push_back(op);
            }
        }
    }
    std::cout <<"The sum is: "<< sumMathsOperations(probNumbers, operators) <<" !" << std::endl;
    return 0;
}