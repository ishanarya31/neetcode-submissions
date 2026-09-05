// class Solution {
// public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//         int e = edges.size();
//         if(e != n-1) return false;
//         vector<vector<int>> adj(n);

//         for(int i =0; i< e; i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }

//         vector<int>parent(n,-1);
//         unordered_set<int> vis;
        
//         vis.insert(0);
//         bool res = dfs(0, adj, parent, vis);
//         return vis.size() == n ? res : false;
//     }
//     bool dfs(int node, vector<vector<int>>& adj, vector<int>& parent, unordered_set<int>& vis){
//         for(auto &neigbor: adj[node]){
//             if(!vis.count(neigbor)){
//                 vis.insert(neigbor);
//                 parent[neigbor] = node;
//                 bool res = dfs(neigbor, adj, parent, vis);
//                 if(res == false){
//                     return false;
//                 }
//             }
//             else if(vis.count(neigbor) && neigbor != parent[node]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    vector<int> parent;

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        parent.assign(n, 0);
        for (int i=0; i<n; i++) parent[i] = i;

        for (const vector<int>& edge : edges) {
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);

            if (root1 == root2) 
                return false;
            
            parent[root2] = root1;
        }

        return true; 
    }

    int find(int node) {
        while (node != parent[node])
            node = parent[node];
        return node;
    }
};
