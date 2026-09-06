class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());

        int max = 0;
        for (int n : unique) {
            if (!unique.contains(n - 1)) {
                int count = 1;
                while (unique.contains(n + 1)) {
                    count++;
                    n++;
                }
                if (count > max) {
                    max = count;
                }
            }
        }
        return max;
    }
};
