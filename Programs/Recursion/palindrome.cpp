#include<bits/stdc++.h>
using namespace std;

bool palindrome(int i, int j, string& s){
    if(i>j)
    return false;

    if(s[i]==s[j]){
        return true;
        i++;
        j--;
    }
    else{
        return false;
    }

    palindrome(i,j,s);

}

int main(){
    string name = "rupal";
    bool ans = palindrome(0,4,name);
    if(ans){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

}