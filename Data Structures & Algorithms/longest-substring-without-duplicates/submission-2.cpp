class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s.size() == 0) return 0;
        int res = 1;
        for(int i = 0; i< n; i++){
            unordered_set<char> tmp;
            tmp.insert(s[i]);
            int currLong = 1;
            for(int j = i+1; j< n; j++){
                if(!tmp.count(s[j])){
                    tmp.insert(s[j]);
                    currLong++;
                }
                else break;
            }
            res = max(res, currLong);
        }
        return res;
    }
};
