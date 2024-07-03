#include<iostream>

using namespace std;

#define TOKEN_TO_STRING(x) #x
void foo(){
    cout<<TOKEN_TO_STRING(2)<<'\n';
    cout<<TOKEN_TO_STRING(hello)<<'\n';
    cout<<TOKEN_TO_STRING(2+1)<<'\n';

    #define VERSION 2
    #define DO_EXPAND_TO_STRING(x) TOKEN_TO_STRING(x)
    cout<<DO_EXPAND_TO_STRING(VERSION)<<'\n';
}

int main(){
    foo();
    return 0;
}