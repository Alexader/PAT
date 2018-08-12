// 记录每个 A 的前面的 P的个数，以及后面 T 的个数，相乘的就是这个A
// 可以形成的 PAT 的个数
#include <iostream>
#include <vector>
#include<string>
using namespace std;
const int mod = 1000000007;
string s;
vector<int> P;
vector<int> T;
int main() {
	cin >> s;
	int count = 0, p = 0, t = 0;
	int len = s.size();
	P.resize(len);
	T.resize(len);
	for (int i = 0; i < len; i++) {
		if (s[i] == 'P')
			p++;
		P[i] = p;
	}
	for (int i = len-1; i >0 ; i--) {
		if (s[i] == 'T')
			t++;
		T[i] = t;
	}
	for (int i = 0; i < len; i++) {
		if (s[i] == 'A') {
			count = (count + P[i] * T[i]) % mod;
		}
	}
	printf("%d", count);
}