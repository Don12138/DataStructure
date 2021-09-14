#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <map>
using namespace std;
class Solution {
public:
    static bool cmp(string a,string b){
        if (a.size()!=b.size())
            return a.size()>b.size();
        else{
            for (int i = 0; i < a.size(); ++i) {
                if (a[i]!=b[i])return a[i]<b[i];
            }
            return true;
        }
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        for (int i = 0; i < dictionary.size(); ++i) {
            int index = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (dictionary[i][index] == s[j]){
                    index++;
                }
            }
            if (index == dictionary[i].size())return dictionary[i];
        }
        return "";
    }
};