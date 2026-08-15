class Solution {
   public:
    string encode(vector<string>& strs) {
        string result;

        for (string s : strs) {
            int l = s.size();
            result += to_string(l) + ",";
        }
        result.append("#");
        for (string s : strs) {
            result.append(s);
        }
        return result;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> res;
        int i = 0;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        i++;
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
};

