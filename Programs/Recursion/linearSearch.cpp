#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[],int n,int key){
    if(n==0)
    return false;

    if(arr[0]==key)
    return true;

    return linearSearch(arr+1,n-1,key);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = 5;
    int key = 7;

    bool ans = linearSearch(arr,n,key);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }

}