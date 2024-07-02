#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>> two{{1,2},{3,4}};
    vector<int> res=two.front();
    for(int v:res)
        cout<<v<<',';
}