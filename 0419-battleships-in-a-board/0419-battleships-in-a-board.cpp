class Solution {
public:
    void dfs(int &curr, int i, int j, vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='.'){
            return;
        }
        board[i][j]='.';

        dfs(curr, i-1, j, board);
        dfs(curr, i+1, j, board);
        dfs(curr, i, j-1, board);
        dfs(curr, i, j+1, board);

    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
      
        int curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(curr, i, j, board);
                    curr++;
                    
                } 
            }
        }
        return curr;
    }
};