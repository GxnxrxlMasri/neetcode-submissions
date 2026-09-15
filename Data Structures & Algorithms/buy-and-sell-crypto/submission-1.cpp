class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int output = 0;
        int minBuy = prices[0];

        for(int i=0; i<prices.size();i++){
            output = std::max(output, prices[i] - minBuy);
            minBuy = std::min(minBuy, prices[i]);
        }
        return output;
    }
};
