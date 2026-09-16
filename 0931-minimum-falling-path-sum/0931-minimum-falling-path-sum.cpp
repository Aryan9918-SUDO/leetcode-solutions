class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       vector<vector<int>>dp(n,vector<int>(n,0));
       for(int j =0;j<n;j++){
        dp[0][j]=matrix[0][j];
       } 
       for(int i =1;i<n;i++){
          for(int j =0; j<n;j++)
          {
              int best = dp[i-1][j];
              if(j>0){
                best= min(best,dp[i-1][j-1]);
              }
              if(j<n-1){
                best = min(best,dp[i-1][j+1]);
              }
              dp[i][j]=matrix[i][j]+best;
            }
        }
        int min_val= dp[n-1][0];
        for(int j =1;j<n;j++){
            min_val = min(min_val,dp[n-1][j]);
        }
        return min_val;
    }
};