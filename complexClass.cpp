#include<iostream>

using namespace std;



class Complex{
    private:
        int real, image;
    public:
        Complex(int r,int i):real(r),image(i){};
        Complex()=default;
        // friend Complex operator+(const Complex&, const Complex&);
        // Complex operator+(const Complex& c){
        //     Complex temp;
        //     temp.real=real+c.real;
        //     temp.image=image+c.image;
        //     return temp;
        // }
        friend ostream& operator<<(ostream& o, const Complex& c);
};
ostream& operator<<(ostream& o, const Complex& c){
    o<<c.real<<c.image;
    return o;
}

Complex operator+(const Complex& lhs, const Complex& rhs){
    cout<<"Friend operator + \n";
    Complex tmp;
    tmp.real=lhs.real+rhs.real;
    tmp.image=lhs.image+rhs.image;
    return tmp;
}
int main(){
    Complex c1(1,1), c2(2,2);
    cout<<c1+c2;
}