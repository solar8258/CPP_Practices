#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;




vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> cur;
    function<void()> dfs=[&](){
    if(nums.size()==cur.size()){
        ans.emplace_back(cur);
        return;
    }

    for(int v:nums){
        if(find(begin(cur),end(cur),v)!=end(cur)){
            continue;
        }
        cur.push_back(v);
        dfs();
        cur.pop_back();
    }
    };
    dfs();
    return ans;
}

int main(){
    vector<int> nums{1,2,3};
    vector<vector<int>> res=permute(nums);
    for(auto &val:res){
        cout<<'[';
        for(int v:val){
            cout<<v<<',';
        }
        cout<<"]\n";
    }
}