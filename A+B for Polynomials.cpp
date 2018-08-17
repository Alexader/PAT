#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5;
int n;
// 多项式的指数值作为vector的下标
vector<double> p[2];
int main() {
	int num, maxep, ep;
	double coe;
	for(int i=0;i<2;i++) {
		scanf("%d %d", &num, &maxep);
		p[i].resize(maxep+1);
		scanf("%lf", &coe);
		p[i][maxep] = coe;
		for(int j=1;j<num;j++) {
			scanf("%d %lf", &ep, &coe);
			p[i][ep] = coe;
		}
	}
  // 把较短的多项式加到较长的上面
	int m, mx, mi;
	if(p[0].size() <= p[1].size()) {
		m = 1; mx = p[1].size(); mi = p[0].size();
	} else {
		m = 0; mx = p[0].size(); mi = p[1].size();
	}
	int cnt = 0;
	for(int i=0;i<mx;i++) {
		if(i<mi) p[m][i] = p[0][i]+p[1][i];
		if(p[m][i] != 0) cnt++;
	}
	printf("%d", cnt);
	for(int i=mx-1;i>=0;i--)
		if(p[m][i] != 0) printf(" %d %0.1lf", i, p[m][i]);
}