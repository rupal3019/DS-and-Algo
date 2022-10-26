#include<bits/stdc++.h>
using namespace std;


void explainPair(){

    pair<int,int> p = {1,3};

    cout<<p.first<<" "<<p.second<<endl; //prints 1 3

    pair<int,pair<int,int>> pr = {1,{2,3}}; 
    cout<<p.first<<" "<<pr.second.first<< ""<<pr.second.first<<endl; // prints 1 2 3

    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};

    cout<<arr[1].second<<endl; //prints 4

}

void explainVector(){

    //empty vector
    vector<int> v;

    v.push_back(1); //{1}
    v.emplace_back(2); //{1,2} these 2 commands are almost same

    vector<pair<int,int>> vec;
    vec.push_back({1,2}); // {{1,2}} //it will be stores as a pair in it
    vec.emplace_back(3,4); // {{1,2},{3,4}};

    //creating a vector of size 5 with all the values initialized to 100
    vector<int> vc(5,100); //{100,100,100,100,100}

    vector<int> ve(5); // size is 5 with all values 0  {0,0,0,0,0}

    vector<int> v1(4,10);
    vector<int> v2(v1); // copy values from v1

    //Take the vector to be {10,20,30,40}
    vector<int>::iterator it = v.begin();  // Now here, this 'it' is pointing towards 10

    it++;
    cout<<*(it)<<""; // prints 20

    it = it+2;
    cout<<*(it)<<""; //prints 30

    vector<int>::iterator it = v.end(); //It will point to position after 40 i.e null

    //vector<int>::iterator it = v.rend(); //it is reverse end.. It will point to position before 10

//    vector<int>::iterator it = v.rbegin(); // It will point to 40

    cout<<v[0]; //prints 10
    cout<<v.back(); // prints 40 i.e last element

    //ways to print a vector

    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*(it)<<""; // normal way
    }

    for(auto it = v.begin();it!=v.end();it++){
        cout<<*(it)<<""; // it automatically moves through the vector
    }

    for(auto it:v){
        cout<<it<<""; //here we are using foreach loop and running though the values
    }

    vector<int> v3 = {10,20,30,40,50};
    v3.erase(v3.begin()); //erases 10

    v3.erase(v3.begin()+1); //erases 20

    v3.erase(v3.begin()+2,v3.begin()+4); // now this will delete 30 and 40.. It will go t0 50 as well but will not delete it

    // Insert function

    v3.insert(v3.begin(),25); // {25,10,20,30,40,50}
    v3.insert(v3.begin()+1,2,10); // {25,10,10,10,20,30,40,50}

    vector<int> copy(2,50);
    v3.insert(v3.begin(),copy.begin(),copy.end()); // insert the copy vector at the starting position

    cout<<v.size(); //prints size

    v.pop_back(); //removes last element

    //v1-> {10,20}
    //v2-> {30,40}

    v1.swap(v2); // it swaps the vector

    v.clear(); // clear the whole vector

    cout<<v.empty(); // tells if the vector is empty or not

}

void explainList(){
    list<int> ls;
    ls.push_back(1); // {1}
    ls.emplace_back(2); // {1,2}

    ls.push_front(0); //{0,1,2}
    ls.emplace_front(); //{1,2}

    //Rest are same as vector.. Here we jysr had push_front which is new
}

void explainDeque(){

    deque<int> dq;

    //same as vector
}

void explainStack(){

    stack<int> s;
    s.push(1); //{1}
    s.push(2); // {2,1}
    s.emplace(3); //{3,2,1}

    cout<<s.top()<<endl; // prints 3

    s.pop(); // removes top

    s.empty();

}

void explainQueue(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); //{1,2}
    q.emplace(3); //{1,2,3}

    q.back()+=5;

    cout<<q.back(); // print 9
    cout<<q.front(); //prints 1

    q.pop(); //[2,3]

}

void explainPQ(){
    //It uses the properties of stack and queue
    //It stores the element in the descending sorted order

    priority_queue<int> pq;
    pq.push(1); //{1}
    pq.push(2); // {2,1}
    pq.push(3); //{3,2,1}
    pq.push(7); //{7,3,2,1}
    pq.push(5); //{7,5,3,2,1}

    pq.pop(); //removes 7

    //Minimum heap
    priority_queue<int,vector<int>,greater<int>> p; // this will now store the elements in the ascending sorted order

}

void explainSet(){
    //Set stored elements in the sorted order
    // it only stores unique elements

    set<int> st;
    st.insert(1); //{1}
    st.insert(2); //{1,2}
    st.emplace(2); //{1,2}
    st.emplace(6); //{1,2,6}
    st.insert(3); //{1,2,3,6}

    auto it = st.find(3);
    auto it = st.find(5); //now 5 is not present so it will point to st.end()
    //to check if element is present or not we write this cndition: if(st.find()!=st.end()){return it;}

    st.erase(3); //removes 3 .. It takes logarithmic time

    //one more way to check the element is present is count.. since set contains uniquw elements so if the count is 1, then it is present
    int c = st.count(1);

    auto it = st.find(3);
    st.erase(it);

    auto it1 = st.find(1);
    auto it2 = st.find(3);
    st.erase(it1,it2); // it will erase from it1 to it2 but will not include it2
     
    
    }

    void explainMultiset(){
        //It is same as set but it allows you to store the duplicate elements
        multiset<int> ms;
        ms.insert(1);//{1}
        ms.insert(1);//{1,1}
        ms.insert(2);//{1,1,2}
        ms.insert(1);//{1,1,1,2}

        ms.erase(1); // it will erase all 1's

        int cnt = ms.count(1); 
        ms.erase(ms.find(1)); // to remove only single 1


    }

    void explainUnorderedSet(){
        //same as the set but it does not store in any order
        //better time complexity O(1)
        unordered_set<int> us;
    }

    void explainMap(){
        //stores as key value pair
        //we can do any type of initialization as below
        map<int,int>m;
        map<int,pair<int,int>> mp;
        map<pair<int,int>,int> mpp;

        m[1] = 2;
        m.insert({3,1});//inserting as a pair
        //all values in map is sorted based on key
        m.insert({2,4});
        //it will be like this
        // {
        //     {1,2},
        //     {2,4},
        //     {3,1}
        // }

        //insertion for mpp
        mpp[{2,3}] = 10;

        //access value of a map
        for(auto it:m){
            cout<<it.first<<" "<<it.second;
        }

        cout<<m[2]; // for accessng key 2
        cout<<m[5]; //prints 0 as not present

        auto it = m.find(1);
         // points to the position where 3 is present
        cout<<*(it).second;
    }

    void explaimultimap(){
        //same as a map
        // use when we have multiple same key value pair

    }

    void explainUnordred(){
        //same as set and unorderedSet differences
    }

    void extraStuff(){

        //to sort an array
        sort(a,a+n); 

        //to sort from a range
        sort(a+2,a+4);//does not include last
        
        //sort in descending order
        sort(a,a+n,greater<int>);

        //for maximum element
        int maxi = *max_element(a,a+n);

        //to get number of set bits
        int n = 7;
        int count = __builtin_popcount(n); //prints 3

        long long num = 12664346312;
        int cnt = __builtin_popcountll(num); //in case of long long
    }




int main(){

}