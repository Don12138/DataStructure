#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution{
public:
    string binaryAdd(string a,string b){
        int lengthA = a.length(),lengthB = b.size();
        int sub = 0;
        string key = "";
        while (lengthA||lengthB){
            int binaryA = lengthA>0?a[--lengthA]-'0':0;
            int binaryB = lengthB>0?b[--lengthB]-'0':0;
            int cur = binaryA+binaryB+sub;
            sub = cur >= 2 ? 1 : 0;
            key.push_back(cur >= 2 ? cur - 2 + '0' : cur + '0');
        }
        if (sub == 1)
            key.push_back('1');
        reverse(key.begin(),key.end());
        return key;
    }
};