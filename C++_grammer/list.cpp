#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
int main(int args, char** argv){

    // vector<int> v = { 1, 2, 3, 4};
    // reverse(v.begin() , v.end());
    // for(auto x : v) cout << x ;

  list<int> li = { 1, 2, 3 ,4 ,4 ,5};

li.unique();

for(auto x : li) cout << x << ' ';
}
