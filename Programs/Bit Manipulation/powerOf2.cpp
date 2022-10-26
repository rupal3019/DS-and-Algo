#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;
    bool ans = true;

    if(n&(n-1)!=0){
        ans = false;
    }
    //ans = true;

    cout<<ans;
}