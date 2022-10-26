#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int* a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void print(int* a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){

    int arr[6] = {4,6,3,2,5,7};
    int n=6;
    bubbleSort(arr,n);
    cout << "printing";
    print(arr,n);
}