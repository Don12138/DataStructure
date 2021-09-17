#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValidRow(vector<char>boardRow){
        int unit[9]={0};
        for (int i = 0; i < 9; ++i) {
            if (boardRow[i] == '.')continue;
            if (++unit[boardRow[i]-'1']>1)
                return false;
        }
        return true;
    }
    bool isValidColumn(vector<vector<char>>board,int row){
        int unit[9]={0};
        for (int i = 0; i < 9; ++i) {
            if (board[i][row] == '.')continue;
            if (++unit[board[i][row]-'1']>1)
                return false;
        }
        return true;
    }
    bool isValidLittleSudoku(vector<vector<char>> board,int rowStart,int columnStart){
        int unit[9]={0};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i+rowStart][j+columnStart] == '.')continue;
                if (++unit[board[i+rowStart][j+columnStart]-'1']>1)
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (!isValidRow(board[i]))return false;
            if (!isValidColumn(board,i))return false;
            if (!isValidLittleSudoku(board,i/3*3,i%3*3))return false;
        }
        return true;
    }
};