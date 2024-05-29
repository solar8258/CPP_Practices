/*
### RAII (Resource Acquisition Is Initialization)
RAII is a programming idiom used in several programming languages, including C++. 
It ensures that resources are properly released when they are no longer needed. 
The key idea is to bind the life cycle of a resource (such as memory, file handles, network sockets) to the lifetime of an object.
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class FileHandler{
    private:
        std::fstream file;
    
    public:
        FileHandler(const string& fileName ){
            file.open(fileName,ios::out|ios::in|ios::app);
            if(!file.is_open())
                throw runtime_error("Failed to open file");
        }
        void write(const string& message)
        {
            file<<message<<'\n';
        }
        ~FileHandler(){
            file.close();
        }
};

int main(){
    try{
        FileHandler handler("example.txt");
        handler.write("Hello,RAII!");
    }   catch(const exception& e){
        cerr<<e.what()<<'\n';
    }
    return 0;
}