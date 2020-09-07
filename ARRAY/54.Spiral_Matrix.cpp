/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return {};
        }
        
        int r1=0, c1=0;
        int r2 = matrix.size()-1;
        int c2 = matrix[0].size()-1;
        vector<int> res;
        
        while(r1<=r2 && c1<=c2){
            for(int i=c1; i<=c2; i++){
                res.emplace_back(matrix[r1][i]);
            }
            
            for(int i=r1+1; i<=r2; i++){
                res.emplace_back(matrix[i][c2]);
            }
            
            if(r1<r2 && c1<c2){
                for(int i=c2-1; i>=(c1+1); i--){
                    res.emplace_back(matrix[r2][i]);
                }

                for(int i=r2; i>=(r1+1); i--){
                    res.emplace_back(matrix[i][c1]);
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        
        return res;
    }
};
