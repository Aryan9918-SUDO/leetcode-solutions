class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minm_price=prices[0];
        int mxm_profit =0;
        for(int i =0; i<n;i++){
            minm_price = min(minm_price,prices[i]);
            mxm_profit = max(mxm_profit,prices[i]-minm_price);
        }
        return mxm_profit;
    }
};