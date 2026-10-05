class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        map<int,int>first;
        map<int,int>last;
        for(int i =0; i<nums.size();i++){
            freq[nums[i]]++;
            if(first.find(nums[i])==first.end()){
                first[nums[i]]=i;
            }
            last[nums[i]]=i;
        }
        int degree =0;
        for(auto it : freq){
            int count=it.second;
            if(count>degree){
                degree=count;
            }
        }
        int minm_length = nums.size();
        for(auto it: freq){
            int num = it.first;
            if(freq[num]==degree){
               int length = last[num]-first[num]+1;
               minm_length = min(length,minm_length);
            }
        }
        return minm_length;
    }
};