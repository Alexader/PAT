#include <iostream>
#include<set>
using namespace std;
const int maxn = 5e4;
struct node {
	int num;
	int cnt;
  // 操作符重载看来还得记一下，全都忘光了，这里函数不加 const
  // 的话编译会出错，好像 C++ 规定的几个重载符的必须是 const（不能修改执行函数的对象）
	bool operator < (const node& b) const {
		if (cnt != b.cnt) return cnt>b.cnt;
		return num < b.num;
	}
};
set<node> st;
int H[maxn] = { 0 };
int n, kn;
int main() {
	scanf("%d%d", &n, &kn);
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		int cnt = 0;
		
		if (i != 0) {
			printf("%d:", tmp);
			for (auto it = st.begin(); it != st.end() && cnt < kn; it++, cnt++)
				printf(" %d", *it);
  		printf("\n");
		}
		if (st.find(node{ tmp, H[tmp] }) == st.end()) {
			st.insert({ tmp, H[tmp] + 1 });
			H[tmp]++;
		}
		else {
			st.erase(node{ tmp, H[tmp] });
			st.insert({ tmp, H[tmp] + 1 });
			H[tmp]++;
		}
	}
}