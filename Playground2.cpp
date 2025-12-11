#include <iostream>
#include <string>
#include <vector>
std::vector<int> parent;
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

bool singleparent(std::vector<int>& parent) {
    int p = find_set(0);
    for(int i=1;i<parent.size();i++){
        if(find_set(i)!=p)
            return false;
    }
    return true;
}
long long closestConnections(std::vector<std::string>& xyz) {
    std::vector<std::vector<int>> xyzint(xyz.size(),std::vector<int>(3,0));
    for(int i=0;i<xyz.size();i++){
        int idx=xyz[i].find(',');
        int x=std::stoi(xyz[i].substr(0,idx));
        int idx2=xyz[i].find(',',idx+1);
        int y=std::stoi(xyz[i].substr(idx+1,idx2));
        int z=std::stoi(xyz[i].substr(idx2+1));
        xyzint[i][0]=x;
        xyzint[i][1]=y;
        xyzint[i][2]=z;
    }
    std::vector<std::pair<long long, std::pair<int,int> > > edges;
    for(int i=0;i<xyzint.size();i++){
        for(int j=i+1;j<xyzint.size();j++){
            long long dist=std::pow((xyzint[i][0]-xyzint[j][0]),2)+std::pow((xyzint[i][1]-xyzint[j][1]),2)+std::pow(xyzint[i][2]-xyzint[j][2],2);
            edges.push_back({dist,{i,j}});
        }
        make_set(i);
    }
    sort(edges.begin(),edges.end());
    int i = 0;
    while(singleparent(parent)==false){
        auto edge = edges[i];
        auto node1 = edge.second.first;
        auto node2 = edge.second.second;
        union_sets(node1,node2);
        i++;
    }
    return (long long)xyzint[edges[i-1].second.first][0]*(long long)xyzint[edges[i-1].second.second][0];
}
int main() {
    std::vector<std::string> xyz;
    std::string s;
    while (std::cin >> s) {
        xyz.push_back(s);
    }
    parent.resize(xyz.size());
    std::cout <<"The product is: "<< closestConnections(xyz) <<" !" << std::endl;
    return 0;
}