#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include <vector>
using namespace std;
const int maxn = 2018;
int n, k, numberTotal = 0, gangNum = 0;
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };// G is the graph, weight is each one's total weight
bool vis[maxn] = { false };
map<string, int> name2index;
map<int, string> index2name;
map<string, int> Gang; // gang's head -> memberNum
int getIndex(string str) {
	if (name2index.find(str) != name2index.end()) {
		// already have its name
		return name2index[str];
	}
	else {
		name2index[str] = numberTotal;
		index2name[numberTotal] = str;
		return numberTotal++;
	}
}
void dfs(int u, int &head, int &memberNum, int &gangWeight) {
	if (vis[u]) return;
	memberNum++;
	vis[u] = true;
	for (int i = 0; i < maxn; i++) {
		if (G[u][i] >0) {
			gangWeight += G[u][i];
			G[u][i] = G[i][u] = 0; // 删除这条边，防止回头
			if (vis[i] == false) {
				if (weight[i] > weight[head]) head = i;
				dfs(i, head, memberNum, gangWeight);
			}
				
		}
	}
}
void traversal() {
	for (int i = 0; i < numberTotal; i++) {
		int head = i, memberNum = 0, gangWeight = 0;
		dfs(head, head, memberNum, gangWeight);
		if (memberNum > 2 && gangWeight > k) {
			if(Gang.find(index2name[head]) == Gang.end())
				Gang.insert(make_pair(index2name[head], memberNum));
		}  
	}
}
int main() {
  ios::sync_with_stdio(false); // 没有这句会超时
	cin>>n>>k;
	string str1, str2;
	int len, index, index2, w;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> w;
		index = getIndex(str1);
		index2 = getIndex(str2);
		G[index][index2] += w;
		G[index2][index] += w;
		weight[index] += w;
		weight[index2] += w;
	}
	traversal();
	cout << Gang.size() << endl;
	for (auto it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first <<" "<< it->second << endl;
	}
}