class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<int> state(n, 0); // 0 = unvisited, 1 = in-progress, 2 = done
        stack<int> stk;

        for(int i = 0; i < n; i++){
            if(state[i] == 0){
                if(!dfs(i, adj, stk, state)){
                    return {}; // cycle found, no valid order
                }
            }
        }

        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }

    bool dfs(int course, vector<vector<int>> &adj, stack<int> &stk, vector<int> &state){
        state[course] = 1; // mark in-progress

        for(auto it : adj[course]){
            if(state[it] == 1) return false;          // back edge -> cycle
            if(state[it] == 0 && !dfs(it, adj, stk, state)) return false; // propagate failure
        }

        state[course] = 2; // mark done
        stk.push(course);
        return true;
    }
};