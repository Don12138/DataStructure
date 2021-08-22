#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int targetDistance = distance(0,0,target[0],target[1]);
        for (int i = 0; i < ghosts.size(); ++i)
            if (distance(target[0],target[1],ghosts[i][0],ghosts[i][1])<=targetDistance)
                return false;
        return true;
    }
    int distance(int x1,int y1,int x2,int y2){
        return (x1-x2)*((x1-x2)>0?1:-1)+(y1-y2)*((y1-y2)>0?1:-1);
    }
};