class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int i =0; i<n-1;i++){
            int sum= nums[i]+nums[i+1];
            if(st.find(sum)!=st.end()){
                return true;
            }
            st.insert(sum);
        } 
        return false;
    }
};