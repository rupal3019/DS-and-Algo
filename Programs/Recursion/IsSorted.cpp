#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    if(n==0 || n==1)
    return 1;

    if(arr[0]>arr[1])
    return 0;

    return isSorted(arr+1,n-1);
}

int main(){

    int arr[5] = {1,2,4,5,6};
    int n = 5;

    bool ans = isSorted(arr,n);
    cout<<"ans : "<<ans;
}