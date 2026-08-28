class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long,int> mp;
        mp[0]=1;
        long long sum =0;
        int count =0;
        int n = nums.size();
        for(int i =0; i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];

            }
            mp[sum]++;

        }
        return count;
    }
};