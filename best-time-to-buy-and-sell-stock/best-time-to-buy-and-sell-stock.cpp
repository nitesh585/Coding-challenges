class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, mx=INT_MIN;
        for(int p: prices){
            mn = min(mn, p);
            mx = max(mx, p-mn);
        }
        return mx;
    }
};