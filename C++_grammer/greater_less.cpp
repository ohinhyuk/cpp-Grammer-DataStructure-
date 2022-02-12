#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// compare 함수 (내림차순)
bool comp_desc(int a , int b){
    return a>b;
}

int main(int args ,  char** argv){
    // compare 함수 생략
    vector<int> v = {4,5,2,1,3};
    sort(v.begin() , v.end());
    cout << "No compare function : " ;
    for(auto x : v) cout << x << ' '; 
    cout << endl;

    // 내림차순 compare 함수
    vector<int> v1 = {4,5,2,1,3};
    sort(v1.begin() , v1.end() , comp_desc);
    cout << "descending compare function : " ;
    for(auto x : v1) cout << x << ' ';
    cout << endl; 

    // greater 함수
    vector<int> v2 = {4,5,2,1,3};
    sort(v2.begin() , v2.end(),greater<>());
    cout << "greater function : " ;
    for(auto x : v2) cout << x << ' ';
    cout << endl;
    
    // less 함수
    vector<int> v3 = {4,5,2,1,3};
    sort(v3.begin() , v3.end(),less<>());
    cout << "less function : " ;
    for(auto x : v3) cout << x << ' ';
    
}