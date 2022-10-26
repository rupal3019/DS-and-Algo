//isme level by level and vertically traverse kr rhe h tree ko
//humne 2 chiz li h isme... 1: horizontal axis , 2: level

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

vector<int> verticalOrder(node *root)
    {
        //Your code here
        //first-> horizontal , second me-- 1:level , 2: values us level pe jo h
        map<int,map<int,vector<int>> > nodes;
        //first -> node , second--hor,level
        queue<pair<node*,pair<int,int> >> q;
        vector<int> ans;
        
        //base
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0))); //kuki starting me 0 level pe and 0 axis pe
        
        while(!q.empty()){
            pair<node*,pair<int,int>> temp = q.front();
            q.pop();
            node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i:nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }