class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> answer;
        unordered_map<char, int> sMap;

        for (int i = 0; i < t.size(); i++) {
            answer[t[i]]++;
        }

        int need = answer.size();
        int have = 0;

        int l = 0;

        int min = s.size() + 1;
        int lMin = -1;
        int rMin = -1;

        for (int r = 0; r < s.size(); r++) {

            // Add right character
            if (answer.find(s[r]) != answer.end()) {
                sMap[s[r]]++;

                if (sMap[s[r]] == answer[s[r]]) {
                    have++;
                }
            }

            // Window is valid
            while (have == need) {

                if (r - l + 1 < min) {
                    min = r - l + 1;
                    lMin = l;
                    rMin = r;
                }

                // Remove left character
                if (answer.find(s[l]) != answer.end()) {

                    if (sMap[s[l]] == answer[s[l]]) {
                        have--;
                    }

                    sMap[s[l]]--;

                }

                l++;
            }
        }

        if (lMin == -1) {
            return "";
        }

        return s.substr(lMin, rMin - lMin + 1);
    }
};