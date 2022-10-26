#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //Constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertNode(Node* &tail,int element, int data){
    Node* temp = new Node(data);
    
    //empty
    if(tail==NULL){
        tail = temp;
        temp->next = temp;
    }
    else{
        //non empty
        Node* curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;

    }
}

void print(Node* &tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}

bool isCircular(Node* head){
    if(head==NULL){
        return false;
    }
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

bool detectLoop(Node* head){
    //first approach
    if(head==NULL){
        return false;
    }
    Node* temp = head;
    map<Node*,bool> visited;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;

}

bool floydDetectionLoop(Node* head){
    if(head==NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
        return true;
        } 
    }

    return false;
}

void deleteNode(Node* &tail, int value){
    
    //starting node
    if(tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        //any other node
        Node* previous = tail;
        Node* current = previous->next;
        while(current->data!=value){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        //only 1 node
        if(current==previous){
            tail=NULL;
        }
        //more than 1 node
        if(tail==current){
            tail = previous;
        }
        current->next = NULL;
        delete current;
    }
}

int main(){
    Node* tail = NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,9);
    print(tail);
    insertNode(tail,5,7);
    print(tail);
    deleteNode(tail,3);
    print(tail);
}
