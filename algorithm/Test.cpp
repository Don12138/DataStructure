#include "LeetCode/problem524.cpp"
//#include "Offer/problem12.cpp"
//#include "Others/Random_Quick_Sort.cpp"
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define lowbit(x) (x&-x)
int main(){
    vector<vector<int>>cld{{1,1}};
    vector<string>arr{"ab","ba","a","b"};
    vector<int>arr1{5,1,5,1,3,5,12,5,1,9,2,7,1,2,4,6,1,5,7,9};
    vector<string>empty;
    Solution a;
    string version1 = "1.0";
    string version2 = "1.0.0";
//    cout<<a.smallestK(arr,4);
    cout<<a.findLongestWord("bab",arr);
//    copy(empty.begin(),empty.end(),ostream_iterator<string>{cout, "\n"});
    return 1;
};