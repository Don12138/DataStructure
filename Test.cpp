#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int a[10010];
int n, i,j, m;
int vis[100100],ans[100100];
int mini,maxi;
int solve(){

    for (i=0;i<n;i++){
        memset (vis,0,sizeof(vis));
        mini=INF,maxi=0;
        for (j=i;j<n;j++){
            mini=min(mini,a[j]);
            maxi=max(maxi,a[j]);
            if (!vis[a[j]]){
                if (maxi-mini == j-i)
                    ans[j-i+1]++;
                vis[a[j]]=1;
            }
            else
                break;

        }
    }

}
int main(){
    int k;
    scanf ("%d %d",&n, &m);
    for (i=0;i<n;i++)
        scanf ("%d",&a[i]);
    memset (ans,0,sizeof(ans));
    solve();
    printf ("Case #1:\n");
    while (m--){
        scanf ("%d", &k);
        printf ("%d\n",ans[k]);
    }
    return 0;
}