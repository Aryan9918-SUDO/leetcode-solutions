class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int a : asteroids){
            bool alive = true;
            while(alive && !st.empty() && a<0 && st.top()>0 ){
                if(st.top()<abs(a)){
                    st.pop();
                }
                else if(st.top()==abs(a)){
                    alive =false;
                    st.pop();
                }
                else{
                    alive = false;
                }
            }
            if(alive){
                st.push(a);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};