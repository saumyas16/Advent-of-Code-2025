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
        
        int dialnew = dial + move;
        dialnew %= 100;
        if(dialnew<0) dialnew += 100;
        //std::cout<<dialnew<<std::endl;
        if(dialnew!=0&&dial!=0){
            if(s[0]=='L'){
                if(dialnew>dial){pass++;
                }
            }else{
                if(dialnew<dial){ pass++;
                }
            }
        }
        if(abs(move)>100)
            pass += abs(move)/100;
        if(dialnew == 0){
            pass++;
        }
        dial = dialnew;
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