#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int s, int e){
    
    int pivot = arr[s];

    int count=0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    int pivotIndex = s+count;

    //place the pivot to the right
    swap(arr[s],arr[pivotIndex]);

    //left and rightpart sambhalo
    int i = s;
    int j=e;

    while(i<pivot && j>pivot){
        while(i<pivot)
            i++;

        while(j>pivot)
            j--;
        
        if(i<pivot && j>pivot){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int s,int e){
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}

int main(){

    int arr[5]={2,1,4,3,5};

    int n=5;    

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}