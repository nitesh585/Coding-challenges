/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

 

Constraints:

    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    Each element of candidate is unique.
    1 <= target <= 500


*/

class Solution {
public:
    
    void helper(vector<int>& cand, int target, vector<vector<int>>& ans, int idx, vector<int> tmp){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=idx; i<cand.size() && target >= cand[i]; i++){
            tmp.push_back(cand[i]);
            
            helper(cand, target-cand[i], ans, i, tmp );
            
            tmp.pop_back();
        }    
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        sort(cand.begin(), cand.end());
        helper(cand, target, ans,0, tmp);
        
        return ans;
    }
};
