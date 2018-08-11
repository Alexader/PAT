#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
int Msize, kn;
bool isPrime(int n) {
	if (n == 1) return false;
	int s = (int)sqrt(n*1.0);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return false;
	return true;
}
int H(int key) {
	return key % Msize;
}
vector<bool> Hash;
int main() {
	scanf("%d%d", &Msize, &kn);
	while (!isPrime(Msize)) Msize++;
	Hash.resize(Msize, false);
	int h, key;
	for (int i = 0; i < kn; i++) {
		scanf("%d", &key);
		h = H(key);
		int home = h;
		bool success = false;
		for (int j = 1; j < Msize; j++) {
			if (Hash[h] == false) {
				if (i == 0)
					printf("%d", h);
				else printf(" %d", h);
				Hash[h] = 1;
				success = true;
				break;
			}
			h = (home + j*j) % Msize;
		}
		if (!success) {
			if (i == 0) printf("-");
			else printf(" -");
		}
	}
}