class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && sorted[i] == sorted[i - 1]) {
                continue;
            }
            int n = sorted[i];
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = n + sorted[l] + sorted[r];
                if(sum < 0){
                    l++;
                }else if ( sum > 0){
                    r--;
                }else{
                    output.push_back({n, sorted[l], sorted[r]});
                    l++;
                    while(sorted[l] == sorted[l-1] && l < r){
                        l++;
                    }
                }
            }
        }
        return output;
    }
};
