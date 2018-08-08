// 以前这道题目有问题，今天提交了以前保存的代码，通过了
#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
using namespace std;
int n, k;
struct millionair
{
	string name;
	int age;
	int wealth;
};
vector<millionair> riches;
bool cmp(millionair &a, millionair &b) {
	if (a.wealth != b.wealth) return a.wealth > b.wealth;
	else if (a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
int main() {
	scanf("%d%d", &n, &k);
	riches.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> riches[i].name;
		scanf("%d%d", &riches[i].age, &riches[i].wealth);

	}
	sort(riches.begin(), riches.end(), cmp);
	int m, Amin, Amax;
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &m, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		int count = 0;
		for (int j = 0; j < n && count != m; j++) {
			if (riches[j].age >= Amin && riches[j].age <= Amax) {
				printf("%s %d %d\n", riches[j].name.c_str(), riches[j].age, riches[j].wealth);
				count++;
			}
		}
		if (count == 0) printf("None\n");
	}
}