class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];

            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int,int>>> q;

        dist[src] = 0;

        q.push({0, {src, 0}});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)
                continue;

            vector<int> temp = dist;

            for(auto edge : adj[node]){

                int nextNode = edge.first;
                int weight = edge.second;

                if(cost + weight < temp[nextNode]){

                    temp[nextNode] = cost + weight;

                    q.push({
                        stops + 1,
                        {nextNode, temp[nextNode]}
                    });
                }
            }

            dist = temp;
        }

        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};