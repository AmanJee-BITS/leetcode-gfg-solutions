class Solution {
private:
    bool helper(char ch) { return ch >= '0' and ch <= '9'; }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        if (expression.size() == 0)
            return ans;

        if (expression.size() == 1 or
            (expression.size() == 2 && helper(expression[0]))) {
            ans.push_back(stoi(expression));
            return ans;
        }

        for (int i = 0; i < expression.size(); i++) {
            if (helper(expression[i]))
                continue;
            char ch = expression[i];
            vector<int> leftAns = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightAns = diffWaysToCompute(expression.substr(i + 1));
            for (auto& le : leftAns) {
                for (auto& ri : rightAns) {
                    if (ch == '+')
                        ans.push_back(le + ri);
                    else if (ch == '-')
                        ans.push_back(le - ri);
                    else
                        ans.push_back(le * ri);
                }
            }
        }

        return ans;
    }
};