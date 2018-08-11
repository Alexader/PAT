#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
typedef long long LL;
int n;
LL gcd(LL a, LL b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
struct Fraction
{
	LL integer;
	LL n;
	LL d;
	Fraction add(Fraction &b) {
		Fraction temp;
		temp.integer = integer + b.integer;
		temp.n = n*b.d + d*b.n;
		temp.d = d*b.d;
		bool neg = false;
		temp.integer += temp.n / temp.d;
		if (temp.n < 0) {
			neg = true; temp.n = -temp.n;
		}
		temp.n %= temp.d;
		LL gd = gcd(temp.n, temp.d);
		temp.n = neg ? -1 * temp.n / gd : temp.n / gd;
		temp.d /= gd;
		return temp;
	}
};
vector<Fraction> v;
int main() {
	scanf("%d", &n);
	v.resize(n);
	Fraction total = { 0, 0, 1 };
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &v[i].n, &v[i].d);
		temp = gcd(abs(v[i].n), v[i].d);
    // 不提前处理进行约分的话会出现超出 LL 表示范围的情况
		v[i].n /= temp; v[i].d /= temp;
		v[i].integer = 0;
		total = total.add(v[i]);
	}
	if (total.integer == 0) {
    // 没有考虑这个结果都是零的情况，卡了最后一个测试点好久啊啊
		if (total.n == 0) printf("0");
		else printf("%lld/%lld", total.n, total.d);
	}
	else {
		if(total.n != 0)
			printf("%lld %lld/%lld", total.integer, total.n, total.d);
		else printf("%lld", total.integer);
	}
}