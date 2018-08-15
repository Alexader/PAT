#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int n, skip, kn;
vector<string> v;
map<string, bool> mp;
int main() {
	cin>>n>>skip>>kn;
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int cnt = 0;
	while(kn<=n) {
		while(kn<=n && mp.find(v[kn-1]) != mp.end()) kn++;
		cout<<v[kn-1]<<endl;
		cnt++;
		mp[v[kn-1]] = true;
		kn += skip;
	}
	if(cnt == 0) cout<<"Keep going...";
}