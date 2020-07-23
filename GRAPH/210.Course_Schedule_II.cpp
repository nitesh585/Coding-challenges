/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.


*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        //Topological sort
        vector<vector<int>> graph(n);
        
        for(int i=0; i<pre.size(); i++){
            graph[pre[i][1]].emplace_back(pre[i][0]);
        }
        
        int inDeg[n];
        memset(inDeg,0,sizeof(inDeg));
        
        for(int i=0; i<pre.size(); i++){
            inDeg[pre[i][0]]++;
        }
        
        queue<int> que;
        for(int i=0; i<n; i++){
            if(inDeg[i]==0){
                que.push(i);
            }
        }
        
        vector<int> order;
        
        int processed=0;
        while(!que.empty()){
            
            int curr = que.front();
            que.pop();
            order.emplace_back(curr);
            
            for(int v : graph[curr]){
                if(--inDeg[v]==0){
                    que.push(v);
                }
            }
            processed++;
        }
        
        if(processed==n)
            return order;
        
        order.clear();
        return order;
        
    }
};
