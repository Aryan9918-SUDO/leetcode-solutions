class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        int n= nums.size();
        for(int i =0; i<n;i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]!=2){
                return nums[i];
            }
        }
        return -1;
    }
};