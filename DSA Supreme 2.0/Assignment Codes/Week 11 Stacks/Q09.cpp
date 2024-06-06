//https://leetcode.com/problems/asteroid-collision/description/

//Astroid collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ast: asteroids){
            if(ast>0){
                st.push(ast);
            }
            else{
                if(st.empty() ||st.top() < 0){
                    st.push(ast);
                }
                else{
                    //Now Collision will occur
                    while(true){  //while loop is for consecutive collisions
                        if(st.empty()){
                            st.push(ast);
                            break;
                        }
                        int ele = st.top();
                        st.pop();
                        if(ele>0){
                            //collision will happen
                            if(abs(ele) > abs(ast)){
                                st.push(ele);
                                break;
                            }
                            else if (abs(ele) == abs(ast)){  // Both ast ans top are distroyed
                                break;
                            }
                        }
                        else{  // ele < 0 ans ast < 0 so no collision
                            st.push(ele);
                            st.push(ast);
                            break;
                        }
                    }
                }
            }
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;--i){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
        
    }
};