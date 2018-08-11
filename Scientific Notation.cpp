// 这种题目真的烦，太多分支判断了，写起来脑壳疼
#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int epos = s.find("E");
	string num = s.substr(0, epos);
	string expo = s.substr(epos + 1, s.length() - epos-1);
	if (num[0] == '-') cout << "-";
	if (expo[0] == '-') {
		int times = -stoi(expo);
		if (times == 0) {
			for (int i = 1; i < num.length(); i++)
				cout << num[i];
		}
		else {
			cout << "0.";
			for (int i = 1; i < times; i++)
				cout << "0";
			for (int i = 1; i < num.length(); i++)
				if (num[i] != '.')cout << num[i];
		}
	}
	else {
		int times = stoi(expo);
		int zeros = times - num.length() + 3;
		if (zeros < 0) {
			for (int i = 1; i < num.size();) {
				if (times == i - 3) cout << '.';
				else {
					if(num[i]!='.') cout << num[i];
					i++;
				}
			}
		}
		else {
			for (int i = 1; i < num.size();i++)
				if (num[i] != '.') cout << num[i];
			for (int i = 0; i < zeros; i++)
				cout << "0";
		}
	}
}