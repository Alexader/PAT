#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> coupon;
vector<int> product;
bool cmp(int a, int b) {
  // 把负的绝对值大的数排在前面，这样负负达到最大的整数
	if (a < 0 && b < 0) return a < b;
	return a > b;
}
int main() {
	scanf("%d", &n);
	coupon.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &coupon[i]);
	scanf("%d", &m);
	product.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &product[i]);
	sort(coupon.begin(), coupon.end(), cmp);
	sort(product.begin(), product.end(), cmp);
	int profit = 0;
	for (int i = 0, j=0; i < n && j < m;) {
		if (coupon[i] * product[j] > 0) {
			profit += coupon[i] * product[j];
			i++; j++;
		}
		else if (coupon[i] < 0) // coupon达到负值，需要让 product进行移动
			j++;
		else i++;
	}
	printf("%d", profit);
}