/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10

*/

class Solution {
public:
    // find next left smaller element
    void leftGreater(vector<int>& heights, vector<int>& lgreater ){
        stack<int> stk;
        
        for(int i=0; i<heights.size(); i++){
            while( !stk.empty() && heights[i] <= heights[stk.top()]  ) {
                stk.pop();
            }
            
            lgreater[i] = !stk.empty() ? stk.top() : -1;
            
            stk.push(i);
        }
    }
    
    // find next right smaller element
    void rightGreater(vector<int>& heights, vector<int>& rgreater ){
        stack<int> stk;
        int n = heights.size();
        
        for(int i = n-1; i>=0 ; i--){
            while( !stk.empty() && heights[i] <= heights[stk.top()]  ) {
                stk.pop();
           }
            
            rgreater[i] = !stk.empty() ? stk.top() : -1;
    
            stk.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }
        
        int N = heights.size();
        vector<int> lgreater(N);
        vector<int> rgreater(N);
        
        rightGreater(heights, rgreater);
        leftGreater(heights, lgreater);
        
        int currmax;
        int totalMax = INT_MIN;
        for(int i=0; i<N; i++){
            
            if(lgreater[i]!=-1 && rgreater[i] != -1){
                currmax = ( rgreater[i]-lgreater[i]-1 )*heights[i];
                
            }else if(lgreater[i]==-1 && rgreater[i]==-1){
                currmax = N*heights[i];
                
            }else if(lgreater[i]==-1){
                currmax = rgreater[i]*heights[i];
                
            }else{
                currmax = (N-lgreater[i]-1)*heights[i];
            }
            
            totalMax = max(totalMax, currmax);
        }
        
        return totalMax;
    }
};
