#include <cstdio>
#include<vector>
#include<map>
// 判断数组中第一个出现的在整个数组中唯一出现的数据
using namespace std;

int n;
vector<int> bets;
map<int, int> mp;
int main() {
	scanf("%d", &n);
	bets.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &bets[i]);
		if (mp.find(bets[i]) != mp.end())
			mp[bets[i]]++;
		else mp[bets[i]] = 1;
	}
	for (int i = 0; i < n;i++)
		if (mp[bets[i]] == 1) {
			printf("%d", bets[i]);
			return 0;
		}
	printf("None");

}