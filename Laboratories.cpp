#include <iostream>
#include <string>
#include <vector>
int splitsum(std::vector<std::string>& sequence) {
    int sum = 0;
    for(int i=0;i<sequence.size();i++){
        for(int j=0;j<sequence[i].size();j++){
            if(sequence[i][j]=='S')
                sequence[i][j]='|';
            if(sequence[i][j]=='|'){
                if(i+1<sequence.size()){
                    if(sequence[i+1][j]=='.')
                        sequence[i+1][j]='|';
                    else{
                        if(sequence[i+1][j]=='^'){
                            if(j-1>=0){
                                sequence[i+1][j-1]='|';
                            }
                            if(j+1<sequence[i].size()){
                                sequence[i+1][j+1]='|';
                            }
                            sum++;
                        }
                    }
                }
            }
        }
    }
    return sum;
}
int main() {
    std::vector<std::string> sequence;
    std::string s;
    while (std::cin >> s) {
        sequence.push_back(s);
    }
    std::cout <<"The sum is: "<< splitsum(sequence) <<" !" << std::endl;
    return 0;
}