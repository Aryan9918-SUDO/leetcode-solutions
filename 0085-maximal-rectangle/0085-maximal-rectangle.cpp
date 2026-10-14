class Solution {
public:
    int largestrectangle(vector<int>& height){
        int n = height.size();
        stack<int>st;
        int maxi=0;
        for(int i =0; i<=n;i++){
            int curr = (i==n)? 0 : height[i];
            while(!st.empty() && height[st.top()]>=curr){
                int length = height[st.top()];
                st.pop();
                int width ;
                if(st.empty()){
                    width =i;
                }
                else{
                    width =i-st.top()-1;
                }
                maxi = max(maxi,length*width);
            }
            if(i<n){
                st.push(i);
            }
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>height(col,0);
        int ans =0;

        for(int i =0; i<row; i++){
            for(int j =0; j<col;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            int area = largestrectangle(height);
            ans = max(area,ans);
        }
        return ans;
    }
};