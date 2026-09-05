class Solution {
public:
    vector<int> parent;
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.assign(n, 0);

        for(int i =0; i< n; i++){
            parent[i] = i;
        }
        for(int i =0; i< edges.size(); i++){
            int root1 = find(edges[i][0]);
            int root2 = find(edges[i][1]);

            parent[root2] = root1;
        }
        unordered_set<int> res;
        for(int i =0;i < n; i++){
            int root = find(i);
            if(!res.count(root)){
                res.insert(root);
            }
        }
        return res.size();
    }
    int find(int node){
        while(node != parent[node]){
            node = parent[node];
        }
        return node;
    }
};
