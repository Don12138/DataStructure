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
static int cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int, vector<int> , less<int>>maxProfit;
        int n = profits.size();
        pair<int,int>capital_profits[n];
        for (int i = 0; i < n; ++i) {
            capital_profits[i].first = capital[i];
            capital_profits[i].second = profits[i];
        }
        sort(capital_profits,capital_profits+n,cmp);
        int start = 0;
        while (k>0 && start<n){
            if (capital_profits[start].first>w) {
                if (!maxProfit.empty()){
                    w += maxProfit.top();
                    maxProfit.pop();
                    k--;
                    continue;
                } else return w;
            }
            for (; start < n && capital_profits[start].first<=w; ++start)
                maxProfit.push(capital_profits[start].second);
            if (start<n){
                w += maxProfit.top();
                maxProfit.pop();
                k--;
            }
        }
        if (k>0)
            while (k>0&&!maxProfit.empty()){
                w += maxProfit.top();
                maxProfit.pop();
                k--;
            }
        return w;
    }
};