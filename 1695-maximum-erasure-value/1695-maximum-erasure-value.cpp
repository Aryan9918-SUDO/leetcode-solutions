class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int n = nums.size();
       set<int>st;
       int sum =0;
       int left =0;
       int right =0;
       int ans =0;
       for(right =0;right<n;right++)
       {
        while(st.find(nums[right])!=st.end())
        {
            sum-=nums[left];
            st.erase(nums[left]);
            left++;
        }
        sum+=nums[right];
        st.insert(nums[right]);
        ans = max(ans,sum);
        }
        return ans;

    }
};