#include <cstdio>
#include<set>
#include<vector>
using namespace std;

int n, m, query_num;
vector<set<int> > sets;
int main() {
	scanf("%d", &n);
	int temp, set_size;
	sets.resize(n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &set_size);
		for (int j = 0; j < set_size; j++) {
			scanf("%d", &temp);
			sets[i].insert(temp);
		}
	}
	scanf("%d", &query_num);
	int set_num1, set_num2;
	set<int> merge_set;
	for (int i = 0; i < query_num; i++) {
		scanf("%d%d", &set_num1, &set_num2);
		set_num1--; set_num2--;
		int ct = 0, nt = sets[set_num2].size();
		for (auto j = sets[set_num1].begin(); j != sets[set_num1].end(); j++) {
			if (sets[set_num2].find(*j) != sets[set_num2].end())
				ct++;
			else
				nt++;
		}
		printf("%0.1f%%\n", 100.0*ct / nt);
	}
}