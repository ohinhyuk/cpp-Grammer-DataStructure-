#include <iostream>
#include <vector>

using namespace std;

string *args_to_strArray(int argc , char** argv ){
    string* array = new string[argc];

    for(int i = 0 ; i < argc ; i++){
        array[i] = argv[i];
    }

    return array;
}

vector<string> args_to_strVector(int argc , char** argv){
    vector<string> s;

    for(int i = 0 ; i < argc ; i++){
        s.push_back(argv[i]);
    }

    return s;
}

void print_args(vector<string> args){
    for(auto x : args){
        cout << x << endl;
    }

}

void print_args(string *args , int argc){
    for(int i = 0 ; i < argc ; i++){
        cout << args[i] << endl;
    }

    delete[] args;
}

int main(int argc , char** argv){
    print_args(args_to_strArray(argc, argv),argc);
    print_args(args_to_strVector(argc , argv));
}