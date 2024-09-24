
#include <iostream>
#include <map>
#include <string>

class encrCaeser{
    public:
    void setKay(std::string& A, std::string& B){
        for(int i =0;i<A.length();i++){
             kayEc.insert(std::pair<char, char>(A[i], B[i]));
             kayDc.insert(std::pair<char, char>(B[i], A[i]));
        }
       
    }
    
    void printMap(){
        std::map<char, char>::iterator itr;
        
        for (itr = kayEc.begin(); itr != kayEc.end(); ++itr) {
       std:: cout << '\t' << itr->first << '\t'<<"-"<<'\t' << itr->second
             << '\n';
        }
        
    }
    
    void encrypt(std::string& str){
        std::string retStr;
        for(int i =0;i<str.length();i++){
            str[i]=kayEc.at(str[i]);
            
        }
       
        
    }
    void decrypt(std::string& str){
        std::string retStr;
        for(int i =0;i<str.length();i++){
            str[i]=kayDc.at(str[i]);
            
        }
       
        
    }
    
private:
    std::map<char,char> kayEc;
    std::map<char,char> kayDc;
};

    int main() { 
        std::string A = {"abcdefghijklmnopqrstuvwxyz "};
        std::string B = {"ygrabzmjklcpefdsthuvqnowxi "};
        
        encrCaeser eC;
        
        eC.setKay(A,B);
     
        
        std::string str = "hello world";
        eC.encrypt(str);
        std::cout<<str<<std::endl;
        eC.decrypt(str);
        std::cout<<str<<std::endl;
        

    }
    
