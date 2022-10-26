#include<bits/stdc++.h>
using namespace std;

//check if value is equal to the sum of its left subtree's value and its right subtree's value

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

pair<bool,int> isSumTreeFast(node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(1,0);
            return p;
        }
        
        if(root->left == NULL && root->right==NULL){
            pair<bool,int> p = make_pair(1,root->data);
            return p;
        }
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool op1 = left.first;
        bool op2 = right.first;
        bool op3 = root->data == (left.second + right.second);
        
        pair<bool,int> ans;
        if(op1 && op2 && op3){
            ans.first = 1;
            ans.second = 2*root->data;
        }
        else{
            ans.first = 0;
        }
        return ans;
    }