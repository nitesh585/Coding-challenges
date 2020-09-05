/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

 

Constraints:

    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;
        int tmp = 0 , n = nums.size();
        while(tmp < k){
            
            while(!dq.empty() && dq.back().first < nums[tmp] ){
                dq.pop_back();
            }
            
            dq.push_back({ nums[tmp] , tmp });
            tmp++;
        }
        
        
        for(int i=tmp; i<n; i++){
            pair<int,int> curr = dq.front();
            ans.emplace_back( curr.first );
            
            while(!dq.empty() && dq.back().first < nums[i] ){
                dq.pop_back();
            }
            
            dq.push_back({ nums[i] , i });
           
            while(!dq.empty() &&  ( i - dq.front().second ) >= k ){
                dq.pop_front();
            }
        }
        
        if(!dq.empty()){
            ans.emplace_back( dq.front().first ); 
        }
        
        return ans;
    }
};
