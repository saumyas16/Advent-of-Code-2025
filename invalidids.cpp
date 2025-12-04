#include <iostream>
#include <string>
#include <vector>
long long suminvalidids(std::vector<std::string> sequence) {
    long long sum = 0;
    for(auto s:sequence){
        std::cout<<s<<std::endl;
        int idx = s.find('-');
        long long dash1 = stoll(s.substr(0,idx));
        long long dash2 = stoll(s.substr(idx+1));
        while(dash1<=dash2){
            std::string sid = std::to_string(dash1);
            int size = sid.size();
            std::string firsthalf = sid.substr(0,size/2);
            std::string secondhalf = sid.substr(size/2);
            if(firsthalf==secondhalf){
                sum += dash1;
                std::cout<<"Adding "<<dash1<<" to sum"<<std::endl;
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