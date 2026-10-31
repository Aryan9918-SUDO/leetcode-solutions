class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        const int MOD= 1e9+7;
        vector<vector<int>>d(m,vector<int>(n));
        vector<vector<int>>r(m,vector<int>(n));
        d[0][0]=0;
        r[0][0]=1;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if (grid[i][j] == 0) {
                   int ways = (d[i][j] + r[i][j]) % MOD;

                   if (i + 1 < m) {
                       d[i+1][j] = (d[i+1][j] + ways) % MOD;
                    }

                   if (j + 1 < n) {
                     r[i][j+1] = (r[i][j+1] + ways) % MOD;
                    }
                }
                else{
                    if(j+1<n){
                        r[i][j+1]=(d[i][j]+r[i][j+1])%MOD;
                    }
                    if(i+1<m){
                        d[i+1][j]=(r[i][j]+d[i+1][j])%MOD;
                    }
                }

            }
        }
        return (r[m-1][n-1] + d[m-1][n-1]) % MOD;
    }
};