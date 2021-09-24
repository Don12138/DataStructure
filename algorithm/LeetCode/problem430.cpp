// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)return head;
        int top = -1;
        Node *p = head,*q,*stack[1000];
        while (p->next||top!=-1||p->child){
            if (p->child){
                stack[++top] = p->next;
                p->next = p->child;
                p->child->prev = p;
                q = p;
                p = p->child;
                q->child = nullptr;
            }else if (!p->next){
                if (top!=-1){
                    if (!stack[top]){
                        top--;
                        continue;
                    }
                    q = stack[top--];
                    p->next = q;
                    q->prev = p;
                    p = q;
                }
            } else{
                p = p->next;
            }
        }
        return head;
    }
};