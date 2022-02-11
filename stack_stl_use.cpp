#include <iostream>
#include <stack>

using namespace std;

int main(int args , char** argv){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << "empty(0 is not empty, 1 is empty) : " << s.empty() << endl;
    cout << "size : " << s.size() << endl;
    cout << "stack values : ";
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << "\n" << "empty(0 is not empty, 1 is empty): " << s.empty() << endl ;    
}