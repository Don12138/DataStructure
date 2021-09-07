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
    int balancedStringSplit(string s) {
        int ans = 0, d = 0;
        for (char ch : s) {
            ch == 'L' ? ++d : --d;
            if (d == 0) {
                ++ans;
            }
        }
        return ans;
    }
};