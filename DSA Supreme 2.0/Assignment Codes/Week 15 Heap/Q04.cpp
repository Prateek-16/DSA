//https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/


//Get Biggest Three Rhombus Sums in a Grid


class Solution {
public:
    bool ispossible(vector<vector<int>>& grid, vector<pair<int, int>>& v) {
        bool ispos = true;
        int n = grid.size();
        int m = grid[0].size();
        for (auto it : v) {
            int cx = it.first;
            int cy = it.second;
            if (cx >= n || cx < 0) {
                ispos = false;
            }
            if (cy >= m || cy < 0) {
                ispos = false;
            }
        }
        return ispos;
    }
    bool getCorner(int cx, int cy, vector<vector<int>>& grid,
                   vector<pair<int, int>>& v, int delta) {
        pair<int, int> A(cx - delta, cy);
        pair<int, int> B(cx, cy + delta);
        pair<int, int> C(cx + delta, cy);
        pair<int, int> D(cx, cy - delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        if (ispossible(grid,v)) {
            return true;
        } else {
            return false;
        }
    }
    void nextPossibleRh(priority_queue<int>& q, int cx, int cy,
                        vector<vector<int>>& grid) {
        vector<pair<int, int>> v(4);
        int delta = 1;
        while (getCorner(cx, cy, grid, v, delta)) {
            int csum = 0;
            pair<int, int> A = v[0];
            pair<int, int> B = v[1];
            pair<int, int> C = v[2];
            pair<int, int> D = v[3];

            csum = grid[A.first][A.second] + grid[B.first][B.second] +
                   grid[C.first][C.second] + grid[D.first][D.second];

            // caculating the sum of vertice squares

            // for(int i = 1;i<(B.first - A.first);i++){
            //     csum+=grid[A.first+i][A.second+i];
            // }
            // for(int i = 1;i<(C.first - B.first);i++){
            //     csum+=grid[B.first+i][B.second-i];
            // }
            // for(int i = 1;i<(C.first - D.first);i++){
            //     csum+=grid[C.first-i][C.second-i];
            // }for(int i = 1;i<(D.first - A.first);i++){
            //     csum+=grid[D.first-i][D.second+i];
            // }

            // A to B
            int x_cor = A.first + 1;
            int y_cor = A.second + 1;
            int k = B.first - A.first;
            while (k-1) {
                csum += grid[x_cor][y_cor];
                x_cor++;
                y_cor++;
                k--;
                // if (x_cor == B.first || y_cor == B.second) {
                //     break;
                // }
            }
            // B to C
            x_cor = B.first + 1;
            y_cor = B.second - 1;
            k = C.first - B.first;
            while (k-1) {
                csum += grid[x_cor][y_cor];
                x_cor++;
                y_cor--;
                k--;
                // if (x_cor == C.first || y_cor == C.second) {
                //     break;
                // }
            }
            // C to D
            x_cor = C.first - 1;
            y_cor = C.second - 1;
            k = C.first - D.first;
            while (k-1) {
                csum += grid[x_cor][y_cor];
                x_cor--;
                y_cor--;
                k--;
                // if (x_cor == D.first || y_cor == D.second) {
                //     break;
                // }
            }
            // D to A
            x_cor = D.first - 1;
            y_cor = D.second + 1;
            k = D.first - A.first;
            while (k-1) {
                csum += grid[x_cor][y_cor];
                x_cor--;
                y_cor++;
                k--;
                // if (x_cor == A.first || y_cor == A.second) {
                //     break;
                // }
            }
            q.push(csum);
            delta++;
        }
    }
    bool canPush(int top, vector<int>& ans) {
        for (auto it : ans) {
            if (it == top) {
                return false;
            }
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q.push(grid[i][j]);
                nextPossibleRh(q, i, j, grid);
            }
        }
        while (!q.empty() && ans.size() < 3) {
            int top = q.top();
            q.pop();
            if (canPush(top, ans)) {
                ans.push_back(top);
            }
        }
        return ans;
    }
};