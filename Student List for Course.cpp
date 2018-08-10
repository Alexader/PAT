#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n, kn;
vector<vector<int> > courses;
struct stu
{
	char id[5];
	vector<int> cs;
};
vector<stu> ss;
bool cmp(stu& a, stu& b) {
	return strcmp(a.id, b.id) < 0;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin >> n >> kn;
	scanf("%d%d", &n, &kn);
	ss.resize(n + 1);
	courses.resize(kn+1);
	int num, cnum, temp;
  // 一开始想的是直接边输入边使用 set 装下学生的姓名，这样就可以直接输出了
  // 当然这道题最后一个点就是卡时间，只能先完成输入，在对学生列表按照名字排序
  // 再把课程信息写入即可。关键是这道题尽然会因为 cin 超时，我想有可能是 cin 在对
  // 字符串的输入输出方面没有 C 的块，即使已经关闭了同步
	for (int i = 1; i <= n; i++) {
		//cin >> ss[i].id >> num;
		scanf("%s %d", ss[i].id, &num);
		for (int j = 0; j < num; j++) {
			//cin >> cnum;
			scanf("%d", &cnum);
			ss[i].cs.push_back(cnum);
		}
	}
	sort(ss.begin() + 1, ss.end(), cmp);
	for (int i = 1; i <= n; i++) {
		int num = ss[i].cs.size();
		for (int j = 0; j < num; j++)
			courses[ss[i].cs[j]].push_back(i);
	}
	for (int i = 1; i <= kn; i++) {
		//cout << i <<" "<< courses[i].size() << endl;
		printf("%d %d\n", i, courses[i].size());
		for (auto it = courses[i].begin(); it != courses[i].end(); it++)
			//cout << ss[*it].id << endl;
			printf("%s\n", ss[*it].id);
	}
}