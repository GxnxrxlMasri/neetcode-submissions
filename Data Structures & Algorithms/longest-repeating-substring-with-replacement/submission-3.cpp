class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;
        int maxf = 0;
        int l = 0;
        int r = 0;
        int output = 0;
        int n = s.size();

        while (r < n) {
            count[s[r]]++;
            maxf = std::max(maxf, count[s[r]]);
            if ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            output = std::max(output, (r - l + 1));
            r++;
        }
        return output;
    }
};
