#include <iostream>
#include<algorithm>
#include <functional>
#include<string>
using namespace std;
string num;
int main() {
	cin >> num;
	num.insert(0, 4 - num.length(), '0');
  // 选择 do while 是因为对于输入 “6172” 也要进行倒转输出的操作
	do {
		sort(num.begin(), num.end(), greater<char>());
		int gt = stoi(num);
		reverse(num.begin(), num.end());
		int lt = stoi(num);
		if (gt == lt) printf("%04d - %04d = 0000", gt, lt);
		else {
			printf("%04d - %04d = %04d\n", gt, lt, gt - lt);
		}
		num = to_string(gt - lt);
    // 如果碰到不是四位数的情况要进行补全
		num.insert(0, 4 - num.length(), '0');
	} while (num != "6174" && num != "0000");
}
