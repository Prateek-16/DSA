//https://leetcode.com/problems/car-fleet-ii/

//Car fleet 2

Steps 
1. Stack will have those cars which may collide
2. Simple baat hai kisi bhi new car ka time for collision nikalna hai toh 
sabse pehele stack se woh cars hata do jo usse tej ho speed mai
3. Ab stack ke top pe jo car hai woh slow hai current car se toh collision time nikalo
4. Ab bas yeh condition dekhlo ki jitne time mai humari current car slower car se collide kar rhi hai usse pehele slower car kisi aur car se toh collide nhi kar ja rahi
5. If false then toh current car slow car se collide karegi and time save kar lo and current car ko stack mai dal dena
6. But agar slow car kisi aur se collide kar jati hai toh slower car ab us car ka part ban jati hai so uska stack mai koi need nhi so pop it, and current car ka collision time slower ke collided car se find karo 


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