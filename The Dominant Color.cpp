#include <cstdio>
#include<map>
// 找一张照片中主要的颜色，也就是看那种颜色出现的频率最高
using namespace std;

int m, n;
map<int, int> mp;
int main() {
	scanf("%d%d", &m, &n);
	int **image = new int*[m];
	for (int i = 0; i < m; i++) {
		image[i] = new int[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &image[i][j]);
			if (mp.find(image[i][j]) != mp.end())
				mp[image[i][j]]++;
			else
				mp[image[i][j]] = 1;
		}
	}
	int max = 0, key;
	for (auto item : mp) {
		if (item.second > max) {
			max = item.second;
			key = item.first;
		}
	}
	printf("%d", key);
}