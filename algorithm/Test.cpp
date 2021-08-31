#include "LeetCode/problem1109.cpp"
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
    vector<vector<int>>arr{{1,2,10},{2,3,20},{2,5,25}};
    vector<int>empty;
    Solution a;
    empty = a.corpFlightBookings(arr,5);
    copy(empty.begin(),empty.end(),ostream_iterator<int>{cout, " "});
    return 1;
};