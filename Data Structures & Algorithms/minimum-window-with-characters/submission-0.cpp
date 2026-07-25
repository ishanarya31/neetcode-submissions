class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> freq;
        for(char c: t){
            freq[c]++;
        }
        int r = 0; int l =0; string res = "";
        unordered_map<char, int> running;
        int formed = 0; int bestLen = INT_MAX;
        int bestStart = -1;
        while(r < m){
            if(freq.count(s[r])){
                running[s[r]]++;
                if(freq[s[r]] == running[s[r]]) formed++;
            }
            while(formed == freq.size()){
                if(r-l+1 < bestLen){
                    bestLen = r-l+1;
                    bestStart = l;
                }
                if(running.count(s[l])){
                    running[s[l]]--;
                    if(running[s[l]] < freq[s[l]]){
                        formed--;
                    }
                }
                l++;
            }
            r++;
        }
        if(bestLen == INT_MAX) return "";
        res = s.substr(bestStart, bestLen);
        return (bestStart == -1) ? "" : res ;
    }
};