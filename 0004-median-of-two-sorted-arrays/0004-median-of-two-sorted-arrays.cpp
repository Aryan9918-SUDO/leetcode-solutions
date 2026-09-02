class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m  = nums1.size();
        int n = nums2.size();
        int left =0;
        int right =0;
        float ans =0.0;
        vector<int>nums;
        while(left<m && right<n){
            if(nums1[left]<=nums2[right]){
                nums.push_back(nums1[left]);
                left++;
            }
            else{
                nums.push_back(nums2[right]);
                right++;
            }
        }
        while(left<m){
            nums.push_back(nums1[left]);
            left++;
        }
        while(right<n){
            nums.push_back(nums2[right]);
            right++;
        }
        if((m+n)%2!=0){
            ans =nums[(m+n)/2];
        }
        else{
            ans = (nums[((m+n)/2)-1]+nums[(m+n)/2])/2.0;
        }
        return ans;
        
    }
};