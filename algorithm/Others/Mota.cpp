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
        pair<int, int>bonus_monsterDamage[monsterNum];//pair第一个是收益，第二个是怪物对英雄的伤害
        bool legal = true;
        int heroBlood = 0;
        for (int i = 0; i < monsterNum; ++i){
            cin>>monsterAttack>>monsterDefend>>monsterBlood;
            if (monsterDefend>=heroAttack){
                legal = false;
                break;
            }//英雄太弱了，有一个怪打不死
            heroDamage = heroAttack - monsterDefend;
            monsterDamage = monsterAttack - heroDefend;
            bonus_monsterDamage[i].second = monsterDamage;
            leftNum = monsterBlood/heroDamage;//英雄要砍多少刀
            if (monsterBlood%heroDamage == 0){//英雄刚好砍死，纯亏血
                bonus_monsterDamage[i].first = -(leftNum-1)*monsterDamage;
            } else{//英雄攻击力溢出，吸血
                bonus_monsterDamage[i].first = heroDamage-(monsterBlood-(leftNum*heroDamage))-monsterDamage*leftNum;
            }
        }
        if (legal){
            sort(bonus_monsterDamage,bonus_monsterDamage,cmp);
            int i;
            for (i = 0; i < monsterNum - 1; ++i) {
                heroBlood+=bonus_monsterDamage[i].first;//将前n-1个收益加起来
            }
            if (heroBlood>=0&&heroBlood>bonus_monsterDamage[i].second)//英雄纯吸血
                cout<<0;
            else if(heroBlood>=0)//英雄纯吸血，但扛不住最后一刀
                cout<<bonus_monsterDamage[i].second+1;
            else//英雄亏血，需要补上血，以及最后一刀
                cout<<(-heroBlood)+1+bonus_monsterDamage[i].second;
        } else cout<<-1<<endl;
    }
}
