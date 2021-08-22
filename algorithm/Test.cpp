#include "LeetCode/problem789.cpp"
//#include "NewCode/NC119.cpp"
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    Solution a;
    vector<char> chars {'a','b','b','b','b','b','b','b','b','b','b'};
    cout<<a.compress(chars);
    for (int i = 0; i < chars.size(); ++i) {
        printf("%c\t",chars[i]);
    }
    return 1;
};