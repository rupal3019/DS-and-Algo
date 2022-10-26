//here, hum yha pe upr se level wise traverse kr rhe h.. jo node mil rhi h use overwrite kr rhe h
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

 vector<int> bottomView(node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        map<int,int> bottomNode;
        queue<pair<node*,int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<node*,int> temp = q.front();
            q.pop();
            
            node* frontNode= temp.first;
            int hd = temp.second;
       
            bottomNode[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto i:bottomNode){
            ans.push_back(i.second);
        }
        
        return ans;
    }