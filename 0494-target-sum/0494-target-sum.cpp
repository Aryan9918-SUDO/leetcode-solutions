class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum =0;
        for(int num: nums){
            totalsum+=num;
        }
        if(abs(target)>totalsum){
            return 0;
        }
        if((totalsum+target)%2!=0){
            return 0;
        }
        int subtarget = (totalsum+target)/2;
        vector<int>dp(subtarget+1,0);
        dp[0]=1;
        for(int num : nums){
            for(int i = subtarget;i>=num;i--){
                dp[i]+=dp[i-num];
            }
        }
        return dp[subtarget];
        
    }
};