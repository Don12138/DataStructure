#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        for (int i = 0 ; i < size ; i += 2*k){
            reverse(s.begin()+i,s.begin()+min(i+k,size));
        }
        return s;
    }
};