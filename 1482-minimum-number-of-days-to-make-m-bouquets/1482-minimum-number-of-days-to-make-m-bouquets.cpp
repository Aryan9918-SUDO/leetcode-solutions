class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k>n){
            return -1;
        }
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;
            int boquet =0;
            int count=0;
            for(int i =0; i<n;i++){
                if(bloomDay[i]<=mid){
                    count++;
                    if(count==k){
                        boquet++;
                        count=0;
                    }
                }
                else{
                    count=0;
                }
            }
            if(boquet>=m){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};