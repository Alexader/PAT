#include <iostream>
#include<vector>
using namespace std;
int n;
vector<int> arr;
int main() {
	scanf("%d", &n);
	arr.resize(n);
	int unbalance = 0, temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		arr[temp] = i;
    // 零因为要参加交换，所以不记录到未归位的数字
		if (temp != i && i!=0) unbalance++;
	}
	int index = 1, cnt = 0;
  // 每次的交换要是能够让一个数字归位的话，是最好的结果；如果零被交换到了零的位置
  // 那么就遍历数组找到第一个没有归位的地方，交换已经归位的零和找到的这个地方。技巧是
  // 每次遍历的时候不用从零开始，因为以前查找过的都是已经归位的，只要从上次的位置开始就可以了
  // 这是贪心算法的应用
	while (unbalance != 0) {
		if (arr[0] == 0) {
			for (; index < n; index++)
				if (arr[index] != index) {
					cnt++;
					arr[0] = arr[index]; arr[index] = 0;
					break;
				}
		}
		else {
			temp = arr[0];
			arr[0] = arr[arr[0]];
			arr[temp] = temp;
			unbalance--;
			cnt++;
		}
	}
	printf("%d", cnt);
}
