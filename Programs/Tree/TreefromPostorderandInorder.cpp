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

void createMapping(int in[],map<int,int> & nodeToIndex, int n){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}

node* solve(int in[],int post[],int &postOrderIndex, int inStart, int inEnd,int n,map<int,int> & nodeToIndex){
    //base
    if((inStart>inEnd)  || postOrderIndex<0){
        return NULL;
    }
    
    int element = post[postOrderIndex--];
    node* root = new node(element);

    // int position = getPos(in,element,n); 
    //with the help of map, yha hume position O(1) me nikaal li
    int position = nodeToIndex[element];        
    
    //yha phle right call kr rhe h.. kuki post order me hum (LRN) phle node lia.. fr use decrement krnge,
    // then right aaega fr left
    
    root->right = solve(in,post,postOrderIndex,position+1,inEnd,n,nodeToIndex);
    
    root->left = solve(in,post,postOrderIndex,inStart,position-1,n,nodeToIndex);
    
    return root;
    
}
//Function to return a tree created from postorder and inoreder traversals.
node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex = n-1;
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    node* ans = solve(in,post,postOrderIndex,0,n-1,n,nodeToIndex);
    return ans;
}