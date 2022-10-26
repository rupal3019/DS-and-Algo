#include<bits/stdc++.h>
using namespace std;

void selectionSort(int* a,int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a[min],a[i]);

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
    selectionSort(arr,n);
    cout << "printing";
    print(arr,n);
}