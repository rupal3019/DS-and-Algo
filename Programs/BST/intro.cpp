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

node* insert(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }
    if(data > root->data){
        root->right = insert(root->right,data);
    }
    else{
        root->left = insert(root->left,data);
    }
    return root;
}

node* minVal(node* root){
    node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

node* maxVal(node* root){
    node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}


void takeinput(node* & root){
    int data;

    while(data!=-1){
        root = insert(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

node* deleteFromBST(node* root, int value){

    //base case
    if(root==NULL){
        return root;
    }

    if(root->data == value){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child

        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }

    else if(root->data < value){
        root->right = deleteFromBST(root->right,value);
        return root;
    }
    else{
        root->left = deleteFromBST(root->left,value);
        return root;
    }
}


int main(){

    node* root = NULL;

    cout<<"Enter data to enter: "<<endl;
    takeinput(root);

    cout<<"printing BST: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"minimum value is: "<<minVal(root)->data;

}