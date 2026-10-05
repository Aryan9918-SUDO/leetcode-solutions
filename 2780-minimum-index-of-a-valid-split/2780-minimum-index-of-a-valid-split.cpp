class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        int dominant;
        int frequency;
        for(int i =0; i<n; i++){
            mpp[nums[i]]++;
            if (mpp[nums[i]]>n/2){
                dominant = nums[i];
                frequency = mpp[nums[i]];
            }
        }
        int count =0;
        for(int i =0; i<=n-2;i++){
            if(nums[i]==dominant){
                count++;
                int rightd = frequency-count;
                if(2*count>i+1 && 2*rightd>n-i-1){
                    return i;
                }
            }
           
        }
        return -1;
    }
};