/*
这道题卡时间，c++ 里面的 string 是不能用的，而且即使关了 cin、cout 的同步
以及使用 char 数组还是会超时，不是很懂。
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> stus[maxn];
int getid(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
int main() {
	scanf("%d%d", &n, &k);
	int lec_id, lec_num, stu_id;
	char temp_name[5];
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &lec_id, &lec_num);
		for (int j = 0; j < lec_num; j++) {
			scanf("%s", temp_name);
			stu_id = getid(temp_name);
			stus[stu_id].push_back(lec_id);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", temp_name);
		stu_id = getid(temp_name);
		sort(stus[stu_id].begin(), stus[stu_id].end());
		printf("%s %d", temp_name, stus[stu_id].size());
		for (auto it = stus[stu_id].begin(); it != stus[stu_id].end(); it++) {
			printf("%d", *it);
		}
		printf("\n");
	}
}