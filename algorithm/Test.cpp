#include "LeetCode/problem430.cpp"
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
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = nullptr;
    vector<ListNode*> ans;
//    copy(arr1.begin(),arr1.end(),ostream_iterator<string>{cout, "\n"});
    ans = a.splitListToParts(&node1,5);
    return 1;
};