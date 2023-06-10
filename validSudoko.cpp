bool check(int mat[9][9],int no,int row,int col){
    for(int i=0;i<9;i++){
        if(mat[i][col]==no)return false;
        if(mat[row][i]==no)return false;
        if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==no)return false;
    }
    return true;
}
bool solveSudoku(int board[9][9], int i, int j)
{
    if(i==9) return true;
    if(j==9) return solveSudoku(board, i+1, 0);
    if(board[i][j] != 0) return solveSudoku(board, i, j+1);

    for(int c=1; c<=9; c++)
    {
        if(check(board, c, i, j)==true)
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)==true) return true;
            //otherwise backtrack
            board[i][j] = 0;
        }
    }
        
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
   if(solveSudoku(matrix,0,0)==true){
       return true;
   }
    return  false;
}