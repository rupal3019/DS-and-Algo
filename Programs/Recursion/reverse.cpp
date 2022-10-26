#include<bits/stdc++.h>
using namespace std;

void reverse(int i, int j, string& s){
    if(i>j)
    return;

    swap(s[i],s[j]);
    i++;
    j--;

    reverse(i,j,s);
}

int main(){
    string name = "rupal";
    reverse(0,4,name);
    
    cout<<name;

}