#include <iostream>
#include <vector>
#include <string>

int exist(vector<vector<char> > &board, string word)
{
    int row = board.size();
    if (row == 0) return 0;
    int col = board[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
	    if (board[i][j] == word[0] && dfs(i, j, word, 0, board))
		    return 1;
    }
    return 0;
}

int dfs(int row, int col, string &word, int index, vector<vector<char> > &board)
{
    if (index == word.size() - 1) return 1;
    char ctmp = board[row][col];
    board[row][col] = '#'; //has visited

    //up
    if (row - 1 >= 0 && board[row - 1][col] == word[index + 1])
	    if (dfs(row - 1, col, word, index + 1, board))
		    return 1;
    //down
    if (row + 1 < board.size()  && board[row + 1][col] == word[index + 1])
	    if (dfs(row + 1, col, word, index + 1, board))
		    return 1;
    //left
    if (col - 1 >= 0 && board[row][col - 1] == word[index + 1])
	    if (dfs(row, col - 1, word, index + 1, board))
		    return 1;
    //right
    if (col + 1 < board[0].size() && board[row][col + 1] == word[index + 1])
	    if (dfs(row, col + 1, word, index + 1, board))
		    return 1;
    
    board[row][col] = ctmp;
    return 0;
}
