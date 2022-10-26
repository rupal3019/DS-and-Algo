#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.empty() || s.top()<=temp){
        s.push(temp);
        return;
    }

    int x = s.top();
    s.pop();
    insert(s,temp);
    s.push(x);
}

void sort(stack<int> &s){
    //base
    if(s.empty())
    return;

    //hypothesis
    int temp = s.top();
    s.pop();
    sort(s);
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
    // vector<int> list = { 5, -2, 9, -7, 3 };
 
    // stack<int> s;
    // for (int i: list) {
    //     s.push(i);
    // }
    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(0);
    s.push(2);

    sort(s);
    cout<<"after sorting";
    print(s);


}