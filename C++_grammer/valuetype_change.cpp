#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main(int args ,char** argv){
    // char before = '3';
    // int after = before - 48;

    // cout << "type : " << typeid(after).name() << endl ;
    // cout << "data : " << after;

    // int before = 100;
    // string s = to_string(before);

    // cout << s;

    

    string s = "1 to 100";
    int i = stoi(s);

    cout << i;
}