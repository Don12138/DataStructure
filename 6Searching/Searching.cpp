#include <cstdio>
#include <cstdlib>
#define m 4
#define ElemType int
typedef struct BTNode{
    struct BTNode *Parent;
    int keyNum;
    ElemType key[m];
    struct BTNode *p[m+1];
}BTNode,*BTree;
void BinarySearching(int *a,int length,int key){
    int low = 1,high = length;
    while (low<=high){
        int mid = (low+high)/2;
        int num = *(a+mid);
        printf("%d\t",num);
        if (num == key){
            return;
        }
        if (num > key)
            high = mid-1;
        else
            low = mid+1;
    }
    printf("%s\t","未找到");
}
void Print(BTNode *btNode){
    if (!btNode) return;
    for (int i = 1; i <= btNode->keyNum; ++i) {
        Print(btNode->p[i]);
        printf("%d\t" , btNode->key[i]);
    }
    Print(btNode->p[btNode->keyNum+1]);
}
void BTNodeSearch(BTNode *btNode,ElemType key){
    bool isFound = false;
    BTNode *searchNode = btNode;
    while (searchNode && !isFound){
        for (int i = 1; i <= searchNode->keyNum; ++i) {
            if (searchNode->key[i] > key){
                printf("%d\t", i);
                searchNode = searchNode->p[i];
                break;
            } else if (searchNode->key[i] == key){
                printf("%d\t", i);
                printf("%s\t","查找成功");
                isFound = true;
                break;
            } else if (searchNode->key[i] < key && i == searchNode->keyNum){
                printf("%d\t", i+1);
                searchNode = searchNode->p[i+1];
                break;
            }
        }
    }
    if (!isFound){
        printf("%s\t","未找到");
    }
}
void BTNodeInsert(BTNode *btNode,ElemType key){
    //见md
}
void BTNodeDelete(BTNode *btNode,ElemType key){
    //见md
}
BTNode* InitBTNode(){
    BTNode *btNode1 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode2 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode3 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode4 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode5 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode6 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode7 = (BTNode*)malloc(sizeof (BTNode));
    BTNode *btNode8 = (BTNode*)malloc(sizeof (BTNode));
    btNode1->keyNum = 1;
    btNode1->key[1] = 35;
    btNode1->Parent = NULL;
    btNode1->p[1] = btNode2;
    btNode1->p[2] = btNode3;

    btNode2->keyNum = 1;
    btNode2->key[1] = 18;
    btNode2->Parent = btNode1;
    btNode2->p[1] = btNode4;
    btNode2->p[2] = btNode5;

    btNode3->keyNum = 2;
    btNode3->key[1] = 43;
    btNode3->key[2] = 78;
    btNode3->Parent = btNode1;
    btNode3->p[1] = btNode6;
    btNode3->p[2] = btNode7;
    btNode3->p[3] = btNode8;

    btNode4->keyNum = 1;
    btNode4->key[1] = 11;
    btNode4->Parent = btNode2;
    btNode4->p[1] = NULL;
    btNode4->p[2] = NULL;

    btNode5->keyNum = 1;
    btNode5->key[1] = 27;
    btNode5->Parent = btNode2;
    btNode5->p[1] = NULL;
    btNode5->p[2] = NULL;

    btNode6->keyNum = 1;
    btNode6->key[1] = 39;
    btNode6->Parent = btNode2;
    btNode6->p[1] = NULL;
    btNode6->p[2] = NULL;

    btNode7->keyNum = 3;
    btNode7->key[1] = 47;
    btNode7->key[2] = 53;
    btNode7->key[3] = 64;
    btNode7->Parent = btNode2;
    btNode7->p[1] = NULL;
    btNode7->p[2] = NULL;
    btNode7->p[3] = NULL;
    btNode7->p[4] = NULL;

    btNode8->keyNum = 1;
    btNode8->key[1] = 99;
    btNode8->Parent = btNode2;
    btNode8->p[1] = NULL;
    btNode8->p[2] = NULL;

    return btNode1;
}
int main(){
//    int a[] = {0,1,3,5,7,9,12,14,16,17,19,20,30,34,36,38,39,40,45,47,49,52,53,54,60,64,69,81,83,85,88,93,95,99,100};
//    BinarySearching(a,34,2);
    BTNode *btNode = InitBTNode();
    Print(btNode);
//    BTNodeSearch(btNode,28);
    return 0;
}