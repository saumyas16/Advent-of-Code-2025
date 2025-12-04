#include <iostream>
#include <string>
#include <vector>
#include <regex>
long long suminvalidids(std::vector<std::string> sequence) {
    long long sum = 0;
    for(auto s:sequence){
        std::cout<<s<<std::endl;
        int idx = s.find('-');
        long long dash1 = stoll(s.substr(0,idx));
        long long dash2 = stoll(s.substr(idx+1));
        while(dash1<=dash2){
            std::string sid = std::to_string(dash1);
            int strsize = sid.size();
            for(int i=0;i<=strsize/2;i++){
                std::string tofind = sid.substr(0,i);
                int countOccurrences = strsize - std::regex_replace(sid, std::regex(tofind), "").length();
                if(countOccurrences==strsize){
                    sum += dash1;
                    std::cout<<"Adding "<<dash1<<" to sum"<<std::endl;
                    break;
                }  
            }
            dash1++;
        }
    }
    return sum;
}
int main() {
    std::vector<std::string> sequence;
    std::string s;
    while (std::getline(std::cin, s, ',')) {  
        sequence.push_back(s);
    }
    std::cout <<"The sum is: "<< suminvalidids(sequence) <<" !" << std::endl;
    return 0;
}