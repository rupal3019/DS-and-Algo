#include<bits/stdc++.h.>
using namespace std;

int main(){
    string ch = "rupal";
    stack<char> s;
    for(int i=0;i<ch.length();i++){
        s.push(ch[i]);
    }
    string ans= "";
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();

    }

    cout<<"ans is: "<<ans;
}