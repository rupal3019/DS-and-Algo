#include<bits/stdc++.h>
using namespace std;

//The diameter of a tree (sometimes called the width)
// is the number of nodes on the longest path between two end nodes.

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
    //O(N^2) complexity
    // Function to return the diameter of a Binary Tree.
    int diameter(node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + 1 + height(root->right);
        
        int ans =  max(op1,max(op2,op3));
        
        return ans;
    }
    //O(N) complexity
    pair<int,int> fastSol(node* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        //pair me first -> diameter , second-> height
        pair<int,int> left = fastSol(root->left);
        pair<int,int> right = fastSol(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + 1 + right.second;
        
        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second , right.second)+1;
        return ans;
    }