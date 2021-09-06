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
    int search(vector<int>& nums, int target) {
        int pos = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        return nums[pos] == target ? pos : -1;
    }
};