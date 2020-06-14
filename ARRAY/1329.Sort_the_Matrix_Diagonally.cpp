/*
Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.
 

Example 1:

Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    1 <= mat[i][j] <= 100

*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i-j].emplace_back(mat[i][j]);
            }
        }
        
        for(auto i=mp.begin(); i!=mp.end(); i++){
            sort(i->second.begin(), i->second.end());
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        
        
        return mat;
    }
};
