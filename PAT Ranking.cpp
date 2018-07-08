/*
PAT 1025 Solution
*/ 
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
// 需要按照当地考场排序，而且要有总体的排序，
const int maxn = 100*301;
int N, K;
struct Grade {
	int location_num;
	string number;
	int score;
	int local_rank;
} Tests[maxn];

bool cmp(Grade &g1, Grade &g2) {
  // 排序规则先按照总成绩，再看学号大小
	if(g1.score > g2.score) return true;
	else if(g1.score == g2.score) {
		return g1.number.compare(g2.number) < 0;
	}
	return false;
}
int main() {
	scanf("%d", &N);

	int location = 1, num_testees = 0, local_start;
	for(int i=0;i<N;i++) {
		scanf("%d", &K);
		local_start = num_testees; // 记录一个考场的开始位置
		for(int j=0;j<K;j++) {
			Tests[num_testees].location_num = location;
			cin>>Tests[num_testees].number;
			scanf("%d", &Tests[num_testees].score);
			num_testees++;
		}
		location++;
		sort(Tests + local_start, Tests+num_testees, cmp); // 一个考场内部排序
		int local_rank = 1, delay = 0;
		Tests[local_start].local_rank = local_rank;
		for (int i = local_start + 1; i < num_testees; i++)
		{
			if (Tests[i].score != Tests[i - 1].score) {
				local_rank += delay + 1;
				delay = 0;
			}
			else delay++;
			Tests[i].local_rank = local_rank;
		}
	}
	printf("%d\n", num_testees);
	sort(Tests, Tests + num_testees, cmp);
	int rank = 1, delay = 0;
	cout<<Tests[0].number<<" ";
		printf("%d %d %d\n", rank, Tests[0].location_num, Tests[0].local_rank);
	for(int i=1;i<num_testees;i++) {
		cout<<Tests[i].number<<" ";
		if(Tests[i].score != Tests[i-1].score) {
			rank += delay + 1;
			delay = 0;
		}
		else delay++;
		if(i!=num_testees-1)
			printf("%d %d %d\n", rank, Tests[i].location_num, Tests[i].local_rank);
		else
			printf("%d %d %d", rank, Tests[i].location_num, Tests[i].local_rank);
	}
}
