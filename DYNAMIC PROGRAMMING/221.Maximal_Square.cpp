/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int dp[row+1][col+1] ;
        for(int i=0; i<=row ; i++)
            for(int j=0; j<=col; j++) dp[i][j]=0;
        
        int mx=0;
        for(int i=1; i<=row; i++){
            for(int j=1; j<=col ; j++){
                if(matrix[i-1][j-1]=='1'){
                  dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j] , dp[i][j-1]))+1;
                  mx = max(mx,dp[i][j]);
                }
            }
        }
        
        return mx*mx;
    }
};
