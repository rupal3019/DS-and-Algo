#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[],int s, int e, int key){
    if(s>e){
        return false;
    }
    int mid = (s+e)/2;
    if(arr[mid]==key){
        return true;
    }

    if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }

}

int main(){
    int arr[7] = {1,5,3,7,4,8,6};
    int s = 0;
    int e = 6;
    int key = 1;

    bool ans = binarySearch(arr,s,e,key);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }

}