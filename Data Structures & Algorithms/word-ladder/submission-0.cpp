class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        wordList.push_back(beginWord);
        // unordered_set<string> dict(wordList.begin(), wordList.end());

        unordered_map<string, vector<string>> graph;
        for(int i =0; i< wordList.size(); i++){
            string curr = wordList[i];
            for(int j = 0; j< wordList.size(); j++){
                if(i != j){
                    string check = wordList[j];
                    int delta = 0;
                    for(int k = 0; k< n; k++){
                        if(curr[k] != check[k]){
                            delta++;
                        }
                    }
                    if(delta == 1){
                        graph[curr].push_back(check);
                    }
                }
            }
        }
        return bfs(beginWord, endWord,graph);
    }
    int bfs(string firstWord, string endWord, unordered_map<string, vector<string>>&graph){
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({firstWord,1});
        vis.insert(firstWord);

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
    
            if(curr.first == endWord){
                return curr.second; 
            }
            for(auto& neigbour: graph[curr.first]){
                if(!vis.count(neigbour)){
                    vis.insert(neigbour);
                    q.push({neigbour,curr.second+1});
                }
            }
        }
        return 0;
    }
};