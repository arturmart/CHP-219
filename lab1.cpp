
#include <iostream>
using namespace std;

int gcd(int a, int b) { 
    if (a == 0) return b;
    return gcd(b % a, a); 
    
}

    int main() { 
        int a = 250, b = 75; 
   
        cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
        
    }
