class Solution {
public:
    vector<string>ans;
    void solve(int index, int n,int open, int close, string& curr){
        if(index==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            open++;
            solve(index+1,n,open,close,curr);
            curr.pop_back();
            open--;
        }
        if(close<open){
            curr.push_back(')');
            close++;
            solve(index+1,n,open,close,curr);
            curr.pop_back();
            close--;
        }
    }
    vector<string> generateParenthesis(int n) {
        
        string curr;
        int open=0;
        int close =0;
        solve(0,n,open,close,curr);
        return ans;
        
    }
};