class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       vector<int>freq(2001,0);
       int k =0;
       for(int i =0; i<nums.size(); i++){
           if(freq[nums[i]]==0){
            k++;
           }
           freq[nums[i]]++;
        }
        vector<int>freq_2(2001,0);
        int left =0;
        int ans =0;
        int distinct=0;
        int n = nums.size();
        for(int right =0; right<nums.size(); right++){
            if(freq_2[nums[right]]==0){
                distinct++;
            }
            freq_2[nums[right]]++;

            while (distinct ==k){
                ans+=n-right;
                freq_2[nums[left]]--;
                if(freq_2[nums[left]]==0){
                    distinct--;
                }
                left++;
                
            }
        }
        return ans;
    }
};