class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> output;
        vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        for (int i = 0; i < sorted.size() - 2; i++) {
            int n = sorted[i];
            int l = i + 1;
            int r = sorted.size() - 1;
            while (l < r) {
                if (sorted[l] + sorted[r] + n == 0) {
                    output.insert({n, sorted[l], sorted[r]});
                    l++;
                    r--;
                } else if (sorted[l] + sorted[r] + n > 0) {
                    r--;
                } else if (sorted[l] + sorted[r] + n < 0) {
                    l++;
                }
            }
        }
        vector<vector<int>> result(output.begin(), output.end());
        return result;
    }
};
