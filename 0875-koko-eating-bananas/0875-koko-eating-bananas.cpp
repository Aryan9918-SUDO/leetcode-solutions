class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high=*max_element(piles.begin(),piles.end());
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            long long total_time =0;
            for(int i =0;i<n;i++){
                int time = (piles[i]+mid-1)/mid;
                total_time+=time;
            }
            if(total_time<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};