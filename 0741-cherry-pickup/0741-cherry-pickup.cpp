class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        const int NEG = -1e9;
        vector<vector<int>>dp(n,vector<int>(n,NEG));
        dp[0][0]= grid[0][0];

        for(int k =1; k<=2*n-2;k++){
            vector<vector<int>>newdp(n,vector<int>(n,NEG));
            int start = max(0,k-(n-1));
            int end = min(n-1,k);

            for(int row1 = start; row1<=end;row1++){
                for(int row2 = start; row2<=end; row2++){
                    int c1 = k-row1;
                    int c2 = k-row2;

                    if(grid[row1][c1]==-1||grid[row2][c2]==-1){
                        continue;
                    }
                    int best = dp[row1][row2];
                    if(row1>0){
                        best = max(best,dp[row1-1][row2]);

                    }
                    if(row2>0){
                        best = max(best,dp[row1][row2-1]);
                    }
                    if(row1>0&&row2>0){
                        best = max(best,dp[row1-1][row2-1]);
                    }
                    if(best==NEG){
                        continue;
                    }
                    if(row1==row2){
                        newdp[row1][row2] =best + grid[row1][c1];
                    }
                    else{
                        newdp[row1][row2]=best+grid[row1][c1]+grid[row2][c2];
                    }
                }
            }
            dp = newdp;
            
        }
        return max(0,dp[n-1][n-1]);
    }
};