#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
vector<int> rides;
int main() {
	int n, k, id;
	scanf("%d", &n);
	rides.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &rides[i]);
	sort(rides.begin(), rides.end(), cmp);
	int index;
	for (index = 0; index < n; index++) {
    // 这里等于号一开始没有写，卡了好久，我好菜啊
		if (index + 1 >= rides[index]) break;
	}
	cout << index;
}