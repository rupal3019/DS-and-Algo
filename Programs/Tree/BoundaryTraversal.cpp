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

void traverseLeft(node* root,vector<int>& ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else{
            traverseLeft(root->right,ans);
        }
    }
    
    void traverseRight(node* root,vector<int>& ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            traverseRight(root->right,ans);
        }
        else{
            traverseRight(root->left,ans);
        }
        ans.push_back(root->data);
        
    }
    
    void traverseLeaf(node* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);  
            return;
        }
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
    }

    vector <int> boundary(node *root)
    {
        //Your code here
        vector <int> ans;
        if(root==NULL){
            return ans;
        }
        //First -> root print kro
        ans.push_back(root->data);
        
        //second -> left print kro except leaf node
        traverseLeft(root->left,ans);
        
        //third-> leaf nodes
        
        //left subtree
        traverseLeaf(root->left,ans);
        //right subtree
        traverseLeaf(root->right,ans);
        
        //fourth -> right print kro reverse me
        traverseRight(root->right,ans);
        
        return ans;
    }
