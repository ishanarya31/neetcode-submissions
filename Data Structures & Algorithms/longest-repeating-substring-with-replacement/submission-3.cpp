class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0, l = 0;
        int freq[26] = {0};
        for (int r = 0; r < n; r++) {
            freq[s[r] - 'A']++;
            int maxFreq = 0;
            for (int i = 0; i < 26; i++) maxFreq = max(maxFreq, freq[i]);
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;   
                maxFreq = 0;
                for (int i = 0; i < 26; i++) maxFreq = max(maxFreq, freq[i]);
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};