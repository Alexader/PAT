#include <iostream>
#include <string>
using namespace std;
int n;
bool islegal(string a) {
	int dotCount = 0;
	double temp;
	for (int i = 0; i < a.length(); i++) {
		if (isalpha(a[i])) return false;
		if (a[i] == '.') {
      // 利用小数点的位置就可以判断精度
			if (++dotCount > 1 || a.length() - i - 1> 2) return false;
		}
	}
	temp = stod(a);
	if (temp < -1000.0 || temp > 1000.0) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	double sum = 0.0;
	int k = 0;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (!islegal(temp)) cout << "ERROR: " << temp << " is not a legal number" << endl;
		else {
			k++;
			sum += stod(temp);
		}
	}
	if(k == 0)
		printf("The average of %d numbers is Undefined", k);
	else if(k==1)
		printf("The average of %d number is %0.2lf", k, sum / k);
	else
		printf("The average of %d numbers is %0.2lf", k, sum/k);
}