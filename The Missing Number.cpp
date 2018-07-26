#include <cstdio>
#include <algorithm>
const int maxn = 1E2;
using namespace std;
int N;
int arr[maxn];
int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
        scanf("%d", &arr[i]);
    arr[0] = 0;
    sort(arr+1, arr+N+1);
    int positiveNum = 0;
    for(int i=1;i<=N;i++) {
        if(arr[i] > 0 && arr[i] != arr[i-1]) {
            positiveNum++;
            if(positiveNum != arr[i]){
                printf("%d", positiveNum);
                return 0;
            }
        }
    }
    printf("%d", positiveNum+1);
}