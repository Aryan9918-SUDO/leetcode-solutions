class Solution {
public:
    vector<vector<string>>ans;
    bool ispalindrome(string s , int start ,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;

            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int index, vector<string>& curr,string s){
        if(index ==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = index; i<s.size();i++){
            if(ispalindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                solve(i+1,curr,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(0,curr,s);
        return ans;
        
    }
};