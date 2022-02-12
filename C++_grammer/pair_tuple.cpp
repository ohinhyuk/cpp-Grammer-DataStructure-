#include <iostream>
#include <utility>
#include <tuple>
#include <vector>

using namespace std;



int main(int args ,char** argv){
    vector<pair<int, string>> v_pair; // vector 에서의 pair 사용.

    v_pair.push_back(make_pair(1,"first")); // pair는 <make_pair> function 을 통해 만들 수 있다.
    v_pair.push_back(make_pair(2,"second"));
    v_pair.push_back(make_pair(3,"third"));
    
    for(auto x : v_pair){
        // first , second로 첫 번째 type , 두 번째 type에 접근 가능
        cout << "first elem : " << x.first << " || second elem : " << x.second << endl; 
        }

    vector<tuple<int,char,string>> v_tuple; // vector에서의 pair 사용.

    v_tuple.push_back(make_tuple(1,'a',"apple")); //tuple은 <make_tuple> function을 통해 만들 수 있다.
    v_tuple.push_back({2,'b',"bus"});
    v_tuple.push_back(make_tuple(3,'c',"column"));

    for(auto x : v_tuple){
        // get 함수와 <순서> 를 통해 3개의 type에 접근 가능.
        cout << "first elem : " << get<0>(x) << " || second elem : " << get<1>(x) << " || third elem : " << get<2>(x) << endl; 
    }
}