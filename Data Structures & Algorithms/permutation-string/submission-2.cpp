class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        if(s2.size() < s1.size()){
            return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            map1[s1[i]]++;
            map2[s2[i]]++;
        }
        if (map1 == map2) {
            return true;
        }
        printMap(map1);
        printMap(map2);
        cout << "Size limit: " << s2.size() - s1.size() << endl;
        for (int i = 1; i <= s2.size() - s1.size(); i++) {
            map2[s2[i - 1]]--;
            if (map2[s2[i - 1]] == 0) {
                map2.erase(s2[i - 1]);
            }
            map2[s2[i + s1.size() - 1]]++;
            printMap(map2);

            if (map1 == map2) {
                return true;
            }
        }
        return false;
    }

    void printMap(unordered_map<char, int>& map1) {
        for (auto& [key, value] : map1) {
            cout << key << ": " << value << endl;
        }

        cout << "............." << endl;
    }
};
