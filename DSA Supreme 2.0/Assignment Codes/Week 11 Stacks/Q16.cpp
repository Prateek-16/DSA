//https://leetcode.com/problems/design-browser-history/description/

// Design Browser History  LC - 1472.

class BrowserHistory {
    stack<string>browserStack,forwardStack;
public:
    BrowserHistory(string homepage) {
        browserStack.push(homepage);
    }
    
    void visit(string url) {
        browserStack.push(url);
        //clearing the forward stack
        while(!forwardStack.empty()){
            forwardStack.pop();
        }
    }
    
    string back(int steps) {
        while(steps--){
            if(browserStack.size() > 1){
                forwardStack.push(browserStack.top());
                browserStack.pop();
            }
        }
        
        return browserStack.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(!forwardStack.empty()){
                browserStack.push(forwardStack.top());
                forwardStack.pop();
            }
        }
        
        return browserStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */