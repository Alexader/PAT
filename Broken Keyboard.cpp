#include <iostream>
#include <vector>
#include<string>
using namespace std;
string s, broke;
vector<bool> mp(256, false);
int main() {
	cin >> s >> broke;
	for (int i = 0; i < broke.length(); i++) {
		if (broke[i] != '-') {
			broke[i] = toupper(broke[i]);
			mp[broke[i]] = true;
		}
	}
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
		if (s[i] != '-' && mp[s[i]] == false) {
			cout << s[i];
      // 已经输出的也要打上记号
			mp[s[i]] = true;
		}
	}
	return 0;
}