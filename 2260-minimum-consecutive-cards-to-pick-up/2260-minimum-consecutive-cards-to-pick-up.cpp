class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int>mpp;
        int minlength =INT_MAX;
        for(int i =0;i<cards.size();i++){
            if(mpp.find(cards[i])!=mpp.end()){
                int len = i-mpp[cards[i]]+1;
                minlength = min(len, minlength);
            }
            mpp[cards[i]]=i;
        }
        return minlength == INT_MAX? -1: minlength;
    }
};