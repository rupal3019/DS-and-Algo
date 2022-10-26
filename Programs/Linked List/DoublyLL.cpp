#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        tail = temp;
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* temp = new Node(data);
    if(tail==NULL){
        tail = temp;
        head = temp;
    }
    else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head, int pos, int data){
    if(pos==1){
        insertAtHead(head,tail,data);
    }
    Node* temp = head;
    int count=1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    //end
    if(temp->next==NULL){
        insertAtTail(head,tail,data);
        return;
    }

    Node* nodetoInsert = new Node(data);
    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;
    temp->next = nodetoInsert;
    nodetoInsert->prev = temp;
}

void deleteNode(Node* &head, int position){
    
    //starting node
    if(position==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    //cout<<getLength(head)<<endl;

    insertAtHead(head,tail,15);
    print(head);

    insertAtHead(head,tail,20);
    print(head);

    insertAtHead(head,tail,25);
    print(head);

    insertAtTail(head,tail,5);
    print(head);

    insertAtPosition(tail,head,4,18);
    print(head);

    deleteNode(head,1);
    print(head);
}

