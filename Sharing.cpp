#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5;
int n;
int t1, t2;
struct node{
	char val;
	int next;
	bool vis;
};
vector<node> LL(maxn);
int main() {
	scanf("%d%d%d", &t1, &t2, &n);
	int a;
	for(int i=0;i<n;i++) {
		scanf("%d ", &a);
		scanf(" %c %d", &LL[a].val, &LL[a].next);
		LL[a].vis = false;
	}
	int ptr = t1;
	while(ptr != -1) {
		LL[ptr].vis = true;
		ptr = LL[ptr].next;
	}
	ptr = t2;
	while(ptr!=-1) {
		if(LL[ptr].vis == true) break;
		LL[ptr].vis = true;
		ptr = LL[ptr].next;
	}
	if(ptr == -1) printf("-1");
	else printf("%05d", ptr);
}