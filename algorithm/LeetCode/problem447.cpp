#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <map>
using namespace std;
class Solution {
public:
    vector<map<int,int>>distance;
    int numberOfBoomerangs(vector<vector<int>>& points) {
        for(int i = 0 ; i < points.size() ; i ++){
            map<int,int>cur;
            for(int j = 0 ; j < points.size() ; j ++){
                if (i==j)continue;
                cur[calculateDistance(points[i][0],points[i][1],points[j][0],points[j][1])]++;
            }
            distance.insert(distance.end(),cur);
        }
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            for(auto it : distance[i]){
                ans+=C(it.second);
            }
        }
        return ans;
    }
    int calculateDistance(int x1,int y1,int x2,int y2){
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
    int C(int m){
        return (m*(m-1));
    }
};