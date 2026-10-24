class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        queue<int>q;

        for(int i =0; i<n; i++){
            if(color[i]==-1){
                q.push(i);
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto neighbr : graph[node]){
                    if(color[neighbr]==-1){
                        color[neighbr]=1-color[node];
                        q.push(neighbr);
                    }
                    else if(color[neighbr]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};