class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxLength = 0;
        unordered_set<char> charSet;

        for(int r = 0; r < s.size(); r++){
            while(charSet.contains(s[r])){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
