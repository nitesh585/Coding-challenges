/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]


*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        if(numRows==0) return res;
        res[0].push_back(1);
        if(numRows==1) return res;
        res[1].push_back(1);
        res[1].push_back(1);
        if(numRows==2) return res;
        
        for(int i=2; i<numRows; i++){        
            res[i].push_back(1);
            for(int j=1; j<res[i-1].size(); j++){
                res[i].push_back(res[i-1][j]+res[i-1][j-1]);
            }
            res[i].push_back(1);
        }
        
        return res;
    }
};
