// struct 와 class를 이용하여 Singlist 구현
// 추가로 template을 사용하여 int 뿐만 아니라 다른 type을 연결하는 singlist로 사용할 수 있다.

#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T data; // Node 속 data 저장.
    Node<T>* next = nullptr;
};

template<typename T>
class Singlist{
private:
    Node<T>* head; // singlist의 시작. list의 data가 들어있지는 않다.
    Node<T>* tail; // sinlist의 마지막. list의 data가 들어있지는 않다.
public:

    Singlist() : head(new Node<T>{-1,nullptr}) , tail(new Node<T>{-1,nullptr}) {}
    ~Singlist() {}

    bool empty(){
        return (head->next == nullptr || head->next == tail) ? true : false;
    }

    // tail 직전 Node를 return

    Node<T>* find_last_node(){
        Node<T>* last = head;
        if(empty()) return nullptr;
        while(last->next != tail){
            last = last->next;
        }   
        return last;
    }

    // tail 직전에 new_Value 값을 data로 갖는 Node를 추가.

    void addNode(T new_value){
        if(empty()){
            head->next = new Node<T>{new_value,tail};
        }
        else{
            Node<T>* last_node = find_last_node();
            last_node->next = new Node<T>{new_value,tail};
        }
    }

    // tail 직전의 Node를 삭제.

    void deleteNode(){
        if(empty()){
            cout << "deleteNode function doesn't work. list is empty." << endl;
            return ;
        }
        else{
            Node<T>* before = head;
            Node<T>* del = head->next;
            while(del->next != tail){
                before = before -> next;
                del = del -> next;
            }
            before -> next = tail;
        }
    }

    // head와 tail을 제외한 노드의 갯수를 return.

    int size(){
        Node<T>* size = head;
        int cnt = 0;
        if(empty()) return cnt;
        while(size->next != tail){
            size = size->next;
            cnt++;
        }
        return cnt;
    }

    // Index N번째에 new_value 값을 data로 가지는 Node를 추가.

    void insertNode(T new_value , int N){
        if(N > size()){
            cout << "singlist has less datas than " << N << "." << "\n";
        }
        else if(N < 0){
            cout << "N is negative number. please give me index number." << "\n";
        }
        else if(empty()){
            addNode(new_value);
        }
        else{
            Node<T>* before = head;
            for(int i = 0 ; i < N ; i++){
                before = before->next;
            }
            before->next = new Node<T>{new_value,before->next};
        }
    }

    // singlist 출력.

    void printAll(){
        Node<T>* node = head;
        if(empty()) return ;
        while(node->next != tail){
            node = node -> next;
            cout << node->data << ' ';
        }
    }

    // value의 값을 data로 가지는 Node가 있는지 없는지 확인.

    bool search(T value){
        Node<T>* node = head->next;
        while(node != tail){
            if(node->data == value) return true;
            node = node->next;
        }
        return false;
    }

    // Index N번째에 있는 Node의 data를 return.

    T getData(int N){
        if(N >= size()){
            return -1;      
        }
        
        Node<T>* node = head;
        for(int i = 0 ; i <= N ; i++){
            node = node -> next;

        }
        return node->data;
    }

};

int main(int args, char** argv){
    Singlist<int> s;

    s.addNode(1);
    s.addNode(2);
    s.addNode(4);
    s.insertNode(10,-1);

}