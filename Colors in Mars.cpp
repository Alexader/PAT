/*
PAT 1027 Solution
*/
#include<iostream>
int RGB[3];
char color[7];

void conver13(int c, char color[], int end) {
	int temp;
	while(c != 0) {
		temp = c % 13;
		c /= 13;
		color[end--] = (temp>=10 ? (temp - 10) + 'A' : temp + '0');
	}
}
int main() {
	scanf("%d%d%d", &RGB[0], &RGB[1], &RGB[2]);
	for(int i=0;i<6;i++)
		color[i] = '0';
	for(int i=0;i<3;i++)
		conver13(RGB[i], color, 2*i+1);
	color[6] = '\0';
	printf("#%s", color);
}
