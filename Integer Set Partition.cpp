#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n;
vector<int> arr;
int sumup(vector<int> &a, int begin, int len) {
	int sum = 0;
	for (int i = begin; i < begin + len; i++)
		sum += a[i];
	return sum;
}
int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());
	int n1, n2;
	n1 = arr.size() / 2;
	n2 = arr.size() - n1;
	int sum1 = sumup(arr, 0, n1);
	int sum2 = sumup(arr, n1, n2);
	printf("%d %d", n2 - n1, sum2 - sum1);
}