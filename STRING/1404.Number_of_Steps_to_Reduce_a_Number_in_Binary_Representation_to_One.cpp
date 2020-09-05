/*
Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:

    If the current number is even, you have to divide it by 2.

    If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.

 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  

Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  

Example 3:

Input: s = "1"
Output: 0

Constraints:

    1 <= s.length <= 500
    s consists of characters '0' or '1'
    s[0] == '1'

*/

class Solution {
public:

    int makeEqualLength(string &str1, string &str2) { 
        int len1 = str1.size(); 
        int len2 = str2.size(); 
        
        if (len1 < len2) { 
            
            for (int i = 0 ; i < len2 - len1 ; i++){ 
                str1 = '0' + str1; 
            }
            
            return len2;
            
        }else if(len1 > len2) { 
            
            for (int i = 0 ; i < len1 - len2 ; i++){ 
                str2 = '0' + str2; 
            }
            
        }
        
        return len1; // If len1 >= len2
    }
    
    string addBitStrings( string first, string second ) { 
        string result;  // To store the sum bits 
        int length = makeEqualLength(first, second); 

        int carry = 0;  // Initialize carry 

        for (int i = length-1 ; i >= 0 ; i--) { 
            int firstBit = first.at(i) - '0'; 
            int secondBit = second.at(i) - '0'; 
            int sum = (firstBit ^ secondBit ^ carry)+'0'; 

            result = (char)sum + result; 
            carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry); 
        } 

        if (carry){ 
            result = '1' + result; 
        }
        
        return result; 
    } 
    
    int numSteps(string s) {
        int steps=0;
        int n = s.length();
        
        while(s!="1"){
            
            if(s[n-1]=='1'){
                s = addBitStrings(s,"1");
            }else{
                s = s.substr(0,n-1);
            }
            
            n = s.length();
            steps++;
        }
        
        return steps;
    }
};
