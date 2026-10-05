class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mpp;
        int count=0;
        int ans =-1;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%2==0){
                mpp[nums[i]]++;
                if(mpp[nums[i]]>count||(mpp[nums[i]]==count&&nums[i]<ans)){
                    count = mpp[nums[i]];
                    ans = nums[i];
                }
                
            }
        }
        return ans;
        
    }
};