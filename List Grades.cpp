#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n;
struct stu
{
	string name;
	string id;
	int grade;
};
bool cmp(stu& a, stu& b) {
	return a.grade >= b.grade;
}
vector<stu> ss;
vector<vector<int> > interval; // 维护一个区间的索引，查询的速度比较快
int main() {
	scanf("%d", &n);
	ss.resize(n);
	char temp_name[11], temp_id[11];
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", temp_name, temp_id, &ss[i].grade);
		ss[i].id = temp_id;
		ss[i].name = temp_name;
	}
	sort(ss.begin(), ss.end(), cmp);
	interval.resize(101);
	for (int i = 0; i < n; i++) {
		interval[ss[i].grade].push_back(i);
	}
	int min, max, count = 0;
	vector<stu> out;
	scanf("%d%d", &min, &max);
	for (int i = min; i <= max; i++) {
		for (int j = 0; j < interval[i].size(); j++) {
			out.push_back(ss[interval[i][j]]);
			count++;
		}
	}
  // 因为只有一次查询区间的操作，所以就只直接 copy 原数据再次排序了
	sort(out.begin(), out.end(), cmp);
	if (count == 0) printf("NONE");
	for (int i = 0; i < out.size();i++)
		printf("%s %s\n", out[i].name.c_str(), out[i].id.c_str());
}