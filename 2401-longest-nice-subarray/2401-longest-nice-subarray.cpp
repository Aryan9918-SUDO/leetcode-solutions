class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int usedbits =0;
        int maxlen =0;
        for(int right=0; right<nums.size(); right++){
            while((usedbits & nums[right])!=0){
                usedbits^=nums[left];
                left++;
            }
            usedbits|=nums[right];
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};