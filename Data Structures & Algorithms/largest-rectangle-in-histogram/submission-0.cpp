class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> stk;
        for(int i = 0; i< n; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty())stk.pop();
        for(int i = n-1; i>= 0; i--){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        for(int i =0; i < n; i++){
            int area = 0;
            area = heights[i] * (right[i] - left[i]-1);
            res = max(res, area);
        }
        return res;
    }
};