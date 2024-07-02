#include<iostream>
using namespace std;

enum DAY{MON,TUS,WED,THU,FRI,SAT,SUN};

// DAY& operator++(DAY d){
//     return (d==SAT)?DAY(SUN):DAY(d+1);
// }


ostream& operator<<(ostream& o, DAY d){
    switch (d)
    {
    case MON:
        o<<"Monday.\n";
        return o;
        // break;
    case TUS:
        o<<"Tuesday \n";
        return o;
        // break;
    case WED:
        o<<"Wednesday\n";
        break;
    case THU:
        o<<"Thursday \n";
        break;
    case FRI:
        o<<"Friday \n";
        break;
    case SAT:
        o<<"Saturday\n";
        break;
    case SUN:
        o<<"Sunday \n";
        break;
    
    default:
        o<<"Wrong day\n";
        break;
    return o;
    }

}

int main(){
    DAY mon=MON;
    cout<<mon;
}