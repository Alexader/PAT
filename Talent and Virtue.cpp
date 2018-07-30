#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
using namespace std;
int n, lb, hb;
struct people
{
	string name;
	int t;
	int v;
	int total;
	people() {};
	people(string n, int vi, int ta) : t(ta), v(vi), name(n), total(ta+vi) {};
};
bool non_decres(people& a, people& b) {
	if (b.total != a.total) return a.total > b.total;
	else if (a.v != b.v) return a.v > b.v;
	else return a.name < b.name;
}
// 这里的比较函数真的烦，直接暴力 if - else解决了
bool cmp(people &a, people &b) {
	if (a.t >= hb && a.v >= hb) { // two sage
		if (b.t >= hb && b.v >= hb)
			return non_decres(a, b);
		else return true;
	}
	else if (b.t >= hb && b.v >= hb) return false;// b is sage and a is not
	else if (a.v >= hb) {
		// a is nobleman
		if (b.v >= hb) return non_decres(a, b);
		else return true;
	}
	else if (b.v >= hb) return false;
	else if (a.v >= a.t) {
		// a is foolman
		if (b.v >= b.t) return non_decres(a, b);
		else return true;
	}
	else if (b.v >= b.t) return false;
	else return non_decres(a, b);
}
vector<people> p;
int main() {
	scanf("%d%d%d", &n, &lb, &hb);
	int ranked = 0, t, v;
	char name[9];
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", name, &v, &t);
		if (v >= lb && t >= lb) {
			ranked++;
			people temp(string(name), v, t);
			p.push_back(temp);
		}
	}
	sort(p.begin(), p.end(), cmp);
	printf("%d\n", ranked);
	for (int i = 0; i < ranked; i++) {
		printf("%s %d %d\n", p[i].name.c_str(), p[i].v, p[i].t);
	}
}