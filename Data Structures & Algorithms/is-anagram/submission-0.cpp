class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        if(s_size != t_size){
            return false;
        }

        std::unordered_map<char, int> alphabetS;
        std::unordered_map<char, int> alphabetT;

        for(int i=0; i<s_size;i++){
            alphabetS[s[i]]++;
            alphabetT[t[i]]++;
        }
        if(alphabetS == alphabetT){
            return true;
        }else{
            return false;
        }
    }
};
