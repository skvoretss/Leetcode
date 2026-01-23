class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for (size_t i = 0; i != tokens.size(); ++i) {
            if (tokens[i].size() == 1)
                if (isdigit(tokens[i][0]))
                    stck.push(stoi(tokens[i]));
                else {
                    int a = stck.top();
                    stck.pop();
                    int b = stck.top();
                    stck.pop();
                    if (tokens[i] == "+")
                        stck.push(a+b);
                    else if (tokens[i] == "*")
                        stck.push(a*b);
                    else if (tokens[i] == "/")
                        stck.push(b/a);
                    else if (tokens[i] == "-")
                        stck.push(b-a);
                }
            else stck.push(stoi(tokens[i]));
        }
        return stck.top();
    }
};