class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto prereq:prerequisites){
            int u = prereq[0];
            int v = prereq[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i =0; i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for( auto neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }

        }
        if(topo.size()!=numCourses){
            return {};
        }
        return topo;
    }
};