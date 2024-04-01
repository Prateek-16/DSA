//https://leetcode.com/problems/daily-temperatures/description/

//Daily temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        int n = temperatures.size();
        st.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int curr_temp = temperatures[i];
            while (st.top() != -1 && temperatures[st.top()] <= curr_temp) {
                st.pop();
            }
            if (st.top() == -1) {
                st.push(i);
                ans[i] = 0;
            } else {
                ans[i] = st.top() - i;
                st.push(i);
            }
        }
        return ans;
    }
};

//********************************OR WITHOUT REVERSE TRAVERSING**********************************
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};