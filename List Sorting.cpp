/*
PAT 1028 Solution
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 100001;
int N, C;
struct record {
	string ID;
	string name;
	int grade;
} records[maxn];
typedef bool (*functionPointer)(record&, record&);

bool cmp1(record &r1, record &r2) {
	return r1.ID < r2.ID;
}
bool cmp2(record &r1, record &r2) {
	if(r1.name < r2.name) return true;
	else if(r1.name == r2.name) {
		return r1.ID < r2.ID;
	}
	return false;
}
bool cmp3(record &r1, record &r2) {
	if(r1.grade < r2.grade) return true;
	else if(r1.grade == r2.grade) {
		return r1.ID < r2.ID;
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &C);
	// record* records = new record[N];
	for(int i=0;i<N;i++) {
		cin>>records[i].ID;
		cin>>records[i].name;
		cin>>records[i].grade;
	}
	// typedef bool (*functionPointer)(record&, record&);
	functionPointer cmps[3] = { cmp1, cmp2, cmp3 };
	sort(records, records + N, cmps[C-1]);
	for(int i=0;i<N;i++) {
		if(i != N-1)
			cout<<records[i].ID<<" "<<records[i].name<<" "<<records[i].grade<<endl;
		else
			cout<<records[i].ID<<" "<<records[i].name<<" "<<records[i].grade;
	}
}
