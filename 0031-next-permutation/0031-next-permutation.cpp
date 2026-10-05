class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int br_pos =-1;
        for(int i =n-2;i>=0; i--){
            if(nums[i]<nums[i+1]){
                br_pos =i;
                break;
            }
        }
        if(br_pos==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i =n-1; i>br_pos; i--){
            if(nums[i]>nums[br_pos]){
                swap(nums[i],nums[br_pos]);
                break;
            }
        }
        reverse(nums.begin()+br_pos+1,nums.end());
        
        
    }
};