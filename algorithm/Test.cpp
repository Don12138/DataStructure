#include "LeetCode/problem17.14.cpp"
//#include "Offer/problem5.cpp"
//#include "Others/Mota.cpp"
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<int>arr{1,3,5,7,2,4,6,8};
    vector<int>empty;
    Solution a;
    string version1 = "1.0";
    string version2 = "1.0.0";
//    cout<<a.smallestK(arr,4);
    empty = a.smallestK(arr,0);
    copy(empty.begin(),empty.end(),ostream_iterator<int>{cout, " "});
    return 1;
};