#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n, Gsize;
vector<int> mice;
vector<int> seq;
vector<int> r; // 保存最后的排名
int main() {
	scanf("%d%d", &n, &Gsize);
	mice.resize(n);
	seq.resize(n);
	r.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &mice[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	vector<int> temp;
	while (seq.size() != 1) {
    // 有多少个组，就会有多少个胜出者，所以这一轮淘汰的排名都是 group + 1
		int group = (seq.size() + Gsize -1) / Gsize;
    
		for (int i = 0; i < seq.size(); i+=Gsize) {
			int max = -1, index = -1;
			int itnum = min(i + Gsize, (int)seq.size());
			for (int j = i; j < itnum; j++) {
				if (mice[seq[j]] > max) {
					if(index!=-1) r[index] = group + 1;
					max = mice[seq[j]]; index = seq[j];
				}
				else r[seq[j]] = group + 1;
			}
			temp.push_back(index);
    }
		seq = temp;
		temp.clear();
	}
	r[seq[0]] = 1; // 第一名需要额外手动输入
	for (int i = 0; i < r.size(); i++) {
		if(i==0) printf("%d", r[i]);
		else printf(" %d", r[i]);
	}
}