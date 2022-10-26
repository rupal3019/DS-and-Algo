#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v, int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int x = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(x);
}

void sort(vector<int>& v){
    //base condition
    if(v.size()<=1)
    return;
    //hypothesis
    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
}

int main(){
    vector<int> v = {1,3,2,5,4,6,5};
    sort(v);
    for(auto itr: v){
        cout<<itr<<" ";
    }
}