class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> minLeft(n);
        vector<int> maxRight(n);

        int min = 100;
        for(int i=0;i<n;i++){
            min = std::min(min, prices[i]);
            minLeft[i] = min;
        }
        
        int max = 0;
        for(int i = n-1; i>=0;i--){
            max = std::max(max, prices[i]);
            maxRight[i] = max;
        }

        int output = 0;
        for(int i = 0;i <n;i++){
            output = std::max(output, maxRight[i] - minLeft[i]);
        }
        return output;
    }
};
