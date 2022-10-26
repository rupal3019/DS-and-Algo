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

node* solve(node* root, int& k, int node){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==node){
        return root;
    }
    node* leftAns = solve(root->left,k,node);
    node* rightAns = solve(root->right,k,node);
    
    if((leftAns!=NULL && rightAns==NULL)){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if((leftAns==NULL && rightAns!=NULL)){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
    
int kthAncestor(node* root, int k, int node)
{
    // Code here
    
    node* ans = solve(root,k,node);
    if(ans==NULL || ans->data == node){
        return -1;
    }
    else{
        return ans->data;        
    }   
}