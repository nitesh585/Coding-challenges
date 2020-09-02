/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false


*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        
        int n = matrix[0].size();
        int m = matrix.size();
        int low = 0;
        int high = n*m - 1;
        
        int i, j;
        while(low <= high){
            int mid = (high+low)/2;
        
            i = mid/n;
            j = mid%n;
            cout<<i<<" "<<j<<endl;    
            if(matrix[i][j]==target){
                return true;
            }else if( matrix[i][j] > target ){
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        
        return false;
    }
};
