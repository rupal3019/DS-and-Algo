#include<bits/stdc++.h>
using namespace std;

void print(int n){
    //base condition
    if(n==0)
    return;
    //induction
    cout<<n<<endl;
    //hypothesis
    print(n-1);
}

int main(){
    int n = 9;
    print(n);
}