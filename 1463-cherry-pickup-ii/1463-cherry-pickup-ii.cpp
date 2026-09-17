class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        const int NEG=-1e9;

        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(col,NEG)));
        
        //base case
        dp[0][0][col-1]= grid[0][0]+grid[0][col-1];

        for(int i =1; i<row;i++){
            for(int j1 =0; j1<col;j1++){
                for(int j2 =0; j2<col; j2++){
                    int cherries;
                    
                    if(j1==j2){
                      cherries = grid[i][j1];
                    }
                    else{
                        cherries= grid[i][j1]+grid[i][j2];
                    }
                    int best = NEG;
                    for(int d1 = -1;  d1<=1; d1++){
                        for(int d2 = -1; d2<=1;d2++){
                            int prev1 = j1-d1;
                            int prev2 = j2-d2;
                            // Check boundaries
                            if (prev1 < 0 || prev1 >= col ||
                                prev2 < 0 || prev2 >= col) {
                                continue;
                            }
                            best = max(best, dp[i-1][prev1][prev2]);
                        }
                        
                    }
                    dp[i][j1][j2]= best + cherries;
                }

            }
        }
        int ans =0;
        for(int j1 =0; j1<col; j1++){
            for(int j2=0; j2<col; j2++){
                ans = max(ans,dp[row-1][j1][j2]);
            }
        }
        return ans;
    }
};