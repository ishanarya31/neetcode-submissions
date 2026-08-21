class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0 ; i< n; i++){
            //odd length palindromes
            int l = i; int r = i;
            while(l >= 0 && r < n && s[r] == s[l]){
                res++;
                r++;
                l--;
            }
            //even case
            l = i; r = i+1;
            while(l >= 0 && r < n && s[r] == s[l]){
                res++;
                r++;
                l--;
            }
        }
        return res;
    }
};