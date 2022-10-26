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
//Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(node* root)
    {
    	// Code here
    	vector <int> res;
    	
    	if(root == NULL){
    	    return res;
    	}
    	
    	queue<node*> q;
    	q.push(root);
    	
        bool leftToRight = true;	
    
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> ans(size);
    	    for(int i=0;i<size;i++){
    	        node* temp = q.front();
    	        q.pop();
    	        
    	        int index = leftToRight?i : size-i-1;
    	        ans[index] = temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left);
    	        }
    	        if(temp->right){
    	            q.push(temp->right);
    	        }
    	    }
    	    leftToRight = !leftToRight;
    	    for(auto i:ans){
    	        res.push_back(i);
    	    }
    	}
    	return res;
    }