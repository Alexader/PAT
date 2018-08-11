#include <iostream>
#include<algorithm>
#include <vector>
#include<cmath>
using namespace std;
int n, m;
struct mooncake
{
	double storage;
	double tPrice;
	double price;
};
vector<mooncake> v;
bool cmp(mooncake& a, mooncake& b) {
	return a.price > b.price;
}
int main() {
	scanf("%d%d", &n, &m);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &v[i].storage);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &v[i].tPrice);
		v[i].price = v[i].tPrice / v[i].storage;
	}
	sort(v.begin(), v.end(), cmp);
	double profit = 0;
	double consume = 0;
  // 有一个测试点就是测试浮点数的精度的问题，所以比较的时候不能直接使用 < 
  // 使用 cmath 中的isgreater 函数是最保险的
	for (int i = 0; i < v.size() && isgreater(m, consume); i++) {
		if (isgreater(m - consume, v[i].storage)) {
			consume += v[i].storage;
			profit += v[i].tPrice;
		}
		else {
			profit += (m - consume)*v[i].price;
			consume = m;
		}
	}
	printf("%0.2lf", profit);
}