#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int args , char ** argv){
    
    vector<int> v1 ;
    
    // vector<int> v2 = {1,2,3};
    
    vector<int> v3(4,3);

    v1.assign(3,4);

    v1[0] = 1;
    v1.at(1) = 3;
    v1.front() = 5;
    v1.push_back(3);

    // cout << v1.size() << v1.capacity() << endl;

    // v1.clear();
    // cout <<v1.size();
    
    // vector<int> v4(v3);
    // v4.insert(v4.begin()+2,6);

    // for(auto x : v1){
    //     cout << x << ' ';
    // }
    // cout << endl;
    // for(auto x : v2){
    //     cout << x << ' ';
    // }
    
    // cout << endl;
    // for(auto x : v3){
    //     cout << x << ' ';
    // }
    
    // cout << endl;
    // for(auto x : v4){
    //     cout << x << ' ';
    // }

    vector<int> v = {1, 2, 3, 4};
    vector<int> :: reverse_iterator it;
    // it = v.end() ;
    vector<int> v2 = {1, 2, 3, 4};

    v2.clear();
    for(auto x : v2) cout << x << ' ';
    // for( it = v2.rbegin() ; it != v2.rend() ; it++){
    //     cout << *it << ' '; // 출력 : 4 3 2 1
    // }

}