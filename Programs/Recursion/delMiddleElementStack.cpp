#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int mid){
    if(s.size()==1){
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();
    solve(s,mid-1);
    return s.push(x);
}

void midDel(stack<int> &s){
    //base condition
    if(s.size()==0){
        return;
    }
    //hypothesis
    int mid = s.size()/2 + 1;

    return solve(s,mid);
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
    //s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(1);
    s.push(0);
    s.push(2);
    midDel(s);
    print(s);

    
}