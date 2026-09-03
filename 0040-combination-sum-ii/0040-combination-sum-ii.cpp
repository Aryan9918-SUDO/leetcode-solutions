class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index, vector<int>& curr, vector<int>& nums, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(index==nums.size()|| target<0){
            return;
        }
        for(int i = index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target){
                break;
            }
            curr.push_back(nums[i]);
            solve(i+1,curr,nums,target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        solve(0,curr,candidates,target);
        return ans;
    }
};