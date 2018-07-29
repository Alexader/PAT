#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1001;
int k;
map<string, pair<double, int> > mp;
struct Institution
{
	string name;
	int Tws;
	int Ns;
	Institution(string name, int Tws, int Ns) : name(name), Tws(Tws), Ns(Ns) {};
};
double getTws(char level, double score) {
	if (level == 'B') return score / 1.5;
	else if (level == 'A') return score;
	else return score * 1.5;
}
bool cmp(Institution &a, Institution &b) {
	if (a.Tws != b.Tws) return a.Tws > b.Tws;
	else if (a.Ns != b.Ns) return a.Ns < b.Ns;
	else return a.name < b.name;
}
std::string str_tolower(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return tolower(c); }
	);
	return s;
}
vector<Institution> ranklist;
int main() {
	ios::sync_with_stdio(false);
	cin >> k;
	string stu_id, sch_name;
	char level;
	double score;
	for (int i = 0; i < k; i++) {
		cin >> stu_id >> score >> sch_name; cin.get();
		level = stu_id[0];
		// 利用 map 进行映射
		sch_name = str_tolower(sch_name);
		double wgrade = getTws(level, score);
		if (mp.find(sch_name) != mp.end()) {
			mp[sch_name].first += wgrade;
			mp[sch_name].second += 1;
		}
		else {
			mp[sch_name].first = wgrade;
			mp[sch_name].second = 1;
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ranklist.push_back(Institution(it->first, (int)it->second.first, it->second.second));
	}

	sort(ranklist.begin(), ranklist.end(), cmp);
	printf("%d\n", ranklist.size());
	int cnt = 1, rankt = 1, i;// cnt 用来记录有多少个相同分数的人。
	for (i = 0; i < ranklist.size()-1; i++) {
		printf("%d %s %d %d\n", rankt, ranklist[i].name.c_str(), ranklist[i].Tws, ranklist[i].Ns);
		if (ranklist[i].Tws == ranklist[i + 1].Tws)
			cnt++;
		else {
			rankt += cnt;
			cnt = 1;
		}
	}
	printf("%d %s %d %d\n", rankt, ranklist[i].name.c_str(), ranklist[i].Tws, ranklist[i].Ns);
}