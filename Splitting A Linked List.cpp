// 第一次写的时候忽略了可能会存在全是正数的情况，所有两个测试出错
// 还是该项柳神学习，三种数字先保存在输出，而不是在输入的时候就输出负数型的
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5;
int n, head, kn;
struct node
{
	int data;
	int next;
} LL[maxn];
vector<int> v[3];
int main()
{
	scanf("%d%d%d", &head, &n, &kn);
	int addr;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &addr);
		scanf("%d%d", &LL[addr].data, &LL[addr].next);
	}
	int ptr = head, cnt = 0;
	while (ptr != -1)
	{
		if (LL[ptr].data < 0)
			v[0].push_back(ptr);
		else if (LL[ptr].data <= kn)
			v[1].push_back(ptr);
		else
			v[2].push_back(ptr);
		ptr = LL[ptr].next;
	}
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (!flag)
			{
				printf("%05d %d", v[i][j], LL[v[i][j]].data);
				flag = true;
			}
			else
				printf(" %05d\n%05d %d", v[i][j], v[i][j], LL[v[i][j]].data);
		}
	}
	printf(" -1");
	return 0;
}