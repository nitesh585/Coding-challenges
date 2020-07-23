/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

 

Constraints:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5


*/

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> graph(numCourses);
        
        for(int i=0; i<pre.size(); i++){
            graph[pre[i][1]].emplace_back(pre[i][0]);
        }
        
        int inDeg[numCourses];
        memset(inDeg,0, sizeof(inDeg));
        
        for(int i=0; i<pre.size(); i++){
            inDeg[pre[i][0]]++;
        }
        
        
        queue<int> que;
        for(int i=0; i<numCourses; i++){
            if(inDeg[i]==0){
                que.push(i);
            }
        }
        
        int cnt=0;
        
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            
            for(auto i : graph[curr]){
                if(--inDeg[i]==0){
                    que.push(i);
                }
            }
            cnt++;
        }
        
        return cnt==numCourses;
    }
};
