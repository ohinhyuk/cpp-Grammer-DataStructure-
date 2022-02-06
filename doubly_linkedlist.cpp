// I made doubly linked list using struct.
// It has many functions . Basic functions and advanced functions.
// And it is used function pointer to check that doubly linked list is ascending sorted or descending sorted.

#include <iostream>

using namespace std;

struct Node{
    int data; // data in Node.
    Node* prev; // pointing before Node.
    Node* next; // pointing after Node.
};

struct List{
    Node* head; // front of list.
    Node* tail; // end of list.

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

// first list node.
// head 바로 다음 node.

pNode begin(pList p){
    return p->head->next;
}

// tail.

pNode end(pList p){
    return p->tail;
}

// list가 비어있다면 true, 아니라면 false return.

bool empty(pList p){
    return begin(p)==end(p);
}

// list 의 last node.
// tail 바로 앞(prev) node.

pNode last(pList p){
    return end(p)->prev;
}

// list node들의 갯수 -> head, tail 제외.

int size(pList p){
    int cnt = 0;
    
    if(empty(p)) return cnt;

    for(pNode n = begin(p) ; n!=end(p) ; n = n->next){
        cnt++;
    } 

    return cnt;
}

// val 값을 data로 지닌 node를 찾아서 return.

pNode find(pList p , int val){
     
    for(pNode n = begin(p) ; n!= end(p) ; n = n->next){
        if(n->data == val) return n;
    }
    return nullptr;
}

// n을 list에서 삭제.

void erase(pNode n){
    n->next->prev = n->prev;
    n->prev->next = n->next;
    delete n;
}

// n을 list에서 삭제. n이 head나 tail이면 실행 X.

void erase(pList p , pNode n){
    if(n == end(p) || n == p->head) return;
    erase(n);
}

// val 값 지닌 노드 삭제.

void pop(pList p , int val){
    erase(p,find(p,val));
}

// val 값 지닌 모든 노드 삭제.

void pop_all(pList p , int val){
    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        if(val == n->data){
            n = n->prev;
            erase(p, n->next);
        }
    }
}

// x가 가리키는 node 앞에 val값을 지닌 새로운 노드 삽입.

void insert(pNode x , int val){
    pNode node = new Node{val, x->prev , x};
    x->prev->next = node;
    x->prev = node;
}

// head 다음(next)에 val값 가진 node 추가.

void push_front(pList p , int val){
    insert(begin(p), val);
}

// tail 앞에 val 값 가진 node 추가.

void push_back(pList p , int val){
    insert(end(p) , val);
}

// head 다음 노드 삭제.

void pop_front(pList p){
    if(!empty(p)) erase(begin(p));
    else{
        cout << "It doesn't work. List is empty." << endl;
    }
}

// tail 이전 노드 삭제.

void pop_back(pList p){
    if(!empty(p)) erase(last(p));
    else{
        cout << "It doesn't work. List is empty." << endl;
    }
}

// list 모든 노드 값 출력.

void print_all(pList p){
    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        cout << n->data << ' ';
    }
    cout << endl;
}

// sorted 된 list에서 data 같은 node들이 있으면 하나만 남기고 삭제.

void unique(pList p){
    if(size(p) <= 1 ) return;

    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        if(n->data == n->prev->data){
            n = n->prev;
            erase(p,n->next);
        }
    }
}

//sort 되었는지 확인.

bool sorted(pList p , int(*comp)(int a, int b)){
    if(size(p) <= 1) return true;

    int data = begin(p)->data;

    for(pNode node = begin(p)->next ; node != end(p) ; node = node->next){
        if(comp(data , node->data) > 0) return false;
        data = node->data; 
    }
    return true;
}

int ascending(int a, int b){
    return (a-b);
}
int descending (int a , int b){
    return (b-a);
}

// z 보다 큰 node들 중 가장 앞쪽에 있는 node return.

pNode more(pList p , int z){
    pNode x = begin(p);

    while(x!=end(p)){
        if(x->data > z) return x;
        x = x->next;
    }

    return nullptr;
}

// z 보다 작은 node들 중 가장 앞쪽에 있는 node return.

pNode less(pList p , int z){
    for(pNode x = begin(p) ; x != end(p) ; x = x->next){
        if(x->data == z) return x;
    }
    return nullptr;
}

// sorted 되어 있는 list에서 value 값을 가진 노드를 sort가 유지되도록 알맞은 자리에 insert.

void push_sorted(pList p , int value){
    if(sorted(p,ascending)) insert(more(p,value),value);
    else if(sorted(p,descending)) insert(::less(p,value), value);
}

// node 순서를 거꾸로

void reverse(pList p){
    if(size(p) <= 1) return;
    
    pNode n = begin(p);
    pNode next_node = begin(p)->next;
    while(n != end(p)){
        n->next = n->prev;
        n->prev = next_node;
        n = next_node;
        next_node = next_node->next;
    }

    p->head->prev = p->head->next;
    p->tail->next = p->tail->prev;
    p->head->next = nullptr;
    p->tail->prev = nullptr;
    pNode temp = p->head;
    p->head = p->tail;
    p->tail = temp;

}

// 가운데 위치에 있는 노드를 return.
// 홀수 개 일때는 가운데 위치.
// 짝수개 일때는 가운데에서 바로 오른쪽에 있는 node.

pNode half(pList p){
    if(empty(p)) return nullptr;

    pNode rabbit = p->head;
    pNode turtle = p->head;

    while(rabbit != end(p)){
        turtle = turtle->next;
        rabbit = rabbit->next;
        if(rabbit == end(p)){
            break;
        }
        rabbit = rabbit->next;
    }

    return turtle;
}

// 노드들의 위치를 섞어주는 함수.
// 반으로 나누어 왼쪽 반쪽에 있던 노드들을 오른쪽 반쪽에 있던 노드들 사이사이에 차례로 insert해준다.

void shuffle (pList p){
    if(size(p) <= 1) return ;

    pNode mid = half(p);
    pNode que = begin(p);

    mid->prev->next = nullptr;
    que->prev = nullptr;
    mid->prev = p->head;
    p->head->next = mid;

    while(que != nullptr){
        mid = mid->next;
        insert(mid,(que->data));
        que = que->next;
    }
}

void bubblesort(pList p,int (*comp)(int a, int b)){
    if(sorted(p,comp)) return ;
    bool complete = false;
    pNode temp = end(p);
    pNode n;
    for(int i = 0 ; i < size(p) ; ++i){
        for(n = begin(p) ; n->next != end(p) ; n = n->next){
            if(comp(n->data , n->next->data) > 0){
                complete = false;
                swap(n->data , n->next->data);
            }
        }
        p->tail = n;
        if(complete) break;
        complete = true;
    }

    p->tail = temp;
}

bool partial_sorted(int(*comp)(int a, int b) ,pNode start , pNode done){
    pNode check = start;
    pNode check_next = check->next;
        
    for(; check != done ; check = check->next ){    
        if(comp(check->data, check_next->data) > 0 ) return false;
        check_next = check_next->next;
    }
    return true;
}
void qsort(pList p, int(*comp)(int a, int b), pNode start , pNode done){
    if(sorted(p,comp)) return ;
    if(start == done) return ;
    if(start->next == done){
        if(comp(start->data , done->data) > 0) swap(start->data,done->data);
        return;
    }
    
    
    if(partial_sorted(comp,start , done)) return ;

    pNode pivot = start;
    start = start->next;

    while(start->prev != done){
        for(;start !=end(p) ; start = start->next){
            if(comp(start->data , pivot->data) >= 0 ){
                break;
            }
        }
        for(;done != begin(p) ; done = done->prev){
            if(comp(done->data , pivot->data) <= 0 ){
                break;
            }
           
        }
        if(start->prev != done){
            swap(start->data , done->data);
            start = start->next;
            done = done->prev;
        }
    }
    swap(done->data , pivot->data);
    print_all(p);
    qsort(p,comp,begin(p),done->prev);
    qsort(p,comp,done->next,last(p));
    

    
}

void insertionsort(pList p , int(*comp)(int a, int b)){
    if(sorted(p,comp)) return;

    for(pNode n = begin(p) ; n != end(p) ; n = n->next){
        for(pNode first = begin(p) ; first != n ; first = first->next){
            if(comp(first->data,n->data) > 0){
                int temp = n->data;
                n = n->prev;
                erase(n->next);
                insert(first,temp);
                break;
            }
        }
    }

}

void selectionsort(pList p , int (*comp)(int a, int b)){
    if(sorted(p,comp)) return;
    

    for(pNode first = begin(p) ; first->next != end(p) ; first = first->next){
        int min_or_max = first->data;
        for(pNode search_min = first->next ; search_min != end(p) ; search_min = search_min ->next){
            if(comp(min_or_max,search_min->data) > 0 ) min_or_max = search_min->data;
        }
        if(min_or_max != first->data){

            for(pNode change = first->next ; change != end(p) ; change = change->next){
                if(min_or_max == change->data) swap(first->data ,change->data);
            }
        }
    }
}

int main(int args, char** argv){
    pList p = new List{};
    push_back(p,11);
    push_back(p,21);
    push_back(p,12);
    push_back(p,23);
    push_back(p,9);
    push_back(p,2);
    push_back(p,1);
    push_back(p,3);
    push_back(p,4);
    push_back(p,6);
    cout << "before sort----------------------------------------" << endl;
    print_all(p);
    cout << "after sort --------------------------------------------" << endl;
    // insertionsort(p,ascending);
    
    // bubblesort 랑 qsort 두개가 여러 같은 값이 중복되면 잘 안된다. ㅠ
    // bubblesort(p,ascending);
    //  qsort(p,ascending,begin(p) , last(p));
    print_all(p);
    

}