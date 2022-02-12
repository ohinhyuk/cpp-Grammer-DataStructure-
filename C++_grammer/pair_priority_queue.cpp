#include <iostream>
#include <queue>
//#include <utility>
using namespace std;

struct cmp{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
              if (a.first == b.first) {
                  return a.second > b.second;
              }
              else {
                  return a.first < b.first;
              }
          }
};
int main(int args , char** argv){

    
    
    // priority_queue<pair<int , int>> pq;
    
    // pq.push({1,2});
    // pq.push({1,3});
    // pq.push({2,2});
    // pq.push({2,5});
    // pq.push({3,1});

    // while(!pq.empty()){
    //     cout << pq.top().first << pq.top().second << endl;
    //     pq.pop();
    // }

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    

    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push({1,2});
    pq.push({1,3});
    pq.push({2,2});
    pq.push({2,5});
    pq.push({3,1});

    while(!pq.empty()){
        cout << pq.top().first << pq.top().second << endl;
        pq.pop();
    }
}