class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total =0;
        for(int i =0; i<n;i++){
            total+=cardPoints[i];
        }
        int windowsize=n-k;
        int windowsum=0;
        for(int i =0; i<windowsize;i++){
           windowsum+=cardPoints[i];
        }
        int minsum=windowsum;
        int left =0;
        for(int right =windowsize; right<n; right++){
            windowsum+=cardPoints[right];
            windowsum-=cardPoints[left];
            left++;
            minsum= min(minsum,windowsum);
        }
        return total-minsum;
    }
};