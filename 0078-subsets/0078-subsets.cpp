class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index, vector<int>& curr,vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        solve(index+1,curr,nums);
        curr.pop_back();
        solve(index+1,curr,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        solve(0,curr,nums);
        return ans;
    }
};