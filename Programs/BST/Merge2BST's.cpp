#include<bits/stdc++.h>
using namespace std;
class TreeNode{

    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};

//Approach 1
// time complexity - O(m+n)
//space complexity - O(m+n)

void inorder(TreeNode *root, vector<int> &arr){
    
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }
        else{
            ans[k++]=b[j++];
        }
    }
    
    while(i<a.size()){
        ans[k++]=a[i++];
    }
    while(j<b.size()){
        ans[k++]=b[j++];
    }
    
    return ans;
}

TreeNode *inordertoBST(int s, int e, vector<int> &in){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    
    TreeNode *root = new TreeNode(in[mid]);
    root->left = inordertoBST(s,mid-1,in);
    root->right = inordertoBST(mid+1,e,in);
    
    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
    
    //Store inorder
    vector<int> bst1,bst2;
    
    inorder(root1,bst1);
    inorder(root2,bst2);
    
    vector<int> mergedArray = mergeArrays(bst1,bst2);
    
    int s=0,e=mergedArray.size()-1;
    
    return inordertoBST(s,e,mergedArray);


}