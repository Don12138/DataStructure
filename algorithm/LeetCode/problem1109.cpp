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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>difference(n+1,0);
        vector<int>ans;
        for (auto& booking : bookings) {
            difference[booking[0]-1]+=booking[2];
            difference[booking[1]]-=booking[2];
        }
        partial_sum(difference.begin(),difference.end()-1,back_inserter(ans));
        return ans;
    }
};