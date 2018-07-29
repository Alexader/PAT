#include <iostream>
#include <string>
#include <vector>
using namespace std;
int m;
struct user
{
	string name;
	string pw;
};
vector<user> acounts;
vector<int> modified;
bool needModified(string &s) {
	bool need = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0' && s[i] != '1' && s[i] != 'l' && s[i] != 'O')continue;
		if (s[i] == '0') s[i] = '%';
		if (s[i] == '1') s[i] = '@';
		if (s[i] == 'l') s[i] = 'L';
		if (s[i] == 'O') s[i] = 'o';
		need = true;
	}
	return need;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	acounts.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> acounts[i].name >> acounts[i].pw;
		cin.get();
		if (needModified(acounts[i].pw))
			modified.push_back(i);
	}
	if (modified.size() == 0) {
		if (m == 1) cout << "There is 1 account and no account is modified";
		else
    // 这里的字符串的真的要完全粘贴题目中的，自己粘贴的上一句的又花了好多时间检查，划不来
			cout << "There are " << m << " accounts and no account is modified";
	}
	else {
		cout << modified.size() << endl;
		for (auto it = modified.begin(); it != modified.end(); it++) {
			cout << acounts[*it].name << " " << acounts[*it].pw << endl;
		}
	}
}