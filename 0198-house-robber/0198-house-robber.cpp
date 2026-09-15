class Solution {
public:
    int f(int indx, vector<int>& nums, vector<int>& dp){
        if(indx ==0){return nums[0];}
        if(indx <0){
            return 0;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        int pick = nums[indx]+f(indx-2,nums,dp);
        int nonpick = f(indx-1,nums,dp);
        return dp[indx]= max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};