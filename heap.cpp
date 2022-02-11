#include <iostream>
#include <algorithm>
using namespace std;

class Heap{
private:
    int* heap_container ;    
    int capacity = 0;
    int full_memory = 0;

public:
    Heap(int capa = 2){
        full_memory = capa;
        heap_container = (int*)malloc( (capa+1) * sizeof(int));
    };
    ~Heap(){};

    void reserve(int capa){
        (int*)realloc(heap_container, (capa+1) * sizeof(int));
        full_memory = capa;
    }
    bool isfull(){
        return full_memory == capacity;
    }

    void heap_push(int data){
        
        heap_container[++capacity] = data;
        int child = capacity;
        int parent = child / 2;
        while(child > 1 && heap_container[child] > heap_container[parent]){
            swap(heap_container[child] , heap_container[parent]);
            child = parent;
            parent = child / 2;
        }
        
    }

    void make_to_heap(int* arr, int arr_size){
        if(arr_size == 0) return;

        for(int i = 0 ; i < arr_size ; ++i){
            if(isfull()) reserve(full_memory * 2);
            heap_push(arr[i]);
        }
    }


    void heap_pop(){
        if(capacity==0) return;

        swap(heap_container[1],heap_container[capacity]);
        capacity--;

        int parent = 1;
        int child = parent * 2;

        if(child+1 <= capacity){
            child = (heap_container[child] < heap_container[child+1]) ? child+1 : child;
        }

        while(child <= capacity && heap_container[parent] < heap_container[child]){
            swap(heap_container[parent] , heap_container[child]);

            parent = child;
            child = parent *2;

            if(child+1 <= capacity){
                child = (heap_container[child] < heap_container[child+1]) ? child+1 : child;
            }
        }
    }

    bool isheap(){
        for(int i = 1 ; i <= capacity ; ++i){
            if((i*2)+1 <= capacity && heap_container[(i*2)+1] > heap_container[i]){
                return false;
            }
            if((i*2) <= capacity && heap_container[i*2] > heap_container[i]) return false;
        }

        return true;
    }

    int heap_size(){
        return capacity;
    }

    void heap_sort(){
        int temp = capacity;
        while(capacity != 0){
            heap_pop();
        }
        capacity = temp;
    }

    void printHeap(){
        cout << "Heap : ";
        for(int i = 1 ; i <= capacity ; ++i){
            cout << heap_container[i] << ' ';
        }
        cout << endl;
    }
};

int main(int args, char** argv){

    Heap h;
    
    int arr[10] = {3, 5, 7 , 8 , 10, 21, 6, 13, 31, 25};
    int arr_size = sizeof(arr)/ sizeof(arr[0]);
    h.make_to_heap(arr,arr_size);
    h.printHeap();

    cout << h.isheap();

}