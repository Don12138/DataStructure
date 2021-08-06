#include <cstdio>
#include <cstdlib>
#define ElemType int
#define MAX_NUM 100
using namespace std;

//定义树的链式存储结构
typedef struct BiTNode {
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    ElemType data;
} BiTNode, *BiTree;

void initTree(BiTNode &T) {
    T = *(BiTNode *) malloc(sizeof(BiTNode));
    T.lchild = NULL;
    T.rchild = NULL;
}

void visit(BiTree node) {
    printf("%d\t", node->data);
}

//先序遍历递归版本
void preOrderTraverse(BiTree tree) {
    if (tree){
        visit(tree);
        preOrderTraverse(tree->lchild);
        preOrderTraverse(tree->rchild);
    }
}

//先序遍历非递归版本
void preOrderTraverseNonrecursion(BiTree tree) {
    BiTree stack[MAX_NUM];
    int top = -1;
    visit(tree);
    stack[++top] = tree;
    BiTree p = tree->lchild;
    while (p||top!=-1){
        if (p){
            visit(p);
            stack[++top] = p;
            p = p->lchild;
        } else{
            p = stack[top--];
            p = p->rchild;
        }
    }
}

//中序遍历递归版本
void inOrderTraverse(BiTree tree) {
    if (tree) {
        inOrderTraverse(tree->lchild);
        visit(tree);
        inOrderTraverse(tree->rchild);
    }
}

//中序遍历非递归版本
void inOrderTraverseNonrecursion(BiTree tree) {
    BiTree stack[MAX_NUM];
    int top = -1;
    stack[++top] = tree;
    BiTree p = tree->lchild;
    while (p||top!=-1){
        if (p){
            stack[++top] = p;
            p = p->lchild;
        } else{
            p = stack[top];
            visit(p);
            top--;
            p = p->rchild;
        }
    }
}

//后序遍历递归算法
void postOrderTraverse(BiTree tree) {
    if (tree) {
        postOrderTraverse(tree->lchild);
        postOrderTraverse(tree->rchild);
        visit(tree);
    }
}

//后序遍历的非递归算法
void postOrderTraverseNonrecursion(BiTree tree) {
    BiTree stack[MAX_NUM];
    int top = -1;
    stack[++top] = tree;
    BiTree p = tree->lchild;
    BiTree q = NULL;
    while (p||top!=-1){
        if (p){
            stack[++top] = p;
            p = p->lchild;
        } else{
            p = stack[top];
            if (p->rchild&&p->rchild!=q){
                p = p->rchild;
                stack[++top] = p;
                p = p -> lchild;
            } else{
                p = stack[top--];
                visit(p);
                q = p;
                p = NULL;
            }
        }
    }
}

//层序遍历算法 借助queue
void LevelOrderTraverse(BiTree tree) {
    BiTree queue[MAX_NUM];
    int front = 0,rear = 0;
    queue[rear++] = tree;
    while (front!=rear){
        BiTree cur = queue[front];
        visit(cur);
        front++;
        if (cur->lchild)
            queue[rear++] = cur->lchild;
        if (cur->rchild)
            queue[rear++] = cur->rchild;
    }
}

//反层次遍历 从下到上，从右到左
void UnLevelOrderTraverse(BiTree tree) {
    BiTree stack[MAX_NUM],queue[MAX_NUM];
    int top = -1,rear = 0,front = 0;
    queue[rear++] = tree;
    while (rear != front){
        BiTree cur = queue[front++];
        stack[++top] = cur;
        if (cur->lchild)
            queue[rear++] = cur->lchild;
        if (cur->rchild)
            queue[rear++] = cur->rchild;
    }
    while (top != -1)
        visit(stack[top--]);
}


int LengthNonrecursion(BiTree tree){
    BiTree queue[MAX_NUM];
    int front = 0,rear = 0;
    queue[rear++] = tree;
    int length = 1;
    int non = 1;
    while (rear!=front){
        BiTree cur = queue[front];
        front++;
        length--;
        if (!length)
            non++;
        if (cur->lchild){
            length++;
            queue[rear++] = cur->lchild;
        }
        if (cur->rchild){
            length++;
            queue[rear++] = cur->rchild;
        }
    }
    return non;
}
//P150 12
bool HasChild(BiTree tree,int x){
    if (!tree)return false;
    if (tree->data == x)return true;
    if (HasChild(tree->lchild,x)||HasChild(tree->rchild,x)){
        printf("%d",tree->data);
        return true;
    }
}

//P150 14
int Width(BiTree tree){
    BiTree queue[MAX_NUM];
    int front = 0,rear = 0;
    queue[rear++] = tree;
    BiTree last = tree;
    int width = 0,curWidth = 0;
    while (rear != front){
        BiTree cur = queue[front];
        front++;
        if (cur->lchild)
            queue[rear++] = cur->lchild;
        if (cur->rchild)
            queue[rear++] = cur->rchild;
        curWidth ++;
        if (cur == last){
            width = width>curWidth?width:curWidth;
            curWidth = 0;
            last = queue[rear];
        }
    }
    return width;
}

//P151 19
int WPL(BiTree root, int deep){
    if (!root)
        return 0;
    static int wpl = 0;
    if (!root->lchild&&!root->rchild)
        wpl += deep*root->data;
    else{
        WPL(root->lchild,deep+1);
        WPL(root->rchild,deep+1);
    }
    return wpl;
}

//P195 6
bool IsSortTree(BiTree tree){
    if (!tree)return true;
    bool ans = true;
    if (tree->lchild)
        ans &= (tree->data>=tree->lchild->data);
    if (tree->rchild)
        ans &= (tree->data<=tree->rchild->data);
    return ans&IsSortTree(tree->lchild)&IsSortTree(tree->rchild);
}

//P195 7
int Floor(BiTree root,BiTree tree){
    static int floor = 1;
    if (root->data == tree->data)
        return floor;
    floor++;
    if (root->data>tree->data)
        return Floor(root->lchild,tree);
    return Floor(root->rchild,tree);
}

//P196 10
void PrintNoLessThanK(BiTree tree,int k){
    if (!tree)return;
    PrintNoLessThanK(tree->rchild,k);
    if (tree->data<k)
        return;
    printf("%d\t",tree->data);
    PrintNoLessThanK(tree->lchild,k);
}

int main() {
    BiTNode node1,node2,node3,node4,node5,node6,node7,node8,node9,node10,node11,node12,node13;
    initTree(node1);
    initTree(node2);
    initTree(node3);
    initTree(node4);
    initTree(node5);
    initTree(node6);            //                 1
    initTree(node7);            //          2             3
    initTree(node8);            //       4     5       6      7
    initTree(node9);            //         8      9          10
    initTree(node10);           //      11   12
    initTree(node11);           //       13
    initTree(node12);
    initTree(node13);
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;
    node4.data = 4;
    node5.data = 5;
    node6.data = 6;
    node7.data = 7;
    node8.data = 8;
    node9.data = 9;
    node10.data = 10;
    node11.data = 11;
    node12.data = 12;
    node13.data = 13;
//以下为二叉排序树
//    node1.data = 9;
//    node2.data = 6;
//    node3.data = 11;
//    node4.data = 1;
//    node5.data = 7;
//    node6.data = 10;
//    node7.data = 13;
//    node8.data = 4;
//    node9.data = 8;
//    node10.data = 12;
//    node11.data = 2;
//    node12.data = 5;
//    node13.data = 3;

    node1.lchild = &node2;
    node1.rchild = &node3;
    node2.lchild = &node4;
    node2.rchild = &node5;
    node3.lchild = &node6;
    node3.rchild = &node7;
    node4.rchild = &node8;
    node5.rchild = &node9;
    node7.lchild = &node10;
    node8.lchild = &node11;
    node8.rchild = &node12;
    node11.rchild = &node13;
    printf("先序遍历 递归版本:\t\t");
    preOrderTraverse(&node1);
    printf("\n先序遍历 非递归版本:\t");
    preOrderTraverseNonrecursion(&node1);
    printf("\n中序遍历 递归版本:\t\t");
    inOrderTraverse(&node1);
    printf("\n中序遍历 非递归版本:\t");
    inOrderTraverseNonrecursion(&node1);
    printf("\n后序遍历 递归版本:\t\t");
    postOrderTraverse(&node1);
    printf("\n后序遍历 非递归版本:\t");
    postOrderTraverseNonrecursion(&node1);
    printf("\n层次遍历\t\t\t\t");
    (LevelOrderTraverse(&node1));
    printf("\n反层次遍历\t\t\t");
    (UnLevelOrderTraverse(&node1));
    printf("\n");
    printf("%d",LengthNonrecursion(&node1));
//    PrintNoLessThanK(&node1,8);
    return 0;
}