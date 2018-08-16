#include <iostream>
#include <set>
using namespace std;
const int maxn = 1e4+1;
int n;
int UFset[maxn] = {0};
int findFather(int node) {
  // 需要使用路径压缩，不然会有一个测试点超时
  if(node == UFset[node]) return node;
  else{
    int F = findFather(UFset[node]);
    UFset[node] = F;
    return F;
  }
}
void Uion(int a, int b) {
	int af = findFather(a);
	int bf = findFather(b);
	if(af != bf)
		UFset[af] = bf;
}
int main() {
	scanf("%d", &n);
	int num;
	for(int i=0;i<n;i++){
    // 每一张照片中默认使用第一个鸟作为根部，如果这第一只鸟没有指向其他鸟的话
		scanf("%d", &num);
		int bird, first;
		scanf("%d", &first);
		if(UFset[first] == 0) UFset[first] = first;
		for(int j=1;j<num;j++) {
			scanf("%d", &bird);
      // 碰到一只鸟出现在不同的照片中了，需要合并分组
			if(UFset[bird] != 0) Uion(bird, first);
			else UFset[bird] = first;
		}
	}
	int father, cnt = 0;
	set<int> group;
	for(int i=0;i<maxn;i++) {
		if(UFset[i] != 0) {
			father = findFather(i);
			group.insert(father);
			cnt++;
		}
	}
	printf("%d %d\n", group.size(), cnt);
	int q;
	scanf("%d", &q);
	int prev, next;
	for(int i=0;i<q;i++) {
		scanf("%d%d", &prev, &next);
		if(findFather(prev) == findFather(next)) printf("Yes\n");
		else printf("No\n");
	}
}