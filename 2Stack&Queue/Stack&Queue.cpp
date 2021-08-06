#include <cstdio>
#include <cstdlib>
#define MaxSize 50
#define ElemType int
typedef struct SqStack{
    ElemType stack[MaxSize];
    int top;
};
typedef struct SqQueue{
    ElemType queue[MaxSize];
    int front;
    int rear;
};
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}*LinkList,LNode;
typedef struct LinkQueue{
    LNode *front;
    LNode *rear;
};

void InitStack(SqStack &S){
    S.top = -1;
}
bool IsEmptyStack(SqStack S){
    if (S.top == -1)
        return true;
    return false;
}
bool IsFullStack(SqStack S){
    if (S.top == MaxSize-1)
        return true;
    else return false;
}
void PushStack(SqStack &S,ElemType a){
    if (IsFullStack(S)){
        printf("该栈已满\n");
        exit(0);
    }
    S.stack[++S.top] = a;
}
void PopStack(SqStack &S,ElemType &a){
    if (IsEmptyStack(S)){
        printf("该栈已空\n");
        exit(0);
    }
    a = S.stack[S.top--];
}
ElemType GetTopStack(SqStack S){
    if (IsEmptyStack(S)){
        printf("该栈已空\n");
        exit(0);
    }
    return S.stack[S.top];
}
void PrintStack(SqStack S){
    int top = S.top;
    while (top!=-1){
        printf("%d\n",S.stack[top]);
        top--;
    }
}

void InitQueue(SqQueue &Q){
    Q.front = 0;
    Q.rear = 0;
}
bool IsEmptyQueue(SqQueue Q){
    return Q.front==Q.rear;
}
bool IsFullQueue(SqQueue Q){
    return (Q.rear+1)%MaxSize == Q.front;
}
void PushQueue(SqQueue &Q,ElemType a){
    if (IsFullQueue(Q)){
        printf("该队列已满\n");
        exit(0);
    }
    Q.queue[Q.rear] = a;
    Q.rear = (Q.rear+1)%MaxSize;
}
void PopQueue(SqQueue &Q,ElemType &a){
    if (IsEmptyQueue(Q)){
        printf("该队列已空\n");
        exit(0);
    }
    a = Q.queue[Q.front];
    Q.front = (Q.front+1)%MaxSize;
}
ElemType GetTopQueue(SqQueue Q){
    if (IsEmptyQueue(Q)){
        printf("该队列已空\n");
        exit(0);
    }
    return Q.queue[Q.front];
}
void PrintQueue(SqQueue Q){
    int front = Q.front;
    while (front!=Q.rear){
        printf("%d\n",Q.queue[front]);
        front = (front+1)%MaxSize;
    }
}

void InitLinkQueue(LinkQueue &Q){
    Q.front = (LNode*)malloc(sizeof(LNode));
    Q.rear = Q.front;
    Q.front->next = NULL;
}
bool IsEmptyLinkQueue(LinkQueue Q){
    return Q.front == Q.rear;
}
void PushLinkQueue(LinkQueue &Q,ElemType a){
    LinkList cur = (LNode*)malloc(sizeof(LNode));
    cur->data = a;
    cur->next = NULL;
    Q.rear->next = cur;
    Q.rear = cur;
}
void PopLinkQueue(LinkQueue &Q,ElemType &a){
    if (IsEmptyLinkQueue(Q)){
        printf("该队已空\n");
        exit(0);
    }
    a = Q.front->data;
    LinkList cur = Q.front;
    Q.front = Q.front->next;
    free(cur);
}

//P85 2
void Reverse_Queue_by_Stack(SqQueue &Q, SqStack &S){
    ElemType cur;
    while (!IsEmptyQueue(Q)){
        PopQueue(Q,cur);
        PushStack(S,cur);
    }
    while (!IsEmptyStack(S)){
        PopStack(S,cur);
        PushQueue(Q,cur);
    }
}
//P85 3
void Enqueue_For_Two_Stack(SqStack &head,SqStack &tail,ElemType x){
    if (IsFullStack(head)||IsFullStack(tail)){
        printf("该队已满\n");
        exit(0);
    }
    ElemType cur;
    if (IsEmptyStack(tail)){
        while (!IsEmptyStack(head)){
            PopStack(head,cur);
            PushStack(tail,cur);
        }
    }
    PushStack(tail,x);
}
void Dequeue_For_Two_Stack(SqStack &head,SqStack &tail,ElemType &x){
    if (IsEmptyStack(head)&&IsEmptyStack(tail)){
        printf("该队已空\n");
        exit(0);
    }
    ElemType cur;
    if (IsEmptyStack(head)){
        while (!IsEmptyStack(tail)){
            PopStack(tail,cur);
            PushStack(head,cur);
        }
    }
    PopStack(head,x);
}
bool QueueEmpty_For_Two_Stack(SqStack &head,SqStack &tail){
    return IsEmptyStack(head)&&IsEmptyStack(tail);
}

//P96 1
bool IsCompatible(char* a){
    SqStack stack = *(SqStack*)malloc(sizeof(SqStack));
    InitStack(stack);
    char cur = '0';
    while (*a != '\0'){
        if (*a == '(' || *a == '[' || *a == '{')
            PushStack(stack,*a);
        else if (*a == ')'){
            if (IsEmptyStack(stack))
                return false;
            PopStack(stack,cur);
            if (cur != '(')
                return false;
        } else if (*a == ']'){
            if (IsEmptyStack(stack))
                return false;
            PopStack(stack,cur);
            if (cur != '[')
                return false;
        } else if (*a == '}'){
            if (IsEmptyStack(stack))
                return false;
            PopStack(stack,cur);
            if (cur != '{')
                return false;
        } else continue;
        a+=1;
        printf("%d\n",stack.top);
    }
    if (IsEmptyStack(stack))
        return true;
    else return false;
}

int main(){
//    SqStack sqStack = *(SqStack*)malloc(sizeof(SqStack));
//    InitStack(sqStack);
//    SqQueue sqQueue = *(SqQueue*)malloc(sizeof(SqQueue));
//    InitQueue(sqQueue);
//    PushQueue(sqQueue,1);
//    PushQueue(sqQueue,2);
//    PushQueue(sqQueue,3);
//    PushQueue(sqQueue,4);
//    PushQueue(sqQueue,5);
//    PushQueue(sqQueue,6);
//    PushQueue(sqQueue,7);
//    PushQueue(sqQueue,8);
//    PushQueue(sqQueue,9);
//    PushQueue(sqQueue,10);
    char *a = (char*)malloc(sizeof(char)*15);
    for (int i = 0; i < 14; ++i) {
        scanf("%c",(a+i));//sacnf 后面的是地址
        printf("%c",*(a+i));
    }
    a[14] = '\0';
    printf("%d",IsCompatible(a));
}

//[][{{{}}}()()]