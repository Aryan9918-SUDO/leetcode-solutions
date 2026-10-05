class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int score =0;
        for(char ch:s){
            if(ch=='('){
                st.push(score);
                score =0;
            }
            else{
                int previous_score=st.top();
                st.pop();
                if(score==0){
                    score = previous_score+1;
                }
                else{
                    score=previous_score+2*score;
                }
            }
        }
        return score;
    }
};