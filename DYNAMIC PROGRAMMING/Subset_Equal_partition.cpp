/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}. 

*/

#include<iostream>
using namespace std;

int subsetPartition(int ar[] , int n, int sum){
    if(sum==0 ){
        return true;
    }
    
    if(n==0 || sum<0){
        return false;
    }
    
    return  subsetPartition(ar, n-1, sum-ar[n-1] ) ||
            subsetPartition(ar, n-1, sum );
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int ar[n];
	    int sum=0;
	    for(int i=0; i<n; i++){
	        cin>>ar[i];
	        sum+=ar[i];
	    }
	    
	    //Solution
	    bool ans = false;
	    if(sum%2==0){
	        ans = subsetPartition(ar, n, sum/2);
	    }
	    
	    if(ans==true){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
	
	return 0;
}
