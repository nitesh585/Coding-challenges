/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1=0, r2=n-1;
        int c1=0, c2=n-1;
        int val=1;
        
        vector<vector<int>> matrix(n, vector<int> (n));
        while(r1<=r2 && c1<=c2){
            for(int i=c1; i<=c2; i++){
                matrix[r1][i] = val;
                val++;
            }
            
            for(int i=r1+1; i<=r2; i++){
                matrix[i][c2] = val;
                val++;
            }
            
            if(r1<r2 && c1<c2){
                for(int i=c2-1; i>=(c1+1); i--){
                    matrix[r2][i] = val;
                    val++;
                }

                for(int i=r2; i>=(r1+1); i--){
                    matrix[i][c1] = val;
                    val++;
                }
            }
            
            r1++;
            r2--;
            c1++;
            c2--;
            
        }
        
        return matrix;
    }
};
