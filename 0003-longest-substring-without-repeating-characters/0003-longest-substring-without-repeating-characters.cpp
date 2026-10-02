class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left =0;
        int maxlen =0;
        int right=0;
        vector<int>mpp(256,-1);
        while(right<n){
            if(mpp[s[right]]!=-1){
                left = max(mpp[s[right]]+1,left);

            }
            mpp[s[right]]=right;
            maxlen = max(maxlen,right-left+1);
            right++;

        }
        return maxlen;
    }
};