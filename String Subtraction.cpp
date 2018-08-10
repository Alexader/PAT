#include <iostream>
#include<string>
using namespace std;
bool show[256] = { false };
string str1, str2;
int main() {
	getline(cin, str1);
	getline(cin, str2);
  // 需要先算出长度，放在循环中会超时
	int len1 = str1.length();
	int len2 = str2.length();
	int ptr = 0;
	while (ptr < len1)
		show[str1[ptr++]] = true;
	ptr = 0;
	while (ptr < len2)
		show[str2[ptr++]] = false;
	ptr = 0;
	while (ptr < len1) {
		if (show[str1[ptr]]) cout << str1[ptr];
		ptr++;
	}
}
