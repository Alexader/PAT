#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
using namespace std;
string days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
string codes[4];
int map1[256] = { 0 };
// 感觉最重要是读懂题目意思，我感觉这个真的有毒，我怎么读感觉是找到第一个相同的大写英文字母。
// 这 TM 是相同位置的相同英文大写字母。向PAT英文低头
pair<int, int> findCommonLetter(string a, string b) {
	pair<int, int> temp;
	int mini = min(a.length(), b.length()), pos;
	for (int i = 0; i < mini; i++) {
		if (a[i] == b[i] && a[i] - 'A' >= 0 && a[i] - 'G' <= 0) {
			temp.first = a[i] - 'A';
			pos = i + 1;
			break;
		}
	}
	for (int i = pos; i < mini; i++) {
		if (a[i] == b[i] && (a[i] - 'A' >= 0 && a[i] - 'N' <= 0 || isdigit(a[i])))
		{
			temp.second = a[i]; break;
		}
	}
	return temp;
}
int findCommon(string a, string b) {
	for (int i = 0, j = 0; i < a.length() && j < b.length(); i++, j++) {
		if (a[i] == b[j] && isalpha(a[i])) return i;
	}
}
int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 4; i++)
		cin >> codes[i];

	auto one = findCommonLetter(codes[0], codes[1]);
	int second = findCommon(codes[2], codes[3]);
  // 输出格式的控制，还是 printf 比较好用，cout 都不会控制进度这些
	printf("%s %02d:%02d", days[one.first].c_str(), isdigit(one.second) ? one.second-'0' : one.second - 'A' + 10, second);
}