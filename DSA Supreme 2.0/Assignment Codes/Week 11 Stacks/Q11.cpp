//https://leetcode.com/problems/car-fleet-ii/

//Car fleet 2

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int>st;
        int n=cars.size();
        vector<double>time(n,-1);
        for(int i=n-1;i>=0;i--){
            //check if ahead car is faster
            while(!st.empty() && cars[st.top()][1]>=cars[i][1]){
                st.pop();
            }
            while(!st.empty()){

                double col_time=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);

                //if time of collision for stack top is more we set Ans Time else pop
                if(time[st.top()] == -1 || time[st.top()]>=col_time){
                    time[i]=col_time;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return time;  
    }
};