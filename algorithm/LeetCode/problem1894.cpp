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
    int chalkReplacer(vector<int>& chalk, int k) {
        int index = 0,n=chalk.size();
        int maxNum = accumulate(chalk.begin(),chalk.end(),0);
        k%=maxNum;
        if (k==0)return 0;
        while (index<n&&k>0){
            if (chalk[index]<=k){
                k-=chalk[index];
                index++;
            } else return index;
        }
        return index;
    }
};