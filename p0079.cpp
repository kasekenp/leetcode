// Runtime: 148 ms, faster than 55.21% of C++ online submissions for Word Search.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Word Search.

#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string &word, vector<bool> &visited, int i, int j, int idx)
    {
        if (visited[i][j])
        {
            return false;
        }
        if (idx == word.size() - 1)
        {
            return *word.rbegin() == board[i][j];
        }
        else if (word[idx] != board[i][j])
        {
            return false;
        }
        visited[i][j] = true;
        bool res = false;
        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {-1, 0, 0, 1};
        for (int k = 0; k < 4; k++)
        {
            if (i + dy[i] < 0 || i + dy[i] >= board.size() || j + dx[i] < 0 || j + dx[i] >= board[0].size())
            {
                continue;
            }
            res |= dfs(board, word, visited, i + dy[i], j + dx[i], idx + 1);
        }
        visited[i][j] = false;
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < (int)board.size(); i++)
        {
            for (int j = 0; j < (int)board[0].size(); j++)
            {
                auto res = dfs(board, word, visited, i, j, 0);
                if (res)
                {
                    return true;
                }
            }
        }
        return false;
    }
};