//yha pe hum har path ka sum nikal rhe h.. mtlb ki jse jse tree traverse kr rhe h to uski value vector me 
// store kr rhe h and sum variable me add kr rhe h.. then check kr rhe h ki vo 'K' ke equal h ya nhi
// end me upr jate time us value ko pop kr rhe h

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

void solve(node* root,vector<int>& path,int k,int& count){
        if(root==NULL)
            return;
            
        path.push_back(root->data);
        
        solve(root->left,path,k,count);
        solve(root->right,path,k,count);
        
        int s = path.size();
        int sum=0;
        for(int i=s-1;i>=0;i--){
            sum+=path[i];
            
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(node *root,int k)
    {
        // code here 
        vector<int> path;
        
        int count=0;
        
        solve(root,path,k,count);
        return count;
    }