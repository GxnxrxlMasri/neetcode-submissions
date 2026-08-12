class Solution {
   public:
    string encode(vector<string>& strs) {
        string result;
        for (string s : strs) {
            result += "\x80" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int count = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\x80') {
                result.push_back("");
                count++;
            } else {
                result[count] += s[i];
            }
        }
        return result;
    }
};