#include <iostream>
#include <string>

using namespace std;

int main(int args , char** argv){
    string s = "Hello My Name is metoday.";
    int sub;
    sub = s.find("h"); // 대소문자 구분함. // 쓰레기값 출력.
    if(sub == string::npos) cout << "npos";
    cout << s.find("Mylldnjaa" , 0 , 3);
   // cout << s.find("e");
    

}