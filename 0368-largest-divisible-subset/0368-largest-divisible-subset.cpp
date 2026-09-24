class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        parent[0]=-1;
        for(int i =1; i<n;i++){
            for(int j =0; j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]= dp[j]+1;
                    parent[i]=j;
                }
            }
        }
        int maximum_element =*max_element(dp.begin(),dp.end());
        int index =0;
        for(int i =0; i<dp.size(); i++){
            if(dp[i]==maximum_element){
                index =i;
                break;
            }
        }
        vector<int>ans;
        while(index !=-1){
            ans.push_back(nums[index]);
            index = parent[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};