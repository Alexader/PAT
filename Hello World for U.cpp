#include <iostream>
#include <string>
using namespace std;
const int maxn = 80;
char u[maxn][maxn]; // 相当于把U字型的字符存储在二维数组中，包括空格
string s;
int main() {
    cin>>s;
    int n = s.size()+2;
    int n1, n2;
    n1 = n/3;
    n2 = n1+ n%3;
    int index = 0;
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++)
            u[i][j] = ' ';

    for(int i=0;i<n1;i++)
        u[i][0] = s[index++];
    for(int i=1;i<=n2-2;i++)
        u[n1-1][i] = s[index++];
    for(int i=n1-1;i>=0;i--)
        u[i][n2-1] = s[index++];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++)
            printf("%c", u[i][j]);
        printf("\n");
    }
}