#include <iostream>
#include<map>
#include<set>
#include <vector>
using namespace std;
int n, m;
//vector<int> lonely;
map<int, int> couple;
set<int> lonely;
int main() {
	scanf("%d", &n);
	int couple1, couple2;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &couple1, &couple2);
		couple[couple1] = couple2;
		couple[couple2] = couple1;
	}
	scanf("%d", &m);
	int temp;
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		if (couple.find(temp) == couple.end() || lonely.find(couple[temp]) == lonely.end())
			lonely.insert(temp);
		// not found in couple list or another couple not found, put in lonely temporary.
		else {
			lonely.erase(couple[temp]);
		}
	}
	printf("%d\n", lonely.size());
	for (auto i = lonely.begin(); i != lonely.end(); i++) {
		if(i!=lonely.begin()) printf(" %05d", *i); 
    // 千万不要忘了输出的时候指定整数的类型，因为我想偷懒不用 string 类型，这个错误犯了听多次的
		else printf("%05d", *i);
	}
}