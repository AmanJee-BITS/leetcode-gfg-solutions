class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> answer(T.size(),0);
        stack<int> st;

        for(int i=0;i<T.size();i++){
            while(!st.empty() && T[i] > T[st.top()]){
                answer[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};