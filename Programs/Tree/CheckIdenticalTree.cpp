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
//Function to check if two trees are identical.
    bool isIdentical(node *r1, node *r2)
    {
        //Your Code here
        if(r1==NULL && r2 == NULL){
            return 1;
        }
        if(r1==NULL && r2 != NULL){
            return 0;
        }
        if(r1!=NULL && r2 == NULL){
            return 0;
        }
        
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        bool data = r1->data == r2->data;
        if(left && right && data){
            return 1;
        }
        else{
            return 0;
        }
    }