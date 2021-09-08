#include "LeetCode/problem502.cpp"
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
    vector<vector<char>>cld{{'A','A'}};
    vector<int>arr{1,2,3};
    vector<int>arr1{0,1,2};
    vector<int>empty;
    Solution a;
    string version1 = "1.0";
    string version2 = "1.0.0";
//    cout<<a.smallestK(arr,4);
    cout << a.findMaximizedCapital(100000,100000,arr,arr1);
//    copy(empty.begin(),empty.end(),ostream_iterator<int>{cout, " "});
    return 1;
};