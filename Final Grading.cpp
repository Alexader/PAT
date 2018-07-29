#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int p, m, n;
struct grade
{
	int online;
	int mid;
	int final;
	grade(int p = -1, int m=-1 , int f =-1) : online(p), mid(m), final(f) {};
};
struct stu
{
	string id;
	int pg;
	int mg;
	int f;
	int fg;
	stu(string id, int pg=-1, int mg=-1, int f=-1) : id(id), pg(pg), mg(mg), f(f) {};
	void setfg() {
		if (pg < 200) fg = -1;
    // 四舍五入的简单实现，这里竟然不会，卡了这个点好久。。。
		else if(mg > f) fg = (int)(0.4*mg + 0.6*f + 0.5);
		else fg = f;
	}
};
bool cmp(stu &a, stu &b) {
  // 这里出成绩的竟然看不懂题目的规则，卡了十多分钟，蠢哭了
	if (a.fg != b.fg) return a.fg > b.fg;
	else return a.id < b.id;
}
map<string, grade> mp;
int main() {
	ios::sync_with_stdio(false);
	cin >> p >> m >> n;
	string id;
	int gra;
	for (int i = 0; i < p; i++) {
		cin >> id >> gra;
		mp[id].online = gra;
	}
	for (int i = 0; i < m; i++) {
		cin >> id >> gra;
		mp[id].mid = gra;
	}
	for (int i = 0; i < n; i++) {
		cin >> id >> gra;
		mp[id].final = gra;
	}
	vector<stu> stus;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		stus.push_back(stu({ it->first, it->second.online, it->second.mid, it->second.final}));
		stus.back().setfg();
	}
	sort(stus.begin(), stus.end(), cmp);

	for (auto it = stus.begin(); it != stus.end(); it++) {
		if (it->fg < 60) break;
		cout << it->id << " " << it->pg << " " << it->mg << " " << it->f << " " << it->fg << endl;
	}
}