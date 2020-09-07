/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

    intervals[i][0] <= intervals[i][1]


*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        /*
        vector<vector<int>> ans;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        for(vector<int> interval:intervals){
            heap.push(interval);
        }
        
        while(!heap.empty()){
            vector<int> first = heap.top();
            heap.pop();
            
            if(!heap.empty()){
            
                vector<int> second = heap.top();
                heap.pop();
                
                if(first[1]>=second[0]){
                    
                    first[1] = max(first[1], second[1]);
                    heap.push(first);
                    
                }else{
                    ans.push_back(first);
                    heap.push(second);
                }
                
            }else{
                ans.push_back(first);
            }
            
        }
        */
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        //merge
        for(vector<int> interval:intervals){
            int n = merged.size();
            if( merged.empty() || merged[n-1][1] < interval[0] ){
                merged.push_back(interval);
            }else{
                merged[n-1][1] = max(merged[n-1][1], interval[1]);
            }
        }
        
        return merged;
    }
};
