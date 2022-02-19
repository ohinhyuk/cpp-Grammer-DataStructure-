#include <iostream>
#include <string.h>

using namespace std;

int main(void){
    char str[] = "a b c d e f";
    char* p_str = strtok(str," ");
    while(p_str != NULL){
        cout << p_str <<endl;
        p_str = strtok(NULL," ");
    }

    char str2[] = "a-b,c:d e-f";
    char* p_str2 = strtok(str2,",- :");

    while(p_str2 != NULL){
        cout << p_str2 << endl;
        p_str2 = strtok(NULL , ",- :");
    }
}