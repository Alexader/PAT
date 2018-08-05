#include <iostream>
#include <vector>
#include<string>
using namespace std;
int n;
char kind[5] = {'S', 'H', 'C', 'D', 'J'};
vector<string> cards(54);
vector<string> shuffles(54);
int order[54];
int main() {
	scanf("%d", &n);
	for(int i=0;i<54;i++)
		scanf("%d", &order[i]);
	int	count = 0;
	for(int i=0;i<4;i++) {
		for(int j=1;j<=13;j++)
      // 这里的用发一开始还不熟
			cards[count++] = kind[i] + to_string(j);
	}
	cards[52] = "J1"; cards[53] = "J2";
	for(int i=0;i<n;i++) {
		for(int j=0;j<54;j++) {
			// shuffle
			shuffles[order[j]-1] = cards[j];
		}
		cards = shuffles;
	}
	for(int i=0;i<54;i++){
	  if(i!=53) printf("%s ", cards[i].c_str());
	  else printf("%s", cards[i].c_str());
	}
}
