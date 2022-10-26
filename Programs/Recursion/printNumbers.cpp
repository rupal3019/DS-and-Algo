#include<bits/stdc++.h>
using namespace std;

void print(int n){
    //base condition
    if(n==0)
    return;
    //hypothesis
    print(n-1);
    //induction
    cout<<n<<endl;
}

int main(){
    int n = 9;
    print(n);
}