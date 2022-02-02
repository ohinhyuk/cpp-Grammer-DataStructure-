// c++ - array를 이용하여 queue 구현
// rear 와 front를 이용하여 circular queue를 구현하였다.


#include <iostream>
#define MAXVALUE 5 // queue size

using namespace std;

template <class T>
class Queue{
public:
    int size; // queue max size.
    int rear; // queue back index.
    int front; // queue front index.
    T* values; // queue using array.

    Queue(){
            front = -1;
            rear = -1;
            size = MAXVALUE;
            values = new T[size];
    }

    ~Queue(){
        delete[] values;
    }

    // queue가 다 찼다면 true return , else false return.

    bool isfull(){
        if((rear+1)%size == front) return true;
        return false;
    }

    // 비어있다면 true, else false.

    bool empty(){
        return (front == -1) ? true : false;
    }

    // 데이터 queue에 입력.

    void push(T value)
    {
        if(empty()){
            values[++rear] = value;
            front++;
        }
        else if(isfull()){
            cout << "queue is full!!" << endl;
        }
        else{
            rear = (rear+1) % size;
            values[rear] = value;
        }
    }

    // 맨 앞의 값 꺼내기.(선입선출)

    void pop(){
        if(empty()) cout << "queue is empty! pop doesn't work." << endl;
        else if( front==rear && front != -1 ){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1) % size;
        }
    }

    // 가장 최근에 들어온 데이터 반환

    T queue_back(){
        if(empty()){
            return -1;
        }
        return values[rear];
    }

    // 가장 먼저 들어온 데이터 반환

    T queue_front(){
        if(empty()){
            return -1;
        }
        return values[front];
    }

    // 현재 queue의 데이터 갯수

    int queue_size(){
        int i = front;
        int cnt = 1;
        if(empty()) return -1;
        else if(isfull()) return size;

        while(i!=rear){
            i = (i+1)%size;
            cnt++;
        }
        return cnt;
    }
};

int main(int args, char** argv){
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(45);
    q.push(55);
    q.push(6);
    cout << q.queue_size() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.push(15);
    q.push(25);
    q.push(35);
    cout << q.isfull() << endl;
    
}