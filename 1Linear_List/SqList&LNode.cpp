#include <cstdio>
#include <cstdlib>

#define ElemType int
#define MAX_SIZE 50
typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SqList;

typedef struct LNode{
    ElemType data;
    struct LNode *link;
} *LinkList;

void LNode_Print(int has_head,LinkList head){
    LinkList q;
    if (has_head==1)
        q = head->link;
    else q = head;
    while (q){
        printf("%d\n",q->data);
        q = q->link;
    }
}

//P43 22
//int length(LinkList L){
//    int length = 0;
//    while (L){
//        length++;
//        L = L->next;
//    }
//    return length;
//}
//LinkList find_suffix(LinkList str1,LinkList str2){
//    int length1 = length(str1);
//    int length2 = length(str2);
//    int diff;
//    LinkList  q,p;
//    if (length1>length2){
//        p = str1,q=str2;
//        diff = length1-length2;
//    } else{
//        p = str2,q=str1;
//        diff = length2-length1;
//    }
//    while (diff --){
//        p = p->next;
//    }
//    while (p){
//        if (q==p)return q;
//        q = q->next;
//        p = p->next;
//    }
//    return NULL;
//}

//P43 23
void Delete_abs(LinkList &head,int n){
    int *arr;
    arr = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n+1; ++i)
        *(arr+i) = 0;
    LinkList p = head->link,pre = head;
    while (p){
        int cur = p->data;
        if (cur<0)cur=-cur;
        if (*(arr+cur)==1){
            pre->link = p->link;
            free(p);
            p = pre->link;
        } else{
            *(arr+cur) = 1;
            p = p->link;
            pre = pre->link;
        }
    }
}

int main() {
    LinkList a20 = (LinkList)malloc(sizeof (LNode));
    a20->link = NULL; a20->data = 30;
    LinkList a19 = (LinkList)malloc(sizeof (LNode));
    a19->link = a20; a19->data = 18;
    LinkList a18 = (LinkList)malloc(sizeof (LNode));
    a18->link = a19; a18->data = -18;
    LinkList a17 = (LinkList)malloc(sizeof (LNode));
    a17->link = a18; a17->data = -23;
    LinkList a16 = (LinkList)malloc(sizeof (LNode));
    a16->link = a17; a16->data = -25;
    LinkList a15 = (LinkList)malloc(sizeof (LNode));
    a15->link = a16; a15->data = 21;
    LinkList a14 = (LinkList)malloc(sizeof (LNode));
    a14->link = a15; a14->data = 19;
    LinkList a13 = (LinkList)malloc(sizeof (LNode));
    a13->link = a14; a13->data = -5;
    LinkList a12 = (LinkList)malloc(sizeof (LNode));
    a12->link = a13; a12->data = -20;
    LinkList a11 = (LinkList)malloc(sizeof (LNode));
    a11->link = a12; a11->data = 20;
    LinkList a10 = (LinkList)malloc(sizeof (LNode));
    a10->link = a11; a10->data = 0;
    LinkList a9 = (LinkList)malloc(sizeof (LNode));
    a9->link = a10; a9->data = 27;
    LinkList a8 = (LinkList)malloc(sizeof (LNode));
    a8->link = a9; a8->data = -3;
    LinkList a7 = (LinkList)malloc(sizeof (LNode));
    a7->link = a8; a7->data = -30;
    LinkList a6 = (LinkList)malloc(sizeof (LNode));
    a6->link = a7; a6->data = 3;
    LinkList a5 = (LinkList)malloc(sizeof (LNode));
    a5->link = a6; a5->data = 2;
    LinkList a4 = (LinkList)malloc(sizeof (LNode));
    a4->link = a5; a4->data = -24;
    LinkList a3 = (LinkList)malloc(sizeof (LNode));
    a3->link = a4; a3->data = 24;
    LinkList a2 = (LinkList)malloc(sizeof (LNode));
    a2->link = a3; a2->data = 8;
    LinkList a1 = (LinkList)malloc(sizeof (LNode));
    a1->link = a2; a1->data = 5;
    LinkList a0 = (LinkList)malloc(sizeof (LNode));
    a0->link = a1; a0->data = -2;
    LinkList head = (LinkList)malloc(sizeof (LNode));
    head->link = a0;
    LNode_Print(1,head);
    Delete_abs(head,30);
    printf("\n");
    LNode_Print(1,head);
}