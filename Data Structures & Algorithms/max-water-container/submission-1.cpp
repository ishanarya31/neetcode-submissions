class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        for(int i =0; i< n; i++){
            for(int j= i+1; j< n; j++){
                if(heights[j] >= heights[i]);
                int dist = j - i;
                res = max(res, dist * min(heights[j], heights[i]));     
            }
        }
        return res;
    }
};
