#define _CRT_SECURE_NO_DEPRECATE

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#include<stdio.h>
void sort(int* a, int l);
const int N = 1010;
int n;
int a[N], b[N];
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		sort(a + 1, *(a + n + 1));
		sort(b + 1, *(b + n + 1));
		//p是渊子马的数组的指针，q是国王妈的数组的指针 
		//win表示渊子马的胜场数 
		int p = 1, q = 1, win = 0;
		while ((p <= n) && (q <= n)) {
			if (a[p] > b[q]) {//渊子马能战胜国王，PK下一组马 
				win++;
				p++;
				q++;
			}
			else {//渊子马不能战胜国王马，渊子用下一匹马去PK 
				p++;
			}
		}
		if (win > (n - win)) {
			printf("%s\n", "YES");
		}
		else {
			printf("%s\n", "NO");
		}
	}
	return 0;
}
void sort(int* a, int l)//a为数组地址，l为数组长度。
{
	int i, j;
	int v;
	//排序主体
	for (i = 0; i < l - 1; i++)
		for (j = i + 1; j < l; j++)
		{
			if (a[i] > a[j])//如前面的比后面的大，则交换。
			{
				v = a[i];
				a[i] = a[j];
				a[j] = v;
			}
		}
}