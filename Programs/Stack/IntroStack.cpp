#include<bits/stdc++.h>
using namespace std;

//Implementation using Array

class Stack{
    //properties
    public:
    int* arr;
    int top;
    int size;

    //behaviour

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }

    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"empty stack"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};


int main(){

    Stack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    cout<<"top element: "<<s.peek()<<endl;

    s.pop();

    cout<<"top element: "<<s.peek()<<endl;

    // stack<int> s;

    // s.push(1);
    // s.push(2);
    // s.push(3);

    // s.pop();

    // cout<<"Top element: "<<s.top()<<endl;

    // cout<<"Number of elements: "<<s.size()<<endl;

    // if(s.empty()){
    //     cout<<"empty"<<endl;
    // }
    // else{
    //     cout<<"Not empty"<<endl;
    // }
}