/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0,i = height.size()-1,j=0,k=height.size()-1;
        int h1,h2;
        while(i!=j){
            
            h1 = height[j];
            h2 = height[i];
            int tmp;
            if(h1<h2){
                tmp = h1*k;
                j++;
            }else{
                tmp = h2*k;
                i--;
            }
            k--;
            if(max<tmp){
                max = tmp;
            }
        }
        return max;
    }
};
