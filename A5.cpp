#include <iostream>
#include <cmath> 
using namespace std; 
const int MOD =1e9+7; 
long long powerMod(long long base, long long exp, long long mod) {     long long result = 1;
                                                                  while (exp > 0) { if (exp % 2 == 1) {  result = (result * base) % mod; 
        } 
        base = (base * base) % mod; 
         exp /= 2; 
    }     return result; 
} int maxNiceDivisors(int primeFactors) {     if (primeFactors == 1) return 1;
                                         
    int q = primeFactors / 3;  
    int r = primeFactors % 3; 
 
    if (r == 0) {  return powerMod(3, q, MOD);
                } else if (r == 1) {       return (powerMod(3,q - 1, MOD) * 4) %MOD; 
    } else { 
        return (powerMod(3, q, MOD) * 2) % MOD; 
    } 
} int main() {     int primeFactors;  
   cout << "Enter the number of prime factors: ";  
   cin >> primeFactors; 
    cout << "Number of nice divisors: " << maxNiceDivisors(primeFactors) << endl;     
return 0;
             } 
