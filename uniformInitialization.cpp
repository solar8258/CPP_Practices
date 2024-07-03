#include<iostream>


using namespace std;
struct CFoo{
    // public:
        // CFoo(int _x,int _y):x(_x),y(_y){cout<<"CConstruct the object with value: "<<_x;};
    int x;
    int y;
};

void foo(){

    int x={4};
    CFoo c{5,6};
    cout<<x<<'\n';
    cout<<c.x<<c.y;
}

int main(){
    foo();
    return 0;
}