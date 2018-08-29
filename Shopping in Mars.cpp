#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int> sum;
int main() {
	scanf("%d%d", &n, &m);
	sum.resize(n+1, 0);
	int num;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
    // 递增加和的数组能够使用二分查找，加快查询速度
		sum[i] = sum[i - 1] + num;
	}
	vector<pair<int, int>> ans;
	int minLost = 1e9;
	int l, mid, r;
	for (int i = 0; i <= n; i++) {
		l = i, r = n;
		do {
			mid = (l + r) / 2;
			if (sum[mid] - sum[i] >= m) {
        // 这里不用区别大于和等于两种情况，这样才能在没有正好的支付方案的时候
        // 找出最小损失的选择
				if (sum[mid] - sum[i] < minLost) {
					minLost = sum[mid] - sum[i];
					ans.clear();
					ans.push_back({ i + 1, mid });
				}
				else if (sum[mid] - sum[i] == minLost) {
					ans.push_back({ i + 1, mid });
					break;
				}
				r = mid - 1;
			}
			else l = mid + 1;
		} while (l<=r);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d-%d\n", ans[i].first, ans[i].second);
	}
}