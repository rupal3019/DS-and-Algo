#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* a,int n){
    for(int i=1;i<n;i++){
        int temp = a[i];
        int j=i-1;

        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
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
    insertionSort(arr,n);
    cout << "printing";
    print(arr,n);
}