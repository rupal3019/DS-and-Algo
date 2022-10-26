#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
    }
};

//yha pe hum sum,maxSum,len,maxLen le rhe h
// hume max sum nikalna h sbse zada length ka(root to leaf)

void solve(node* root,int len,int& maxLen,int sum,int& maxSum){
        
        if(root==NULL){
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len==maxLen){
                maxSum = max(sum,maxSum);
            }
            return;
        }    
        sum +=root->data;
        solve(root->left,len+1,maxLen,sum,maxSum);
        solve(root->right,len+1,maxLen,sum,maxSum);
        
    }
    
    
    int sumOfLongRootToLeafPath(node *root)
    {
        //code here
        int len=0;
        int maxLen = 0;
        int sum=0;
        int maxSum=0;
        
        solve(root,len,maxLen,sum,maxSum);
        return maxSum;
    }