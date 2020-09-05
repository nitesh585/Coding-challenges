/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:

    
    int numTrees(int n) {
        /*
	  Approach 1 : Non-DP
        if(input==1){
            return 1;
        }
        double n = input;
        double res=1;
        for(int k=2; k<=n; k++){
            res*=((n/k)+1);
        }
        
        int ans = round(res);
        return ans;
        */
        
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i] = 0;
            for(int j=0; j<i; j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];
    }
};
