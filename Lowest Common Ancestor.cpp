#include <cstdio>
#include<map>
using namespace std;
const int maxn = 50;
int M, N;
int preOrder[maxn];
map<int, bool> mp;
int main() {
    scanf("%d%d", &M, &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &preOrder[i]);
        mp[preOrder[i]] = true;
    }
    int u, v;
    for(int i=0;i<M;i++) {
        scanf("%d%d", &u, &v);
        int a;
        for(int j=0;j<N;j++) {
            // 查看第一个大小出现的在 [u, v]（闭区间，假设 u < v）之间的元素就是要找的共同祖先
            a = preOrder[j];
            if((u<a && a< v) || (u>a && a>v) || a==u || a==v) break;
        }
        if(!mp[u] && !mp[v])
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if(!mp[u])
            printf("ERROR: %d is not found.\n", u);
        else if(!mp[v])
            printf("ERROR: %d is not found.\n", v);
        else if(a == v || a == u)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
}