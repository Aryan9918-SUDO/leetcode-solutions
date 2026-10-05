class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int>mpp;
        for(int i =0; i<responses.size(); i++){
            set<string>st(responses[i].begin(), responses[i].end());
            for(string s : st){
                mpp[s]++;
            }
        }
        int count =0;
        string ans ="";
        for(auto it : mpp){
            string name = it.first;
            int freq = it.second;
            if(freq>count ||(freq==count && name<ans)){
                ans = name;
                count = freq;
            }
        }
        return ans;
    }
};