#include<iostream>
#include <vector>
#include <stack>
using namespace std;
int m, n, kn;
vector<int> seq;
bool isPopSeq(vector<int> &v) {
  // 这其实是一个栈的模拟过程：需要弹出的元素，要不还没有入栈，要不就在栈顶
  // 所以对于可能的 pop sequence，先查看栈顶是不是要弹出的元素，如果不是，
  // 一直压栈到要输出的元素为止。压栈的过程中可能会超过栈的容量，判断的时候比较的符号需要
  // 想清楚，需不需要等于号。此外压栈的元素也很好控制，因为只能是升序的，一直让 num++ 即可
	stack<int> sta;
	sta.push(0);
	int num = 1, index = 0, cap = m + 1;
	while (index < n) {
		while (v[index]>sta.top() && sta.size() < cap && index < n) {
			sta.push(num++);
		}
		if (v[index] == sta.top()) {
			index++;
			sta.pop();
		}
		else return false;
	}
	return true;
}
int main() {
	scanf("%d%d%d", &m, &n, &kn);
	seq.resize(n);
	for (int i = 0; i < kn; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &seq[j]);
		if (isPopSeq(seq)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}