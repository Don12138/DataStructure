#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int stack[2000];
    int compress(vector<char>& chars) {
        int count = 0,pointer = 0,slowPointer = 0;
        while (pointer < chars.size()){
            char curChar = chars[pointer];
            int start = pointer;
            while (pointer<chars.size() && chars[pointer] == curChar)
                pointer ++;
            int sub = pointer - start;
            chars[slowPointer++] = curChar;
            if(sub > 1){
                int top = -1;
                while (sub){
                    count++;
                    stack[++top] = sub%10;
                    sub/=10;
                }
                while (top != -1)
                    chars[slowPointer++] = stack[top--]+'0';
            }
            count++;
        }
        return count;
    }
};