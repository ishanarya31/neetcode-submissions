class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for(int i =0; i< n; i++){
            if(!stk.empty() && tokens[i] == "+"){
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                stk.push(op1 + op2);
            }
            else if(!stk.empty() && tokens[i] == "-"){
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                stk.push(op2 - op1);
            }
            else if(!stk.empty() && tokens[i] == "*"){
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                stk.push(op1 * op2);
            }
            else if(!stk.empty() && tokens[i] == "/"){
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                stk.push(op2/op1);
            }
            else stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }
};