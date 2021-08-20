#include "algorithm"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
    struct node {//设置双向链表结构
        node* next;
        node* pre;
        int key;
        int val;
        node(int k, int v) : key(k), val(v), next(NULL), pre(NULL) {}//可以直接输入数字初始化
    };
    node* head = new node(-1, -1);//设置一个头
    node* tail = new node(-1, -1);//设置一个尾
    int length = 0;//记录链表中有效结点（除去头尾）的数量
    map<int, node* > mp; //哈希表
    void update(node* p) { //每次访问后，更新优先度，即将访问的节点放在第一个位置
        //将p节点从原位置删除
        node* q = p->pre;
        q->next = p->next;
        p->next->pre = q;
        //将p节点插入到第一个位置
        p->next = head->next;
        head->next->pre = p;
        head->next = p;
        p->pre = head;
    }
    void set(int key, int val, int k) { //插入数据
        if (mp.count(key)) //插入的数据已经存在，更新p节点的位置
            update(mp[key]);
        else {     //否则加入数据
            node* p = new node(key, val);  //创建新节点加入哈希表
            mp[key] = p;
            length++;
            //将p节点插入到第一个位置
            p->next = head->next;
            p->next->pre = p;
            head->next = p;
            p->pre = head;
            if (length > k) {  //超出LRU缓存空间
                node* q = tail->pre->pre;
                node* t = q->next;
                q->next = tail;
                tail->pre = q;
                mp.erase(t->key);//删除map里面的数据
                free(p);
            }
        }
    }
    int get(int key) {  //访问数据
        if (mp.count(key)) {  //哈希表找到数据更新节点，并返回
            node* p = mp[key];
            update(p);
            return p->val;
        }
        else {//返回-1
            node* p = new node(-1, -1);
            return p->val;
        }
    }
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        head->next = tail;
        tail->next = head; //先将链表首位相接,便于插入与删除
        vector<int> res;  //记录输出
        for (int i = 0; i < operators.size(); i++) {
            if (operators[i][0] == 1)
                set(operators[i][1], operators[i][2], k);
            else if (operators[i][0] == 2) {
                res.push_back(get(operators[i][1]));
            }
        }
        return res;
    }
};