#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

struct List{
    Node* head;
    Node* tail;

    List(){
        head = new Node{};
        tail = new Node{};
        head->next = tail;
        tail->prev = head;
    }
    ~List(){}
};

using pNode = Node*;
using pList = List*;

pNode begin(pList p){
    return p->head->next;
}
pNode end(pList p){
    return p->tail;
}

bool empty(pList p){
    return begin(p)==end(p);
}

pNode last(pList p){
    return end(p)->prev;
}

int size(pList p){
    int cnt = 0;
    
    if(empty(p)) return cnt;

    for(pNode n = begin(p) ; n!=end(p) ; n = n->next){
        cnt++;
    } 

    return cnt;
}

pNode find(pList p , int val){
    pNode n = nullptr; 
    for(n = begin(p) ; n!= end(p) ; n = n->next){
        if(n->data == val) break;
    }
    return n;
}

void erase(pNode n){
    n->next->prev = n->prev;
    n->prev->next = n->next;
    delete n;
}

void erase(pList p , pNode n){
    if(n == end(p) || n == p->head) return;
    erase(n);
}

void pop(pList p , int val){
    erase(p,find(p,val));
}

void pop_all(pList p , int val){
    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        if(val == n->data){
            n = n->prev;
            erase(p, n->next);
        }
    }
}

void insert(pNode x , int val){
    pNode node = new Node{val, x->prev , x};
    x->prev->next = node;
    x->prev = node;
}

void push_front(pList p , int val){
    insert(begin(p), val);
}

void push_back(pList p , int val){
    insert(end(p) , val);
}

void pop_front(pList p){
    if(!empty(p)) erase(begin(p));
    else{
        cout << "It doesn't work. List is empty." << endl;
    }
}

void pop_back(pList p){
    if(!empty(p)) erase(last(p));
    else{
        cout << "It doesn't work. List is empty." << endl;
    }
}

void print_all(pList p){
    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        cout << n->data << ' ';
    }
    cout << endl;
}

void unique(pList p){
    if(size(p) <= 1 ) return;

    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        if(n->data == n->prev->data){
            n = n->prev;
            erase(p,n->next);
        }
    }
}

bool sorted(pList p , int(*comp)(int a, int b)){

}



int main(int args, char** argv){
    pList p = new List{};
    push_front(p,1);
    push_front(p,0);
    push_front(p,-1);
    push_back(p,2);
    push_back(p,3);
    print_all(p);
    cout << size(p) << endl;
    push_front(p,3);
    push_back(p,3);
    print_all(p);
    pop_all(p,3);
    print_all(p);
    for(int i = 0 ; i < 5 ; i ++){
        pop_front(p);
    }
    print_all(p);
    push_back(p,3);
    push_back(p,4);
    insert(find(p,4),3);
    insert(p->tail,8);
    print_all(p);
}