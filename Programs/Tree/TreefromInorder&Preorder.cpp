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

int getPos(int in[],int element, int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    node* solve(int in[],int pre[],int &preOrderIndex, int inStart, int inEnd,int n){
        //base
        if((inStart>inEnd)  || preOrderIndex>=n){
            return NULL;
        }
        
        //finding root node
        int element = pre[preOrderIndex++];
        node* root = new node(element);
        //getting element position in inOrder
        int position = getPos(in,element,n);
        
        root->left = solve(in,pre,preOrderIndex,inStart,position-1,n); // LNR
        root->right = solve(in,pre,preOrderIndex,position+1,inEnd,n); //LNR
        
        return root;
        
    }
    
    
    node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0; // starting root hota hai preOrder me
        node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }