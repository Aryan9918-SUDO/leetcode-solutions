class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftmax(n,0);
        vector<int>rightmax(n,0);
        int left_max =0;
        int right_max=0;
        int water =0;
        for(int i =0; i<n; i++){
            if(height[i]>left_max){
                left_max=height[i];
                
            }
            leftmax[i]=left_max;
        }
        for(int i = n-1; i>=0; i--){
            if(height[i]>right_max){
                right_max=height[i];
            }
            rightmax[i]=right_max;
        }
        for(int i =0; i<n;i++){
            water+=min(leftmax[i],rightmax[i])-height[i];
        }
        return water;
        
    }
};