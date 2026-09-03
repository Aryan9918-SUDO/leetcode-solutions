class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index, vector<int>& curr,vector<int>& nums, int target ){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(index==nums.size()||target<0){
            return;
        }
        if(nums[index]<=target){
            curr.push_back(nums[index]);
            solve(index,curr,nums,target-nums[index]);
            curr.pop_back();
        }
        solve(index+1,curr,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(0,curr,candidates,target);
        return ans;
    }
};