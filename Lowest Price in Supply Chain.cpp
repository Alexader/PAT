#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
double p, r;
vector<vector<int> > tree;
int mini = 1e5, cnt = 0;
void dfs(int root, int depth) {
	if(tree[root].empty()) {
		if(depth<mini){
			mini = depth; cnt = 1;
		}
		else if(depth == mini)
			cnt++;
	}
	for(int i=0;i<tree[root].size();i++)
		dfs(tree[root][i], depth+1);
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	tree.resize(n);
	int num;
	for(int i=0;i<n;i++) {
		scanf("%d", &num);
		int child;
		for(int j=0;j<num;j++){
			scanf("%d", &child);
			tree[i].push_back(child);
		}
	}
	dfs(0, 0);
	printf("%0.4lf %d", p*pow(1+0.01*r, mini), cnt);
}