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
    int calculate(int i){
        if (!i)return 0;
        int index = i&(-i);
        i=i>>index;
        if (index!=1) return calculate(i);
        else{
            index = i&-i;
            if (index==1)return 1;
            else return calculate(i>>index);
        }
    }
    int findIntegers(int n) {
        int ans = 0;
        calculate(32);
//        for (int i = 0; i <= n; ++i){
//            ans+=!calculate(i);
//        }
        return ans;
    }
};