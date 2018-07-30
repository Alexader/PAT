#include <iostream>
#include <string>
using namespace std;
int n, D;
string ans;
int main() {
	ios::sync_with_stdio(false);
	cin >> D >> n;
	ans = to_string(D);
	string temp;
	for (int i = 0; i < n-1; i++) {
		int cnt = 0, k;

		for (int j = 0; j < ans.length(); j = k) {
			for (k = j; k < ans.length() && ans[j] == ans[k]; k++);
			temp.push_back(ans[j]);
			temp += to_string(k - j);
		}
		ans = temp;
		temp = "";
	}
	cout << ans;
}