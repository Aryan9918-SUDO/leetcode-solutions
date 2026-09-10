class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>outdegree(n,0);
        for(int i =0;i<n;i++){
            outdegree[i]=graph[i].size();
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        queue<int>q;
        for(int i =0; i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto neighbor : adj[node]){
                outdegree[neighbor]--;
                if(outdegree[neighbor]==0){
                    q.push(neighbor);
                }
            }

        }
        sort(topo.begin(), topo.end());
        return topo;
       
    }
};