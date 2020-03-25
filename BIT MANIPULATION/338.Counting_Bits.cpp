/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]


*/

class Solution {
public:
    bool power_of_2(int n){
        return !(n && (n&(n-1)));
    }
    
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0]=0;
        
        if(num==0){
            return res;
        }
        
        res[1]=1;
        int power=1;
        bool flag=true;
        
        for(int i=2;i<=num;i++){
           
            int index = i-power;
            if(power_of_2(i)){
                res[i]=1;
                power= (i==2) ? power : power<<=1;
                flag=false;
                continue;
            }
            if(flag || power_of_2(index)){
                res[i] = res[index]+1;
                flag = true;
            }else{
                res[i] = res[index];
            }
        }
        return res;
    }
};




//easiest solution ( Slower than above solution )
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1,0);
        for(int i = 1;i<=num;++i){
            ret[i]=ret[i&(i-1)]+1;
        }
        return ret;
    }
};
