class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> answer;
        unordered_map<char, int> sMap;

        for (int i = 0; i < t.size(); i++) {
            answer[t[i]]++;
        }
        int rMin = s.size() + 1;
        int lMin = s.size() + 1;
        int l = 0;
        int min = s.size() + 1;
        for (int r = 0; r < s.size(); r++) {
            sMap[s[r]]++;
            while(checkValid(sMap, answer)){
                if(r-l < min){
                    min = r-l;
                    rMin = r;
                    lMin = l;
                }
                sMap[s[l]]--;
                if(sMap[s[l]] < 1){
                    sMap.erase(s[l]);
                }
                l++;
            }
        }
        if(lMin == s.size() + 1 || rMin == s.size() + 1){
            return "";
        }else{
            return s.substr(lMin, rMin - lMin + 1);

        }

    }

    bool checkValid(unordered_map<char, int>& sMap, unordered_map<char, int>& answer){
        for(auto& [key,value] : answer){
            if(value > sMap[key]){
                return false;
            }
        }
        return true;
    }
};
