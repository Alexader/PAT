#include <cstdio>
#include<set>
#include<vector>
#include<map>
// 这题目太水了，还以为需要考虑只有一个元素对应的 friendid 不能算friendid。
using namespace std;
int k;
vector<int> arr;
set<int> ids;
int getFriendId(int a) {
	int id = 0;
	while (a != 0) {
		id += a % 10;
		a /= 10;
	}
	return id;
}
int main() {
	scanf("%d", &k);
	arr.resize(k);
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);

	int id;
	for (int i = 0; i < k; i++) {
		id = getFriendId(arr[i]);
		ids.insert(id);
	}
	printf("%d\n", ids.size());
	for (auto it = ids.begin(); it != ids.end(); it++) {
		if(it != ids.begin())
			printf(" %d", *it);
		else
			printf("%d", *it);
	}
}