Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.



class Solution {
public:
    bool isprime(int a){
        if(a==1 || a==0){
            return false;
        }
        if(a==2){
            return true;
        }
        if(a%2==0){
            return false;
        }
        
        for(int i=3;i<=sqrt(a);){
            if(a%i==0){
                return false;
            }    
            i+=2;
        }
        return true;
    }
    
    int countPrimes(int n) {
        int count=0;
        for(int i=1;i<n;i++){
            if(isprime(i)){
                count++;
            }
        }
        return count;
    }
};
