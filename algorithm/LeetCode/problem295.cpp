#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
class MedianFinder {
public:
    priority_queue<int, vector<int> , less<int>> lessThanMid;
    priority_queue<int, vector<int> , greater<int>> greaterThanMid;
    MedianFinder() {}

    void addNum(int num) {
        if (lessThanMid.size() == 0||num<=lessThanMid.top()){
            lessThanMid.push(num);
            if (lessThanMid.size() == greaterThanMid.size() + 2){
                greaterThanMid.push(lessThanMid.top());
                lessThanMid.pop();
            }
        } else{
            greaterThanMid.push(num);
            if (lessThanMid.size() + 2 == greaterThanMid.size()){
                lessThanMid.push(greaterThanMid.top());
                greaterThanMid.pop();
            }
        }
    }

    double findMedian() {
        if (lessThanMid.size()>greaterThanMid.size())return lessThanMid.top();
        else if (lessThanMid.size()<greaterThanMid.size())return greaterThanMid.top();
        else return (greaterThanMid.top()+lessThanMid.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */