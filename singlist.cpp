#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
};

template<typename T>
class Singlist{
private:
    Node<T>* head;
    Node<T>* tail;
public:

    Singlist() : head(new Node<T>{-1,nullptr}) , tail(new Node<T>{-1,nullptr}) {}
    ~Singlist() {}

    bool empty(){
        return (head->next == nullptr || head->next == tail) ? true : false;
    }

    Node<T>* find_last_node(){
        Node<T>* last = head;
        if(empty()) return nullptr;
        while(last->next != tail){
            last = last->next;
        }   
        return last;
    }

    void addNode(T new_value){
        if(empty()){
            head->next = new Node<T>{new_value,tail};
        }
        else{
            Node<T>* last_node = find_last_node();
            last_node->next = new Node<T>{new_value,tail};
        }
    }

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

    void printAll(){
        Node<T>* node = head;
        if(empty()) return ;
        while(node->next != tail){
            node = node -> next;
            cout << node->data << ' ';
        }
    }

    bool search(T value){
        Node<T>* node = head->next;
        while(node != tail){
            if(node->data == value) return true;
            node = node->next;
        }
        return false;
    }

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