#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int args , char** argv){

    vector<int> v = {6, 2, 3, 4 ,3 ,6 ,6 ,7, 2, 1};

    sort(v.begin() , v.end());

    // 1 2 2 3 3 4 6 6 6 7

    cout << upper_bound(v.begin() , v.end() , 3) -v.begin() ; // 3
    
    cout << upper_bound(v.begin() , v.end() , 5) -v.begin() ; // 6

}