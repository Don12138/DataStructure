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
    int compareVersion(string version1, string version2) {
        int version1_num[250] = {0};
        int version2_num[250] = {0};
        int fast,slow,count1 = 0,count2 = 0;
        for (fast = 0,slow = 0; fast <= version1.size(); ++fast) {
            if (fast == version1.size() || version1[fast] == '.'){
                version1_num[count1++] = stoi(version1.substr(slow,fast));
                slow = fast+1;
            }
        }
        for (fast = 0,slow = 0; fast <= version2.size(); ++fast) {
            if (fast == version2.size() || version2[fast] == '.'){
                version2_num[count2++] = stoi(version2.substr(slow,fast));
                slow = fast+1;
            }
        }
        for (int i = 0; i < max(count1,count2); ++i) {
            cout<<version1_num[i]<<"   "<<version2_num[i]<<endl;
//            if (version1_num[i] > version2_num[i])
//                return 1;
//            else if (version1_num[i] < version2_num[i])
//                return -1;
        }
        return 0;
    }
};