/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
	  // min heap
        priority_queue< pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > p;
        
        int m = matrix.size(), n = matrix[0].size();
        
        //insert 1st column
        for(int i = 0; i<m; i++){
            p.push({ matrix[i][0] , {i, 0} });
        }
        
        int ans = -1 ;
        while(k--){
            pair<int,pair<int,int>> tmp = p.top();
            p.pop();
            
            int row = tmp.second.first, col = tmp.second.second;
            ans = tmp.first;
            
            if(col < n-1){
                p.push({matrix[row][col+1], {row, col+1 } });
            }
        }
        
        while(!p.empty()){
            p.pop();
        }
        
        return ans;
    }
};
