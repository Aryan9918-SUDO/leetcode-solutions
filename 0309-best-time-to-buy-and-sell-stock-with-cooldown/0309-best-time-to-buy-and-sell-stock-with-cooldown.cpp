class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int hold = -prices[0];
        int sold = 0;
        int rest =0;
        for(int i =1;i<n;i++){
            int prevhold = hold;
            int prevrest = rest;
            int prevsold = sold;
            
            hold = max(prevhold,rest-prices[i]);
            sold = prevhold+prices[i];
            rest = max(prevrest,prevsold);
        }
        return max(sold,rest);
    }
};