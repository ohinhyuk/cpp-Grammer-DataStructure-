#include <iostream>
#include <vector>

using namespace std;

template <typename T>
// 0. comp 함수
bool ascending(T a , T b){
    return a < b;
}

template <typename T>
bool descending(T a , T b){
    return b < a;
}


template <typename T>
// 1. bubble sort
void bubblesort(T* a , int a_size , bool(*comp)(T a, T b)){
    if(a_size == 0 || a_size == 1) return ;

    bool sorted_check = true;
    int decreasing_size = a_size-1;

    for(int i = 0 ; i < a_size-1 ; i++){
        for(int j = 0 ; j < decreasing_size ; j++){
            if(!comp(a[j],a[j+1])) {
                sorted_check = false; // false means not yet sort completed.
                swap(a[j],a[j+1]);
            }
        }
        if(sorted_check) break; // if sort is completed , break. 연산 속도를 높이는 장치 ②
        sorted_check = true;
        decreasing_size--; // 연산 속도를 높이는 장치 ①
    }

}
// 2. insertion sort
template <typename T>
vector<char> insertionsort(T* a, int a_size ,bool(*comp)(T a , T b)){    
    
    vector<T> v;
    for(int i = 0 ; i < a_size ; ++i){
        v.push_back(a[i]); // copy array to vector
    }
    
    if(v.size() == 0 || v.size() == 1){
        return v;
    }

    for(int end = 1; end < v.size() ; ++end){
        for(int start = 0 ; start < end ; ++start){
            if(comp(v[end],v[start])){ 
                v.insert(v.begin() + start , v[end]); 
                v.erase(v.begin() + end + 1);
            }
        }
    }

    return v;
}

// 3. selection Sort

template <typename T>
void selectionsort(T *a , int a_size , bool(*comp)(T a, T b)){
    if(a_size == 0 || a_size == 1) return ;
    
    for(int start = 0 ; start < a_size-1 ; ++start){
        T min_or_max = a[start]; // a[start] is value of index N.
        
        int index = start;  // index of N.
    
        for(int search = start+1 ; search < a_size ; search++ ){
            if(!comp(min_or_max , a[search])){ // finding min or max value and index.
                min_or_max = a[search];
                index = search;
            }
        }
        swap(a[start],a[index]);
    }


}

// 4. Quick sort
template <typename T>
bool less(T a , T b) { return a<b; } 

template <typename T>
void swap(T* a , int i , int j) { T t = a[i]; a[i] = a[j]; a[j] = t; }

template <typename T>
int partition(T *a ,int lo , int hi){
    int i = lo;
    int j = hi+1;

    while(1){
        while(::less( a[++i] ,a[lo]))
            if(i==hi) break;
        while(::less(a[lo],a[--j]))
            if(j==lo) break;

        if(i >= j) break;
        swap(a,i,j);

    }
    swap(a,lo,j);
    return j;

}

template <typename T>
void Quicksort(T *a ,int lo, int hi){
    if(hi <= lo) return;


    int j =partition(a,lo,hi);

    Quicksort(a,lo,j-1); // recursion lo ~ before pivot.
    Quicksort(a,j+1,hi); // recursion after pivot ~ hi.

}

int main(int args , char** argv){
    vector<char> insertion;
    char a[] = { 'A' , 'B', 'C' ,'G', 'R', 'A','H', 'Y','E', 'R','W','Q','K','G','L','D','O'};
    int N = sizeof(a)/ sizeof(a[0]);

    cout << "unsorted : ";
    for(int i = 0 ; i < N ; ++i){
        cout << a[i] ;
    }
    cout << endl;
    
    Quicksort(a,0,N-1);
    // bubblesort(a,N,ascending);
    // insertion = insertionsort(a,N,ascending);
    //selectionsort(a,N,ascending);
    cout << "sorted : ";
    for(int i = 0 ; i < N ; ++i){
          cout << a[i] ;
        // cout << insertion[i];
    }
}