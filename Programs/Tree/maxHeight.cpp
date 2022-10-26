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

 int height(node* root){
        // code here 
        if(root==NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right)+1;
}