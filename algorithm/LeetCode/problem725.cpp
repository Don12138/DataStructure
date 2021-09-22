#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *p = head,*q=head,*r;
        int len = 0;
        while (p){
            p = p->next;
            len++;
        }
        int basic = len/k;
        int sub = len%k;
        vector<ListNode*>ans;
        if (basic == 0){
            for (int i = 0; i < k; ++i) {
                if (sub-->0){
                    ans.push_back(q);
                    r = q->next;
                    q->next = nullptr;
                    q = r;
                } else
                    ans.push_back(nullptr);
            }
        }
        while (q){
            ans.push_back(q);
            if (sub-->0){
                q = q->next;
            }
            for (int i = 0; i < basic-1; ++i) {
                q = q->next;
            }
            r = q->next;
            q->next = nullptr;
            q = r;
        }
        return ans;
    }
};