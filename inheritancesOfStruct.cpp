#include<iostream>

using namespace std;

struct Rect{
    int width;
    int height;
};
struct DoubleRect: Rect{  //public inheritance 
    DoubleRect(const Rect& r1, const Rect& r2):inner{r2}
    {
        width={r1.width};
        height={r1.height};
    };
    Rect inner;
};
int main(){
    DoubleRect d{
        {.width=4,.height=3},
        {.width=2,.height=1}};
    cout<<d.inner.height<<d.inner.width<<'\n';  //1,2
    cout<<d.height<<d.width;                    //3,4
}