class Solution {
public:
    int partitionString(string s) {
        int ans =1;
        int left =0;
        string current ="";
        vector<int>freq(26,0);
        for(int right =0; right<s.size(); right++){
            if(freq[s[right]-'a']==1){
                ans++;
                freq = vector<int>(26,0);

            }
            freq[s[right]-'a']=1;   
        }
        return ans;
    }
};