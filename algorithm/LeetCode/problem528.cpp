#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
class Solution {
private:
    uniform_int_distribution<int> dis;
    mt19937 rng;
    vector<int> prefix;



public:
    Solution(vector<int>& w): rng(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(prefix));
    }

    int pickIndex() {
        int x = dis(rng);
        return lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
    }
};
