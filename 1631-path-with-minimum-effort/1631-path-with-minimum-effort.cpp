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

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==row-1 && c==col-1){
                return effort;
            }
            int nr[]={1,-1,0,0};
            int nc[]={0,0,-1,1};
            for(int k=0; k<4;k++){
                int newr = r+nr[k];
                int newc = c+nc[k];
                
              
                if(newr<0||newr>=row||newc<0||newc>=col){
                    continue;
                }
                int difference = abs(heights[newr][newc]-heights[r][c]);
                int neweffort = max(effort,difference);
                if(neweffort<dist[newr][newc]){
                    dist[newr][newc]=neweffort;
                    pq.push({neweffort,{newr,newc}});
                }
            }
        }
        return 0;
    }
};