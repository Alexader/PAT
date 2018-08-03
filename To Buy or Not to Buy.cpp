#include <iostream>
#include<string>
#include <map>
using namespace std;
map<char, int> mp;
int main() {
	ios::sync_with_stdio(false);
	string shopOwner, eva;
	cin >> shopOwner >> eva;
	for (int i = 0; i < shopOwner.size(); i++) {
		if (mp.find(shopOwner[i]) == mp.end())
			mp[shopOwner[i]] = 1;
		else mp[shopOwner[i]]++;
	}
	int count = 0;
	for (int i = 0; i < eva.size(); i++) {
		if (mp.find(eva[i]) == mp.end() || mp[eva[i]] <= 0) count++;
		else
			mp[eva[i]]--;
	}
	if (count != 0) cout << "No " << count << endl;
	else cout << "Yes " << shopOwner.size() - eva.size() << endl;
}