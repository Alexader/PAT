#include<iostream>
#include <vector>
#include <string>
using namespace std;
string s;
const int maxn = 1e3 + 1;
bool ans[maxn][maxn];
// 真的不敢相信，这个暴力都能通过，这个实在是太水了
bool isSys(int im, int jm) {
	while (im < jm) {
		if (s[im] != s[jm]) return false;
		jm--; im++;
	}
	return true;
}
int main() {
	getline(cin, s);
	int n = s.length(), maxL = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (isSys(i, j) && j - i + 1 > maxL) maxL = j - i + 1;
		}
	}
	cout << maxL;
}