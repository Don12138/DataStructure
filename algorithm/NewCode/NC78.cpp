#include<algorithm>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* head = pHead,*q = NULL,*p = pHead;
        while (p){
            head = p;
            p = p ->next;
            head->next = q;
            q = head;
        }
        return head;
    }
};