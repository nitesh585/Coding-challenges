/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        bool inserted = false;
        //insert
        for(auto i= intervals.begin() ; i!=intervals.end(); i++){
            if((*i)[0] >= newInterval[0]){
                inserted = true;
                intervals.insert(i, newInterval);
                break;
            }
        }
        
        if(intervals.size()==0){
            intervals.push_back(newInterval);
        }
        
        if(intervals.size()>0 && !inserted){
            intervals.push_back(newInterval);
        }
        
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
