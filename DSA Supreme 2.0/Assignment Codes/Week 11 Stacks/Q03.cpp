//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

//Celebrity problem

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()!=1){
            int p1=st.top();
            st.pop();
            int p2=st.top();
            st.pop();
            if(M[p1][p2]==1){
                st.push(p2);
            }
            else{
                st.push(p1);
            }
            
        }
        int celeb=st.top();
        //now the last person might be celebrity
        for(int i=0;i<n;i++){
            if(celeb!=i && (M[celeb][i]!=0 || M[i][celeb]!=1)){
                return -1;
            }
        }
        return celeb;
    }
};