class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>hold(k+1,INT_MIN);
        vector<int>cash(k+1,0);

        for(auto price : prices){
            for(int i =1; i<=k;i++){
                hold[i]=max(hold[i],cash[i-1]-price);
                cash[i]=max(cash[i],hold[i]+price);
            }
        }
        return cash[k];
        
    }
};