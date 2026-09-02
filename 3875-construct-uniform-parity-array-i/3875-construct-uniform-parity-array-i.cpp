class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
       
        //lets create all even
        for(int i =0;i<n;i++){
           if(nums1[i]%2!=0){
            return true;
           }

        }
        for(int i =0; i<n;i++){
            if(nums1[i]%2==0){
                return true;
            }
        }
        return false;
        
    }
};