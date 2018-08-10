#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> dis;
int main() {
	scanf("%d", &n);
	dis.resize(n+1, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dis[i]);
		dis[i] += dis[i-1];
	}
	int total = dis[n];
	scanf("%d", &m);
	int s, e, temp;
  // 比较两个方向的距离即可
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &s, &e);
		if (s > e) { temp = s; s = e; e = temp; }
		int oneway = dis[e-1] - dis[s - 1];
		cout << min(oneway, total - oneway) << endl;
	}
}