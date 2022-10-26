#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k){
    //base condition
    if(n==1 && k==1)
    return 0;
    //hypothesis
    int mid = pow(2,n-1)/2;
    if(k<=mid){
        return solve(n-1,k);
    }
    else{
        return !solve(n-1,k-mid);
    }
}

int main(){
    int n = 4,k=4;
    cout<<solve(n,k);
}