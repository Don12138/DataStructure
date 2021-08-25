#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maxMultiply(vector<string> arr){
        int unit[arr.size()];//数组容量为变量时，不能初始化数组
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i){
            unit[i] = 0;
            for (int j = 0; j < arr[i].size(); ++j)
                unit[i]|=(1<<(arr[i][j]-'a'));
        }
        for (int i = 0; i < arr.size()-1; ++i)
            for (int j = i; j < arr.size(); ++j)
                if ((unit[i] & unit[j])==0){
                    int re = arr[i].size()*arr[j].size();
                    ans = max(ans,re);
                }
        return ans;
    }
};