// 参考晴神的分块的思想，虽然这么朴素的思想，但是自己就是想不出来
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
const int maxn = 1e5 + 1;
const int blockSz = 316; // 这是最佳的分块大小sqrt(maxn)，算法导论中有证明。
int n;
int block[blockSz];//
int table[maxn]; // hash table
stack<int> st;
void peekMedia(int K) {
	int sum = 0;
	int idx = 0;
	while (sum + block[idx] < K) {
		sum += block[idx++];
	}
	int ptr = blockSz*idx;
	while (table[ptr] + sum < K) {
		sum += table[ptr++];
	}
	printf("%d\n", ptr);
}
void Push(int k) {
	st.push(k);
	block[k / blockSz]++;
	table[k]++;
}
void Pop() {
	int val = st.top();
	st.pop();
	table[val]--;
	block[val / blockSz]--;
	printf("%d\n", val);
}
int main() {
	cin >> n;

	string cmd;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "Push") {
			cin >> val;
			Push(val);
		}
		else if (cmd == "Pop") {
			if (st.empty()) cout << "Invalid" << endl;
			else
				Pop();
		}
		else {
			if (st.empty()) cout << "Invalid" << endl;
			else {
				int K = st.size();
				if (K % 2 == 0) K /= 2;
				else K = (K + 1) / 2;
				peekMedia(K);
			}
		}
	}
}