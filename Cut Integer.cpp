#include <iostream>
#include<string>
using namespace std;
int n;
int main() {
	cin>>n;
	string s, pre, later;
	long int a, b, c;
	for(int i=0;i<n;i++){
		cin>>s;
		pre = s.substr(0, s.length()/2);
		later = s.substr(s.length()/2, s.length()/2);
		a = stoi(s);
		b =stoi(pre);
		c =stoi(later);
    // 要注意这里的后面的书=数可能去到零，不然会有浮点数错误
		if(b*c != 0 && a%(b*c)==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}