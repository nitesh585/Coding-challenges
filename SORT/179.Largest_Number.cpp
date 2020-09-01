/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer

*/



bool comp(int a,int b){
    string stra = to_string(a);
    string strb = to_string(b);

    string str1 = stra + strb;
    string str2 = strb + stra;
    return str1 > str2;
}


class Solution {
public:
    
    
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0){
            return "";
        }
        
        sort(nums.begin(), nums.end(), comp);
        
        string ans = "";
        for(int i=0; i<nums.size(); i++){
            ans+=to_string(nums[i]);
        }
        
        int i=0;
        
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        
        if(i==ans.size()){
            return "0";
        }
        
        return ans;
    }
};
