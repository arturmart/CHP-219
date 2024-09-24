
#include <iostream>
using namespace std;

int gcd(int a, int b) { 
    if (a == 0) return b;
    return gcd(b % a, a); 
    
}

/*
   a=250    b=75    75%250=75
   a=75     b=250   250%75=25
   a=25     b=75    75%25=0
   a=0      b=25    ret b
   
   */

    int main() { 
        int a = 250, b = 75; 
   
        cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
        
    }
