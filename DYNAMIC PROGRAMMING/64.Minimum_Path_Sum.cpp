/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.


*/

class Solution {
public:
    int min_sum = INT_MAX;
    // recursive solution
    void dfs(vector<vector<int>> &grid, int row, int col, int sum){
        if(row>= grid.size() || col >= grid[0].size()) return;
        
        sum += grid[row][col]; 
        
        dfs(grid,row+1,col , sum);
        dfs(grid,row,col+1, sum);
        
        if(row == grid.size()-1 && col == grid[0].size()-1)
            min_sum = min(min_sum , sum );
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        //dfs(grid,0,0,0);
        
        
        //using Dynamic programming
        int row = grid.size();
        int col = grid[0].size();
        
        int ar[row][col];
        
        ar[0][0] = grid[0][0];
        
        for(int i=1; i<row; i++){
            ar[i][0] = (grid[i][0]+ar[i-1][0]);
        }
        
        for(int i=1; i<col; i++){
            ar[0][i] = (grid[0][i]+ar[0][i-1]);
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col;j++){
                ar[i][j] = min(ar[i-1][j] +grid[i][j] , ar[i][j-1] +grid[i][j] );
            }
        }
        
        return ar[row-1][col-1];
    }
};
