#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <set>
#include <map>
using namespace std;
const double sub = 1e-8;
int cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)return a.first>b.first;
    else return a.second<b.second;
}
int main()
{
    int num;
    cin >> num;
    while (num-->0){
        int monsterNum,heroAttack,heroDefend;
        cin>>monsterNum>>heroAttack>>heroDefend;
        int monsterAttack,monsterDefend,monsterBlood,heroDamage,monsterDamage,leftNum;
        pair<int, int>bonus_monsterDamage[monsterNum];//pair��һ�������棬�ڶ����ǹ����Ӣ�۵��˺�
        bool legal = true;
        int heroBlood = 0;
        for (int i = 0; i < monsterNum; ++i){
            cin>>monsterAttack>>monsterDefend>>monsterBlood;
            if (monsterDefend>=heroAttack){
                legal = false;
                break;
            }//Ӣ��̫���ˣ���һ���ִ���
            heroDamage = heroAttack - monsterDefend;
            monsterDamage = monsterAttack - heroDefend;
            bonus_monsterDamage[i].second = monsterDamage;
            leftNum = monsterBlood/heroDamage;//Ӣ��Ҫ�����ٵ�
            if (monsterBlood%heroDamage == 0){//Ӣ�۸պÿ���������Ѫ
                bonus_monsterDamage[i].first = -(leftNum-1)*monsterDamage;
            } else{//Ӣ�۹������������Ѫ
                bonus_monsterDamage[i].first = heroDamage-(monsterBlood-(leftNum*heroDamage))-monsterDamage*leftNum;
            }
        }
        if (legal){
            sort(bonus_monsterDamage,bonus_monsterDamage,cmp);
            int i;
            for (i = 0; i < monsterNum - 1; ++i) {
                heroBlood+=bonus_monsterDamage[i].first;//��ǰn-1�����������
            }
            if (heroBlood>=0&&heroBlood>bonus_monsterDamage[i].second)//Ӣ�۴���Ѫ
                cout<<0;
            else if(heroBlood>=0)//Ӣ�۴���Ѫ��������ס���һ��
                cout<<bonus_monsterDamage[i].second+1;
            else//Ӣ�ۿ�Ѫ����Ҫ����Ѫ���Լ����һ��
                cout<<(-heroBlood)+1+bonus_monsterDamage[i].second;
        } else cout<<-1<<endl;
    }
}
