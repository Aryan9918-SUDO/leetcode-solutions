class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,
                      vector<pair<int,pair<int,int>>>,
                      greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int nr[] = {-1,1,0,0};
        int nc[] = {0,0,-1,1};
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int effort = it.first;
            int r= it.second.first;
            int c = it.second.second;
            if(r==row-1 && c==col-1){
                return effort;
            }
            for(int i =0; i<4; i++){
                int dr = r+nr[i];
                int dc = c+nc[i];
                if(dr<0 ||dr>=row ||dc<0 ||dc>=col){
                    continue;
                }
                int difference = abs(heights[dr][dc]-heights[r][c]);
                int neweffort = max(difference,effort);
                if(neweffort<dist[dr][dc]){
                    dist[dr][dc]=neweffort;
                    pq.push({neweffort,{dr,dc}});
                }

            }
            
        }
        return 0;
    }
};