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
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int>ans(k,0);
        if (k == 0)return ans;
        priority_queue<int, vector<int> , less<int>> heap;
        for (int i = 0; i < k; ++i)
            heap.push(arr[i]);
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < heap.top()){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            ans[i] = heap.top();
            heap.pop();
        }
        return ans;
    }
};