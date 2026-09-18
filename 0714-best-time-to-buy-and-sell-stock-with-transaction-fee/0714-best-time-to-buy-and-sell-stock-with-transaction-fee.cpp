class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0];
        int sold =0;
        
        for(int i =1; i<n;i++){
            int prevhold = hold;
            int prevsold = sold;
            
            hold = max(prevhold,prevsold-prices[i]);
            sold = max(prevsold, prevhold+prices[i]-fee);
        }
        return sold;
    }
};