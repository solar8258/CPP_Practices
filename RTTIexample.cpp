/***
 * 
RTTI in C++ allows the type of an object to be determined during program execution. 
RTTI is most useful when dealing with polymorphism. 
You can retrieve the exact type of an object when you only have a pointer or reference to a base class.
 The primary RTTI features in C++ are `dynamic_cast` and `typeid`.
*/
#include<iostream>
#include<typeinfo>
using namespace std;
class Base{
    public:
        virtual ~Base(){cout<<"destroyed the Base object.\n";}  
};

class Derived:public Base{
    virtual ~Derived() override {cout<<"Destroyed the Derived object.\n";}
};

int main(){
    Base *b = new Derived();

    /*
    
- `dynamic_cast` is used to safely convert the base class pointer to a derived class pointer. 
   It returns `nullptr` if the conversion is not possible.*/
    Derived *d=dynamic_cast<Derived*> (b);
    if(d){
        cout<<"b is actually pointing to a Derived.\n";
    }
    else{
        cout<<"b is not pointing to a Derived.\n";
    }
//- `typeid` provides the actual type of the object pointed to by `b`.
// Comparing `typeid(*b)` with `typeid(Derived)` checks if `b` actually points to a `Derived` object.
    if(typeid(*b)==typeid(Derived))
        cout<<"b is of type Derived.\n";
    else
        cout<<"b is not of type Derived.\n";
    
    delete b;
    return 0;
}