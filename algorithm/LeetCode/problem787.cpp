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
        //dp[i][k]��ʾ��src���ྭ��kվ����i�����ٷ���
        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        //��ʼ�� src �� src�ķ���Ϊ0
        for (int k = 0; k <= K + 1; ++k){
            dp[src][k] = 0;
        }
        //��ʼ��̬�滮
        for (int k = 1; k <= K + 1; ++k){
            for (auto &flight : flights){
                //�����src���ྭ��k - 1վ�ɴ�flight[0]
                if (dp[flight[0]][k - 1] != INT_MAX){
                    //���´�src���ྭ��kվ����flight[1]
                    dp[flight[1]][k] = min(dp[flight[1]][k], dp[flight[0]][k - 1] + flight[2]);
                }
            }
        }
        return dp[dst][K+1] == INT_MAX ? -1 : dp[dst][K+1];
    }
};