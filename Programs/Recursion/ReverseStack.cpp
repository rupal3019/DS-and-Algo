#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.size()==0){
        s.push(temp);
        return;
    }

    int x = s.top();
    s.pop();
    insert(s,temp);

    s.push(x);
}

void reverse(stack<int> &s){
    //base condition
    if(s.size()==1){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);

}

void print(stack<int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(0);
    s.push(2);

    print(s);
}