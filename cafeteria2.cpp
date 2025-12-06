#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
long long sumfreshvegetables(std::vector<std::string>& ranges) {
    std::cout<<ranges.size()<<" initial ranges."<<std::endl;

    for(int i=0;i<ranges.size();i++){
        if(ranges[i].empty()) continue;
        int idx1 = ranges[i].find('-');
        std::string lowerStr1 = ranges[i].substr(0,idx1);
        std::string upperStr1 = ranges[i].substr(idx1+1);
        for(int j=i+1;j<ranges.size();j++){
            if(ranges[j].empty()) continue;
            int idx2 = ranges[j].find('-');
            std::string lowerStr2 = ranges[j].substr(0,idx2);
            std::string upperStr2 = ranges[j].substr(idx2+1);
            if(!(stoll(upperStr1)<stoll(lowerStr2)||stoll(upperStr2)<stoll(lowerStr1))){
                std::string newLower = std::to_string(std::min(stoll(lowerStr1),stoll(lowerStr2)));
                std::string newUpper = std::to_string(std::max(stoll(upperStr1),stoll(upperStr2)));
                ranges[i] = newLower + "-" + newUpper;
                ranges.erase(ranges.begin()+j);
                i--;
                break;
            }
        }
    }
    std::cout<<ranges.size()<<" merged ranges."<<std::endl;
    long long sum = 0;
    for(auto range: ranges){
        if(range.empty()) continue;
        int idx = range.find('-');
        std::string lowerStr = range.substr(0,idx);
        std::string upperStr = range.substr(idx+1);
        std::cout<<"Final Range: "<<lowerStr<<"-"<<upperStr<<std::endl;
        sum += (stoll(upperStr)-stoll(lowerStr)+1);
    }
    return sum;
}
int main() {
    std::vector<std::string> ranges;
    std::vector<std::string> values;

    std::string line;
    bool readingRanges = true;

    while (std::getline(std::cin, line)) {
        // Switch to second vector when blank line is found
        if (line.empty()) {
            readingRanges = false;
            continue;
        }

        if (readingRanges) {
            ranges.push_back(line);
        } else {
            values.push_back(line);
        }
    }
    std::cout <<"The sum is: "<< sumfreshvegetables(ranges) <<" !" << std::endl;
    return 0;
}