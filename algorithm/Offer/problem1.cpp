#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int Divide(int dividend, int divisor){
        if (dividend == 0x80000000 && divisor == -1)return 0x7fffffff;
        bool negative = false;
        if (dividend > 0){
            negative = !negative;
            dividend = -dividend;
        }
        if (divisor > 0){
            negative = !negative;
            divisor = -divisor;
        }
        int key = DivideCore(dividend,divisor);
        return negative?-key:key;

    }
    int DivideCore(int dividend,int divisor){
        int key = 0;
        while (dividend <= divisor){
            int value = divisor;
            int cur = 1;
            while (value >= 0xc0000000 && dividend <= value + value){
                value += value;
                cur += cur;
            }
            key += cur;
            dividend -= value;
        }
        return key;
    }
};