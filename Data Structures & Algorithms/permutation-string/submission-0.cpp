class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int wnsz = s1.size();
        vector<int> freq(26,0);
        for(int i =0; i< wnsz; i++){
            freq[s1[i]-'a']++;
        }
        int l = 0; int r = wnsz;
        vector<int> tfreq(26,0);
        for(int i = l; i< r; i++){
            tfreq[s2[i]-'a']++;
        }
        while(r < s2.size()){
            if(tfreq == freq) return true;
            tfreq[s2[r]-'a']++;
            r++;
            tfreq[s2[l]-'a']--;
            l++;
        }
        if(tfreq == freq) return true;
        return false;
    }
};
