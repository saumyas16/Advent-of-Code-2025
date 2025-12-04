#include <iostream>
#include <string>
#include <vector>
int password(std::vector<std::string> sequence) {
    int pass = 0;
    int dial = 50;
    for (auto s : sequence) {
        int move = 0;
        if(s[0]=='L'){
            move = stoi(s.substr(1))*-1;
        }else{
            move = stoi(s.substr(1));
        }
        dial += move;
        dial %= 100;
        
        if(dial == 0)
            pass++;
    }
    return pass;
}
int main() {
    std::vector<std::string> sequence;
    std::string s;
    while (std::cin >> s) {
        sequence.push_back(s);
    }
    std::cout <<"Password is: "<< password(sequence) <<" !" << std::endl;
    return 0;
}