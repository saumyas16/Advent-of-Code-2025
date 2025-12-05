#include <iostream>
#include <string>
#include <vector>
int forklifting(std::vector<std::string> sequence) {
    int sum = 0;
    for(int i=0;i<sequence.size();i++){
        for(int j=0;j<sequence[i].size();j++){
            if(sequence[i][j]=='.') continue;
            int count = 0;
            if(i-1>=0&&j-1>=0){
                if(sequence[i-1][j-1]=='@') count++;
                if(sequence[i-1][j]=='@') count++;
                if(sequence[i][j-1]=='@') count++;
            }else if(i-1>=0){
                if(sequence[i-1][j]=='@') count++;
            }else if(j-1>=0){
                if(sequence[i][j-1]=='@') count++;
            }
            if(i+1<sequence.size()&&j+1<sequence[i].size()){
                if(sequence[i+1][j+1]=='@') count++;
                if(sequence[i+1][j]=='@') count++;
                if(sequence[i][j+1]=='@') count++;
            }else if(i+1<sequence.size()){
                if(sequence[i+1][j]=='@') count++;
            }else if(j+1<sequence[i].size()){
                if(sequence[i][j+1]=='@') count++;  
            }
            if(i-1>=0&&j+1<sequence[i].size()){
                if(sequence[i-1][j+1]=='@') count++;
            }
            if(i+1<sequence.size()&&j-1>=0){
                if(sequence[i+1][j-1]=='@') count++;
            }
            if(count<4){
                sum++;
                //std::cout<<"Position "<<i<<","<<j<<" is weak with "<<count<<" supports."<<std::endl;
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
    std::cout <<"The sum is: "<< forklifting(sequence) <<" !" << std::endl;
    return 0;
}