/*
Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column

Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= n, m <= 50
    1 <= matrix[i][j] <= 10^5.
    All elements in the matrix are distinct.

*/

class Solution {
public:
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,pair<int,int>> mymap;
        vector<int> res;
        
        int row = matrix.size() , col = matrix[0].size();
        
        int a=0, b=0;
        int mini = INT_MAX;
        // store minimum element row-wise into map along with the index
        for(int i=0; i<row ; i++){
            mini = INT_MAX;
            for(int j=0; j<col; j++){
                if(mini>matrix[i][j]){
                    a = i; 
                    b = j;
                    mini = matrix[i][j];
                }
            }
            mymap[mini] = {a,b};
        }
        
        int maxi = INT_MIN;
            
        // find maximum element in column and check whether the index is present in the map or not
        for(int i=0; i<col ; i++){
            maxi = INT_MIN;
            for(int j=0; j<row; j++){
               if(maxi<matrix[j][i]){
                   a = j;
                   b = i;
                   maxi = matrix[j][i];
               }
            }
            if(mymap.find(maxi) != mymap.end()){
                if(mymap[maxi].first==a && mymap[maxi].second==b )
                    res.emplace_back(maxi);
            }   
        }
        
        return res;
    }
};
