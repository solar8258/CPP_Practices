#include<iostream>

using namespace std;
//unnamed namespace has local linkage,same as the static function
namespace  {

    void foo(){
        cout<<"V1\n";
    }
}

//inline namespace scope is current file, but will not affect it's linkage
inline namespace V2{
    void foo(){
        cout<<"V2\n";
    }
}
int main(){
    // V1::foo();
    V2::foo();
    foo();
    return 0;
}