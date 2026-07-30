class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int l = 1; int r = piles[n-1];
        int mid = 0;
        while(l < r){
            mid = (r-l)/2 + l;
            int time = 0;
            for(int i = 0 ; i< n; i++){
                time += (piles[i] + (mid-1))/mid;
            }
            if(time > h){
                l = mid + 1;
            }   
            else if(time <= h){
                r = mid;
            }
        }
        return l;
    }
};