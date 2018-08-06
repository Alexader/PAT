#include <iostream>
#include<algorithm>
#include <vector>
#include<map>
using namespace std;
int n, m;
struct stu
{
	int id;
  // score 数组里面的成绩是按照 ACME的顺序安排的，这样按照下标比较过去就自动
  // 符合了题目要求的相同最高排名时候的按照成绩优先级选
	int score[4];
	int bestRank;
	int bestC;
};
int flag = 0;
bool cmp(stu& a, stu& b) {
  // 这个方法是看的柳神的，我之前写了四个比较函数，蠢死。。。
	return a.score[flag] > b.score[flag];
}
map<int, int>mp;
vector<stu> ss;
int main() {
	scanf("%d%d", &n, &m);
	ss.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &ss[i].id, &ss[i].score[1], &ss[i].score[2], &ss[i].score[3]);
		ss[i].score[0] = (int)(ss[i].score[3] + ss[i].score[1] + ss[i].score[2] + 0.5) / 3;
		ss[i].bestRank = 2e4 + 1;
		mp[ss[i].id] = -1;
	}
	for (int i = 0; i < 4; i++) {
		sort(ss.begin(), ss.end(), cmp);
		int rank = 0, prev = 101, delay = 1;
		for (int j = 0; j < ss.size(); j++) {
      // 用 delay 和 prev 实现顺延的排名，不然有两个测试过不去
			if (ss[j].score[flag] == prev) delay++;
			else {
				rank += delay; delay = 1;
				prev = ss[j].score[flag];
			}
			if (ss[j].bestRank > rank) {
				ss[j].bestRank = rank;
				ss[j].bestC = flag;
			}
			if (i == 3) {
        // 用来记录最后一次排序后每个学生的下标，虽然感觉这样比较蠢
        // 暂时没有想到更好的
				mp[ss[j].id] = j;
			}
		}
		flag++;
	}
	int id;
	char c[] = { 'A', 'C', 'M', 'E' };
	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		if (mp.find(id) == mp.end()) printf("N/A\n");
		else {
			printf("%d %c\n", ss[mp[id]].bestRank, c[ss[mp[id]].bestC]);
		}
	}
}
