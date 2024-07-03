#include<iostream>
#include<vector>
#include<memory>

using namespace std;


class SegmentTreeNode{
    public:
        SegmentTreeNode(int start,int end,int sum,
                        SegmentTreeNode* left=nullptr,
                        SegmentTreeNode* right=nullptr):
            start(start),
            end(end),
            sum(sum),
            left(left),
            right(right){}
        SegmentTreeNode(const SegmentTreeNode&)=delete;
        SegmentTreeNode& operator=(const SegmentTreeNode&)=delete;
        ~SegmentTreeNode(){
            cout<<"Dtor called for: "<<sum<<" with range of: "<<start<<" and "<<end<<'\n';
            delete left;
            delete right;
            left=right=nullptr;
        }
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_.swap(nums);
        if(!nums_.empty())
            root_.reset(buildTree(0,nums_.size()-1));
    }

    void update(int index, int val) {
        updateTree(root_.get(),index,val);
    }

    int sumRange(int left, int right) {
        return sumRange(root_.get(),left,right);
    }
private:
    vector<int> nums_;
    std::unique_ptr<SegmentTreeNode> root_;
    SegmentTreeNode* buildTree(int start,int end){
        if(start==end){
            return new SegmentTreeNode(start,end,nums_[start]);
        }
        int mid=start+(end-start)/2;
        auto left=buildTree(start,mid);
        auto right=buildTree(mid+1,end);
        return new SegmentTreeNode(start,end,left->sum+right->sum,left,right);
    }
    void updateTree(SegmentTreeNode* root,int i,int val){
        if(root->start==i&&root->end==i){
            root->sum=val;
            return;
        }
        int mid=root->start+(root->end-root->start)/2;
        if(i<=mid){
            updateTree(root->left,i,val);
        }
        else{
            updateTree(root->right,i,val);
        }
        root->sum=root->left->sum+root->right->sum;
    }

    int sumRange(SegmentTreeNode* root,int i,int j){
        if(i==root->start&&j==root->end){
            return root->sum;
        }
        int mid=root->start+(root->end-root->start)/2;
        if(j<=mid){
            return sumRange(root->left,i,j);
        }
        else if(i>mid){
            return sumRange(root->right,i,j);
        }
        else{
            return sumRange(root->left,i,mid)+sumRange(root->right,mid+1,j);
        }
    }
};

int main(){
    vector<int> nums{1,12,30,4,59,6,87,-8};
    cout<<NumArray(nums).sumRange(0,1)<<'\n';
}