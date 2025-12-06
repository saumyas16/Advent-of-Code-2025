#include <iostream>
#include <string>
#include <vector>
int sumfreshvegetables(std::vector<std::string>& ranges, std::vector<std::string>& values) {
    int sum = 0;
    for(auto val: values){
        for(auto range: ranges){
            int idx = range.find('-');
            std::string lowerStr = range.substr(0,idx);
            std::string upperStr = range.substr(idx+1);
            //if(val.size()>=lowerStr.size()&&val.size()<=upperStr.size() &&val.compare(lowerStr) >= 0 && val.compare(upperStr) <= 0){
            if(stoll(val)>=stoll(lowerStr) &&stoll(val)<=stoll(upperStr)){
                sum++;
                //std::cout<<"Value "<<val<<" is in range "<<range<<std::endl;
                break;
            }
        }
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
    std::cout <<"The sum is: "<< sumfreshvegetables(ranges, values) <<" !" << std::endl;
    return 0;
}