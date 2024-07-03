#include<iostream>
#include<memory>
#include<string>
using namespace std;
class Entry{
    public:
        Entry(const string& name):m_name{name}{};
        ~Entry(){}
        void doSomeThing(){}
    private:
        int arr[1024];
        string m_name;
};
void bar2(){
    const int LEN=64;
    std::unique_ptr<uint32_t[]> x(new uint32_t[LEN]);
    for(int i=0;i<LEN;i++){
        x[i]=i;
        cout<<x[i]<<'\n';
    }


}

void foo(){
    auto uptr=std::make_unique<Entry>("foo");
    // cout<<"uptr: "<<uptr<<" &uptr: "<<&uptr<<'\n';
    cout<<sizeof(uptr)<<'\n';
    #if 0
    // cout<<sizeof(std::unique_ptr<int>)<<sizeof(int *)<<'\n';  //8,8
    std::unique_ptr<uint32_t> uPtrX(new uint32_t(0xff));
    cout<<*uPtrX<<'\n';
    uint32_t t = 0x00700000;
    //x = &t;                            //compilation error-use memory not already allocated/owned
    std::unique_ptr<uint32_t> uPtrY(new uint32_t(0x65766173));     //ASCII:evas
    uPtrX.reset(new uint32_t(0xf00));    //will free the previous x first and set x to new then
    // x = y;                            //compilation error - copy
    uPtrX = std::move(uPtrY);            //delete x, x = y, y = nullptr
    #endif
}

void bar(){
    const int LEN = 5;
    std::unique_ptr<int[]> uPtr(new int[LEN]);
    for(int i=0;i<LEN;i++){
        uPtr[i]=i;
    }
    int* raw_ptr = uPtr.get();            // Get the raw pointer from unique_ptr
    for (int i = 0; i <= LEN; ++i) {
        cout << *raw_ptr << " ";   // Print the current element
        ++raw_ptr;                      // Increment the pointer
    } // uPtr will be deleted automatically here
}


int main()
{
    foo();
    // bar();
    // testArray();
    return 0;
}