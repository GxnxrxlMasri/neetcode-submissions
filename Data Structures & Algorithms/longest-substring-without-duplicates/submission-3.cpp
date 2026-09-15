class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int output = 0;
        int l = 0;
        int r = 0;
        unordered_set<int> unique;

        while (r < s.size()) {
            if (unique.contains(s[r])) {
                // cout << "l: " << l << " r: " << r << " o: " << output << endl;

                unique.erase(s[l]);
                l++;
            } else {

                unique.insert(s[r]);
                output = std::max(output, r - l+1);
                // cout << "l: " << l << " r: " << r << " o: " << output << endl;
                r++;
            }
        }
        return output;
    }
};
