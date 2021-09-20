#include "LeetCode/problem673.cpp"
//#include "Offer/problem12.cpp"
//#include "Others/Random_Quick_Sort.cpp"
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<int>arr1{2,2,2,2,2};
    Solution a;
//    copy(arr1.begin(),arr1.end(),ostream_iterator<string>{cout, "\n"});
    cout<<a.findNumberOfLIS(arr1);
    return 1;
};