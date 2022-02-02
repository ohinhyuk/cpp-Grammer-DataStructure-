// array를 통한 stack 구현.
// 기능
// 1) empty 2) push 3) pop 4) top 5) size
// stack이 비어있을 때 N의 값은 -1

#include <iostream>

using namespace std;

struct Stack{

    // 스택의 크기를 나타내는 N
    // 스택의 값 저장소 arr
    int N = -1;
    int * arr;

};

using stack = Stack *;

// 1) empty
// stack s 가 비어있다면 true를 , 아니라면 false 를 출력.

bool empty(stack s){
    return (s->N == -1) ? true : false;
}

// 2) push
// stack s 에 num 값을 집어넣음.
void push (stack s , int num){
    s->arr[++s->N] = num;
}

// 3) pop
// stack s에서 가장 최근에 들어온 값을 뺌.
void pop (stack s){
    if(empty(s)){
        cout << "It doesn't work. stack is empty" << "\n";
    }
    else{
        s->N--;
    }
}

// 4) top
// stack s 에서 가장 최근에 들어온 값을 출력.
int top(stack s){
    if(empty(s)){
        return -1;
    }
    else{
        return s->arr[s->N];
    }
    
}

// 5) size
// stack s 의 크기를 출력.

int size(stack s){
    return s->N+1;
}



int main(int args , char** argv){

    stack s = new Stack;

    push(s, 2);
    push(s, 1);
    cout << top(s) << "\n";
    pop(s);
    cout << size(s) << "\n";
    cout << top(s) << "\n";
    pop(s);
    pop(s);
    cout << top(s) << "\n";
    cout << size(s) << "\n";
    cout << empty(s);


    return 0;
}

