#include <iostream>
#include <stdlib.h>

using namespace std;

// 생성자 소멸자 test

class Test{
    public :
    Test(){
        cout << "Test constructor" << endl;
    }
    ~Test(){
        cout << "Test destructor" << endl;
    }
};

int main(int args , char ** argv){
    
    //malloc
    char * p_char;
    p_char = (char*)malloc(sizeof(char)); // char 메모리 할당
    free(p_char);

    char * p_chararr;
    p_chararr = (char*)malloc(sizeof(char) * 10); //char_array 메모리 할당
    free(p_chararr);

    //calloc
    char* p_char2;
    p_char2 = (char*)calloc(sizeof(char));
    free(p_char2);

    char* p_chararr2;
    p_chararr2 = (char*)calloc(10,sizeof(char));
    free(p_chararr2);

    //new
    char* p_char2;
    p_char2 = new char;
    delete p_char2;

    char* p_chararr2;
    p_chararr2 = new char [10];
    delete[] p_chararr2;

    // 생성자 호출
    cout << "malloc test" << endl;
    Test* t2;
    t2 = (Test*)malloc(sizeof(Test));
    free (t2);

    cout << "new test" <<endl;
    Test* t;
    t = new Test;
    delete t;

    //realloc
    realloc(p_chararr,sizeof(char) * 20); // 메모리 재 할당.



}