class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index,vector<int>& curr, vector<int>& nums,int target,int k){
        if(target==0 && curr.size()==k){
            ans.push_back(curr);
            return;
        }
        if(index==nums.size()||target<0|| curr.size()>k){
            return;
        }
        if(nums[index]<=target){
            curr.push_back(nums[index]);
            solve(index+1,curr,nums,target-nums[index],k);
            curr.pop_back();
        }
        solve(index+1,curr,nums,target,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i =1;i<=9;i++){
            nums.push_back(i);
        }
        vector<int>curr;
        solve(0,curr,nums,n,k);
        return ans;
    }
};