class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int left =0;
        int right = 0;
        vector<int>freq_count(26,0);

        int maxlen =0;
        int maxfreq=0;
        while(right<n){
            freq_count[s[right]-'A']++;
            maxfreq = max(maxfreq,freq_count[s[right]-'A']);
            while((right-left+1)-maxfreq>k){
                freq_count[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;

        
    }
};