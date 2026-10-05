class Solution {
public:
    string findValidPair(string s) {
        int n  = s.size();
        string ans ="";
        map<char, int>mpp;
        for(char ch : s){
            mpp[ch]++;
        }
        for(int i =0; i<n-1; i++){
            if(s[i]!=s[i+1] && s[i]-'0'==mpp[s[i]] && s[i+1]-'0'==mpp[s[i+1]]){
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                return ans;

            }
        }
        return "";
    }
};