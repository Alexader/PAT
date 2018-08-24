#include <iostream>
#include <vector>
#include<cmath>
#include<map>
using namespace std;
int n, head;
const int maxn = 1e5;
struct node {
	int key;
	int next;
}LL[maxn];
map<int, bool> exist;
int main() {
	scanf("%d%d", &head, &n);
	int addr;
	for (int i = 0; i < n; i++) {
		scanf("%d", &addr);
		scanf("%d%d", &LL[addr].key, &LL[addr].next);
	}
	int ptr = head;
	vector<pair<int, int> >remain;
	while (ptr != -1) {
		if (exist.find(abs(LL[ptr].key)) != exist.end())
			remain.push_back({ ptr,LL[ptr].key });
		else {
			exist[abs(LL[ptr].key)] = true;
			if (ptr != head)
				printf(" %05d\n%05d %d", ptr, ptr, LL[ptr].key);
			else printf("%05d %d", ptr, LL[ptr].key);
		}
		ptr = LL[ptr].next;
	}
	printf(" -1\n");
  // 这里要进行特殊判断，不然最后面的 -1 就会输出了
	if (remain.size() != 0) {
		for (int i = 0; i < remain.size(); i++) {
			if (i != 0)
				printf(" %05d\n%05d %d", remain[i].first, remain[i].first, remain[i].second);
			else printf("%05d %d", remain[i].first, remain[i].second);
		}
		printf(" -1");
	}
}