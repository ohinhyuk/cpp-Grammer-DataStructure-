#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int args , char** argv){
    vector<int> v = { 2, 2, 2 , 2, 3, 4 ,5};

    sort(v.begin() , v.end());
    
    v.erase( unique(v.begin() , v.end()) , v.end());

    for(auto x : v){
        cout << x << ' ';
    }
}