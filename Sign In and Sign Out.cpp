#include <iostream>
#include<algorithm>
#include <vector>
#include<string>
using namespace std;
int n;
struct stu
{
	string id;
	string in;
	string out;
};
// 题目很巧，时间的大小可以直接使用字符串的大小表示
bool cmp1(stu& a, stu& b) {
	return a.in < b.in;
}
bool cmp2(stu& a, stu& b) {
	return a.out > b.out;
}
vector<stu> ss;
int main() {
	scanf("%d", &n);
	ss.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> ss[i].id >> ss[i].in >> ss[i].out;
	}
	sort(ss.begin(), ss.end(), cmp1);
	cout << ss[0].id << " ";
	sort(ss.begin(), ss.end(), cmp2);
	cout << ss[0].id;
}