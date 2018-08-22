#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
vector<string> sn;
// 这个比较函数是真的神奇，字符串相加在比较
bool cmp(string &a, string &b) {
	return a + b < b + a;
}
string ans;
int main() {
	cin >> n;
	sn.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> sn[i];
	}
	sort(sn.begin(), sn.end(), cmp);
	for(int i=0;i<n;i++)
	  ans+=sn[i];
	while (!ans.empty() && ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.empty()) cout<<0;
	cout<<ans;
}