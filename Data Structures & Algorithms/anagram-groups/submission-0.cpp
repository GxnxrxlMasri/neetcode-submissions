class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<std::unordered_map<char,int>> anagrams;
        vector<vector<string>> groups;
        for(int i =0;i<strs.size();i++){
            std::unordered_map<char,int> anagram;
            string n = strs[i];
            for(int j=0;j<n.size();j++){
                if(anagram.contains(n[j])){
                    anagram[n[j]]++;
                }else{
                    anagram.insert({n[j],0});
                }
            }
            bool found = false;
            for(int j=0; j<anagrams.size();j++){
                if(anagram == anagrams[j]){
                    found = true;
                    groups[j].push_back(n);
                }
            }
            if(!found){
                anagrams.push_back(anagram);
                groups.push_back({n});
            }

        }
        return groups;
        
    }
};
