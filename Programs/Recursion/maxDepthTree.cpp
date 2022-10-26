#include<bits/stdc++.h>
using namespace std;

class Treenode{
    public:
    int data;
    Treenode* left = NULL;
    Treenode* right = NULL;

    Treenode(int n){
        data = n;
    }
};

int maxDepth(Treenode* root){
    //base
    if(root == NULL)
    return 0;
    ////hypothesis
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    //induction
    return max(left,right) + 1; // we need to add root as well, that is why we add 1 here
}

int main(){
    Treenode* root = new Treenode(1);
    root->left = new Treenode(2);
    root->right = new Treenode(3);
    root->left->left = new Treenode(4);
    root->right->right = new Treenode(5);
    root->left->left->left = new Treenode(6);
    cout<<maxDepth(root);
}