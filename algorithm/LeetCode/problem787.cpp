#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //dp[i][k]表示从src至多经过k站到达i的最少费用
        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        //初始化 src 到 src的费用为0
        for (int k = 0; k <= K + 1; ++k){
            dp[src][k] = 0;
        }
        //开始动态规划
        for (int k = 1; k <= K + 1; ++k){
            for (auto &flight : flights){
                //如果从src至多经过k - 1站可达flight[0]
                if (dp[flight[0]][k - 1] != INT_MAX){
                    //更新从src至多经过k站到达flight[1]
                    dp[flight[1]][k] = min(dp[flight[1]][k], dp[flight[0]][k - 1] + flight[2]);
                }
            }
        }
        return dp[dst][K+1] == INT_MAX ? -1 : dp[dst][K+1];
    }
};