/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        
        
        int ar[n+1];
        ar[0]=0;
        ar[1]=1;
        ar[2] =1;
        
        for(int i=3;i<=n;i++){
            ar[i] = ar[i-1]+ar[i-2]+ar[i-3];
        }
        return ar[n];
    }
};
