bool isQueenSafe(vector<pair<int,int>> &queensPos, int row, int col){
    // Time Complexity: O(N)
    for(auto pos : queensPos){
        // same row
        if(pos.first == row) return false;
        // same column
        if(pos.second == col) return false;
        // same diagonal
        if(abs(row - pos.first) == abs(col - pos.second)) return false;
    }
    return true;
}

void addSolution(vector<vector<int>> &ans, vector<pair<int,int>> &queensPos, int n){
    vector<vector<int>> board(n, vector<int>(n, 0));
    for(auto pos : queensPos){
        board[pos.first][pos.second] = 1;
    }
    vector<int> flat;
    for(auto r : board){
        flat.insert(flat.end(), r.begin(), r.end());
    }
    ans.push_back(flat);
}

void backtracking(vector<vector<int>> &ans, vector<pair<int,int>> &queensPos, int n, int col){
    // Base Case
    if(col == n){
        addSolution(ans, queensPos, n);
        return;
    }
    // check all possibilities
    for(int i = 0; i < n; i++){
        if(isQueenSafe(queensPos, i, col)){
            queensPos.push_back({i, col});
            backtracking(ans, queensPos, n, col + 1);
            queensPos.pop_back();
        }
    }
}


vector<vector<int>> solveNQueens(int n) {
    // Approach: Back tracking
    // Time Complexity: O(4^N)
    // Space Complexity: O(N*N)
    vector<vector<int>> ans;
    vector<pair<int,int>> queensPos;
    backtracking(ans, queensPos, n, 0);
    return ans;
}