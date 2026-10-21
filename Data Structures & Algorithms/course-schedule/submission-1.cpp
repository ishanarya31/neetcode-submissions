class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Cycle Detection - Algo in Graph
        
        //initialization : 
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses,0);
        vector<int> ans;

        //creating the graph
        for(int i = 0 ; i< prerequisites.size() ; i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);

            inDegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i< numCourses ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int t = q.front();
            q.pop();

            ans.push_back(t);
            for(auto x: adjList[t]){
                inDegree[x]--;

                if(inDegree[x] == 0){
                    q.push(x);
                }
            }
        }

        //check the ans array size
        return (ans.size() == numCourses) ? true : false;
        

        
    }
};