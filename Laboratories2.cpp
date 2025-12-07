#include <iostream>
#include <string>
#include <vector>
long long splitsum(std::vector<std::string>& sequence) {
    for(long long i=0;i<sequence.size();i++){
        for(long long j=0;j<sequence[i].size();j++){
            if(sequence[i][j]=='S')
                sequence[i][j]='|';
            if(sequence[i][j]=='|'){
                if(i+1<sequence.size()){
                    if(sequence[i+1][j]=='.')
                        sequence[i+1][j]='|';
                    else{
                        if(sequence[i+1][j]=='^'){
                            if(j-1>=0&&sequence[i+1][j-1]=='.'){
                                sequence[i+1][j-1]='|';
                            }
                            if(j+1<sequence[i].size()&&sequence[i+1][j+1]=='.'){
                                sequence[i+1][j+1]='|';
                            }
                        }
                    }
                }
            }
        }
    }
    std::vector<std::vector<long long>> dp(sequence.size(),std::vector<long long>(sequence[0].size(),0));
    for(long long i=0;i<sequence.size();i++){
        for(long long j=0;j<sequence[i].size();j++){
            if(i==0){
                if(sequence[i][j]=='|'){
                    dp[i][j]=1;
                }
            }else{
                if(sequence[i][j]=='|'){
                    dp[i][j]=dp[i-1][j];
                    if(j-1>=0&&sequence[i-1][j-1]=='|'&&sequence[i][j-1]=='^'){
                        dp[i][j]+=dp[i-1][j-1];
                    }
                    if(j+1<sequence[i].size()&&sequence[i-1][j+1]=='|'&&sequence[i][j+1]=='^'){
                        dp[i][j]+=dp[i-1][j+1];
                    }
                }
            }
        }
    }
    long long sum=0;
    for(long long j=0;j<sequence[0].size();j++){
        sum+=dp[sequence.size()-1][j];
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