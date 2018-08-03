#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n, m, kn;
vector<vector<int> > v2Edge;
vector<bool> hashT;
bool isVertexCover(vector<int> & t) {
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < v2Edge[t[i]].size(); j++)
			hashT[v2Edge[t[i]][j]] = true;
	}
	for (int i = 0; i < hashT.size(); i++) {
		if (hashT[i] == false) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	v2Edge.resize(n);
	hashT.resize(m, false);
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
    // 记录的是顶点和边的关系
		v2Edge[v1].push_back(i);
		v2Edge[v2].push_back(i);
	}
	cin >> kn;
	int nodeNum;
	vector<int> vSet;
	for (int i = 0; i < kn; i++) {
		cin >> nodeNum;
		vSet.clear();
		vSet.resize(nodeNum);
		for (int j = 0; j < nodeNum; j++)
			cin >> vSet[j];
		if (isVertexCover(vSet))
			cout << "Yes" << endl;
		else cout << "No" << endl;
    // 判断函数每次都会改变全局变量 hashT，所以一定要记得恢复
    // 感觉自己写图相关的算法每次都是这里会出问题
		fill(hashT.begin(), hashT.end(), false);
	}
}