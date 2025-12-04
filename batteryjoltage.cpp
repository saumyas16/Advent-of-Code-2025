#include <iostream>
#include <string>
#include <vector>
long long batterypower(std::vector<std::string> sequence) {
    long long sum = 0;
    for(auto s:sequence){
        int j = 12;
        std::string str = "";
        int start = 0;
        while(j>0){
            char maxx = '0';
            for(int i=start;i<=s.size()-j;i++){
                if(s[i]>maxx){
                    maxx = s[i];
                    start = i+1;
                }
            }
            str += maxx;
            j--;
        }
        sum += stoll(str);
    }
    return sum;
}
int main() {
    std::vector<std::string> sequence;
    std::string s;
    while (std::cin >> s) {
        sequence.push_back(s);
    }
    std::cout <<"The sum is: "<< batterypower(sequence) <<" !" << std::endl;
    return 0;
}