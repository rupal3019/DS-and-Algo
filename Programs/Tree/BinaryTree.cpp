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

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data to insert on the left of: "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data to insert on the right of: "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
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

void ReverselevelOrderTraversal(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    // q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        // if(temp==NULL){
        //     cout<<endl;
        //     if(!q.empty()){
        //         q.push(NULL);
        //     }
        // }
        // else{
        s.push(temp);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        // }
    }
    while(!s.empty()){
    root = s.top();
    cout<<root->data<<" ";
    s.pop();
}
}

void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorder_Iterative(node* root){
    stack<node*> s;
    node* curr = root;

    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    int data;
    cout<<"Enter root data: ";
    cin>>data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }

}


int main(){

    node* root = NULL;
    
    //buildFromLevelOrder(root);
    //levelOrderTraversal(root);
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"Reverse level order traversal: ";
    // ReverselevelOrderTraversal(root);
    cout<<endl;
    cout<<"inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"inorder traversal: ";
    inorder(root);
    // cout<<endl;
    // cout<<"preorder traversal: ";
    // preorder(root);
    // cout<<endl;
    // cout<<"postorder traversal: ";
    // postorder(root);
    // cout<<endl;

}