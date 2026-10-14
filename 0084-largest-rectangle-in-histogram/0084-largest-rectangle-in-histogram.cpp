class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxi =0;
        for(int i =0; i<=n; i++){
            int currheight =(i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>=currheight){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                   width=i;
                }
                else{
                    width = i-st.top()-1;
                }
                maxi = max(maxi,height*width);
            }
            if(i<n){
              st.push(i);
            }
        }
        return maxi;
    }
};