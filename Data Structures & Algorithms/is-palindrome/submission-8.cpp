class Solution {
   public:
    bool isPalindrome(string s) {
        unordered_set<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'e',
                                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0',
                                        '1','2','3','4','5','6','7','8','9'};
        int left = 0;
        int right = s.size()-1;

        while (left < right) {
            while (!alphabet.contains(tolower(s[left])) && left < right) {
                left++;
            }
            while (!alphabet.contains(tolower(s[right])) && left < right) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
