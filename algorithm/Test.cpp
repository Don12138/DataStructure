#include "LeetCode/problem68.cpp"
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
    vector<string>arr{"What","must","be","acknowledgment","shall","be"};
    vector<int>arr1{0,1,2};
    vector<string>empty;
    Solution a;
    string version1 = "1.0";
    string version2 = "1.0.0";
//    cout<<a.smallestK(arr,4);
    empty = a.fullJustify(arr,16);
    copy(empty.begin(),empty.end(),ostream_iterator<string>{cout, "\n"});
    return 1;
};