#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int> mp;
int main() {
	string s;
	string t;
	while (cin >> s) {
		cin.get();
    // 主要就是如何剥除非字母数字的字符
		for (int i = 0; i < s.length(); i++) {
			if (isalnum(s[i])) {
				s[i] = tolower(s[i]);
				t += s[i];
			}
			if(!isalnum(s[i]) || i==s.length()-1) {
				if (!t.empty()) mp[t]++;
				t = "";
			}
		}
	}
	int maxn = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second > maxn) {
			maxn = it->second;
			t = it->first;
		}
	}
	cout << t << " " << maxn << endl;
}
