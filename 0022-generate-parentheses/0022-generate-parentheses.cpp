class Solution {
public:
    vector<string>ans;
    void backtrack(string &s, int open,int close,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+='(';
            open++;
            backtrack(s,open,close,n);
            s.pop_back();
            open--;
        }
        if(close<open){
            s+=')';
            close++;
            backtrack(s,open,close,n);
            s.pop_back();
            close--;
        }
    }

    vector<string> generateParenthesis(int n) {
        string s ="";
        int open =0;
        int close =0;
        backtrack(s,open,close,n);
        return ans;    
    }
};