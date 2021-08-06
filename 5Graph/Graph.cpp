#include <cstdio>
#include <cstdlib>
#define MaxVertexNum 100
typedef int VertexType;
typedef int EdgeType;

typedef struct {
    VertexType Vexs[MaxVertexNum];
    EdgeType Edges[MaxVertexNum][MaxVertexNum];
}AMGraph;//邻接矩阵

typedef struct EdgeNode{
    struct EdgeNode *nextEdge;
    EdgeType edgeData;
    int vertexIndex;
}EdgeNode;
typedef struct {
    struct EdgeNode *firstEdge;
    VertexType vertexData;
}VertexNode,AdjList[MaxVertexNum];
typedef struct {
    AdjList vertexes;
    int vertexNum,edgeNum;
}ALGraph;//邻接表

typedef struct OLEdgeNode{
    int headVexIndex,tailVexIndex;
    struct OLEdgeNode *headLink,*tailLink;//相同弧头或弧尾的下一个弧结点指针
    EdgeType edgeData;
}OLEdgeNode;
typedef struct{
    struct OLEdgeNode *firstHeadEdge,*firstTailEdge;//以此结点为头或尾的第一个弧
    VertexType vertexData;
}OLVertexNode,OrtList[MaxVertexNum];
typedef struct {
    OrtList ortList;
    int vertexNum,edgeNum;
}OLGraph;//十字链表:容易找到以Vi为头的弧和以Vi为尾的弧，容易求出顶点的出度和入度,只用来表示有向图

typedef enum {unvisited,hasvisited} Mark;
typedef struct AMEdgeNode{
    int iVexIndex,jVexIndex;
    struct AMEdgeNode *iLink,*jLink;//相同i弧或j弧的下一个弧结点指针
    EdgeType edgeData;
}AMEdgeNode;
typedef struct{
    struct AMEdgeNode *firstEdge;//和此结点相邻的第一个弧
    VertexType vertexData;
}AMVertexNode,AMList[MaxVertexNum];
typedef struct {
    OrtList ortList;
    int vertexNum,edgeNum;
}AMLGraph;//邻接多重表:一个弧只用一个结点表示，只用来表示无向图

ALGraph InitOriginALGraph(){
    ALGraph alGraph = *(ALGraph*)malloc(sizeof (ALGraph));
    VertexNode *node1 = (VertexNode*)malloc(sizeof (VertexNode));
    node1->vertexData = 1;
    VertexNode *node2 = (VertexNode*)malloc(sizeof (VertexNode));
    node2->vertexData = 2;
    VertexNode *node3 = (VertexNode*)malloc(sizeof (VertexNode));
    node3->vertexData = 3;
    VertexNode *node4 = (VertexNode*)malloc(sizeof (VertexNode));
    node4->vertexData = 4;
    VertexNode *node5 = (VertexNode*)malloc(sizeof (VertexNode));
    node5->vertexData = 5;
    VertexNode *node6 = (VertexNode*)malloc(sizeof (VertexNode));
    node6->vertexData = 6;
    VertexNode *node7 = (VertexNode*)malloc(sizeof (VertexNode));
    node7->vertexData = 7;
    VertexNode *node8 = (VertexNode*)malloc(sizeof (VertexNode));
    node8->vertexData = 8;
    VertexNode *node9 = (VertexNode*)malloc(sizeof (VertexNode));
    node9->vertexData = 9;
    VertexNode *node10 = (VertexNode*)malloc(sizeof (VertexNode));
    node10->vertexData = 10;
    VertexNode *node11 = (VertexNode*)malloc(sizeof (VertexNode));
    node11->vertexData = 11;
    VertexNode *node12 = (VertexNode*)malloc(sizeof (VertexNode));
    node12->vertexData = 12;
    EdgeNode *edge1 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge1->edgeData = 1;
    edge1->vertexIndex = 2;
    EdgeNode *edge2 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge2->edgeData = 2;
    edge2->vertexIndex = 3;
    EdgeNode *edge3 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge3->edgeData = 3;
    edge3->vertexIndex = 4;
    EdgeNode *edge4 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge4->edgeData = 4;
    edge4->vertexIndex = 4;
    EdgeNode *edge5 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge5->edgeData = 5;
    edge5->vertexIndex = 5;
    EdgeNode *edge6 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge6->edgeData = 6;
    edge6->vertexIndex = 10;
    EdgeNode *edge7 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge7->edgeData = 7;
    edge7->vertexIndex = 8;
    EdgeNode *edge8 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge8->edgeData = 8;
    edge8->vertexIndex = 6;
    EdgeNode *edge9 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge9->edgeData = 9;
    edge9->vertexIndex = 6;
    EdgeNode *edge10 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge10->edgeData = 10;
    edge10->vertexIndex = 7;
    EdgeNode *edge11 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge11->edgeData = 11;
    edge11->vertexIndex = 8;
    EdgeNode *edge12 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge12->edgeData = 12;
    edge12->vertexIndex = 12;
    EdgeNode *edge13 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge13->edgeData = 13;
    edge13->vertexIndex = 9;
    EdgeNode *edge14 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge14->edgeData = 14;
    edge14->vertexIndex = 9;
    EdgeNode *edge15 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge15->edgeData = 15;
    edge15->vertexIndex = 9;
    EdgeNode *edge16 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge16->edgeData = 16;
    edge16->vertexIndex = 7;
    EdgeNode *edge17 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge17->edgeData = 17;
    edge17->vertexIndex = 12;
    EdgeNode *edge18 = (EdgeNode*)malloc(sizeof (EdgeNode));
    edge18->edgeData = 18;
    edge18->vertexIndex = 11;
    node1->firstEdge = edge1;
    edge1->nextEdge = edge2;
    edge2->nextEdge = NULL;
    node2->firstEdge = edge3;
    edge3->nextEdge = NULL;
    node3->firstEdge = edge4;
    edge4->nextEdge = edge9;
    edge9->nextEdge = edge5;
    edge5->nextEdge = NULL;
    node4->firstEdge = edge6;
    edge6->nextEdge = edge7;
    edge7->nextEdge = edge8;
    edge8->nextEdge = NULL;
    node5->firstEdge = edge10;
    edge10->nextEdge = NULL;
    node6->firstEdge = edge11;
    edge11->nextEdge = edge14;
    edge14->nextEdge = edge16;
    edge16->nextEdge = NULL;
    node7->firstEdge = edge15;
    edge15->nextEdge = edge18;
    edge18->nextEdge = NULL;
    node8->firstEdge = edge13;
    edge13->nextEdge = NULL;
    node9->firstEdge = NULL;
    node10->firstEdge = edge12;
    edge12->nextEdge = NULL;
    node11->firstEdge = edge17;
    edge17->nextEdge = NULL;
    node12->firstEdge = NULL;
    alGraph.edgeNum = 18;
    alGraph.vertexNum = 12;
    alGraph.vertexes[1]=*node1;
    alGraph.vertexes[2]=*node2;
    alGraph.vertexes[3]=*node3;
    alGraph.vertexes[4]=*node4;
    alGraph.vertexes[5]=*node5;
    alGraph.vertexes[6]=*node6;
    alGraph.vertexes[7]=*node7;
    alGraph.vertexes[8]=*node8;
    alGraph.vertexes[9]=*node9;
    alGraph.vertexes[10]=*node10;
    alGraph.vertexes[11]=*node11;
    alGraph.vertexes[12]=*node12;
    return alGraph;
}

void Print(VertexNode vertexNode){
    printf("%d\t",vertexNode.vertexData);
}

void BFS(ALGraph alGraph){
    bool visited[MaxVertexNum];
    for (int i = 1; i < MaxVertexNum; ++i) {
        visited[i] = false;
    }
    int queue[MaxVertexNum];
    int rear=0,front=0;
    queue[rear++] = 1;
    visited[1] = true;

    while (rear!=front){
        VertexNode cur = alGraph.vertexes[queue[front++]];
        Print(cur);
        EdgeNode *edgeNode = cur.firstEdge;
        while (edgeNode){
            if (!visited[edgeNode->vertexIndex]){
                queue[rear++] = edgeNode->vertexIndex;
                visited[edgeNode->vertexIndex] = true;
            }
            edgeNode = edgeNode->nextEdge;
        }
    }
}

bool DFSvisited[MaxVertexNum];
void DFS(int i,ALGraph alGraph){
    VertexNode vertexNode = alGraph.vertexes[i];
    Print(vertexNode);
    EdgeNode *edgeNode = vertexNode.firstEdge;
    while (edgeNode){
        int vertexIndex = edgeNode->vertexIndex;
        if (!DFSvisited[vertexIndex]){
            DFSvisited[vertexIndex] = true;
            DFS(vertexIndex,alGraph);
        }
        edgeNode = edgeNode->nextEdge;
    }
}
void DFSRecursion(ALGraph alGraph){
    for (int i = 0; i < MaxVertexNum; ++i)
        DFSvisited[i] = false;
    for (int i = 1; i < alGraph.vertexNum+1; ++i)
        if (!DFSvisited[i])
            DFS(i,alGraph);
}

//硬性的从左到右深度优先
void DFSNonRecursion1(ALGraph alGraph){
    bool visited[MaxVertexNum];
    for (int i = 0; i < MaxVertexNum; ++i) {
        visited[i] = false;
    }
    int stack[MaxVertexNum];
    int top = -1;
    stack[++top] = 1;
    visited[1] = true;
    Print(alGraph.vertexes[1]);
    while (top!=-1){
        int cur = stack[top];
        VertexNode vertexNode = alGraph.vertexes[cur];
        EdgeNode *edgeNode = vertexNode.firstEdge;
        if (edgeNode){
            int vertexIndex = edgeNode->vertexIndex;
            while (edgeNode&&visited[vertexIndex]){
                edgeNode = edgeNode->nextEdge;
                if (edgeNode)
                    vertexIndex = edgeNode->vertexIndex;
            }
            if (edgeNode){
                stack[++top] = vertexIndex;
                Print(alGraph.vertexes[vertexIndex]);
                visited[vertexIndex] = true;
            }
            else
                top--;
        }else
            top--;
    }

}

//从右到左
void DFSNonRecursion2(ALGraph alGraph){
    bool visited[MaxVertexNum];
    for (int i = 0; i < MaxVertexNum; ++i) {
        visited[i] = false;
    }
    int stack[MaxVertexNum];
    int top = -1;
    stack[++top] = 1;
    visited[1] = true;
    while (top!=-1){
        int index = stack[top--];
        Print(alGraph.vertexes[index]);
        EdgeNode* cur = alGraph.vertexes[index].firstEdge;
        while (cur){
            if (!visited[cur->vertexIndex]){
                stack[++top] = cur->vertexIndex;
                visited[cur->vertexIndex] = true;
            }
            cur = cur->nextEdge;
        }
    }
}

bool TopologicSort(ALGraph alGraph){
    int indegree[MaxVertexNum];
    for (int i = 0 ; i < MaxVertexNum; ++i)
        indegree[i] = 0;
    for (int i = 1 ; i <= alGraph.vertexNum ; i ++) {
        VertexNode vertexNode = alGraph.vertexes[i];
        for (EdgeNode *cur = vertexNode.firstEdge;  cur ; cur = cur->nextEdge) {
            indegree[cur->vertexIndex]++;
        }
    }
    int stack[MaxVertexNum];
    int top = -1;
    for (int i = 1; i < alGraph.vertexNum; ++i) {
        if (indegree[i] == 0){
            stack[++top] = i;
        }
    }
    while (top!=-1){
        int index = stack[top--];
        Print(alGraph.vertexes[index]);
        for (EdgeNode *cur = alGraph.vertexes[index].firstEdge;  cur ; cur = cur->nextEdge) {
            indegree[cur->vertexIndex]--;
            if (indegree[cur->vertexIndex] == 0)
                stack[++top] = cur->vertexIndex;
        }
    }
    for (int i = 1; i < alGraph.vertexNum; ++i) {
        if (indegree[i]!=0)return false;
    }
    return true;
}

int main(){
    ALGraph alGraph = InitOriginALGraph();
    BFS(alGraph);
    printf("\n");
    DFSRecursion(alGraph);
    printf("\n");
    DFSNonRecursion1(alGraph);
    printf("\n");
    DFSNonRecursion2(alGraph);
    printf("\n");
    TopologicSort(alGraph);
    return 0;
}

