class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int e = edges.size();

        parent.assign(e+1,0);
        for(int i =1 ; i<= e; i++) parent[i] = i;

        int lastIdx = -1;
        for(int i =0; i< e;i++){
            int root1 = find(edges[i][0]);
            int root2 = find(edges[i][1]);

            if(root1 == root2){
                lastIdx = i;
            }
            parent[root2] = root1;
        }
        return edges[lastIdx];
    }
    int find(int node){
        while(node != parent[node]){
            node = parent[node];
        }
        return node;
    }
};