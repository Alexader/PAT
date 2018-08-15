// 典型的贪心算法
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main()
{
  scanf("%d", &n);
  v.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  double result = v[0];
  for (int i = 1; i < n; i++)
    result = (result + v[i]) / 2.0;
  printf("%d", (int)result);
  return 0;
}