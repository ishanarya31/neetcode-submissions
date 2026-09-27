class Solution {
public:
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        int n = tickets.size();
        string start = "JFK";
        for(int i =0; i< n; i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto &[_,node]: graph){
            sort(node.rbegin(), node.rend());
        }
        //data structures required :
        // priority_queue<string, vector<string>, greater<>> pq;
        // vector<string> res;

        // pq.push(start);

        // while(!pq.empty()){
        //     string curr = pq.top();
        //     pq.pop();
        //     res.push_back(curr);
        //     for(auto &neig: graph[curr]){
        //         pq.push(neig);
        //     }
        //     graph[curr].clear();
        // }
        // return res;
        dfs(start, graph);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(string curr, unordered_map<string, vector<string>>& graph){
        while(!graph[curr].empty()){
            string next = graph[curr].back();
            graph[curr].pop_back();
            dfs(next, graph);
        }
        res.push_back(curr);
    }
};