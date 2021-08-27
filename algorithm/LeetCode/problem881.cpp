#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int light = 0,heavy = people.size()-1;
        while (light<=heavy){
            int sum = people[light]+people[heavy];
            if (sum<=limit){
                heavy--;
                light++;
            } else{
                heavy --;
            }
            ans++;
        }
        return ans;
    }
};