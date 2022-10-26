#include<bits/stdc++.h>
using namespace std;

//check if difference between left and right is not greater than 1

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

int height(node* root){
        // code here 
        if(root==NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right)+1;
    }
    //O(N^2)
bool isBalanced(node *root)
    {
        if(root == NULL){
            return 1;
        }
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
    
        bool third = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && third){
            return 1;
        }
        else{
            return 0;
        }
    }

    //O(N)
    pair<bool,int> isBalancedFast(node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(1,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool op1 = left.first;
        bool op2 = right.first;
        bool op3 = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        ans.second = max(left.second,right.second)+1;
        
        if(op1 && op2 && op3){
            ans.first = 1;
        }
        else{
            ans.first = 0;
        }
        return ans;
    }