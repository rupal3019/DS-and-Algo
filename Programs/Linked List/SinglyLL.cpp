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

void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &tail,Node* &head, int pos, int data){
    //beginning
    if(pos==1){
        InsertAtHead(head,data);
        return;
    }
    Node* temp = head;

    int count=1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    //end
    if(temp->next==NULL){
        InsertAtTail(tail,data);
        return;
    }

    Node *nodetoInsert = new Node(data);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}

void deleteNode(Node* &head, int position){
    
    //starting node
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //any other node
        Node* current = head;
        Node* previous = NULL;
        int count=1;
        while(count<position){
            previous = current;
            current = current->next;
            count++;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    //new Node
    Node* node1 = new Node(5);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    //head pointed to node1
     Node* head = node1;
    // print(head);
    // InsertAtHead(head,12);
    // print(head);
    // InsertAtHead(head,18);
    // print(head);

    //tail pointed to node1
    Node* tail = node1;
    print(head);
    InsertAtTail(tail,12);
    print(head);
    InsertAtTail(tail,15);
    print(head);
    InsertAtTail(tail,18);
    print(head);

    //insert at a position
    InsertAtPosition(tail,head,1,9);
    print(head);

    deleteNode(head,2);
    print(head);
}