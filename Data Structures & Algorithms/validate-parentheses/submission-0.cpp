class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i =0; i < n; i++){
            char curr = s[i];
            if(!stk.empty() && stk.top() == '(' && curr == ')'){
                stk.pop();
                continue;
            }
            else if(!stk.empty() && stk.top() == '{' && curr == '}'){
                stk.pop();
                continue;
            }
            else if(!stk.empty() && stk.top() == '[' && curr == ']'){
                stk.pop();
                continue;
            }
            else stk.push(curr);
        }
        return stk.empty() ? true : false;
    }
};