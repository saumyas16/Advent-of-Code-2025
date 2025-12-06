#include <iostream>
#include <string>
#include <vector>
#include <sstream>
long long sumMathsOperations(std::vector<std::vector<long long>>& probNumbers, std::vector<std::string>& operators) {
    long long ans = 0;
    for(long long i = 0; i < operators.size(); i++) {
        long long sum = 0;
        long long prod = 1;
        if(operators[i] == "+") {
            for(int num: probNumbers[i]) {
                sum += num;
            }
            //std::cout<<"Sum for operator + at index "<<i<<" is "<<sum<<std::endl;
            ans += sum;
        } else if(operators[i] == "*") {
            for(int num: probNumbers[i]) {
                prod *= num;
            }
            //std::cout<<"Product for operator * at index "<<i<<" is "<<prod<<std::endl;
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
    
    std::istringstream iss(inputlines[inputlines.size()-1]);
    std::string op;
    while(iss >> op) {
        operators.push_back(op);
    }
    std::vector<long long> numbers;
    for(long long i = 0; i < inputlines[0].size(); i++) {
        //check for break
        bool isBreak=true;
        for(int j=0;j<inputlines.size()-1;j++){
            if(inputlines[j][i]!=' '){
                isBreak=false;
                break;
            }
        }
        if(isBreak==true){
            //clean the vector
            probNumbers.push_back(numbers);
            numbers.clear();
            continue;
        }
        else{
            int num = 0;
            for(int j=0;j<inputlines.size()-1;j++){
                if(inputlines[j][i]!=' ')
                    num = num*10 + (inputlines[j][i]-'0');
            }
            numbers.push_back(num);
        }
    }
    probNumbers.push_back(numbers);
    std::cout <<"The sum is: "<< sumMathsOperations(probNumbers, operators) <<" !" << std::endl;
    return 0;
}