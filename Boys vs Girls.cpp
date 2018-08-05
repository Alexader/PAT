#include <iostream>
#include<algorithm>
#include <vector>
#include<string>
using namespace std;
int n;
struct Student
{
	string name;
	char sex;
	string id;
	int grade;
};
bool cmp(Student &a, Student &b) {
  // 根据字母顺序正好女生排在男生前面
	if (a.sex != b.sex) return a.sex < b.sex;
	return a.grade > b.grade;
}
vector<Student> s;
int main() {
	scanf("%d", &n);
	s.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].sex >> s[i].id >> s[i].grade;
	}
  // 男女生一起排序比较方便，因为只需要最好成绩和最差成绩
	sort(s.begin(), s.end(), cmp);
	bool exist = false;
	if (s[0].sex == 'F' && s.back().sex == 'M') {
		cout << s[0].name <<" "<< s[0].id << endl;
		cout << s.back().name <<" "<< s.back().id << endl;
		exist = true;
	}
	else {
		if (s[0].sex == 'F') {
			cout << s[0].name <<" "<< s[0].id << endl;
			cout << "Absent" << endl;
		}
		else {
			cout << "Absent" << endl;
			cout << s.back().name <<" "<< s.back().id << endl;
		}
	}
	if (exist) cout << abs(s[0].grade - s.back().grade);
	else cout << "NA";
}
