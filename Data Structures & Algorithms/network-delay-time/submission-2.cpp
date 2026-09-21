class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(int i =0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        // vector<int> fasTime(n+1,INT_MAX);
        // queue<pair<int, int>> q;
        // q.push({k,0});
        // while(!q.empty()){
        //     int sz = q.size();
        //     for(int i =0; i< sz; i++){
        //         auto curr = q.front();
        //         q.pop();
        //         if(curr.second < fasTime[curr.first]){
        //             fasTime[curr.first] = curr.second;
        //         }
        //         for(auto& neig : graph[curr.first]){
        //             if(fasTime[neig.first] > curr.second + neig.second){
        //                 q.push({neig.first, curr.second + neig.second});
        //             }
        //         }
        //     }
        // }
        // int mxTime = -1;
        // for(int i =1; i<= n; i++){
        //     if(fasTime[i] > mxTime){
        //         mxTime = fasTime[i];
        //     }
        // }
        // return (mxTime == INT_MAX) ? -1 : mxTime;
        vector<bool> visited(n+1,0); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int t = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(visited[curr.second]) continue;
            else visited[curr.second] = true;
            t = curr.first;
            for(auto &neig : graph[curr.second]){
                if(!visited[neig.first]){
                    pq.push({curr.first + neig.second, neig.first});
                }
            } 
        }
        for(int i =1; i<= n; i++){
            if(visited[i] == false){
                return -1;
            }
        }
        return t;
    }
};