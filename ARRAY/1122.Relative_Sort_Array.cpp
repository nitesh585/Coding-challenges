/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

 

Constraints:

    arr1.length, arr2.length <= 1000
    0 <= arr1[i], arr2[i] <= 1000
    Each arr2[i] is distinct.
    Each arr2[i] is in arr1

*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if(arr2.size()==0){
            sort(arr1.begin() , arr1.end());
            return arr1;
        }
        
        vector<int> res;
        map<int,int> freq;
        
        for(int arr:arr1) freq[arr]++;
        
        for(int i=0; i<arr2.size(); i++){
            while(freq[arr2[i]]){
                res.emplace_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }
        
        for(auto it = freq.begin() ; it!=freq.end() ; it++){
            if(it->second!=0){
                while(it->second){
                    res.emplace_back(it->first);
                    it->second--;
                }
            }
        }
        
        return res;
    }
};
