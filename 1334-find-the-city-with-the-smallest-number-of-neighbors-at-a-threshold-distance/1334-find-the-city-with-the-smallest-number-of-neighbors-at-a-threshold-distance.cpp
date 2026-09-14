class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            dist[u][v]=weight;
            dist[v][u]=weight;
        }
        for(int k =0;k<n;k++){
            for(int i =0; i<n;i++){
                for(int j =0; j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX){
                        continue;
                    }
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
                }
            }
        }
        int mincount = INT_MAX;
        int answer=-1;
        for(int i =0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                
                if(i!=j&&dist[i][j]<=distanceThreshold){
                    count++;
                }
                
            }
            if(count<=mincount){
                mincount =count;
                answer = i;
            }
        }
        return answer;
    }
};