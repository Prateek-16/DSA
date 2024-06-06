//https://www.geeksforgeeks.org/problems/count-the-reversals0401/1

//Count the reversal

int countRev (string s)
{
    // your code here
    
    stack<char>st;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(!st.empty() && s[i]=='}'&& st.top()=='{'){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    if(st.size() & 1){
        return -1;
    }
    while(!st.empty()){
        char ch=st.top();
        st.pop();
        if((ch=='{' && st.top()=='{') || (ch=='}' && st.top()=='}')){
            count++;
        }
        else{
            count+=2;
        }
        st.pop();
    }
    return count;
    
}