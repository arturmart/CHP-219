// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>


class caesarEncoding{
    public:
    
    std::string encode(std::string str){
        std::string ret = "";
        for(int i = 0; i<str.size(); i++){
            ret+= (str[i]+mv);
        }
        
        return ret;
        
    }
    
    std::string decode(std::string str){
        std::string ret = "";
        for(int i = 0; i<str.size(); i++){
            ret+= (str[i]-mv);
        }
        
        return ret;
        
    }
    
    int mv = 3;
    
    
};
int main() {
    caesarEncoding cE;
    
    std::string str = "Hello World";
    str = cE.encode(str);
    
    
    std::cout << str << std::endl;
    
    str = cE.decode(str);
    
    
    std::cout << str  << std::endl;
    
    

    return 0;
}
