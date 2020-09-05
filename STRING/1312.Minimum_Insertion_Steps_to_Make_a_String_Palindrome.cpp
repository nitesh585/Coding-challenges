/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any insertions.

Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Example 4:

Input: s = "g"
Output: 0

Example 5:

Input: s = "no"
Output: 1

 

Constraints:

    1 <= s.length <= 500
    All characters of s are lower case English letters.

*/

class Solution {
public:
    int minInsertions(string str) {
		int n =str.length();
		int table[n][n], l, h, gap;  
		memset(table, 0, sizeof(table));  

		for (gap = 1; gap < n; ++gap)  
			for (l = 0, h = gap; h < n; ++l, ++h)  
				table[l][h] = (str[l] == str[h])?  table[l + 1][h - 1] :  (min( table[l][h - 1], table[l + 1][h]) + 1);  
		return table[0][n - 1];        
    }
};
