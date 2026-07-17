class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxSoFarL = 0;
        int maxSoFarR = 0;
        int water = 0;
        while(l < r)
        {
            if(height[l] > maxSoFarL)
            {
                maxSoFarL = height[l];
            }
            water += maxSoFarL - height[l];

            if(height[r] > maxSoFarR)
            {
                maxSoFarR = height[r];
            }
            water += maxSoFarR - height[r];

            if(height[l] < height[r])
                l++;
            else
                r--;
        }

        return water;
    }
};

