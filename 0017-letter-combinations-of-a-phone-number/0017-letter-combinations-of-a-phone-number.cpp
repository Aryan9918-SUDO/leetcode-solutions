class Solution {
public:
    vector<string>ans;
    void backtrack(string &current, int index,string &digits, vector<string> &letters ){
        
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        string possible = letters[digits[index]-'0'];
        for(int i =0; i<possible.size(); i++){
            current+=possible[i];
            backtrack(current,index+1,digits,letters);
            current.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>letters ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string current="";
        int index =0;
        backtrack(current,index,digits,letters);
        return ans;
    }
};