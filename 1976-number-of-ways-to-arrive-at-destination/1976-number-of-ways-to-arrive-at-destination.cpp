class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto road : roads){

            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0, 0});

        int MOD = 1e9 + 7;

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            long long weight = it.first;
            int node = it.second;

            // Ignore outdated entry
            if(weight > dist[node])
                continue;

            for(auto road : adj[node]){

                int nextnode = road.first;
                int distance = road.second;

                if(weight + distance < dist[nextnode]){

                    dist[nextnode] = weight + distance;

                    ways[nextnode] = ways[node];

                    pq.push({
                        dist[nextnode],
                        nextnode
                    });
                }

                else if(weight + distance == dist[nextnode]){

                    ways[nextnode] =
                        (ways[nextnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};