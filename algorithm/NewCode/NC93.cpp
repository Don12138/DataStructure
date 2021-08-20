#include "algorithm"
#include "vector"
#include "map"
using namespace std;
class Solution {
public:
    struct node {//����˫������ṹ
        node* next;
        node* pre;
        int key;
        int val;
        node(int k, int v) : key(k), val(v), next(NULL), pre(NULL) {}//����ֱ���������ֳ�ʼ��
    };
    node* head = new node(-1, -1);//����һ��ͷ
    node* tail = new node(-1, -1);//����һ��β
    int length = 0;//��¼��������Ч��㣨��ȥͷβ��������
    map<int, node* > mp; //��ϣ��
    void update(node* p) { //ÿ�η��ʺ󣬸������ȶȣ��������ʵĽڵ���ڵ�һ��λ��
        //��p�ڵ��ԭλ��ɾ��
        node* q = p->pre;
        q->next = p->next;
        p->next->pre = q;
        //��p�ڵ���뵽��һ��λ��
        p->next = head->next;
        head->next->pre = p;
        head->next = p;
        p->pre = head;
    }
    void set(int key, int val, int k) { //��������
        if (mp.count(key)) //����������Ѿ����ڣ�����p�ڵ��λ��
            update(mp[key]);
        else {     //�����������
            node* p = new node(key, val);  //�����½ڵ�����ϣ��
            mp[key] = p;
            length++;
            //��p�ڵ���뵽��һ��λ��
            p->next = head->next;
            p->next->pre = p;
            head->next = p;
            p->pre = head;
            if (length > k) {  //����LRU����ռ�
                node* q = tail->pre->pre;
                node* t = q->next;
                q->next = tail;
                tail->pre = q;
                mp.erase(t->key);//ɾ��map���������
                free(p);
            }
        }
    }
    int get(int key) {  //��������
        if (mp.count(key)) {  //��ϣ���ҵ����ݸ��½ڵ㣬������
            node* p = mp[key];
            update(p);
            return p->val;
        }
        else {//����-1
            node* p = new node(-1, -1);
            return p->val;
        }
    }
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        head->next = tail;
        tail->next = head; //�Ƚ�������λ���,���ڲ�����ɾ��
        vector<int> res;  //��¼���
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