#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int args , char** argv){
    // string s;
    // vector<int> v = {2 , 1 ,4 ,5 ,3};
    // vector<int> :: iterator it;
    
    // it = find( v.begin() , v.end() , 3);
    // cout << *it << endl;
    // cout << it - v.begin() << endl;
    // cout << "-------------------" << endl; 
    // it = find(v.begin() , v.end() , 6);
    // cout << *it <<endl;
    // cout << it - v.begin() << endl;

    // int arr[] = { 1 , 3 , 5 , 2 , 6 };
    // int* p;

    // p = find(arr , arr+ 5 ,4);
    
    // cout << *p << endl;
    // cout << p - arr ;

    vector<int> v = {1, 2, 3, 4, 5};
vector<int>::iterator it;

it = find(v.begin() , v.end() , 6);
if(it == v.end()){
	cout << "Not Found.";
}
else{
	cout << "index : " << it - v.begin() ;
}

int arr[] = {1 , 2, 3 ,4 ,5};
int* p ;
p = find( arr , arr + 5 , 6 );

if(p == arr + 5){
    cout << "Not Found.";
}
else{
    cout << "index : " << p - arr ;
}


}