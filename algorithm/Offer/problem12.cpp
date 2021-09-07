#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i ,int j,int index){
        if (index == word.size())return true;
        if (i>0&&board[i-1][j] == word[index]){
            board[i-1][j]*=-1;
            if (dfs(board,word,i-1,j,++index))return true;
            board[i-1][j]*=-1;
            index --;
        }
        if (j>0&&board[i][j-1] == word[index]){
            board[i][j-1]*=-1;
            if (dfs(board,word,i,j-1,++index))return true;
            board[i][j-1]*=-1;
            index --;
        }
        if (i<board.size()-1&&board[i+1][j] == word[index]){
            board[i+1][j]*=-1;
            if (dfs(board,word,i+1,j,++index))return true;
            board[i+1][j]*=-1;
            index --;
        }
        if (j<board[i].size()-1&&board[i][j+1] == word[index]){
            board[i][j+1]*=-1;
            if (dfs(board,word,i,j+1,++index))return true;
            board[i][j+1]*=-1;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size()==0||board[0].size()*board.size()<word.size())return false;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == word[0]){
                    int index = 1;
                    board[i][j]*=-1;
                    if (dfs(board,word,i,j,index))return true;
                    board[i][j]*=-1;
                }
        return false;
    }
};