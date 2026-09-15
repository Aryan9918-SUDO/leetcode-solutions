class Solution {
public:
    int f (int start, int end , vector<int>& nums){
        int prev2 =0;
        int prev1 =0;

        for(int i =start; i<=end;i++){
            int curr = max(nums[i]+prev2,prev1);
            prev2 = prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int case1= f(0,n-2,nums);
        int case2 = f(1,n-1,nums);
        return max(case1,case2);
    }
};