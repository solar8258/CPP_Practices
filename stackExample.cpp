#include<iostream>
#include<stack>
#include<vector>

using namespace std;


vector<int>  greaterNumbers(vector<int> &nums){
    const int n=nums.size();
    // vector<int> ans(n,-1);

    stack<int> st;

    for(int i=2*n-1;i>=0;i--){
        int x=nums[i%n];  //nums=[1,2,1], n=3, 2*n-1=2*3-1=5,  5%3=2
        while(!st.empty()&&st.top()<=x){
            st.pop();
        }
        if(i<n){
            if(!st.empty()){
                nums[i]=st.top();
            }
            else{
                nums[i]=-1;
            }
        }
        st.push(x);
    }
    return nums;
}

int main(){
    vector<int> nums{1,2,1};
    vector<int> res=greaterNumbers(nums);
    for(auto &v:res){
        cout<<v<<',';
    }
}