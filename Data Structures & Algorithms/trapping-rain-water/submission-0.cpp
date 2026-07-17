class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> maxLeft(n, 0), maxRight(n, 0);

        for(int i = 0; i < n; i++){
            int m = 0;
            for(int j = i+1; j < n; j++) m = max(m, height[j]);
            maxRight[i] = m;
        }
        for(int i = 0; i < n; i++){
            int m = 0;
            for(int j = i-1; j >= 0; j--) m = max(m, height[j]);
            maxLeft[i] = m;
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            res += max(0, min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return res;
    }
};
